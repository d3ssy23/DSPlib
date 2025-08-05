#include "Delay.hpp"

	void Delay::setDelayTime(float ms)
		{
			delaySamples = (int)((ms/1000.0f)*sample_rate); //formula
			buffer.resize(delaySamples + 1, 0.0f);
			writeIndex = 0;
		}
		
	void Delay::setFeedback(float f) { feedback = f;}

	void Delay::setWet(float w) {wetMix = w;}

	float Delay::process(float in)
		{
			int readIndex = (writeIndex + 1) % buffer.size();
			float delayed = buffer[readIndex];

			buffer[writeIndex] = in + delayed * feedback;
			writeIndex = (writeIndex + 1) % buffer.size();

			return (1.0f - wetMix) * in + wetMix * delayed;
		}
