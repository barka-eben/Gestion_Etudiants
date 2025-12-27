#include <stdio.h>
#include "bibliotheque.h"

int main()
{
    etudiant etu[MAX];
    int n = 0, choix;

    do
    {
// presentation des options au user
        printf("\n1. Ajouter\n2. Rechercher\n3. Modifier\n4. Supprimer\n5. Trier\n6. Afficher\n0. Quitter\n");
        scanf("%d", &choix);
// appel des fonctions pour  chaque choix
        switch (choix)
        {
        case 1: n = ajouter(etu, n); break;
        case 2: rechercher(etu, n); break;
        case 3: modifier(etu, n); break;
        case 4: n = supprimer(etu, n); break;
        case 5: trienom(etu, n); break;
        case 6: afficher(etu, n); break;
        }
    } while (choix != 0);

    return 0;
}
