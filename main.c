#include <stdio.h>
#include "bibliotheque.h"

int main() {
    Etudiant etudiants[MAX_ETUDIANTS];
    int n = 0;
    int choix;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Modifier un etudiant\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterEtudiant(etudiants, &n);
                break;
            case 2:
                modifierEtudiant(etudiants, n);
                break;
            case 0:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
