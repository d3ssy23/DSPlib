#pragma once
#include "../DSPlib.hpp"

class PulseWidth : public DSPModule
{
	PulseWidth(float sampleRate) : sr(sampleRate){}
	float setDuty(float dutySet);
	float setPhase(float ps);
	float setFrequency(float freq);
	virtual float process() override;

	private:
		float frequency = 440.0f;
		float sr;
		float phase = 0.0f;
		float duty = 0.25f;
		float output;
		float phaseInc = 0.0f;

};