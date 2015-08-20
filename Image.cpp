#ifndef _IMAGE_H
#define _IMAGE_H

#include "Image.h"
#include <cmath>

#endif

using namespace std;
typedef unsigned char unchar;

// Constructor
Image::Image(const char* filename) {
 imageData = new unchar*[HEIGHT];
	filteredData = new unchar*[HEIGHT];

	for (int i = 0; i < HEIGHT; i++) {
	 imageData[i] = new unchar[WIDTH];
		filteredData[i] = new unchar[WIDTH];
	}

	pInFile = new ifstream;
	pInFile->open(filename, ios::in | ios::binary);
	pInFile->seekg(0, ios::beg);
	pInFile->read(reinterpret_cast<char*>(c_vHeaderData[i]), 1078);

	for (i = 0; i < HEIGHT; i++) {
		pInFile->read(reinterpret_cast<char*> imageData[i]), WIDTH);
	}

	pInFile->close();
}
