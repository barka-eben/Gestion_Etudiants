#include "bibliotheque.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

int calcul_age(Etudiant e){
    time_t maintenant = time(NULL);
    struct tm *date = localtime(&maintenant);
    int annee_actuelle = date->tm_year + 1900;
    int age=annee_actuelle - e.date_naissance.annee;
    int mois_actuel = date->tm_mon + 1;
    int jour_actuel = date->tm_mday;
    if (mois_actuel<e.date_naissance.mois || (mois_actuel==e.date_naissance.mois && jour_actuel<e.date_naissance.jour))
        age--;
    if (age < 0)
        age = 0;
    return age;
}

Etudiant *tab = NULL;   
int n = 0;              
void ajout_etudiant(){
    Etudiant *temp = realloc(tab, (n + 1) * sizeof(Etudiant));
    if (temp == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return;
    }
    tab = temp;
    printf("Entrer les informations de l'etudiant %d:\n",n+1);
    printf("Nom: ");
    scanf("%s",tab[n].nom);
    printf("Prenom: ");
    scanf("%s",tab[n].prenom);
    printf("Sexe(M/F): ");
    scanf(" %c",&tab[n].sexe);
    printf("Matricule: ");
    scanf("%s",tab[n].matricule);
    printf("Date de naissance(separez le jour, mois et annee par la touche 'Entrer'): ");
    scanf("%d %d %d",&tab[n].date_naissance.jour,&tab[n].date_naissance.mois,&tab[n].date_naissance.annee);
    printf("Departement: ");
    scanf("%s",tab[n].departement);
    printf("Filiere: ");
    scanf("%s",tab[n].filiere);
    printf("Region d'origine: ");
    scanf("%s",tab[n].region_origine);
    n++;
}

void afficher_etudiants() {
    if (n == 0) {
        printf("Aucun etudiant a afficher\n");
        return;
    }
    printf("+---------------+---------------+------+-------------+-------------------+---------------+---------------+----------------------+------+\n");
    printf("| Nom           | Prenom        | Sexe |  Matricule  | Date naissance    | Departement   | Filiere       | Region origine       | Age  |\n");
    printf("+---------------+---------------+------+-------------+-------------------+---------------+---------------+----------------------+------+\n");
    for (int i = 0; i < n; i++) {
        printf("| %-13s | %-13s |  %-c   | %-11s | %02d/%02d/%04d        | %-13s | %-13s | %-20s | %-4d |\n",
               tab[i].nom,
               tab[i].prenom,
               tab[i].sexe,
               tab[i].matricule,
               tab[i].date_naissance.jour,
               tab[i].date_naissance.mois,
               tab[i].date_naissance.annee,
               tab[i].departement,
               tab[i].filiere,
               tab[i].region_origine,
               calcul_age(tab[i]));
    }
    printf("+---------------+---------------+------+-------------+-------------------+---------------+---------------+----------------------+------+\n");
}
