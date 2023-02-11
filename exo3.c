/*

 Author: Yannis STEFANELLI

 Creation Date: 11-02-2023 17:44:53

 Description :

*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct {
    char *name;
    char *author;
    char *editor;
    char *barcode;
} Livre;

Livre *create_book(Livre **livre) { //allocation de la mémoire sur la structure
    *livre = (Livre *)malloc(sizeof(Livre));
    return *livre;
}

void change_value_of(Livre *livre, char* param) {

    char *arg = malloc(sizeof(char) * 15); //le paramètre à changer
    char *value = malloc(sizeof(char) * 200); //sa valeur
    int j = 0;
    int k = 0;

    for (; param[j] != ','; j++) { //bloc de parsing pour savoir quel argument va être modifié
        arg[j] = param[j];
    }
    j++;
    for (; param[j] != 0; j++, k++) { //bloc de parsing pour savoir quel paramètre va être modifié/ajouté
        value[k] = param[j];
    }

    if (strcmp("name", arg) == 0) //bloc de comparaison
        livre->name = value;
    else if (strcmp("author", arg) == 0)
        livre->author = value;
    else if (strcmp("editor", arg) == 0)
        livre->editor = value;
    else if (strcmp("barcode", arg) == 0)
        livre->barcode = value;
    else
        printf("Entrez un paramètre valide !\n");
}

void display(Livre *livre, ...) { // "..." est un attribut elliptique

    //un paramètre optionnel permet de n'afficher qu'un seul attribut de Livre

    va_list args; //initialisation d'une liste d'arguments pour pouvoir prendre en compte les paramètres optionnels
    va_start(args, *livre); //début de la liste

    switch (va_arg(args, int)) { //bloc de comparaison avec l'argument optionnel
        case 1:
            printf("Titre :%s\n", livre->name);
        break;
        case 2:
            printf("Auteur(e) :%s\n", livre->author);
        break;
        case 3:
            printf("Editeur :%s\n", livre->editor);
        break;
        case 4:
            printf("Code Barres :%s\n", livre->barcode);
        break;
        default: //si aucun argument optionnel n'est fourni, on tombe dans le case default, et on affiche tout
            printf("Titre :%s\nAuteur(e) :%s\nEditeur :%s\nCode Barres :%s\n", livre->name, livre->author, livre->editor, livre->barcode);
        break;
    }
    va_end(args); //fin liste
}


int main(void)
{
    Livre *harry_potter = NULL;
    create_book(&harry_potter);

    change_value_of(harry_potter, "author, J.K Rowling");
    change_value_of(harry_potter, "name, Harry Potter");
    change_value_of(harry_potter, "editor, Folio Junior");
    change_value_of(harry_potter, "barcode, 405876");

    display(harry_potter);
    printf("\n");

    Livre *les_3_mousquetaires = NULL;
    create_book(&les_3_mousquetaires);

    change_value_of(les_3_mousquetaires, "author, Alexandre Dumas");
    change_value_of(les_3_mousquetaires, "name, Les Trois Mousquetaires");

    //argument optionnel : 1 - titre, 2 - auteur, etc...
    display(les_3_mousquetaires, 1);
    display(les_3_mousquetaires, 2);
    printf("\n");

    return 0;
}