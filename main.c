#include <stdio.h>
#include <string.h>
#include "bibliotheque.h"
int main(){
    int choix;
    int taille = 0;
    printf("Bienvenue sur le gestionnaire d'etudiants!\n");

    // Demander le nombre initial d'etudiants a enregistrer
    do {
        printf("Entrez le nombre d'etudiants a enregistrer: ");
        if (scanf("%d", &taille) != 1) {
            printf("Entree invalide ! Veuillez entrer un nombre entier.\n");
            while(getchar() != '\n'); 
            taille = 0;
        } else if (taille <= 0) {
            printf("Le nombre doit etre positif !\n");
        }
    } while (taille <= 0);
    for (int i = 0; i < taille; i++) {
        ajout_etudiant();
    }

    // Boucle principale du menu
    do {
        printf("___________________________MENU___________________________\n");
        printf("Faire un choix parmi les options suivantes:\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher les etudiants\n");
        printf("3. Supprimer un etudiant\n");
        printf("4. Modifier un etudiant\n");
        printf("5. Rechercher un etudiant\n");
        printf("6. Trier les etudiants par ordre alphabetique\n");
        printf("7. Trier les etudiants par filiere\n");
        printf("8. Rechercher un etudiant par nom (dichotomie)\n");   
        printf("9. Quitter\n");
        printf("Choix: ");
        if (scanf("%d", &choix) != 1) {
            printf("Entree invalide ! Veuillez entrer un nombre entier.\n");
            while(getchar() != '\n'); 
            choix=0;
            continue;
        }
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
                recherche_nom_dichotomie();
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