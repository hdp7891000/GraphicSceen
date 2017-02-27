/*
 * widget7Seg.hpp
 *
 *  Created on: Feb 24, 2017
 *      Author: shapa
 */

#pragma once

#include "shapeSprite.hpp"
#include "shapeMulti.hpp"
#include <vector>


class Gfx7SegShape : public GfxSpriteShape {
public:
	Gfx7SegShape();
	virtual ~Gfx7SegShape() {};

	const int8_t &getValue() const { return value; }
	void setValue(const int8_t &value);
private:
	int8_t value;
};

class GfxMulti7SegShape : public GfxMultiShape {
public:
	GfxMulti7SegShape(const size_t size);
	virtual ~GfxMulti7SegShape() {};

	const int32_t &getValue() const { return value; }
	void setValue(const int32_t &value);

private:
	int32_t value;
};


