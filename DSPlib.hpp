#pragma once
#include <math.h>
#include <vector>
#include <cmath>
#include "stddef.h"
#include "oscillators/SineOsc.hpp"
#include "../portaudio/include/portaudio.h"
#include "DSPModule.hpp"
#include "DSPEffect.hpp"
#include "Delay.hpp"
#include "oscillators/SquareOsc.hpp"
#include "oscillators/PulseWidth.hpp"
#include "effects/Delay.hpp"

// constexpr const size_t BUFFER_SIZE = 256;
// constexpr const size_t SAMPLE_RATE = 48000; // better than define and modifiable

struct DSPModType{
	DSPModule* generator;
	DSPEffect* effect;
};

struct AudioConfig
{
	size_t buffer_size = 256;
	float sample_rate = 48000.0f;
	size_t numChannels = 2;
};