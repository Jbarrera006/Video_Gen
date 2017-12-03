#pragma once
#include <stdio.h>
#include "global.h"
#include "frame.h"


class rectangle
	{
	public:
		rectangle(void);
		~rectangle(void);
		void draw_rect(int x, int y, int w, int h, byte r, byte g, byte b);
		void draw_frame(double t);
		FILE *pipe;
	};

