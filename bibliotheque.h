#ifndef ETUDIANT_H
#define ETUDIANT_H

#define MAX 10
#define ANNEE 2026
// enregistrement date
typedef struct
{
    int jour;
    int mois;
    int annee;
} date;
// enregistrement etudiant
typedef struct
{
    char matricule[50];
    char nom[50];
    char prenom[100];
    char departement[50];
    char option[50];
    char sexe[2];
    char region[10];
    date naissance;
} etudiant;

/* presentation de mes fonctions */
int ajouter(etudiant tab[], int n);
void rechercher(etudiant tab[], int n);
void modifier(etudiant tab[], int n);
int supprimer(etudiant tab[], int n);
void trienom(etudiant tab[], int n);
void afficher(etudiant tab[], int n);

#endif
