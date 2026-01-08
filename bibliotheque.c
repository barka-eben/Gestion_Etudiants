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

void supprimer_etudiant(){
    char mat[11];
    int num=-1;
    int conteur;
    printf("Entrer le matricule de l'etudiant a supprimer: ");
    scanf("%s", mat);
    for (int i=0;i<n;i++){
        if (strcmp(mat,tab[i].matricule)==0){
            num=i;
            break;
        }
    }
    if (num==-1){
            printf("Matricule introuvable \n");
            return;
        }
    for (conteur=num;conteur<n-1;conteur++){
            tab[conteur]=tab[conteur+1];
        }
    n--;
    if (n == 0) {
        free(tab);
        tab = NULL;
    } else {
        Etudiant *temp = realloc(tab, n * sizeof(Etudiant));
        if (temp != NULL) {
            tab = temp;
        }
    }
    printf("Le matricule '%s' a ete supprimer \n",mat);

}

void modifier_etudiant(){
    char mat[11];
    int num=-1;
    int nombre;
    printf("Entrer le matricule de l'etudiant a modifier: ");
    scanf("%s", mat);
    for (int i=0;i<n;i++){
        if (strcmp(mat,tab[i].matricule)==0){
            num=i;
            break;
        }
    }
    if (num==-1){
            printf("Matricule introuvable \n");
            return;
        }
    printf("Quelle information de l'etudiant %s ayant le matricule %s voulez-vous modifier?\n", tab[num].nom,tab[num].matricule); 
    printf("1. Pour le Nom\n");
    printf("2. Pour le Prenom\n");
    printf("3. Pour le Sexe\n");
    printf("4. Pour le Date de naissance(jour mois annee)\n");
    printf("5. Pour le Departement\n");
    printf("6. Pour le Filiere\n");
    printf("7. Pour le Region d'origine\n");
    printf("8. . Pour le Quitter \n");
    scanf("%d",&nombre);
    switch (nombre){
    case 1:
        printf("Nom: ");
        scanf("%s",tab[num].nom);
        break;
    case 2:
        printf("Prenom: ");
        scanf("%s",tab[num].prenom);
        break;
    case 3:
        printf("Sexe: ");
        scanf(" %c",&tab[num].sexe);
        break;
    case 4:
        printf("Date de naissance(separez le jour, mois et annee par la touche 'Entrer'): ");
        scanf("%d %d %d",&tab[num].date_naissance.jour,&tab[num].date_naissance.mois,&tab[num].date_naissance.annee);
        break;
    case 5:
        printf("Departement: ");
        scanf("%s",tab[num].departement);
        break;
    case 6:
        printf("Filiere: ");
        scanf("%s",tab[num].filiere);
        break;
    case 7:
        printf("Region d'origine: ");
        scanf("%s",tab[num].region_origine);
        break;
    case 8:
        break;
    default:
        printf("Choix non valide\n");
    }
}

void rechercher_etudiant(){
    char matri[11];
    int nbre=-1;
    printf("Entrerz le matricule de l'etudiant a rechercher: ");
    scanf("%s", &matri);
    for(int i=0;i<n;i++){
        if (strcmp(matri,tab[i].matricule)==0){
            nbre=i;
            break;
        }
    }
    if (nbre==-1){
        printf("Etudiant avec le matricule %s introuvable \n",matri);
        return;
    }
    printf("Etudiant avec le matricule %s trouve:\n",matri);
    printf("+---------------+---------------+------+-------------+-------------------+---------------+---------------+----------------------+------+\n");
    printf("| Nom           | Prenom        | Sexe |  Matricule  | Date naissance    | Departement   | Filiere       | Region origine       | Age  |\n");
    printf("+---------------+---------------+------+-------------+-------------------+---------------+---------------+----------------------+------+\n");
        printf("| %-13s | %-13s |  %-c   | %-11s | %02d/%02d/%04d        | %-13s | %-13s | %-20s | %-4d |\n",
               tab[nbre].nom,
               tab[nbre].prenom,
               tab[nbre].sexe,
               tab[nbre].matricule,
               tab[nbre].date_naissance.jour,
               tab[nbre].date_naissance.mois,
               tab[nbre].date_naissance.annee,
               tab[nbre].departement,
               tab[nbre].filiere,
               tab[nbre].region_origine,
               calcul_age(tab[nbre]));
    printf("+---------------+---------------+------+-------------+-------------------+---------------+---------------+----------------------+------+\n");

}

void tri_alphabetique(){
    Etudiant nomprem;
    if (n < 2) {
        printf("Pas assez d'etudiants pour trier.\n");
        return;
    }
    for(int i=0;i<n-1;i++){
        for (int j=i+1; j<n;j++){
            if (stricmp(tab[i].nom,tab[j].nom)>0){
                nomprem=tab[i];
                tab[i]=tab[j];
                tab[j]=nomprem;
            }
        }
    }
    
    printf("Tri par nom effectue (ordre alphabetique).\n");
    afficher_etudiants();
}

void tri_par_filiere() {
    Etudiant temp;
    if (n < 2) {
        printf("Pas assez d'etudiants pour trier.\n");
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (stricmp(tab[i].filiere, tab[j].filiere) > 0) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }

    printf("Tri par filiere effectue (ordre alphabetique).\n");
    afficher_etudiants();
}


void recherche_matricule_dichotomie(){
    Etudiant mattri;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(tab[i].matricule, tab[j].matricule) > 0) {
                mattri = tab[i];
                tab[i] = tab[j];
                tab[j] = mattri;
            }
        }
    }

    char mat[11];
    int debut=0;
    int fin=n-1;
    printf("Entrerz le matricule de l'etudiant a rechercher: ");
    scanf("%s", mat);

    while (debut<=fin){
        int milieu=(debut+fin)/2;
        int position=strcmp(tab[milieu].matricule,mat);
        if (position==0){
            printf("Etudiant avec le matricule %s trouve:\n",mat);
            printf("+---------------+---------------+------+-------------+-------------------+---------------+---------------+----------------------+------+\n");
            printf("| Nom           | Prenom        | Sexe |  Matricule  | Date naissance    | Departement   | Filiere       | Region origine       | Age  |\n");
            printf("+---------------+---------------+------+-------------+-------------------+---------------+---------------+----------------------+------+\n");
                printf("| %-13s | %-13s |  %-c   | %-11s | %02d/%02d/%04d        | %-13s | %-13s | %-20s | %-4d |\n",
                    tab[milieu].nom,
                    tab[milieu].prenom,
                    tab[milieu].sexe,
                    tab[milieu].matricule,
                    tab[milieu].date_naissance.jour,
                    tab[milieu].date_naissance.mois,
                    tab[milieu].date_naissance.annee,
                    tab[milieu].departement,
                    tab[milieu].filiere,
                    tab[milieu].region_origine,
                    calcul_age(tab[milieu]));
            printf("+---------------+---------------+------+-------------+-------------------+---------------+---------------+----------------------+------+\n");
            return;
        }

        if (position<0){
            debut=milieu+1;
        }else{
            fin=milieu-1;
        }

    }
    printf("Etudiant avec le matricule %s introuvable.\n", mat);
}

