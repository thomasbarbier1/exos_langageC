// cd Users/BarbieT/Documents
// gcc -std=c11 -Wall arrstruct.c -o arrstruct.exe
// @ThomasBarbier

#include <stdio.h>

typedef struct TAB_T {
    int Tab_Element[9];
    int NbElement;
    int Param;
} StructTAB;

void AfficherLargeur (StructTAB ST);
void InverserTab     (StructTAB *ST);
void AfficherHauteur (StructTAB ST);

int main(){

    printf("\n");
    StructTAB ST1;

    /*
    for(int i=0; i < 10; i++){
        ST1.Tab_Element[i] = i;
    }
    */

    ST1.Tab_Element[0] =  1;
    ST1.Tab_Element[1] =  2;
    ST1.Tab_Element[2] =  4;
    ST1.Tab_Element[3] =  5;
    ST1.Tab_Element[4] =  7;
    ST1.Tab_Element[5] =  8;
    ST1.Tab_Element[6] = 10;
    ST1.Tab_Element[7] = 11;
    ST1.Tab_Element[8] = 13;

    ST1.NbElement   = 9;
    ST1.Param       = 4;

    AfficherLargeur(ST1);
    InverserTab(&ST1);
    AfficherLargeur(ST1);
    AfficherHauteur(ST1);

    return 0;
}

void AfficherLargeur(StructTAB ST){

    printf("Affichage en largeur:\n");

    int nbElemLigne = 0;

    for(int i=0; i<ST.NbElement; i++){

        printf("%d\t", ST.Tab_Element[i]);

        nbElemLigne++;
        if(nbElemLigne == ST.Param){
           printf("\n");
           nbElemLigne = 0;
        }
    }

    printf("\n\n");
}

void InverserTab(StructTAB *ST){

    printf("Inversion de ST1!\n");
    StructTAB STtemp;

    STtemp.NbElement = ST->NbElement;
    STtemp.Param     = ST->Param;

    int MAX = ST->NbElement;

    // copie du tableau dans temp
    for(int i=0; i<MAX; i++){
        STtemp.Tab_Element[i] = ST->Tab_Element[i];
    }

    // inversion
    for(int i=0; i<MAX; i++){
        ST -> Tab_Element[MAX -1 - i] = STtemp.Tab_Element[i];
    }
}

void AfficherHauteur(StructTAB ST){

    printf("Affichage en hauteur:\n");

    int MAX = ST.NbElement;

    //##################################################
    /*
    for(int i=(MAX-1); i>ST.Param; i--){

        printf("\n");

        for(int j=i; j>=0; j-=ST.Param){
            printf("\t%d\t", ST.Tab_Element[j]);
        }
    }
    */
    //##################################################

    for(int i=0; i<ST.Param; i++){

        for(int j=i; j<MAX; j+=ST.Param){
            printf("\t%d\t", ST.Tab_Element[j]);
        }

        printf("\n");
    }

    printf("\n");
}
