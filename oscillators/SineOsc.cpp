#include "SineOsc.hpp"

void SineOsc::setFrequency(float freq)
{
	frequency = freq;
}
void SineOsc::setPhase(float ps)
{
	phase = ps;
}

 float SineOsc::process()
		{
			float output = std::sin(phase*2.0f*M_PI);
			phase += frequency/sampleRate;
			if(phase >= 1.0f) phase -= 1.0f;
			return output;
		}

SineOsc::~SineOsc()
{
	
}		