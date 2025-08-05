#pragma once
#include "DSPlib.hpp"


class SineOsc : public DSPModule
{

	public:
		SineOsc(float sampleRate)
		: sampleRate(sampleRate)
		{}
		void setFrequency(float freq);
		void setPhase(float ps);
		virtual float process() override;
		virtual ~SineOsc();


	private:
		float frequency;
		float sampleRate = 440.0f;
		float phase = 0.0f;


};