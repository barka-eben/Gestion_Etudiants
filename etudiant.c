#include <stdio.h>
#include <string.h>
#include "etudiant.h"

/* Ajouter un étudiant */
void ajouterEtudiant(Etudiant etudiants[], int *n) {
    printf("Matricule : ");
    scanf("%s", etudiants[*n].matricule);

    printf("Nom : ");
    scanf("%s", etudiants[*n].nom);

    printf("Prenom : ");
    scanf("%s", etudiants[*n].prenom);

    printf("Date de naissance : ");
    scanf("%s", etudiants[*n].date_naissance);

    printf("Sexe : ");
    scanf("%s", etudiants[*n].sexe);

    printf("Departement : ");
    scanf("%s", etudiants[*n].departement);

    printf("Filiere : ");
    scanf("%s", etudiants[*n].filiere);

    printf("Region d'origine : ");
    scanf("%s", etudiants[*n].region_origine);

    (*n)++;
    printf("Etudiant ajoute avec succes.\n");
}

/* Rechercher un étudiant par matricule */
int rechercherEtudiant(Etudiant etudiants[], int n, char matricule[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(etudiants[i].matricule, matricule) == 0) {
            return i;
        }
    }
    return -1;
}

/* Modifier un étudiant */
void modifierEtudiant(Etudiant etudiants[], int n) {
    char matricule[20];
    printf("Entrer le matricule de l'etudiant a modifier : ");
    scanf("%s", matricule);

    int index = rechercherEtudiant(etudiants, n, matricule);

    if (index == -1) {
        printf("Etudiant non trouve.\n");
        return;
    }

    printf("Nouveau nom : ");
    scanf("%s", etudiants[index].nom);

    printf("Nouveau prenom : ");
    scanf("%s", etudiants[index].prenom);

    printf("Nouvelle date de naissance : ");
    scanf("%s", etudiants[index].date_naissance);

    printf("Nouveau sexe : ");
    scanf("%s", etudiants[index].sexe);

    printf("Nouveau departement : ");
    scanf("%s", etudiants[index].departement);

    printf("Nouvelle filiere : ");
    scanf("%s", etudiants[index].filiere);

    printf("Nouvelle region d'origine : ");
    scanf("%s", etudiants[index].region_origine);

    printf("Informations modifiees avec succes.\n");
}
