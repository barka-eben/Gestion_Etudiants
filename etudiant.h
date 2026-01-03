#ifndef ETUDIANT_H
#define ETUDIANT_H

#define MAX_ETUDIANTS 100

/* Structure Etudiant */
typedef struct {
    char matricule[20];
    char nom[30];
    char prenom[30];
    char date_naissance[15];
    char sexe[10];
    char departement[30];
    char filiere[30];
    char region_origine[30];
} Etudiant;

/* Prototypes des fonctions */
void ajouterEtudiant(Etudiant etudiants[], int *n);
int rechercherEtudiant(Etudiant etudiants[], int n, char matricule[]);
void modifierEtudiant(Etudiant etudiants[], int n);

#endif
