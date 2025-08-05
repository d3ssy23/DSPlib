#pragma once

class DSPModule{
	public:
		virtual float process() = 0;
		virtual ~DSPModule() {}
};
