#include "fechaFAT12.h"
#include <stdio.h>

void show_b16(FechaFAT12);

int main()
{
    FechaFAT12 f;
    f.dia=1;
    f.mes=1;
    f.anio=1980-1980;
    show_b16(f);

    printf("tamanio de FechaFAT12=%d\n",sizeof(FechaFAT12));
    show_b16(f);
    printf("\t\t1 de enero de 1980\n\n");
    FechaFAT12 F;
    F.dia=31;
    F.mes=12;
    F.anio=2099-1980;
    printf("\n");
    show_b16(F);
    printf("\t\t31 de diciembre de 2099\n\n");
    uInt16 f1=*((uInt16*)(&f));
return 0;
};

void show_b16(FechaFAT12 fech){
    int i, intTmp;
    intTmp=*((int*)(&fech));
    for(int i=8*sizeof(FechaFAT12)-1;i>=0;i--)
    {
        printf("%d",((intTmp>>i)&0x00001));
        }
    }
