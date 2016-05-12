#define cimg_display 0
#include "CImg.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace cimg_library;
using namespace std;

extern "C" {
	 void function_two(unsigned char *arr, int width, int height, int stride);
}

int main(int argc, char **argv) {
	cout << "We have " << argc << " command line parameter(s)\n";
	cout << "Parameters are:\n";
	for (int i = 0; i < argc; i++) {
		cout << "Argument " << i << ": " << argv[i] << endl;
	}

	//YOU: Create an array here
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int stride = atoi(argv[3]);
	int size = width * height; 
	//CImg<unsigned char> image(width,height,1,3,0);
	CImg<unsigned char> feels_bad_image("./feelsbad.png");
	cout << "This is feelsbad.width():" << feels_bad_image.width() << endl;
	cout << "This is feelsbad.height():" << feels_bad_image.height() << endl;
	//CImg<unsigned char> feels_bad_new_image(feels_bad_image.width(),feels_bad_image.height(), 1, 3, 0);
	// This is a test in making a gradient image.
	//for (int i = 0; i < width; i++) {
	//	for (int j = 0; j < height; j++) {
	//		image[(j*width+i)] = 255;
	//		image[(size+j*width+i)] = 0;
	//		image[(size+size+j*width+i)] = 255;

	//	}
	//}
	//image.save_jpeg("old_image.jpg", 50);
	//Calling the assembly function like this
	clock_t start_time = clock();
	function_two(feels_bad_image,width, height,stride);
	clock_t end_time = clock();

	cout << "Running time for function_two: " << end_time - start_time << " ticks\n";
	feels_bad_image.save_jpeg("output.jpg", 50);
}
