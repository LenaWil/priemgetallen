//
//  main.c
//  Priemgetallen
//
//  Created by Tijmen Wildervanck on 09-02-13.
//  Copyright (c) 2013 CGU. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "/Users/tijmenwildervanck/Dropbox/xcode/elib/preprossesor.h"
//#include <time.h>

//nsigned char data(){
    
//}

int main ()
{
    ecalloc(int, testa, 60);
    unsigned long int totgetal=0;
    //while (totgetal==0);
    static unsigned char* data;
    printf("\nTot welk getal moet de mac gaan (kan maximaal %lu zijn (2^%lu), en gebruik geen '.' of '-'):", ULONG_MAX, (sizeof(totgetal)<<3));
    scanf("%ld", &totgetal);
    //totgetal=1000000000;
    data = (unsigned char*) calloc ((totgetal+8),1);
    //    for (long int schoolmaak; schoolmaak<= totgetal; schoolmaak++) {
//        data[schoolmaak]=0;
//    }
    if (data==NULL) {
        printf("fout: te hoog getal");
        return 1;
    }
    for (long unsigned int huidiggetal= 2; huidiggetal <= totgetal; huidiggetal++) {
        if (((data[((huidiggetal>>3))])&((UCHAR_MAX+1)>>1)>>(huidiggetal&((sizeof(unsigned char)<<3)-1)))==0) {
            printf("%lu\n", huidiggetal);
            for (long long unsigned int toptellen = huidiggetal*huidiggetal, testa;toptellen <= totgetal; toptellen+=huidiggetal) {
                //if ((toptellen%huidiggetal)==0) {
                testa=((UCHAR_MAX+1)>>1)>>(toptellen&((sizeof(unsigned char)<<3)-1));
                data[(toptellen>>3)]|=testa;
                //}
            }
        }
    }
    free(data);
}