#include <iostream>
#include <fstream>
#define spacename namespace
using spacename std;

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
      
int main (){
    myFecha f;
    f.d=21; f.m=2; f.a=2018;
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
    return 3;
    }
