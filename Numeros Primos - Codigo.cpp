#include <iostream>
#include <conio.h>
#include <stdlib.h>


using namespace std;

int main()
{
    int numero1;
    float numero2;
    float numero3;
    int numero3entera;
    float numero3decimal;
    int primo;
    char a;
    do
    {
    system("cls");
    cout << "Ingrese un numero Natural: ";
    cin >> numero1;
    numero3=0;
    numero3entera=0;
    numero3decimal=0;
    primo=0;
    numero2=numero1+1;
    do
    {
        numero2=numero2-1;
        numero3=(numero1/numero2);
        numero3entera=numero3/1;
        numero3decimal=numero3-numero3entera;

        if (numero3decimal==0)
            {primo=primo+1;}
        else {}
    }
    while (numero2>=1);
    if (primo>=3)
        {cout << numero1 << " no es primo" << endl;}
      else {cout << numero1 << " es primo" << endl;}
      cout << "" << endl;
      do
      {
      cout << "Desea terminar: Y/N" << endl;
      a=getch();
      }
      while (a!=110&&a!=121);}
    while (a!=121);
}

