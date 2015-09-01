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

void findAverage(double imageData[][]) {
    	double total = 0;
    	for (int i = 0; i < HEIGHT; i++) {
    		for (int j = 0; j < WIDTH; j++) {
    			total += imageData[i][j];
    		}
    	}
    	return (total / (HEIGHT * WIDTH));
}

void Image::createGaussianFilter() {
    	// copy input image into new image
	for (int i = 0; i < HEIGHT; i++) {
        strncpy(reinterpret_cast<char*>(filteredData[i]), reinterpret_cast<char*> imageData[i]));
    }

		double sigma = 1.0;
		double mean = findAverage(imageData);
		double sum = 0.0;
		for (int x = 0; x < HEIGHT; x++)
			for (int y = 0; y < WIDTH; y++) {
				filteredData[x][y] = exp(-0.5 * (pow( imageData[x] - mean)/sigma, 2.0)
					+ pow( imageData[y] - mean)/sigma, 2.0) / (2 * M_PI * sigma * sigma);
				sum += filteredData[x][y];
			}
		for (int x = 0; x < HEIGHT; x++)
			for (int y = 0; y < WIDTH; y++)
				filteredData[x][y] /= sum;
}

void insertionSort(int window[]) {
    int temp, i , j;
    for(i = 0; i < 9; i++) {
        temp = window[i];
        for(j = i - 1; j >= 0 && temp < window[j]; j--) {
            window[j + 1] = window[j];
        }
        window[j + 1] = temp;
    }
}

void Image::createMedianFilter() {
	// copy input image into new image
	for (int i = 0; i < HEIGHT; i++) {
        strcpy(reinterpret_cast<char*>(filteredData[i]), reinterpret_cast<char*> imageData[i]));
    }

    filteredData[][] = imageData[][];
    int window[9];

    for (int y = 1; y < HEIGHT - 1; y++)
    	for (int x = 1; y < WIDTH - 1; x++)
    		window[0] = imageData[y - 1, x - 1];
    		window[1] = imageData[y][x - 1];
    		window[2] = imageData[y + 1][x - 1];
    		window[3] = imageData[y - 1][x];
    		window[4] = imageData[y][x];
    		window[5] = imageData[y + 1][x];
    		window[6] = imageData[y - 1][x + 1];
    		window[7] = imageData[y][x + 1];
    		window[8] = imageData[y + 1][x + 1];
    		insertionSort(window);
    		filteredData[y][x] = window[4];
}


