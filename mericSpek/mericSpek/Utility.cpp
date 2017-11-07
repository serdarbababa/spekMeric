#include "Utility.h"

Utility::Utility(void)
{
}

Utility::~Utility(void)
{
}

/*
void discreteHaarWaveletTransform(data_tipi * x, int size){
    
	data_tipi *output = new data_tipi[size];

    int length = size/2;

	while(true){
        for (int i = 0 ; i <length;i++){
			data_tipi summ = x[i * 2] + x[i * 2 + 1];
            data_tipi difference = x[i * 2] - x[i * 2 + 1];
            output[i] = summ;
            output[length + i] = difference;
		}
        if (length == 1)
            return output;

        
        x = output[:length << 1]

        length /=2;
}*/


data_tipi * Utility::discreteHaarWaveletTransform(data_tipi * inputI, int size){    
	
	data_tipi *input = new data_tipi[size];
	data_tipi *output = new data_tipi[size];
	
	for(int i = 0 ; i < size; i++)
		input[i] = inputI[i];

	for (int length = size /2; length>0; length /= 2) {
        // length = input.length / 2^n, WITH n INCREASING to log_2(input.length)
        for (int i = 0; i < length; ++i) {
            int sum = inputI[i * 2] + inputI[i * 2 + 1];
            int difference = inputI[i * 2] - inputI[i * 2 + 1];
            output[i] = sum/2;
            output[length + i] = difference/2;
        }
        if (length == 1) {
            //cout <<endl;
            //for(int i = 0 ; i < size; i++)
            //    cout << output[i]<<"\t";
            return output;
        }

        //Swap arrays to do next iteration
        //System.arraycopy(output, 0, input, 0, length << 1);
		for(int i = 0;i<length ;i++)
			inputI[i]=output[i];
    }
    
	return output;
}
/*
void Utility::readWav(char * filename){
	CWave *c = new CWave();	
	c->Load(filename);
	byte * dataa = c->GetData();
	//cout << c->GetSize()<<endl;
	int bits = c->GetBitsPerSample()/8;
	int chanels = c->GetChannels();
	int size = c->GetSize()/(bits*chanels);
	data_size= size;
	
	data = new data_tipi[size];
	
	for( int i = 0 ; i < size; i++){			
		data[i]=0;
		for(int j = 0;j<1;j++){//c->GetChannels();j++)
			//if(bits==2){
			//	signed short temp =0;
			//	//data[i]=0;
			//	temp=(temp<<8)+dataa[i*(bits*chanels)+1];
			//	temp=(temp<<8)+dataa[i*(bits*chanels)];
			//	//data[i]= (short*)(&dataa[i*(bits*chanels)]);
			//	data[i]=temp;
			//}
			//else if(bits== 4)
			//	data[i]=(int)(&dataa[i*(bits*chanels)]);
			signed short temp=0;

			for(int k = bits-1 ; k >=0; k--)
				temp=(temp<<8)+dataa[i*(bits*chanels)+k];
				//data[i]+= dataa[i*(bits*chanels)+k] * pow(2,8*k);
			data[i]=temp;
		}
			//for(int k = 0 ; k < bits; k++)
			//	data[i]+= dataa[i*(bits*chanels)+k] * pow(2,8*k);
		//cout << i << "\t" << data[i]<<endl;
	}
}
*/
void Utility::generate_carrier_signal(int samples_in_second, int frequency, data_tipi max){
	//carrier_signal = new data_tipi[samples_in_second];
	//for(int i = 0 ; i < 


}


int Utility::readWav(char* filePath ,data_tipi **output1, int *fs, int *datasize){
    
    wav_hdr wavHeader;
    int headerSize = sizeof(wav_hdr), filelength = 0;
    
    FILE* wavFile = fopen(filePath, "r");
    if (wavFile == nullptr)
    {
        fprintf(stderr, "Unable to open wave file: %s\n", filePath);
        return 1;
    }
    filelength = getFileSize(wavFile);
    
    
    //Read the header
    size_t bytesRead = fread(&wavHeader, 1, headerSize, wavFile);
    //cout << "Header Read " << bytesRead << " bytes." << endl;
    *datasize=(filelength-sizeof(wavHeader))/2;
    short * output = new short[filelength-headerSize];
    *fs= wavHeader.SamplesPerSec;
    if (bytesRead > 0)
    {
        //Read the data
        uint16_t bytesPerSample = wavHeader.bitsPerSample / 8;      //Number     of bytes per sample
        uint64_t numSamples = wavHeader.ChunkSize / bytesPerSample; //How many samples are in the wav file?
        static const uint16_t BUFFER_SIZE = 4096;
        char * buffer = new char[BUFFER_SIZE];
        bool jumping = false;
        int counter = 0;
        while ((bytesRead = fread(buffer, sizeof buffer[0], BUFFER_SIZE / (sizeof buffer[0]), wavFile)) > 0)
        {
            /** DO SOMETHING WITH THE WAVE DATA HERE **/
            //cout << "Read " << bytesRead << " bytes." << endl;
            int upperBound =  BUFFER_SIZE/(wavHeader.bitsPerSample/8);
            for(int i = 0 ; i <upperBound; i+=2){
                
                //short val =(short)(buffer[i*2] | buffer[i*2+1] << 8);
                //short a=buffer[i*2];
                //short b = buffer[i*2+1]<<8;
                //output[counter++]=a+b;
                /*short a = (short)(buffer[i*2] | buffer[i*2+1] << 8);
                if(counter >=200060 && counter < 200070){
                    for(int j =-4; j< 4;j++){
                        printf("(%d %d %d %d)\t",i,i*2+j,j,buffer[i*2+j]);
                    }
                    printf("\n%d %d %d %d %d\n",counter, buffer[i*2], buffer[i*2+1],(short)(buffer[i*2] | buffer[i*2+1] << 8),a);//cout <<counter<< "\t"<<buffer[i*2]<<"\t"<<buffer[i*2+1] << "\t" <<a << endl;
                }
                
                */
                output[counter++]=short(( char)(buffer[i*2+1]) << 8 | (unsigned char)(buffer[i*2]));;
                //counter++;
            }
            if(jumping)
                break;
        }
        printf("\n\n");
        delete [] buffer;
        buffer = nullptr;
        
        
        cout << "File is                    :" << filelength << " bytes." << endl;
        cout << "RIFF header                :" << wavHeader.RIFF[0] << wavHeader.RIFF[1] << wavHeader.RIFF[2] << wavHeader.RIFF[3] << endl;
        cout << "WAVE header                :" << wavHeader.WAVE[0] << wavHeader.WAVE[1] << wavHeader.WAVE[2] << wavHeader.WAVE[3] << endl;
        cout << "FMT                        :" << wavHeader.fmt[0] << wavHeader.fmt[1] << wavHeader.fmt[2] << wavHeader.fmt[3] << endl;
        cout << "Data size                  :" << wavHeader.ChunkSize << endl;
        
        // Display the sampling Rate from the header
        cout << "Sampling Rate              :" << wavHeader.SamplesPerSec << endl;
        cout << "Number of bits used        :" << wavHeader.bitsPerSample << endl;
        cout << "Number of channels         :" << wavHeader.NumOfChan << endl;
        cout << "Number of bytes per second :" << wavHeader.bytesPerSec << endl;
        cout << "Data length                :" << wavHeader.Subchunk2Size << endl;
        cout << "Audio Format               :" << wavHeader.AudioFormat << endl;
        // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM
        
        cout << "Block align                :" << wavHeader.blockAlign << endl;
        cout << "Data string                :" << wavHeader.Subchunk2ID[0] << wavHeader.Subchunk2ID[1] << wavHeader.Subchunk2ID[2] << wavHeader.Subchunk2ID[3] << endl;
        cout << "header size = "<<sizeof(wavHeader)<<endl;
        
    }
    fclose(wavFile);
    *output1=output;
    return 0;
}


void Utility::readWavFile(char* filePath ){
    
    wav_hdr wavHeader;
    int headerSize = sizeof(wav_hdr), filelength = 0;
    
    FILE* wavFile = fopen(filePath, "r");
    if (wavFile == nullptr)
    {
        fprintf(stderr, "Unable to open wave file: %s\n", filePath);
        return ;
    }
    filelength = getFileSize(wavFile);
    
    
    //Read the header
    size_t bytesRead = fread(&wavHeader, 1, headerSize, wavFile);
    cout << "Header Read " << bytesRead << " bytes." << endl;
    if (bytesRead > 0)
    {
        //Read the data
        uint16_t bytesPerSample = wavHeader.bitsPerSample / 8;      //Number     of bytes per sample
        uint64_t numSamples = wavHeader.ChunkSize / bytesPerSample; //How many samples are in the wav file?
        static const uint16_t BUFFER_SIZE = 4096;
        int8_t* buffer = new int8_t[BUFFER_SIZE];
        
        delete [] buffer;
        buffer = nullptr;
        filelength = getFileSize(wavFile);
        
        cout << "File is                    :" << filelength << " bytes." << endl;
        cout << "RIFF header                :" << wavHeader.RIFF[0] << wavHeader.RIFF[1] << wavHeader.RIFF[2] << wavHeader.RIFF[3] << endl;
        cout << "WAVE header                :" << wavHeader.WAVE[0] << wavHeader.WAVE[1] << wavHeader.WAVE[2] << wavHeader.WAVE[3] << endl;
        cout << "FMT                        :" << wavHeader.fmt[0] << wavHeader.fmt[1] << wavHeader.fmt[2] << wavHeader.fmt[3] << endl;
        cout << "Data size                  :" << wavHeader.ChunkSize << endl;
        
        // Display the sampling Rate from the header
        cout << "Sampling Rate              :" << wavHeader.SamplesPerSec << endl;
        cout << "Number of bits used        :" << wavHeader.bitsPerSample << endl;
        cout << "Number of channels         :" << wavHeader.NumOfChan << endl;
        cout << "Number of bytes per second :" << wavHeader.bytesPerSec << endl;
        cout << "Data length                :" << wavHeader.Subchunk2Size << endl;
        cout << "Audio Format               :" << wavHeader.AudioFormat << endl;
        // Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM
        
        cout << "Block align                :" << wavHeader.blockAlign << endl;
        cout << "Data string                :" << wavHeader.Subchunk2ID[0] << wavHeader.Subchunk2ID[1] << wavHeader.Subchunk2ID[2] << wavHeader.Subchunk2ID[3] << endl;
    }
    fclose(wavFile);
    
}


// find the file size
int Utility::getFileSize(FILE* inFile){
    int fileSize = 0;
    fseek(inFile, 0, SEEK_END);
    
    fileSize = (int)ftell(inFile);
    
    fseek(inFile, 0, SEEK_SET);
    return fileSize;
}


int Utility::writeWav(char* filePath ,data_tipi * output, int fs, int  datasize){
    //source = http://www.cplusplus.com/forum/beginner/166954/
    ofstream f(filePath, ios::binary );
    
    // Write the file headers
    f << "RIFF    WAVEfmt ";     // (chunk size to be filled in later)
    write_word( f,     16, 4 );  // no extension data
    write_word( f,      1, 2 );  // PCM - integer samples
    write_word( f,      1, 2 );  // two channels (stereo file)
    write_word( f,  fs, 4 );  // samples per second (Hz)
    write_word( f, fs*2, 4 );  // (Sample Rate * BitsPerSample * Channels) / 8
    write_word( f,      2, 2 );  // data block size (size of two integer samples, one for each channel, in bytes)
    write_word( f,     16, 2 );  // number of bits per sample (use a multiple of 8)
    
    // Write the data chunk header
    size_t data_chunk_pos = f.tellp();
    f << "data    ";  // (chunk size to be filled in later)
    
    // Write the audio samples
    // (We'll generate a single C4 note with a sine wave, fading from left to right)
    //constexpr double two_pi = 6.283185307179586476925286766559;
    //constexpr double max_amplitude = 32760;  // "volume"
    
    //double hz        = fs;    // samples per second
    //double frequency = 261.626;  // middle C
    //double seconds   = (float)datasize/(float)fs;      // time
    cout << "datasize= "<<datasize<<"\t"<< "seconds= "<< (float)datasize/fs << endl;
    int N = datasize/2;// hz * seconds;  // total number of samples
    for (int n = 0; n < N; n++)
    {
        //double amplitude = (double)n / N * max_amplitude;
        //double value     = sin( (two_pi * n * frequency) / hz );
        write_word( f, (int)(        output[n]           ), 2 );
        //write_word( f, 0, 2 );
    }
    
    // (We'll need the final file size to fix the chunk sizes above)
    size_t file_length = f.tellp();
    
    // Fix the data chunk header to contain the data size
    f.seekp( data_chunk_pos + 4 );
    write_word( f, file_length - data_chunk_pos + 8 );
    
    // Fix the file header to contain the proper RIFF chunk size, which is (file size - 8) bytes
    f.seekp( 0 + 4 );
    write_word( f, file_length - 8, 4 );
    return 0;
}




void Utility::testWav(char * filename, data_tipi * data , int num_samples, int fs){
    //const int NUM_SAMPLES = (WAVFILE_SAMPLES_PER_SECOND*2);
    
    int NUM_SAMPLES = num_samples;
    //short waveform[NUM_SAMPLES];
    //double frequency = 440.0;
    //int volume = 32000;
    int length = NUM_SAMPLES;
    
    //int i;
    //for(i=0;i<length;i++) {
    //    double t = (double) i / WAVFILE_SAMPLES_PER_SECOND;
    //    waveform[i] = volume*sin(frequency*t*2*M_PI);
    //}
    
    FILE * f = custom_wavfile_open(filename,fs);
    if(!f) {
        printf("couldn't open sound.wav for writing: %s",strerror(errno));
        return ;
    }
    
    wavfile_write(f,data,length);
    wavfile_close(f);
    
    

}
