#include <stdio.h>

typedef struct{
    int a;
    int b;
    int c;
} ineq;

void afficher_ineq(ineq s);
void afficher_poly(ineq p[], int n);
int test_ineq(ineq s, int x, int y);
int test_poly(ineq p[], int n, int x, int y);
void dessiner_poly(ineq p[], int n, int xmin, int xmax, int ymin, int ymax);

int main(){
    
    ineq d;
    d.a = 2;
    d.b = 1;
    d.c = 2;
    afficher_ineq(d);

    ineq triangle[3] = {
        {-1,-5,16},
        { 4, 1,12},
        {-3, 4,10},
    };

    ineq penta[5] = {
        { 1, 0, 0},
        { 0, 1, 0},
        { 1,-1, 5},
        {-1, 1, 5},
        {-1,-1,15}
    };

    afficher_poly(triangle, 3);
    afficher_poly(penta, 5);

    int Nb = test_poly(triangle, 3, 2, 5);
    printf("Le point A[2,5] satisfait %d inequations dans triangle.\n", Nb);

    dessiner_poly(triangle, 3, -10, 10, -10, 10);
    dessiner_poly(penta, 5, -10, 10, -10, 10);

    return 0;
}

void afficher_ineq(ineq s){

    printf("%dx + %dy + %d >= 0\n", s.a, s.b, s.c);

}

void afficher_poly(ineq p[], int n){

    for(int i=0; i<n; i++){
        afficher_ineq(p[i]);
        printf("\n");
    }
}

int test_ineq(ineq s, int x, int y){
    int S = (s.a * x) + (s.b * y) + s.c;
    if(S<0) return 0;
    else return 1;
}


int test_poly(ineq p[], int n, int x, int y){

    // printf("Test du point A[%d,%d]:\n", x,y);

    int RetVal = 0;

    for(int i=0; i<n; i++){

        // printf("Test de l'inequation: ");
        // afficher_ineq(p[i]);

        if(test_ineq(p[i],x,y)){
            // printf("\tA est bien dans le demi-plan.\n");
            RetVal++;
        } else {
            // printf("\tA n'est pas dans le demi-plan.\n");
        }

    }

    return RetVal;
}

void dessiner_poly(ineq p[], int n, int xmin, int xmax, int ymin, int ymax){

    for(int y=ymax; y>=ymin; y--){

        printf("\n");

        for(int x=xmin; x<=xmax;x++){
            if(test_poly(p, n, x, y) != 3) printf(".");
            else printf("#");
        }
    }
    printf("\n\n");
}
