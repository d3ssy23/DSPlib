#include "../DSPlib.hpp"

AudioConfig conf1;
SineOsc osc(conf1.buffer_size);

// void AudioCallback(float *in, float *outL, float *outR, size_t numSamples)
// {
// 	for (size_t i{};i<numSamples;++i)
// 	{
// 		float sample = osc.process();
// 		outL[i] = sample;
// 		outR[i] = sample;
// 	}
// }

int AudioCallback(const void* input, void* output, unsigned long frameCount,const PaStreamCallbackTimeInfo* timeInfo,
					PaStreamCallbackFlags statusFlags,void *userData)
{
	float* in = (float*)input;
	float* out = static_cast<float*>(output);
	// userdata actually tells the callback function what type of sound we have in the buffer
	// that's why we use out struct DSPModType
	DSPModType* type = static_cast<DSPModType*>(userData);
	for(size_t i=0;i<frameCount;++i)
	{
		// processing input
		float inputSample = in[i*2];
		//float output = type->effect->process(input);

		//direct sound sent to out
		// float sample = type->generator->process(); // we assign to sample the inherited process func
		// out[i*2] = sample;
		// out[i*2+1] = sample;

		// signal processed direct dry to effet wet
		float dry = type->generator->process();
		float wet = type->effect->process(dry);
		out[i*2] = wet;
		out[i*2+1] = wet;


	}
	return paContinue;
}