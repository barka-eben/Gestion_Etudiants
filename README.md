# Projet : Gestion des Étudiants en Langage C

## Description

Ce projet est une application console écrite en **langage C** qui permet de gérer les informations des étudiants à l’aide de **structures de données**.
Il est réalisé dans le cadre d’un **exercice académique en groupe**.

Le programme permet d’ajouter, modifier, supprimer, rechercher, trier et afficher des étudiants à partir de plusieurs critères.


## Objectifs

* Utiliser les **structures (`struct`) en C**
* Appliquer la **modularisation du code**
* Implémenter des **algorithmes de tri et de recherche**
* Travailler en **collaboration avec GitHub**
* Respecter les bonnes pratiques de programmation en C


## Structure du projet

📂 gestion-etudiants
│
├── main.c
├── bibliotheque.h
├── bibliotheque.c
└── README.md

### Description des fichiers

* **main.c** :
  Contient le programme principal et le menu interactif.

* **bibliotheque.h** :
  Contient la structure `Etudiant`, les constantes et les prototypes des fonctions.

* **bibliotheque.c** :
  Contient l’implémentation des fonctions de gestion des étudiants.


## Informations d’un étudiant

Chaque étudiant est caractérisé par :

* Matricule
* Nom
* Prénom
* Date de naissance
* Département
* Filière
* Sexe
* Région d’origine


## Fonctionnalités

Le programme permet de :

*  Ajouter un étudiant
*  Modifier les informations d’un étudiant
*  Supprimer un étudiant
*  Rechercher un étudiant par matricule
*  Effectuer une recherche par dichotomie
*  Trier les étudiants par ordre alphabétique
*  Trier les étudiants par filière
*  Afficher la liste des étudiants
*  Calculer l’âge d’un étudiant


## Concepts utilisés

* Structures (`struct`)
* Tableaux de structures
* Fonctions
* Modularisation (`.h` / `.c`)
* Recherche séquentielle
* Recherche dichotomique
* Algorithmes de tri
* Manipulation des chaînes de caractères


## Compilation et exécution

### Compilation

bash:gcc main.c bibliotheque.c -o gestion_etudiants

### Exécution

bash:./gestion_etudiants


## Utilisation

Après l’exécution, un **menu interactif** s’affiche et permet à l’utilisateur de choisir l’action à effectuer (ajout, suppression, recherche, tri, affichage, etc.).


## Travail en groupe

Ce projet est réalisé en **travail collaboratif**.
Chaque membre du groupe contribue via le dépôt GitHub.



## Cadre académique

Projet réalisé dans le cadre d’un exercice pratique en **langage C**.


## ✍️ Auteurs

* BARKA EBEN-EZEER (barka-eben)

