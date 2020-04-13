#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Equipos
{
    int Bolillero;
    char Nombre[20];
    char Confederacion[40];
};

struct Grupo
{
    Equipos EquiposG[4];
    char Letra;
};

struct Aordenar
{
    char Nombre[20];
    char Confederacion[40];
    char Letra;
};

void MostrarArrayOrdenado(Aordenar Array1[32])
{
    int i=0;
    system("cls");
    for (i=0; i<32; i++)
        {
        cout << "Letra de grupo: " << Array1[i].Letra << endl;
        cout << "Nombre: " << Array1[i].Nombre << endl;
        cout << "Confederacion: " << Array1[i].Confederacion << endl;
        cout << "------------------------" << endl;
        }
    cout << "Oprima una tecla para volver al menu (limpiara la pantalla)" << endl;
    getch();
}

void OrdenarG(Aordenar Array1[])
{
    int i,j;
    Aordenar Aux;
    for (i=0; i<31; i++)
    {
        for (j=0; j<31-i; j++)
        {
            if (Array1[j+1].Letra<Array1[j].Letra)
            {
                Aux = Array1[j];
                Array1[j] = Array1[j+1];
                Array1[j+1] = Aux;
            }
        }
    }
}

void OrdenarE(Aordenar Array1[])
{
    int i,j;
    Aordenar Aux;
    for (i=0; i<31; i++)
    {
        for (j=0; j<31-i; j++)
        {
            if (strcmp(Array1[j+1].Nombre, Array1[j].Nombre)<0)
            {
                Aux = Array1[j];
                Array1[j] = Array1[j+1];
                Array1[j+1] = Aux;
            }
        }
    }
}

void OrdenarC(Aordenar Array1[])
{
    int i,j;
    Aordenar Aux;
    for (i=0; i<31; i++)
    {
        for (j=0; j<31-i; j++)
        {
            if (strcmp(Array1[j+1].Confederacion, Array1[j].Confederacion)<0)
            {
                Aux = Array1[j];
                Array1[j] = Array1[j+1];
                Array1[j+1] = Aux;
            }
        }
    }
}

void OrdenarGC(Aordenar Array1[])
{
    int i,j;
    Aordenar Aux;
    for (i=0; i<31; i++)
    {
        for (j=0; j<31-i; j++)
        {
            if (Array1[j+1].Letra<Array1[j].Letra || (Array1[j+1].Letra==Array1[j].Letra && strcmp(Array1[j+1].Confederacion, Array1[j].Confederacion)<0))
            {
                Aux = Array1[j];
                Array1[j] = Array1[j+1];
                Array1[j+1] = Aux;
            }
        }
    }
}

void OrdenarGCE(Aordenar Array1[])
{
    int i,j;
    Aordenar Aux;
    for (i=0; i<31; i++)
    {
        for (j=0; j<31-i; j++)
        {
            if (Array1[j+1].Letra<Array1[j].Letra || (Array1[j+1].Letra==Array1[j].Letra && strcmp(Array1[j+1].Confederacion, Array1[j].Confederacion)<0) || (Array1[j+1].Letra==Array1[j].Letra && strcmp(Array1[j+1].Confederacion, Array1[j].Confederacion)==0 && strcmp(Array1[j+1].Nombre, Array1[j].Nombre)<0))
            {
                Aux = Array1[j];
                Array1[j] = Array1[j+1];
                Array1[j+1] = Aux;
            }
        }
    }
}

void Ordenar(Aordenar Array1[])
{
    FILE *a,*b,*c,*d,*e,*f,*g,*h;
    Grupo Grupos[8];
    int i,j,k;
    k=0;
    if (a=fopen("../Ejercicio 2/Grupo_A","rb"))
        {
            fread(&Grupos[0], sizeof(Grupo), 1, a);
            fclose(a);
        }
    if (b=fopen("../Ejercicio 2/Grupo_B","rb"))
        {
            fread(&Grupos[1], sizeof(Grupo), 1, b);
            fclose(b);
        }
    if (c=fopen("../Ejercicio 2/Grupo_C","rb"))
        {
            fread(&Grupos[2], sizeof(Grupo), 1, c);
            fclose(c);
        }
    if (d=fopen("../Ejercicio 2/Grupo_D","rb"))
        {
            fread(&Grupos[3], sizeof(Grupo), 1, d);
            fclose(d);
        }
    if (e=fopen("../Ejercicio 2/Grupo_E","rb"))
        {
            fread(&Grupos[4], sizeof(Grupo), 1, e);
            fclose(e);
        }
    if (f=fopen("../Ejercicio 2/Grupo_F","rb"))
        {
            fread(&Grupos[5], sizeof(Grupo), 1, f);
            fclose(f);
        }
    if (g=fopen("../Ejercicio 2/Grupo_G","rb"))
        {
            fread(&Grupos[6], sizeof(Grupo), 1, g);
            fclose(g);
        }
    if (h=fopen("../Ejercicio 2/Grupo_H","rb"))
        {
            fread(&Grupos[7], sizeof(Grupo), 1, h);
            fclose(h);
        }
    for (i=0; i<8; i++)
    {
        for (j=0; j<4; j++)
        {
            strcpy(Array1[k].Nombre, Grupos[i].EquiposG[j].Nombre);
            strcpy(Array1[k].Confederacion, Grupos[i].EquiposG[j].Confederacion);
            Array1[k].Letra = Grupos[i].Letra;
            k++;
        }
    }
}

char MenuOrdenar(Aordenar Array1[])
{
    system("cls");
    char Opcion;
    cout << "Ordenar por:" << endl;
    cout << "1 - Letra de grupo" << endl;
    cout << "2 - Nombre de equipo" << endl;
    cout << "3 - Confederacion" << endl;
    cout << "4 - Letra de grupo y confederacion" << endl;
    cout << "5 - Numero de Grupo, confederacion y nombre de equipo" << endl;
    cout << "Esc - Salir" << endl;
    cout << "" << endl;
    do
    Opcion=getch();
    while (Opcion!= '1' && Opcion!= '2' && Opcion!= '3' && Opcion!= '4' && Opcion!= '5' && Opcion!= 27);
    switch (Opcion)
    {
    case '1':
        OrdenarG(Array1);
        MostrarArrayOrdenado(Array1);
        break;
    case '2':
        OrdenarE(Array1);
        MostrarArrayOrdenado(Array1);
        break;
    case '3':
        OrdenarC(Array1);
        MostrarArrayOrdenado(Array1);
        break;
    case '4':
        OrdenarGC(Array1);
        MostrarArrayOrdenado(Array1);
        break;
    case '5':
        OrdenarGCE(Array1);
        MostrarArrayOrdenado(Array1);
        break;
    }
    return Opcion;
}

int main()
{
    Aordenar Array1[32];
    Ordenar(Array1);
    char Salida;
    do
        Salida=MenuOrdenar(Array1);
    while (Salida!=27);
}
