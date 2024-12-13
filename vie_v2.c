/*
 * @BarbierThomas
 * https://github.com/thomasbarbier1/exos_langageC/blob/main/vie.c
 *
 * cd Users/BarbieT/Documents/
 * gcc -std=c11 -Wall vie.c -o vie.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define H 10
#define L 10

void affiche_cellule     (int etat);
void affiche_terrain     (int tab[H][L]);
void copie_terrain       (int src[H][L], int dest[H][L]);
int  etat_cellule        (int terrain[H][L], int ligne, int colonne);
int  voisinage_cellule   (int terrain[H][L], int ligne, int colonne);
void calcule_voisinage   (int terrain[H][L], int voisins[H][L]);
void affiche_voisinages  (int voisins[H][L]);
int  regle_du_jeu        (int etat, int voisinage);
void nouvelle_generation (int terrain[H][L], int voisins[H][L]);
void affiche_evolution   (int terrain[H][L], int nb_generations);

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

    int generation;
    printf("Entrer le generation a afficher: ");
    scanf("%d", &generation);
    affiche_evolution(depart, generation);

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

            if(h<0 || h==H || l<0 || l==L) continue;     // if out of bond -> skip
            if(h==ligne && l==colonne) continue;         // if not a neighbor cell -> skip
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

int regle_du_jeu(int etat, int voisinage){

    /*
     * REGLE DU JEU:
     *
     *    - Si une cellule a exactement 3 cellules voisines vivantes,
     *      elle est vivante a l'etape suivante.
     *
     *    - Si ne cellule a exactement 2 cellules voisines vivantes,
     *      elle reste dans son etat actuel.
     *
     *    - Si elle <2 ou >3 cellules voisines vivantes,
     *      elle meurt.
     *
     */

    switch (voisinage)
    {
        case 2:
            return etat;
        case 3:
            return 1;
        default:
            return 0;
    };
}

void nouvelle_generation(int terrain[H][L], int voisins[H][L]){

    int etat, voisinage;

    for(int h=0; h<H; h++){

        for(int l=0; l<L; l++){

            etat      = terrain[h][l];
            voisinage = voisins[h][l];

            terrain[h][l] = regle_du_jeu(etat, voisinage);
        }
    }
}

void affiche_evolution(int terrain[H][L], int nb_generations){

    int copie[H][L];
    copie_terrain(terrain, copie);
    int voisins[H][L];

    for(int i=0; i<=nb_generations; i++){

        system("cls");
        // printf("\n########################## Generation %d:", i);
        affiche_terrain(copie);
        calcule_voisinage(copie, voisins);
        // printf("          ----------");
        // affiche_voisinages(voisins);
        nouvelle_generation(copie, voisins);
        usleep(100000);
    }
}
