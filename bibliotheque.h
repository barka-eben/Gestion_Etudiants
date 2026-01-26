#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

// Structure pour la date
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Structure pour l'etudiant
typedef struct {
    char matricule[15];
    char nom[40];
    char prenom[40];
    Date date_naissance;
    char departement[50];
    char filiere[50];
    char sexe;
    char region_origine[50];
} Etudiant;

// Declaration des fonctions
void ajout_etudiant();
void afficher_etudiants();
void supprimer_etudiant();
void modifier_etudiant();
void rechercher_etudiant();
void tri_alphabetique();
void tri_par_filiere();
void recherche_nom_dichotomie();

#endif