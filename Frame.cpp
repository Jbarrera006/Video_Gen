#include "frame.h"
#include <cstring>
//#include <stdio.h>


Frame::Frame(void)
	{
	pixels = new byte[W * H * 3];
	}


Frame::~Frame(void)
	{
	delete pixels;
	}

void Frame::setPixel(int y, int x, byte g, byte r, byte b)
	{
	if(x <= 0 || x >= W || y <= 0 || y >= H) return;
	pixels[y * W * 3 + x * 3 + 0] = r;
	pixels[y * W * 3 + x * 3 + 1] = g;
	pixels[y * W * 3 + x * 3 + 2] = b;
	}

void Frame::clear()
	{
	memset(pixels, 0, H * W * 3);
	}

bool Frame::isOutside(int * x, int * y) const
	{
	return *x <= 0 || *x >= W || *y <= 0 || *y >= H;
	}

void Frame::write(FILE * file) const
	{
	fwrite(pixels, 3, W * H, file);
	}