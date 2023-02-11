/*

 Author: Yannis STEFANELLI

 Creation Date: 11-02-2023 16:39:25

 Description :

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double* a_tab;
    unsigned int a_taille;
} TableauDouble;

typedef TableauDouble* PtrTableauDouble;

void TableauDouble_construire(PtrTableauDouble *dd, unsigned taille) {
    *dd = malloc(sizeof(TableauDouble));
    (*dd)->a_taille = taille;
    (*dd)->a_tab = malloc(taille * sizeof(double));
}

void TableauDouble_afficher (const PtrTableauDouble dd) {
    for (int i = 0; i != dd->a_taille; i++) {
        printf("%lf", dd->a_tab[i]);
        if (i < dd->a_taille -1)
            printf(" - ");
    }
    printf("\n");
}

void TableauDouble_modifier (PtrTableauDouble const dd, const unsigned index, const double valeur) {
    dd->a_tab[index] = valeur;
}

void TableauDouble_liberer (PtrTableauDouble dd) {
    free(dd);
}

double TableauDouble_get(PtrTableauDouble dd, const unsigned index) {
    printf("%lf", dd->a_tab[index]);
}

void TableauDouble_set(PtrTableauDouble dd, const unsigned index, double val) {
    dd->a_tab[index] = val;
}

int C_2() {

    PtrTableauDouble d1 = NULL;
    unsigned t1=5;

    TableauDouble_construire(&d1,t1);
    TableauDouble_afficher(d1);
    TableauDouble_modifier(d1,2, 3.13589985);
    TableauDouble_afficher(d1);
    printf("%5.10f\n",TableauDouble_get(d1,2));
    TableauDouble_set(d1,2,62.1);
    printf("%5.10f\n",TableauDouble_get(d1,2));
    TableauDouble_afficher(d1);
    TableauDouble_liberer(d1);
    TableauDouble_afficher(d1);
    
    return 0;
}

int main() {
    return C_2();
}

