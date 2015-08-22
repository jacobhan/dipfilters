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

// Destructor
Image::~Image() {
	delete pInFile;
	delete pOutFile;

	for (int i = 0; i < HEIGHT; i++) {
		delete[] imageData[i];
		delete[] filteredData[i];
	}

	delete[] imageData;
	delete[] filteredData;
}

void Image::writeG(const char* filename) {
	createGaussianFilter();
	pOutFile = new ofstream;
	pOutFile->open(filename, ios::out | ios::trunc | ios::binary);
	pOutFile->write(reinterpret_cast<char*>(c_vHeaderData), 1078);

	for (int i = 0; i < HEIGHT; i++) {
		pOutFile->write(reinterpret_cast<char*>(filteredData[i]), WIDTH);
	}

	pOutFile->close();
}

void Image::writeM(const char* filename) {
	createMedianFilter();
	pOutFile = new ofstream;
	pOutFile->open(filename, ios::out | ios::trunc | ios::binary);
	pOutFile->write(reinterpret_cast<char*>(c_vHeaderData), 1078);

	for (int i = 0; i < HEIGHT; i++) {
		pOutFile->write(reinterpret_cast<char*>(filteredData[i]), WIDTH);
	}

	pOutFile->close();
}




