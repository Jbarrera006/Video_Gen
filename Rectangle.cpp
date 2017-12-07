#include "Rectangle.h"
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <stdio.h>
#include <cstring>
#include <cassert>

using namespace std;
static Frame frame;

Rectangle::Rectangle(int x, int y, int w, int h, byte r, byte g, byte b): 
r(r), g(g), b(b), x(x), y(y), h(h), w(w){}


//void Rectangle::draw(){
//	int x0 = x;
//	int x1 = x + w;
//	int y0 = y;
//	int y1 = y + h;
//	for (int y = y0; y < y1; ++y) {
//		for (int x = x0; x < x1; ++x) {
//			frame.setPixel(x, y, r, g, b);
//		}
//	}
//}

void Rectangle::draw(){
	for (int y = 100; y < 200; ++y) {
		for (int x = 100; x < 200; ++x) {
			frame.setPixel(x, y, 255, 255, 0);
		}
	}
}