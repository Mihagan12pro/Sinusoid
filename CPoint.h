#pragma once
#include"SinusoidDoc.h"


#define Document CSinusoidDoc
#define Rect CRect
class CPoint
{
private:
	

	double width, height;
	double centerY;

	double amplitude, frequency;

	int i;

public :
	const int points_count = 40;
	const double pi = 3.14159265358979323846;

	double X();
	double Y();

	CPoint(int _i,double _width,double height);


	
};