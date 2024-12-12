/*
 * @BarbierThomas
 *
 * cd Users/BarbieT/Documents/
 * gcc -std=c11 -Wall vie.c -o vie.exe
 *
 */

#include <stdio.h>

#define H 10
#define L 10

void affiche_cellule    (int etat);
void affiche_terrain    (int tab[H][L]);
void copie_terrain      (int src[H][L], int dest[H][L]);
int  etat_cellule       (int terrain[H][L], int ligne, int colonne);
int  voisinage_cellule  (int terrain[H][L], int ligne, int colonne);
void calcule_voisinage  (int terrain[H][L], int voisins[H][L]);
void affiche_voisinages (int voisins[H][L]);

int main(){

    int depart[H][L] = {

      // 0 1 2 3 4 5 6 7 8 9
        {0,0,0,0,0,0,0,0,0,0}, // 0    0001110000
        {0,0,0,0,1,0,0,0,0,0}, // 1    0001121000
        {0,0,0,0,0,1,0,0,0,0}, // 2    0013532000
        {0,0,0,1,1,1,0,0,0,0}, // 3
        {0,0,0,0,0,0,0,0,0,0}, // 4
        {0,0,0,0,0,0,0,0,0,0}, // 5
        {0,0,0,1,1,1,0,0,0,0}, // 6
        {0,0,0,0,0,1,0,0,0,0}, // 7
        {0,0,0,0,1,0,0,0,0,0}, // 8
        {0,0,0,0,0,0,0,0,0,0}  // 9
    };

    int destination[H][L];

    printf("Test de affiche_cellule(depart[1][4]): ");
    affiche_cellule(depart[1][4]);
    printf("\n");

    printf("Test de affiche_terrain(int etat):\n");
    affiche_terrain(depart);

    printf("Test de copie_terrain(int)");
    copie_terrain(depart, destination);
    affiche_terrain(destination);

    printf("Test de etat_cellule(depart, 7, 4): ");
    int etat = etat_cellule(depart, 7, 4);
    printf("%d\n", etat);

    printf("Test de int voisinage_cellule(depart, 2, 4): ");
    int nb_cell = voisinage_cellule(depart, 2, 4);
    printf("%d\n", nb_cell);

    printf("Test de void calcule_voisinage(depart, voisins):");
    int voisins[H][L];
    calcule_voisinage(depart, voisins);
    affiche_voisinages(voisins);


    return 0;
}

void affiche_cellule(int etat){

    if(etat==0) printf(".");
    else printf("o");
}

void affiche_terrain(int tab[H][L]){

    for(int h=0; h<H; h++){

        printf("\n");

        for(int l=0; l<L; l++){

            affiche_cellule(tab[h][l]);
        }
    }

    printf("\n");
}

void copie_terrain(int src[H][L], int dest[H][L]){

    for(int h=0; h<H; h++){

        for(int l=0; l<L; l++){

            dest[h][l] = src[h][l];
        }
    }
}

int etat_cellule(int terrain[H][L], int ligne, int colonne){

    if(terrain[ligne][colonne] == 0) return 0;
    else return 1;
}

int voisinage_cellule(int terrain[H][L], int ligne, int colonne){

    int nb_cellule = 0;

    for(int h = ligne-1; h<=ligne+1; h++){

        for(int l = colonne-1; l<=colonne+1; l++){

            if(h==l) continue;
            if(etat_cellule(terrain, h, l)) nb_cellule++;
        }
    }

    return nb_cellule;
}

void calcule_voisinage(int terrain[H][L], int voisins[H][L]){

    for(int h=0; h<H; h++){

        for(int l=0; l<L; l++){

            voisins[h][l] = voisinage_cellule(terrain, h, l);
        }
    }
}

void affiche_voisinages(int voisins[H][L]){

    for(int h=0; h<H; h++){

        printf("\n");

        for(int l=0; l<L; l++){

            printf("%d", voisins[h][l]);
        }
    }

    printf("\n");
}
