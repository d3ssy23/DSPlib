# pragma once

class DSPEffect{
	public:
		virtual float process(float in) = 0;
		virtual ~DSPEffect() {}
};