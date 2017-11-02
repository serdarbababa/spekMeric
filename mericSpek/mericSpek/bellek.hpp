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
    //egit options
    // 1 exact match
    //2 approximate match
    // 3 use wavelet, exact match
    // 4 use wavelet, apropriate match
    int egit(data_tipi *veri, int depth, int option);
    //// 1 exact match
    //2 approximate match
    // 3 use wavelet, exact match
    // 4 use wavelet, apropriate match
    int wavIleEgit(char * filename, int depth, int kaydirma, int option);
    void goster();
    void ozetle();
    int kaydet(char * filename);
    int dosyadanGeriGetir(char * filename);
};
#endif /* bellek_hpp */
