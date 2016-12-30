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
	ColorDepth_24 = 24,
	ColorDepth_32 = 32,
};

enum PixelFormat {
	PixelFormat_GrayScale,
	PixelFormat_ARGB8888,
	PixelFormat_RGB888,
	PixelFormat_RGB565,
	PixelFormat_ARGB1555,
	PixelFormat_ARGB4444,
	PixelFormat_L8,
	PixelFormat_AL44,
	PixelFormat_AL88,
};

class GfxSurface {
private:
	GfxSurface(void);
public:
	GfxSurface(ColorDepth bitsDepth, uint16_t width, uint16_t heigth);
	GfxSurface(PixelFormat pixFormat, uint16_t width, uint16_t heigth);
	virtual ~GfxSurface(void);
	void fill(uint32_t value);
public:
	uint8_t *getFrameBuffer(void) { return line; }
	const uint16_t &getBytesPerLine(void) { return bytesPerLine; }
	const uint16_t &getWidth(void) { return width; }
	const uint16_t &getHeigth(void) { return heigth; }
	const ColorDepth &getBitsDepth(void) { return bitsDepth; }
	const PixelFormat &getPixelFormat(void) { return pixelFormat; }
public:
	void drawPixel(uint16_t x, uint16_t y, uint8_t alpha);
	void drawPixel(uint16_t x, uint16_t y, uint32_t argb);

	uint32_t getPixel(uint16_t x, uint16_t y);
private:
	void create(void);
	ColorDepth format2depth(const PixelFormat &fmt);
private:
	uint8_t *line;
	uint16_t bytesPerLine;
	uint16_t bytesPerPixel;
	uint16_t width;
	uint16_t heigth;
	ColorDepth bitsDepth;
	PixelFormat pixelFormat;
};



#endif /* SURFACE_HPP_ */