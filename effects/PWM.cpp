#include "PWM.hpp"

float PWM::process(float in)
{
	float normalized = 0.5f * in +  0.5f;
		(phase< duty) ? output = 1.0f :output = -1.0f;
		
		return output;
}
	void PWM::setFrequency(float freq) {frequecy = freq;}
	void PWM::setPhase(float ps) {phase = ps;}
	void PWM::setDuty(float du) {duty =du; } 