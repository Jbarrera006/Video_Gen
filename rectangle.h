#pragma once
#include <stdio.h>
#include "global.h"
#include "frame.h"


class rectangle
	{
	public:
		rectangle(void);
		~rectangle(void);
		void draw(int x, int y, int w, int h, byte r, byte g, byte b);
		FILE * pipe;
	};