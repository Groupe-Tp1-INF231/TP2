#include <stdio.h>
#include <stdlib.h>

/* Définition d'une cellule pour liste simplement chaînée circulaire */
typedef struct Cellule {
    int data;
    struct Cellule *suiv;
} Cellule;

/* Créer une nouvelle cellule */
Cellule* creerCellule(int val) {
    Cellule *nouveau = (Cellule*)malloc(sizeof(Cellule));
    if (!nouveau) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    nouveau->data = val;
    nouveau->suiv = NULL;
    return nouveau;
}

/* Insertion en tête */
Cellule* insererTete(Cellule* tete, int val) {
    Cellule* nouveau = creerCellule(val);

    if (tete == NULL) {
        nouveau->suiv = nouveau; // premier élément, circulaire vers lui-même
        return nouveau;
    }

    // Trouver le dernier élément
    Cellule* dernier = tete;
    while (dernier->suiv != tete) {
        dernier = dernier->suiv;
    }

    nouveau->suiv = tete;
    dernier->suiv = nouveau;

    return nouveau; // nouveau devient la nouvelle tête
}

/* Insertion en queue */
Cellule* insererQueue(Cellule* tete, int val) {
    Cellule* nouveau = creerCellule(val);

    if (tete == NULL) {
        nouveau->suiv = nouveau;
        return nouveau;
    }

    // Trouver le dernier
    Cellule* dernier = tete;
    while (dernier->suiv != tete) {
        dernier = dernier->suiv;
    }

    dernier->suiv = nouveau;
    nouveau->suiv = tete;

    return tete; // tête ne change pas
}

/* Afficher la liste */
void afficherListe(Cellule* tete) {
    if (tete == NULL) {
        printf("Liste vide\n");
        return;
    }

    Cellule* temp = tete;
    printf("Liste circulaire : ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->suiv;
    } while (temp != tete);
    printf("(retour tete)\n");
}

/* Libérer la liste */
void libererListe(Cellule* tete) {
    if (tete == NULL) return;

    Cellule* cur = tete->suiv;
    while (cur != tete) {
        Cellule* suiv = cur->suiv;
        free(cur);
        cur = suiv;
    }
    free(tete);
}

/* Programme principal avec menu */
int main() {
    Cellule* tete = NULL;
    int choix, val;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1) Inserer en tete\n");
        printf("2) Inserer en queue\n");
        printf("3) Afficher la liste\n");
        printf("4) Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Valeur a inserer en tete : ");
                scanf("%d", &val);
                tete = insererTete(tete, val);
                break;

            case 2:
                printf("Valeur a inserer en queue : ");
                scanf("%d", &val);
                tete = insererQueue(tete, val);
                break;

            case 3:
                afficherListe(tete);
                break;

            case 4:
                libererListe(tete);
                printf("Fin du programme\n");
                return 0;

            default:
                printf("Choix invalide\n");
        }
    }
}
