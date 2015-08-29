#include <iostream>
#include "Image.cpp"
#include <fstream>

using namespace std;

// Gaussian Filter
int main() {
	Image img("test.bmp");
	img.writeG("output.bmp");
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
			cout << filteredData[i][j] << "/t";
		cout << end1;
}
