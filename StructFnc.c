#include "Struktura.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void IspisStudenata(Student S[],int BrStu)
{
    for(int i=0;i<BrStu;i++)
    {
        printf("    %i) %s %s %s %d %d %d \n",i+1,S[i].ime,S[i].prezime,S[i].brIndexa,S[i].ocena1,S[i].ocena2,S[i].ocena3);
    }
}

int UnosStudenta(Student S[], int BrStu)
{
    char imeTmp[30],prezimeTmp[30],brindTmp[30];

    printf("\n      Ime: ");
    fflush(stdin);
    scanf("%s",imeTmp);

    printf("\n      Prezime: ");
    fflush(stdin);
    scanf("%s",prezimeTmp);

    printf("\n      Broj indeksa: ");
    fflush(stdin);
    scanf("%s",brindTmp);

    printf("\n      Ocena 1: ");
    fflush(stdin);
    scanf("%d",&(S[BrStu]).ocena1);

    printf("\n      Ocena 2: ");
    fflush(stdin);
    scanf("%d",&(S[BrStu]).ocena2);

    printf("\n      Ocena 3: ");
    fflush(stdin);
    scanf("%d",&(S[BrStu]).ocena3);



    int LenIme= strlen(imeTmp);
    int LenPrezime= strlen(prezimeTmp);
    int LenBrInd= strlen(brindTmp);

    (S[BrStu]).ime = (char *) malloc(LenIme*sizeof(char));
    (S[BrStu]).prezime = (char *) malloc(LenPrezime*sizeof(char));
    (S[BrStu]).brIndexa = (char *) malloc(LenBrInd*sizeof(char));

    strcpy( (S[BrStu]).ime,imeTmp);
    strcpy( (S[BrStu]).prezime,prezimeTmp);
    strcpy( (S[BrStu]).brIndexa,brindTmp);


    BrStu++;

    return BrStu;
}


void Pretraga(Student S[], int BrStu)
{
    char prezimeSearch[30];

    for(int i=0;i<30;i++)
    {
       prezimeSearch[i]='\0';
    }

    printf("\n      Prezime za pretragu: ");
    fflush(stdin);
    scanf("%s",prezimeSearch);
    printf("\n");

    int DuzinaPrez=strlen(prezimeSearch);

   for(int i=0;i<BrStu;i++)
    {
       if(strncmp(S[i].prezime,prezimeSearch,DuzinaPrez)==0)
       {
            printf("    %i) %s %s %s %d %d %d \n",i+1,S[i].ime,S[i].prezime,S[i].brIndexa,S[i].ocena1,S[i].ocena2,S[i].ocena3);

       }
    }
    printf("\n");
}

void Korekcija(Student S[])
{
    int Rednibr,Kor;

    printf("\n      Redni broj studenta za korekciju : ");
    fflush(stdin);
    scanf("%d",&Rednibr);
    Rednibr--;
    printf("\n    1) Korekcija imena\n");
    printf("    2) Korekcija prezimena\n");
    printf("    3) Korekcija broja indeksa\n");
    printf("    4) Korekcija ocene1\n");
    printf("    5) Korekcija ocene2\n");
    printf("    6) Korekcija ocene3\n");
    fflush(stdin);
    scanf("%d",&Kor);

    switch(Kor)
    {
    case 1:
        printf("\n      Novo ime : ");
        fflush(stdin);
        scanf("%s",S[Rednibr].ime);
        break;
    case 2:
        printf("\n      Novo prezime : ");
        fflush(stdin);
        scanf("%s",S[Rednibr].prezime);
        break;
    case 3:
        printf("\n      Novi broj indeksa : ");
        fflush(stdin);
        scanf("%s",S[Rednibr].brIndexa);
        break;
    case 4:
        printf("\n      Nova ocena1 : ");
        fflush(stdin);
        scanf("%d",&S[Rednibr].ocena1);
        break;
    case 5:
        printf("\n      Nova ocena2 : ");
        fflush(stdin);
        scanf("%d",&S[Rednibr].ocena2);
        break;
    case 6:
        printf("\n      Nova ocena3 : ");
        fflush(stdin);
        scanf("%d",&S[Rednibr].ocena3);
        break;
    default: break;
    }




}
