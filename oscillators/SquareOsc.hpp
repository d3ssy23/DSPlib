#pragma once
#include "../DSPlib.hpp"

class SquareOsc : public DSPModule
{
	public:
		SquareOsc(float sampleRate) 
		: sr(sampleRate){ updatePhase();}

		void setFrequency(float freq);
		virtual float process() override;

		private:
			float sr;
			float frequency;
			float phaseInc;
			float phase = 0.0f;
			float output;
		
			void updatePhase();
			
};