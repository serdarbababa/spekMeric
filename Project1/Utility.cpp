#include "Utility.h"


Utility::Utility(void)
{
}


Utility::~Utility(void)
{
}


//void discreteHaarWaveletTransform(data_tipi * x, int size){
//    
//	data_tipi *output = new data_tipi[size];
//
//    int length = size/2;
//
//	while(true){
//        for (int i = 0 ; i <length;i++){
//			data_tipi summ = x[i * 2] + x[i * 2 + 1];
//            data_tipi difference = x[i * 2] - x[i * 2 + 1];
//            output[i] = summ;
//            output[length + i] = difference;
//		}
//        if (length == 1)
//            return output;
//
//        
//        //x = output[:length << 1]
//
//        length /=2;
//}


//public static int[] discreteHaarWaveletTransform(int[] input) {

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
            return output;
        }

        //Swap arrays to do next iteration
        //System.arraycopy(output, 0, input, 0, length << 1);
		for(int i = 0;i<length ;i++)
			inputI[i]=output[i];
    }
	return output;
}

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

void Utility::generate_carrier_signal(int samples_in_second, int frequency, data_tipi max){
	carrier_signal = new data_tipi[samples_in_second];
	//for(int i = 0 ; i < 


}
//
//data_tipi * discreteHaarWaveletTransform(data_tipi * x, int size){
//
//	data_tipi *t=calloc(len+f-1, sizeof(double));
//memcpy(&t[f], x, len*sizeof(double));        
//for (int i=0; i<lev; i++) {
//memset(t, 0, (f-1)*sizeof(double));        
//memset(y, 0, len*sizeof(double));
//int len2=len/2;
//for (int j=0; j<len2; j++)           
//    for (int k=0; k<f; k++) {          
//        y[j]     +=t[2*j+k]*h[k];      
//        y[j+len2]+=t[2*j+k]*g[k];      
//    }
//len=len2;                            
//memcpy(&t[f], y, len*sizeof(double));    
//}
//}