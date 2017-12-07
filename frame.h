#pragma once
#include "global.h"
#include <stdio.h>

class Frame{

	public:
		Frame(void);
		~Frame(void);
		void setPixel(int y, int x, byte g, byte r, byte b);
		void clear();
		bool isOutside(int x, int y) const;
		void write(FILE * file) const;

	private:
		unsigned char * pixels;
};

