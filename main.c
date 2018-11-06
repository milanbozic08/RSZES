#include <stdio.h>
#include <stdlib.h>
#include "Struktura.h"
#include "FileFnc.h"
#include "StructFnc.h"

int main()
{
    FILE *file;
    Student SviStud[100];
    int BrojStudenata=0;
    int input;

    file=fopen("spisakstudenata.txt","r");
    if(file!=NULL)
        {
        BrojStudenata=ReadFile(file,SviStud,BrojStudenata);
         printf("   Fajl spisakstudenata.txt je ucitan !\n");
        }
    else
        printf("    Fajl spisakstudenata.txt NIJE pronadjen !\n");

    fclose(file);

    do
    {
        printf("\n1) Unos novog studenta\n");
        printf("2) Pretraga studenta po prezimenu\n");
        printf("3) Ispis svih studenata\n");
        printf("4) Korigovanje podataka o studentu\n");
        printf("5) Izlaz\n");
        scanf("%d",&input);

        switch(input)
        {
        case 1:
            BrojStudenata=UnosStudenta(SviStud,BrojStudenata);
            break;
        case 2:
            Pretraga(SviStud,BrojStudenata);
            break;
        case 3:
            IspisStudenata(SviStud,BrojStudenata);
            break;
        case 4:
             Korekcija(SviStud);
            break;
        case 5:
            file=fopen("spisakstudenata.txt","w");
            WriteToFile(file,SviStud,BrojStudenata);
            fclose(file);
            break;
        default: break;
        }
    }
    while(input!=5);

    return 0;
}
