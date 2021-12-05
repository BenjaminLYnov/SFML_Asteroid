#ifndef OVNISHAPE_H
#define OVNISHAPE_H
#pragma once

#include "Shape.hpp"

class OVNIShape : public Shape
{
public:
	OVNIShape();
	~OVNIShape();

private:
	void SetShapeOutsideScreen();
};
#endif