#include "rectangle.h"
#include <iostream>
#include <sstream>
#include <sys/stat.h>
#include <stdio.h>
#include <cstring>
#include <cassert>

using namespace std;
static Frame frame;

rectangle::rectangle(void)
	{
	const char * cmd = 
		"ffmpeg              "
		"-y                  "
		"-hide_banner        "
		"-f rawvideo         " // input to be raw video data
		"-pixel_format rgb24 "
		"-video_size 720x480 "
		"-r 60               " // frames per second
		"-i -                " // read data from the standard input stream
		"-pix_fmt yuv420p    " // to render with Quicktime
		"-vcodec mpeg4       "
		"-an                 " // no audio
		"-q:v 5              " // quality level; 1 <= q <= 32
		"output.mp4          ";

	// Run the ffmpeg command and get pipe to write into its standard input stream.
#ifdef _WIN32
	FILE * pIp = _popen(cmd, "wb");
#else
	FILE * pIp = popen(cmd, "w");
#endif
	if (pIp == 0) {
		cout << "error: " << strerror(errno) << endl;
		//return 1;
	}
	pipe = pIp;
	}

rectangle::~rectangle(void)
	{
	fflush(pipe);

#ifdef _WIN32
	_pclose(pipe);

#else
	pclose(pipe);

#endif
	}

void rectangle::draw(int x, int y, int w, int h, byte r, byte g, byte b)
	{
	int x0 = x;
	int x1 = x + w;
	int y0 = y;
	int y1 = y + h;
	for (int y = y0; y < y1; ++y) 
		{
		for (int x = x0; x < x1; ++x) 
			{
			frame.setPixel(x, y, r, g, b);
			}
		}
	}