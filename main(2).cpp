#include <iostream>
#include <stdio.h>
#include "global.h"
#include "Frame.h"
#include "Rectangle.h"

using namespace std;

const double frames_per_second = 30; 
const int duration_in_seconds = 9;

const double pps = 80;

static Frame frame;
static Rectangle rectangle1(0, 0, 20, 10, 0x00, 0xff, 0x00);
static Rectangle rectangle2(0, 0, 20, 10, 0xff, 0xff, 0x00);
static Rectangle rectangle3(0, 0, 20, 10, 0x00, 0xff, 0xff);


void draw_objects(double t){
	frame.clear();
	//const double pps = 80; // pixels per second
	/*rectangle1.setX(t * 40);
	rectangle1.setY(t * 50);
	rectangle2.setX(t * 35);
	rectangle2.setY(t * 20);
	rectangle3.setX(t * 100);
	rectangle3.setY(t * 79);*/
	rectangle1.draw();
	rectangle2.draw();
	rectangle3.draw();
}

int main(int argc, char * argv[]){

	const char * cmd = 
		"ffmpeg              "
		"-y                  "
		"-hide_banner        "
		"-f rawvideo         " // input to be raw video data
		"-pixel_format rgb24 "
		"-video_size 720x480 "
		"-r 30               " // frames per second
		"-i -                " // read data from the standard input stream
		"-pix_fmt yuv420p    " // to render with Quicktime
		"-vcodec mpeg4       "
		"-an                 " // no audio
		"-q:v 5              " // quality level; 1 <= q <= 32
		"output.mp4          ";

	// Run the ffmpeg command and get pipe to write into its standard input stream.
#ifdef _WIN32
	FILE * pipe = _popen(cmd, "wb");
#else
	FILE * pipe = popen(cmd, "w");
#endif
	if (pipe == 0) {
		std::cout << "error: " << strerror(errno) << endl;
		return 1;
	}

	int num_frames = duration_in_seconds * frames_per_second;
	for (int i = 0; i < num_frames; ++i) {
		double time_in_seconds = i / frames_per_second;
		draw_objects(time_in_seconds);
		frame.write(pipe);
	}

fflush(pipe);
#ifdef _WIN32
	_pclose(pipe);

#else
	pclose(pipe);

#endif

	cout << "num_frames: " << num_frames << endl;
	cout << "Done." << endl;

	return 0;
}//*/