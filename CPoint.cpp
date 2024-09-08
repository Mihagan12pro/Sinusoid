#include "pch.h"
#include "CPoint.h"

CPoint::CPoint(int _i,double _width,double _height)
{
	i = _i;

	CPoint::width = _width;
	height = _height;

	frequency = 1;

	amplitude = height / 2;
	centerY = height / 2;

}

double CPoint::X()
{
	return (2 * pi * i) / (points_count - 1);
}
double CPoint::Y()
{
	return centerY + amplitude * sin(frequency * X());
}