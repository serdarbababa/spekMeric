#pragma once
#include <cstdlib>
#include <iostream>
//#include <fftw.h>
//#include <rfftw.h>
//#include <fftw.h>
//#include <rfftw.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
//#include <windows.h>
#include <vector>
#include <time.h> 




using namespace std;

typedef int data_tipi  ;

class Utility
{
public:
	Utility(void);
	~Utility(void);

	data_tipi * discreteHaarWaveletTransform(data_tipi * data, int size);
	void readWav(char *);
	void generate_carrier_signal(int samples_in_second, int frequency, data_tipi max);

public:
	data_tipi * data;
	int data_size;
	int carrier_data_size;
	data_tipi * carrier_signal;
};

