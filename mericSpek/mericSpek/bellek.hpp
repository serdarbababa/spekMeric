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
    int egit(data_tipi *veri, int depth);
    int wavIleEgit(char * filename, int depth, int kaydirma);
    void goster();
    void ozetle();
};
#endif /* bellek_hpp */
