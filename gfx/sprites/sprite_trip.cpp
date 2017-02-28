/*
 * sprite_temperature.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: shapa
 */

#include "sprites.hpp"

static const uint8_t s_tripA[] = {
	0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0x00, 0xff, 0xff,
	0xff, 0xf0, 0x00, 0x0f, 0xff,
	0xff, 0xf0, 0x00, 0x0f, 0xff,
	0xff, 0xf0, 0xff, 0x0f, 0xff,
	0xff, 0x00, 0xff, 0x00, 0xff,
	0xff, 0x00, 0xff, 0x00, 0xff,
	0xff, 0x00, 0x00, 0x00, 0xff,
	0xff, 0x00, 0x00, 0x00, 0xff,
	0xff, 0x00, 0xff, 0x00, 0xff,
	0xf0, 0x0f, 0xff, 0xf0, 0x0f,
	0xf0, 0x0f, 0xff, 0xf0, 0x0f,
	0xf0, 0x0f, 0xff, 0xf0, 0x0f,
	0xff, 0xff, 0xff, 0xff, 0xff,
};

static const uint8_t s_tripB[] = {
	0xff, 0xff, 0xff, 0xff, 0xff,
	0xf0, 0x00, 0x00, 0xff, 0xff,
	0xf0, 0x00, 0x00, 0x0f, 0xff,
	0xf0, 0x0f, 0xff, 0x00, 0xff,
	0xf0, 0x0f, 0xff, 0x00, 0xff,
	0xf0, 0x0f, 0xf0, 0x0f, 0xff,
	0xf0, 0x00, 0x00, 0xff, 0xff,
	0xf0, 0x00, 0x00, 0x00, 0xff,
	0xf0, 0x0f, 0xff, 0xf0, 0x0f,
	0xf0, 0x0f, 0xff, 0xf0, 0x0f,
	0xf0, 0x0f, 0xff, 0xf0, 0x0f,
	0xf0, 0x00, 0x00, 0x00, 0xff,
	0xf0, 0x00, 0x00, 0x0f, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff,
};

const Sprite Sprite_TripA(
	ColorDepth_4,
	10,
	sizeof(s_tripA) / 5,
	sizeof(s_tripA),
	s_tripA
);

const Sprite Sprite_TripB(
	ColorDepth_4,
	10,
	sizeof(s_tripB) / 5,
	sizeof(s_tripB),
	s_tripB
);

