#include <stdio.h>
#include "Struktura.h"
#include <stdlib.h>
#include <string.h>

int ReadFile(FILE *F,Student S[],int brStudenata)  // vraca broj ucitanih studenata
{
    char all[100],imeTmp[30],prezimeTmp[30],brindTmp[30];
    int oc1Tmp,oc2Tmp,oc3Tmp;


    for(int i=0;i<100;i++)
        all[i]='\0';




    while( fscanf(F,"%s",all) != EOF )
    {
        for(int i=0;i<100;i++)
        {
            if(all[i]==';' || all[i]==',')
                all[i]=' ';
        }
        for(int i=0;i<30;i++)
        {
            imeTmp[i]='\0';
            prezimeTmp[i]='\0';
            brindTmp[i]='\0';
        }

        sscanf(all,"%s %s %s %d %d %d",imeTmp,prezimeTmp,brindTmp,&oc1Tmp,&oc2Tmp,&oc3Tmp);

        int LenIme= strlen(imeTmp);
        int LenPrezime= strlen(prezimeTmp);
        int LenBrInd= strlen(brindTmp);


        (S[brStudenata]).ime = (char *) malloc(LenIme*sizeof(char));
        (S[brStudenata]).prezime = (char *) malloc(LenPrezime*sizeof(char));
        (S[brStudenata]).brIndexa = (char *) malloc(LenBrInd*sizeof(char));

        strcpy( (S[brStudenata]).ime,imeTmp);
        strcpy( (S[brStudenata]).prezime,prezimeTmp);
        strcpy( (S[brStudenata]).brIndexa,brindTmp);

         (S[brStudenata]).ocena1=oc1Tmp;
         (S[brStudenata]).ocena2=oc2Tmp;
         (S[brStudenata]).ocena3=oc3Tmp;
        //S = (Student *) malloc(sizeof(Student)*3);
        //S=S+sizeof(Student);
       // printf("%s %s %s %d %d %d \n",S->ime,S->prezime,S->brIndexa,S->ocena1,S->ocena2,S->ocena3);

       for(int i=0;i<100;i++)
        all[i]='\0';

        brStudenata++;
    }

    return brStudenata;


}

void WriteToFile(FILE *F,Student S[],int brStudenata)
{
    for(int i=0;i<brStudenata;i++)
    {
        fprintf(F,"%s;%s;%s;%d,%d,%d\n",S[i].ime,S[i].prezime,S[i].brIndexa,S[i].ocena1,S[i].ocena2,S[i].ocena3);
    }
}


