#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    char matricule[11];
    char nom[30];
    char prenom[30];
    Date date_naissance;
    char departement[30];
    char filiere[50];
    char sexe;
    char region_origine[50];
} Etudiant;

#endif