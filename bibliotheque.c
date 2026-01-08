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
