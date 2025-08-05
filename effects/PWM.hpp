#pragma once
#include "../DSPlib.hpp"

class PWM :public DSPEffect
{

	public:

	PWM(float sampleRate): sr (sampleRate){}

	void setDuty(float du); //ensure it's between 0 and 1;
	void setPhase(float ps);
	void setFrequency(float freq);

	virtual float process(float in);
	private:
		float frequecy = 440.0f;
		float sr;
		float phase = 0.0f;
		float phaseInc = 0.0f;
		float duty = 0.25;
		float output;

};