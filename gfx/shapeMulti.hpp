/*
 * shapeMulti.hpp
 *
 *  Created on: Feb 27, 2017
 *      Author: shapa
 */

#pragma once

#include "shape.hpp"
#include <vector>

class GfxMultiShape : public GfxShape {
public:
	GfxMultiShape(){};
	virtual ~GfxMultiShape();
	virtual void setVisible(const bool& val);
	virtual void setSurface(GfxSurface *surface);
	virtual void createSurface();
	virtual bool Blend(GfxSurface *surface);
protected:
	std::vector<GfxShape*>shapes;
private:
	virtual bool draw();
};