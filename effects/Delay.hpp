#include "DSPlib.hpp"

class Delay : public DSPEffect
{
	private:
		float sample_rate;
		float feedback;
		float wetMix;
		int delaySamples;
		int writeIndex;
		std::vector<float> buffer;

	public:
		Delay(float SampleRate, float delayMs = 500.0f, float feedback = 0.5f, float wet = 0.5f)
		: sample_rate(SampleRate), feedback(feedback), wetMix(wet)	
		{
			setDelayTime(delayMs);
		}
		void setDelayTime(float ms);
		void setFeedback(float f);
		void setWet(float w);

		virtual float process(float in) override;

};