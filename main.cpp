#include "CSVLogger.h"

int main() {

	CSVLogger logfile("logfile");
	logfile << "hello";
	logfile << "hi" << std::endl;

	int a = 1;
	int16_t b = 2;
	int32_t c = 3;
	uint16_t d = 4;
	uint32_t e = 5;
	logfile << a << b << c << d << e << std::endl;

	unsigned char f = 50;
	char g = 'B';
	const char* h = "89";
	logfile << f << g << h;

	double i = 10.5;
	logfile << i;

	int8_t j = 22;
	uint8_t k = 33;
	logfile << j << k << std::endl;

	int arr[] = {11,12,13,14};
	logfile << arr << std::endl;

	return 0;
}
