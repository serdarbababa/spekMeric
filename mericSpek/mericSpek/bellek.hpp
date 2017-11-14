//
//  bellek.hpp
//  mericSpek
//
//  Created by ser on 28/10/2017.
//  Copyright © 2017 home sweet home. All rights reserved.
//

#ifndef Bellek_hpp
#define Bellek_hpp

#include <stdio.h>
#include "Agac.h"
#include "Utility.h"

class Bellek{
private:
    //hold in memory
    Agac *a;
    //int depth;
public:
    Bellek();
    ~Bellek();
    //egit options
    // 1 exact match
    //2 approximate match
    // 3 use wavelet, exact match
    // 4 use wavelet, apropriate match
    int agac_egit(data_tipi *veri, int depth, int option);
    //// 1 exact match
    //2 approximate match
    // 3 use wavelet, exact match
    // 4 use wavelet, apropriate match
    int agac_wavIleEgit(char * filename, int depth, int kaydirma, int option);
    
    void agac_goster();
    void agac_ozetle();
    void agac_kisa_ozetle();
    void yaprak_topla();
    
    int agac_kaydet(char * filename);
    int agac_gerigetir(char * filename);
    int getBranchId(data_tipi *veri, int depth, int option);
    //int getWavIDs(char * filename, int *ids, int *count , int windowSize, int offset, int option);
    
};
#endif /* bellek_hpp */
