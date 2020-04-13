#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define ArchivoA "Grupo_A"
#define ArchivoB "Grupo_B"
#define ArchivoC "Grupo_C"
#define ArchivoD "Grupo_D"
#define ArchivoE "Grupo_E"
#define ArchivoF "Grupo_F"
#define ArchivoG "Grupo_G"
#define ArchivoH "Grupo_H"

using namespace std;

struct Equipo
{
    int Bolillero;
    char Nombre[20];
    char Confederacion[40];
};

struct Grupo
{
    Equipo EquiposG[4];
    char Letra;
};

void Cambiar(Equipo V[8],int Pos1, int Pos2)
{
    strcpy(V[Pos1].Confederacion, V[Pos2].Confederacion);
    strcpy(V[Pos1].Nombre, V[Pos2].Nombre);
}

void SorteoGrupos(void)
{
    FILE *a,*b,*c,*d,*e,*f,*g,*h,*z;
    Equipo Equipos[32];
    Equipo Bolillero1[8];
    Equipo Bolillero2[8];
    Equipo Bolillero3[8];
    Equipo Bolillero4[8];
    Equipo Aux[]={1,"Alemania","UEFA: Eurocopa",1,"Brasil","Conmebol: Copa America"};
    Grupo Grupos[8];
    char Letras[8]= {'A','B','C','D','E','F','G','H'};
    int i,j,x,k,y,q;
    bool w;
    system("cls");
    srand(time(NULL));
    if (z=fopen("../Ejercicio 1/TP_Equipos32","rb"))
    {
        fread(Equipos, sizeof(Equipo), 32, z);
        fclose(z);
    }
    for (i=0; i<8; i++)
    {
        Grupos[i].Letra = Letras[i];
    }
    while (y>1)
    {
        for (i=0; i<8; i++)
        {
            Bolillero1[i].Bolillero = Equipos[i].Bolillero;
            strcpy(Bolillero1[i].Confederacion, Equipos[i].Confederacion);
            strcpy(Bolillero1[i].Nombre, Equipos[i].Nombre);
        }
        for (k=8; k<16; k++)
        {
            Bolillero2[k-8].Bolillero = Equipos[k].Bolillero;
            strcpy(Bolillero2[k-8].Confederacion, Equipos[k].Confederacion);
            strcpy(Bolillero2[k-8].Nombre, Equipos[k].Nombre);
        }
        for (k=16; k<24; k++)
        {
            Bolillero3[k-16].Bolillero = Equipos[k].Bolillero;
            strcpy(Bolillero3[k-16].Confederacion, Equipos[k].Confederacion);
            strcpy(Bolillero3[k-16].Nombre, Equipos[k].Nombre);
        }
        for (k=24; k<32; k++)
        {
            Bolillero4[k-24].Bolillero = Equipos[k].Bolillero;
            strcpy(Bolillero4[k-24].Confederacion, Equipos[k].Confederacion);
            strcpy(Bolillero4[k-24].Nombre, Equipos[k].Nombre);
        }
        Grupos[0].EquiposG[0].Bolillero = Bolillero1[7].Bolillero;
        strcpy(Grupos[0].EquiposG[0].Confederacion, Bolillero1[7].Confederacion);
        strcpy(Grupos[0].EquiposG[0].Nombre, Bolillero1[7].Nombre);
        i=7;
        j=1;
        q=0;
        while (i>0)
            {
                x=rand()%i;
                Grupos[j].EquiposG[0] = Bolillero1[x];
                strcpy(Bolillero1[x].Confederacion, Bolillero1[i-1].Confederacion);
                strcpy(Bolillero1[x].Nombre, Bolillero1[i-1].Nombre);
                j++;
                i--;
            }
        w=true;
        while ((q>7)||(w))
        {
            w=false;
            q=0;
            i=8;
            j=0;
            while ((i>0)&&(q<8))
            {
                x=rand()%i;
                if ((strcmp(Bolillero2[x].Confederacion, Aux[1].Confederacion)!=0)||(strcmp(Grupos[j].EquiposG[0].Confederacion, Aux[1].Confederacion)!=0))
                {
                    Grupos[j].EquiposG[1] = Bolillero2[x];
                    Cambiar(Bolillero2,x,i-1);
                    j++;
                    i--;
                }
                else
                    q++;
            }
        }
        w=true;
        y=0;
        while (((q>7)||(w))&&(y<2))
        {
            w=false;
            q=0;
            i=8;
            j=0;
            y++;
            while ((i>0)&&(q<8))
            {
                x=rand()%i;
                if (((strcmp(Bolillero3[x].Confederacion, Grupos[j].EquiposG[0].Confederacion)!=0)&&(strcmp(Bolillero3[x].Confederacion, Grupos[j].EquiposG[1].Confederacion)!=0))||((strcmp(Grupos[j].EquiposG[0].Confederacion, Aux[0].Confederacion)!=0)||(strcmp(Grupos[j].EquiposG[1].Confederacion, Aux[0].Confederacion)!=0)))
                {
                    Grupos[j].EquiposG[2] = Bolillero3[x];
                    Cambiar(Bolillero3,x,i-1);
                    j++;
                    i--;
                }
                else
                    q++;
            }
        }
        w=true;
        y=0;
        while (((q>7)||(w))&&(y<2))
        {
            w=false;
            q=0;
            i=8;
            j=0;
            y++;
            while ((i>0)&&(q<8))
            {
                x=rand()%i;
                if (!(((strcmp(Bolillero4[x].Confederacion, Grupos[j].EquiposG[0].Confederacion)==0)||(strcmp(Bolillero4[x].Confederacion, Grupos[j].EquiposG[1].Confederacion)==0)||(strcmp(Bolillero4[x].Confederacion, Grupos[j].EquiposG[2].Confederacion)==0))||((strcmp(Bolillero4[x].Confederacion, Aux[0].Confederacion)==0)&&(((strcmp(Grupos[j].EquiposG[1].Confederacion, Aux[0].Confederacion)==0)&&((strcmp(Grupos[j].EquiposG[2].Confederacion, Aux[0].Confederacion)==0)||(strcmp(Grupos[j].EquiposG[2].Confederacion, Aux[0].Confederacion)==0)))||((strcmp(Grupos[j].EquiposG[0].Confederacion, Aux[0].Confederacion)==0)&&(strcmp(Grupos[j].EquiposG[2].Confederacion, Aux[0].Confederacion)==0))))))
                {
                    Grupos[j].EquiposG[3] = Bolillero4[x];
                    Cambiar(Bolillero4,x,i-1);
                    j++;
                    i--;
                }
                else
                    q++;
            }
        }
    }
    if (a=fopen(ArchivoA,"wb"))
    {
        fwrite(&Grupos[0], sizeof(Grupo), 1, a);
        fclose(a);
    }
    if (b=fopen(ArchivoB,"wb"))
    {
        fwrite(&Grupos[1], sizeof(Grupo), 1, b);
        fclose(b);
    }
    if (c=fopen(ArchivoC,"wb"))
    {
        fwrite(&Grupos[2], sizeof(Grupo), 1, c);
        fclose(c);
    }
    if (d=fopen(ArchivoD,"wb"))
    {
        fwrite(&Grupos[3], sizeof(Grupo), 1, d);
        fclose(d);
    }
    if (e=fopen(ArchivoE,"wb"))
    {
        fwrite(&Grupos[4], sizeof(Grupo), 1, e);
        fclose(e);
    }
    if (f=fopen(ArchivoF,"wb"))
    {
        fwrite(&Grupos[5], sizeof(Grupo), 1, f);
        fclose(f);
    }
    if (g=fopen(ArchivoG,"wb"))
    {
        fwrite(&Grupos[6], sizeof(Grupo), 1, g);
        fclose(g);
    }
    if (h=fopen(ArchivoH,"wb"))
    {
        fwrite(&Grupos[7], sizeof(Grupo), 1, h);
        fclose(h);
    }
    for (k=0; k<8; k++)
    {
        cout << "------------------------" << endl;
        cout << "******* Grupo " << Grupos[k].Letra << " *******" << endl;
        for (y=0; y<4; y++)
        {
            cout << "------------------------" << endl;
            cout << "Grupo: " << Grupos[k].Letra << endl;
            cout << "Bolillero: " << Grupos[k].EquiposG[y].Bolillero << endl;
            cout << "Nombre: " << Grupos[k].EquiposG[y].Nombre << endl;
            cout << "Confederacion: " << Grupos[k].EquiposG[y].Confederacion << endl;
        }
    }
    cout << "------------------------" << endl;
    cout << "Oprima una tecla para volver al menu (limpiara la pantalla)" << endl;
    getch();
}

char Menu()
{
    system("cls");
    char Opcion;
    cout << "Seleccione una opcion:" << endl;
    cout << "1 - Crear y mostrar grupos" << endl;
    cout << "Esc - Salir" << endl;
    cout << "" << endl;
    do
        Opcion=getch();
    while (Opcion!= '1' && Opcion!= 27);
    switch (Opcion)
    {
    case '1':
        SorteoGrupos();
        break;
    }
    return Opcion;
}

int main()
{
    char Salida;
    do
        Salida=Menu();
    while (Salida!=27);
}
