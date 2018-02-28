#include "fechaFAT12.h"
#include <stdio.h>

int main()
{
    fechafat12 f;
    f.dia=1;
    f.mes=1;
    f.anio=0;
    show_b16(f);
    return 0;
};

void show_b16(FechaFAT12 fech){
    int i, intTmp;
    intTmp=*((int*)(&fech))
    for(i=8*sizeof(FechaFAT12)-1;i>=0;i--)
    {
        printf("%d",((intTmp=>>i)&0x00001);
        }
    }
