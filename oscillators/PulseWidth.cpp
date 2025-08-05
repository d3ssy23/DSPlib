#include "PulseWidth.hpp"

float PulseWidth::setDuty(float dutySet)
	{
		duty = dutySet;
	}
float PulseWidth::setPhase(float ps)
	{
		phase = ps;
	}	

float PulseWidth::process()
	{
		if(phase > duty)
			output = 1.0f;
		else
			output = -1.0f;
		phase += phaseInc;
		if(phase >= 1.0f)
			phase -= 1.0f;

		return output;	
	}	
float PulseWidth::setFrequency(float freq)
{
	frequency = freq;
}	