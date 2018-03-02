//FECHA EN FAT12
#ifndef FEHCA_FAT12
#define FECHA_FAT12


struct fechafat12{
    unsigned dia:5;
    unsigned mes:4;
    unsigned anio:7;
} __attribute__((packed));//FechaFat12;

typedef struct fechafat12 FechaFAT12;

struct Int16{
    unsigned myInt16:16;
    }__attribute__((packed));

typedef struct Int16 uInt16;

union UInt16{
};


#endif // FECHA_FAT12
