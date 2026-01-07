#include <stdio.h>
#include <string.h>
#include "bibliotheque.h"
int main(){
    int choix;
    do {
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher les etudiants\n");
        printf("3. Supprimer un etudiant\n");
        printf("4. Modifier un etudiant\n");
        printf("5. Rechercher un etudiant\n");
        printf("6. Trier les etudiants par ordre alphabetique\n");
        printf("7. Trier les etudiants par filiere\n");
        printf("8. Rechercher un etudiant par matricule (dichotomie)\n");   
        printf("9. Quitter\n");
        printf("Choix: ");
        scanf("%d",&choix);
        switch(choix){
            case 1:
                ajout_etudiant();
                break;
            case 2:
                afficher_etudiants();
                break;
            case 3:
                supprimer_etudiant();
                break;
            case 4:
                modifier_etudiant();
                break;
            case 5:
                rechercher_etudiant();
                break;
            case 6:
                tri_alphabetique();
                break;
            case 7:
                tri_par_filiere();
                break;
            case 8:
                recherche_matricule_dichotomie();
                break;
            case 9:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 9);
    return 0;
}