#include "SquareOsc.hpp"

void SquareOsc::setFrequency(float freq)
		{
			frequency = freq;
			updatePhase();
		}
float SquareOsc::process()
{
		if(phase < 0.5)
			{
				output = 1.0f;
			}else{

				output = -1.0f;
			}
			phaseInc += frequency/sr;
			if(phase >= 1.0f) phase -= 1.0f;
			return output;
}		

void SquareOsc::updatePhase()
{
	phaseInc = frequency / sr;

}