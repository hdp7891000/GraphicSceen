/*
 * surface.hpp
 *
 *  Created on: May 24, 2016
 *      Author: shapa
 */

#ifndef SURFACE_HPP_
#define SURFACE_HPP_

#include <stdlib.h>
#include <stdint.h>

enum ColorDepth {
	ColorDepth_4 = 4,
	ColorDepth_8 = 8,
	ColorDepth_16 = 16,
	ColorDepth_32 = 32
};

class GfxSurface {
private:
	GfxSurface(void);
public:
	GfxSurface(ColorDepth bitsDepth, uint16_t width, uint16_t heigth);
	virtual ~GfxSurface(void);
	void fill(uint32_t value);
public:
	uint8_t **getFrameBuffer(void) { return line; }
	const uint16_t &getBytesPerLine(void) { return bytesPerLine; }
	const uint16_t &getWidth(void) { return width; }
	const uint16_t &getHeigth(void) { return heigth; }
	const ColorDepth &getBitsDepth(void) { return bitsDepth; }
private:
	void create(void);
private:
	uint8_t **line;
	uint16_t bytesPerLine;
	uint16_t width;
	uint16_t heigth;
	ColorDepth bitsDepth;
};



#endif /* SURFACE_HPP_ */
