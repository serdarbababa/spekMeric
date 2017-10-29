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

//typedef int data_tipi  ;
typedef short data_tipi  ;

typedef struct  WAV_HEADER
{
    /* RIFF Chunk Descriptor */
    uint8_t         RIFF[4];        // RIFF Header Magic header
    uint32_t        ChunkSize;      // RIFF Chunk Size
    uint8_t         WAVE[4];        // WAVE Header
    /* "fmt" sub-chunk */
    uint8_t         fmt[4];         // FMT header
    uint32_t        Subchunk1Size;  // Size of the fmt chunk
    uint16_t        AudioFormat;    // Audio format 1=PCM,6=mulaw,7=alaw,     257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM
    uint16_t        NumOfChan;      // Number of channels 1=Mono 2=Sterio
    uint32_t        SamplesPerSec;  // Sampling Frequency in Hz
    uint32_t        bytesPerSec;    // bytes per second
    uint16_t        blockAlign;     // 2=16-bit mono, 4=16-bit stereo
    uint16_t        bitsPerSample;  // Number of bits per sample
    /* "data" sub-chunk */
    uint8_t         Subchunk2ID[4]; // "data"  string
    uint32_t        Subchunk2Size;  // Sampled data length
} wav_hdr;


class Utility
{
public:
	Utility(void);
	~Utility(void);

    //wavelet transform
	data_tipi * discreteHaarWaveletTransform(data_tipi * data, int size);
    
    //reads given wav file
	int readWav(char* filePath ,data_tipi ** output, int *fs, int * datasize);
	//generates carrier signal
    void generate_carrier_signal(int samples_in_second, int frequency, data_tipi max);
    //returns size of file
    int getFileSize(FILE* inFile);
    
public:
	//data_tipi * data;
	//int data_size;
	//int carrier_data_size;
	//data_tipi * carrier_signal;
};

