#pragma once
#include <stdio.h>
#include "global.h"
#include "frame.h"


class Rectangle{

	public:
		Rectangle(int x, int y, int w, int h, byte r, byte g, byte b);
		void draw();
		void setX(int x){this-> x = x;}
		void setY(int y){this-> y = y;}

	private:
		int x, y, w, h;
		byte r, g, b;
};