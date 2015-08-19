#include <fstream>

using namespace std;
typedef unsigned char unchar;

class Image {
	public:
		Image(const char* filename); // Constructor
		~Image(); // Deconstructor
		void writeG(const char* filename); // for Gaussian Filter
		void createGaussianFilter();
		void writeM(const char* filename); // for Median Filter
		void createMedianFilter();
	private:
		ifstream* pInFile;
		ofstream* pOutFile;
		unchar c_vHeaderData[1078]; // .bmp header data with offset 1078
		unchar** imageData;
		unchar** filteredData;
};
