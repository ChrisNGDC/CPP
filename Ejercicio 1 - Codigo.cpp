#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define Archivo1 "TP_Equipos32"

using namespace std;

struct Equipo
{
    int Bolillero;
    char Nombre[20];
    char Confederacion[40];
};

void Inicializar(void)
{
    FILE *z;
    Equipo Vequipos[]={1,"Alemania","UEFA: Eurocopa",1,"Brasil","Conmebol: Copa America",1,"Portugal","UEFA: Eurocopa",1,"Argentina","Conmebol: Copa America",1,"Belgica","UEFA: Eurocopa",1,"Polonia","UEFA: Eurocopa",1,"Francia","UEFA: Eurocopa",1,"Rusia","AFC: Copa Asiatica",2,"Espana","UEFA: Eurocopa",2,"Peru","Conmebol: Copa America",2,"Suiza","UEFA: Eurocopa",2,"Inglaterra","UEFA: Eurocopa",2,"Colombia","Conmebol: Copa America",2,"Mexico","Concacaf: Copa Concacaf",2,"Uruguay","Conmebol: Copa America",2,"Croacia","UEFA: Eurocopa",3,"Dinamarca","UEFA: Eurocopa",3,"Islandia","UEFA: Eurocopa",3,"Costa Rica","Concacaf: Copa Concacaf",3,"Suecia","UEFA: Eurocopa",3,"Tunez","CAF: Copa Africana de Naciones",3,"Egipto","CAF: Copa Africana de Naciones",3,"Senegal","CAF: Copa Africana de Naciones",3,"Iran","AFC: Copa Asiatica",4,"Serbia","UEFA: Eurocopa",4,"Nigeria","CAF: Copa Africana de Naciones",4,"Australia","AFC: Copa Asiatica",4,"Japon","AFC: Copa Asiatica",4,"Marruecos","CAF: Copa Africana de Naciones",4,"Panama","Concacaf: Copa Concacaf",4,"Corea del Sur","AFC: Copa Asiatica",4,"Arabia Saudita","AFC: Copa Asiatica"};
    if (z=fopen(Archivo1,"wb"));
    {
        fwrite(Vequipos, sizeof(Equipo), 32, z);
        fclose(z);
    }
}

int main()
{
    Inicializar();
    cout << "******** Equipos agregados ********" << endl;
    getch();
}
