#include <iostream>
#include <fstream>
#include <windows.h>
//#define spacename namespace
using namespace std;

string DiaNLateX[]={
       "Domingo",          //0
       "Lunes",            //1
       "Martes",           //2
       "Mi\\'{e}rcoles",   //3
       "Jueves",           //4
       "Viernes",          //5
       "S\\'abado"         //6
       };
string MesNLateX[]={
       "Enero",
       "Febrero",
       "Marzo",
       "Abril",
       "Mayo",
       "Junio",
       "Julio",
       "Agosto",
       "Septiembre",
       "Octrubre",
       "Noviembre",
       "Diciembre"};

struct myFecha{
       int d, m, a;
       };
string get_nombre_dia(int);

int algoritmo(myFecha*);

void inicio_carta(myFecha*);

int inicio_mes(int,int);

int main (){
    myFecha f;
    /*cout<<"Introduzca dia: ";
    cin>>f.d;
    cout<<"Mes: ";
    cin>>f.m;
    cout<<"A±o";
    cin>>f.a;*/
    f.d=23; f.m=2; f.a=2018;
    string file_name="carta.tex";
    ofstream ofsObj(file_name.c_str());
    int intI=algoritmo(&f);
    cout<<DiaNLateX[intI]<<" "<<f.d<<" de "<<MesNLateX[f.m-1]<<" de "<<f.a<<endl;
    if (ofsObj){
       ofsObj<<"\\documentclass{article}"<<endl<<"\\begin{document}"<<endl<<"\\begin{flushright}"<<endl<<DiaNLateX[intI]<<" "<<f.d<<" de "<<MesNLateX[f.m-1]<<" de "<<f.a<<endl<<"\\end{flushright}"<<endl<<"\\end{document}"<<endl;
       }
       else{cout<<"nohay objeto ofsObj"<<endl;}
    system("pause>asdfas");
}

int algoritmo(myFecha *F){
    int t, inM;
    inM=inicio_mes(F->m,F->a);
    t= ((F->a-1)*365+((F->a-1)/4-3*((F->a-1)/100+1)/4)%7+inM+F->d%7)%7;
    return t;
    }

int inicio_mes(int mes, int anio)
{
    if (anio%4!=0){
    switch(mes)
    {
               case 1:
                    return 0;
               case 2:
                    return 3;
               case 3:
                    return 3;
               case 4:
                    return 6;
               case 5:
                    return 1;
               case 6:
                    return 4;
               case 7:
                    return 6;
               case 8:
                    return 2;
               case 9:
                    return 5;
               case 10:
                    return 0;
               case 11:
                    return 3;
               case 12:
                    return 5;
               }
    }else
    {
         switch(mes)
         {
               case 1:
                    return 0;
               case 2:
                    return 3;
               case 3:
                    return 4;
               case 4:
                    return 0;
               case 5:
                    return 2;
               case 6:
                    return 5;
               case 7:
                    return 0;
               case 8:
                    return 3;
               case 9:
                    return 6;
               case 10:
                    return 1;
               case 11:
                    return 4;
               case 12:
                    return 6;
               }
         }
}
