#include <stdio.h>
#include <string.h>
#include "bibliotheque.h"

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

// fonction ajouter
int ajouter(etudiant tab[], int n)
{
    if (n >= MAX)
    {
        printf("Tableau plein.\n");
        return n;
    }

    printf("Matricule: ");
    scanf("%s", tab[n].matricule);

    printf("Nom: ");
    scanf("%s", tab[n].nom);

    printf("Prenom: ");
    scanf("%s", tab[n].prenom);

    printf("Date naissance (jj/mm/aaaa): ");
    scanf("%d/%d/%d",
          &tab[n].naissance.jour,
          &tab[n].naissance.mois,
          &tab[n].naissance.annee);

    printf("Departement: ");
    scanf("%s", tab[n].departement);

    printf("Option: ");
    scanf("%s", tab[n].option);

    printf("Sexe (M/F): ");
    scanf("%s", tab[n].sexe);

    printf("Region: ");
    scanf("%s", tab[n].region);

    return n + 1;
}
// fonction rechercher à partrir du nom
void rechercher(etudiant tab[], int n)
{
    char rech[50];
    int trouve = 0;

    printf("Nom a rechercher: ");
    scanf("%s", rech);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(tab[i].nom, rech) == 0)
        {
            printf("Nom: %s Prenom: %s Age: %d\n",
                   tab[i].nom,
                   tab[i].prenom,
                   ANNEE - tab[i].naissance.annee);
            trouve = 1;
            break;
        }
    }

    if (!trouve)
        printf("Aucun etudiant trouve.\n");
}
// fonction modifier etudiant à partir de son matricule
void modifier(etudiant tab[], int n)
{
    char mat[50];
    printf("Matricule a modifier: ");
    scanf("%s", mat);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(tab[i].matricule, mat) == 0)
        {
            printf("Nouveau nom: ");
            scanf("%s", tab[i].nom);
            printf("Nouveau prenom: ");
            scanf("%s", tab[i].prenom);
            return;
        }
    }
    printf("Etudiant non trouve.\n");
}
// fonction supprimer
int supprimer(etudiant tab[], int n)
{
    char mat[50];
    printf("Matricule a supprimer: ");
    scanf("%s", mat);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(tab[i].matricule, mat) == 0)
        {
            for (int j = i; j < n - 1; j++)
                tab[j] = tab[j + 1];

            printf("Suppression reussie.\n");
            return n - 1;
        }
    }

    printf("Etudiant non trouve.\n");
    return n;
}
// fonction trie par ordre alphabetique des noms
void trienom(etudiant tab[], int n)
{
    etudiant temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(tab[i].nom, tab[j].nom) > 0)
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
}
// fonction d'affichage de tous les etudiants
void afficher(etudiant tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %s (%d ans)\n",
               tab[i].nom,
               tab[i].prenom,
               ANNEE - tab[i].naissance.annee);
    }
}
