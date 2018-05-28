unit Unidad1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Edit4: TEdit;
    Label1: TLabel;
    Label10: TLabel;
    Label11: TLabel;
    Label12: TLabel;
    Label13: TLabel;
    Label14: TLabel;
    Label15: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    procedure Button1Click(Sender: TObject);
    procedure Edit1Change(Sender: TObject);

  private

  public

  end;

var
  Form1: TForm1;
  tablaSAT: array[1..7,1..4] of Real;
  IngTotal, IngEx, Deduc,ISRRet,IngGrav:Real;

implementation

{$R *.lfm}

{ TForm1 }
function num_de_intervalo(IngGravable:Real): Integer;
var
  ret:Integer;
  index:Integer;
begin
  tablaSAT[1,1]:=0.01;         tablaSAT[1,2]:=50000.0;       tablaSAT[1,3]:=12000.0;            tablaSAT[1,4]:=1.5;
  tablaSAT[2,1]:=50000.01;     tablaSAT[2,2]:=100000.0;      tablaSAT[2,3]:= 17000.0 ;          tablaSAT[2,4]:= 2.5;
  tablaSAT[3,1]:=100000.01;    tablaSAT[3,2]:=  200000.0;    tablaSAT[3,3]:=  21000.0;          tablaSAT[3,4]:= 4.5 ;
  tablaSAT[4,1]:= 200000.01;   tablaSAT[4,2]:=  400000.0;    tablaSAT[4,3]:= 75000.0 ;          tablaSAT[4,4]:=25.0;
  tablaSAT[5,1]:=  400000.01;  tablaSAT[5,2]:=  750000.0 ;   tablaSAT[5,3]:=  88000.0;          tablaSAT[5,4]:=  28.5;
  tablaSAT[6,1]:= 750000.01;   tablaSAT[6,2]:= 1000000.0;    tablaSAT[6,3]:= 200000.0  ;        tablaSAT[6,4]:=30.0;
  tablaSAT[7,1]:=1000000.01;   tablaSAT[7,2]:=1000000000000; tablaSAT[7,3]:=300000;             tablaSAT[7,4]:= 35.0;

  ret:=-1;
  for index:=0 to 7 do
      if (IngGravable>=tablaSAT[index,1]) and (IngGravable<=tablaSAT[index,2]) then
      begin
        ret:=index;
        Break;
      end;
     Exit;
end;


function fisr(index:Integer):Real;
var
    Excedente, tasa, cuota_fija,ISR:Real;
begin
   Excedente:= IngGrav-tablaSAT[index,1];
   //Label12.Caption:=floattostr(Excedente);
   tasa:=tablaSAT[index,4];
   //Label13.Caption:=floattostr(tasa);
   cuota_fija:=tablaSAT[index,3];
   //Label14.Caption:=floattostr(cuota_fija);
   ISR:=tasa*Excedente/100+cuota_fija-ISRRet;
   Exit;
end;

procedure TForm1.Button1Click(Sender: TObject);

var
  NumDInt:Integer;
  ISR:Real;

begin
  IngTotal:= strtofloat(Edit1.Text);
  IngEx:= strtofloat(Edit2.Text);
  Deduc:= strtofloat(Edit3.Text);
  ISRRet:= strtofloat(Edit4.Text);
  IngGrav:= IngTotal-IngEx-Deduc;
  Label6.Caption:= floattostr(IngGrav);
  NumDInt := num_de_intervalo(IngGrav) ;
  if (NumDInt<0) then
     begin
       Label8.Caption:='EL INGRESO GRAVABLE ES MUY GRANDE';
       Exit;
     end;
   ISR:= fisr(NumDInt);

   Label15.Caption:=floattostr(ISR);
end;

procedure TForm1.Edit1Change(Sender: TObject);
begin

end;

end.

