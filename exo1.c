/*

 Author: Yannis STEFANELLI

 Creation Date: 11-02-2023 15:41:07

 Description :

*/

#include <stdlib.h>
#include <stdio.h>

typedef double* PtrTableauDouble;

void TableauDouble_construire(PtrTableauDouble *dd, const unsigned taille) {
    *dd = malloc(sizeof(PtrTableauDouble));
}

void TableauDouble_afficher (const PtrTableauDouble dd, const unsigned taille) {
    for (int i = 0; i <= taille; i++) {
        printf("%lf", dd[i]);
        if (i < taille)
            printf(" - ");
    }
    printf("\n");
}

void TableauDouble_modifier (PtrTableauDouble const dd, const unsigned taille, const unsigned index, const double valeur) {
    dd[index] = valeur;
}

void TableauDouble_liberer (PtrTableauDouble *dd) {
    *dd = NULL; //on set l'adresse de dd à NULL, pour éviter les read après le free
    free(*dd);
}

double TableauDouble_get(PtrTableauDouble dd, const unsigned taille, const unsigned index) {
    printf("%lf", dd[index]);
}

void TableauDouble_set(PtrTableauDouble dd, const unsigned taille, const unsigned index, double val) { 
    dd[index] = val;
}

int C_1() {
    
    PtrTableauDouble d1 = NULL;
    unsigned t1=5;

    TableauDouble_construire(&d1,t1);
    TableauDouble_afficher(d1,t1);
    TableauDouble_modifier(d1,t1,2, 3.13589985);
    TableauDouble_afficher(d1,t1);
    printf("%5.10f\n",TableauDouble_get(d1,t1,2));
    TableauDouble_set(d1,t1,2,62.1);
    printf("%5.10f\n",TableauDouble_get(d1,t1,2));
    TableauDouble_afficher(d1,t1);
    TableauDouble_liberer(&d1);
    printf("\nlà on va segfault si les choses sont bien faites :\n");
    TableauDouble_afficher(d1,t1);
    return 0;
}

int main() {
    return C_1();
}
