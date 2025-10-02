#include <stdio.h>
#include <stdlib.h>

/* Définition d'une cellule de la liste doublement chaînée circulaire */
typedef struct Cellule {
    int data;
    struct Cellule *prec;
    struct Cellule *suiv;
} Cellule;

/* Crée une nouvelle cellule contenant val */
Cellule* creerCellule(int val) {
    Cellule *nouveau = (Cellule*)malloc(sizeof(Cellule));
    if (!nouveau) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    nouveau->data = val;
    nouveau->prec = nouveau->suiv = NULL;
    return nouveau;
}

/* Insertion en tête : retourne la nouvelle tête */
Cellule* insererTete(Cellule* tete, int val) {
    Cellule *nouveau = creerCellule(val);

    if (tete == NULL) {
        /* Liste vide : la cellule pointe sur elle-même */
        nouveau->suiv = nouveau->prec = nouveau;
        return nouveau;
    }

    /* Liste non vide : insérer juste avant tete et retourner nouveau comme tête */
    Cellule *dernier = tete->prec;

    nouveau->suiv = tete;
    nouveau->prec = dernier;
    dernier->suiv = nouveau;
    tete->prec = nouveau;

    return nouveau; /* nouveau devient la nouvelle tête */
}

/* Insertion en queue : retourne la tête (inchangée si non vide) */
Cellule* insererQueue(Cellule* tete, int val) {
    Cellule *nouveau = creerCellule(val);

    if (tete == NULL) {
        /* Liste vide : nouveau seul élément */
        nouveau->suiv = nouveau->prec = nouveau;
        return nouveau;
    }

    /* Insérer juste avant la tête (c'est la queue logique) */
    Cellule *dernier = tete->prec;

    nouveau->suiv = tete;
    nouveau->prec = dernier;
    dernier->suiv = nouveau;
    tete->prec = nouveau;

    return tete; /* tête inchangée */
}

/* Affiche la liste (une seule fois autour du cercle) */
void afficherListe(Cellule* tete) {
    if (tete == NULL) {
        printf("Liste vide\n");
        return;
    }

    printf("Liste (depuis la tete) : ");
    Cellule* temp = tete;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->suiv;
    } while (temp != tete);
    printf("(retour tete)\n");
}

/* Libère toutes les cellules */
void libererListe(Cellule* tete) {
    if (tete == NULL) return;

    Cellule *cur = tete->suiv;
    while (cur != tete) {
        Cellule *suiv = cur->suiv;
        free(cur);
        cur = suiv;
    }
    free(tete);
}

/* Programme principal : menu simple */
int main(void) {
    Cellule *tete = NULL;
    int choix = 0, val;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1) Inserer en tete\n");
        printf("2) Inserer en queue\n");
        printf("3) Afficher la liste\n");
        printf("4) Quitter\n");
        printf("Choix : ");
        if (scanf("%d", &choix) != 1) {
            printf("Entrée invalide\n");
            return 1;
        }

        switch (choix) {
            case 1:
                printf("Valeur a inserer en tete : ");
                if (scanf("%d", &val) != 1) { printf("Entrée invalide\n"); return 1; }
                tete = insererTete(tete, val);
                break;

            case 2:
                printf("Valeur a inserer en queue : ");
                if (scanf("%d", &val) != 1) { printf("Entrée invalide\n"); return 1; }
                tete = insererQueue(tete, val);
                break;

            case 3:
                afficherListe(tete);
                break;

            case 4:
                libererListe(tete);
                printf("Au revoir\n");
                return 0;

            default:
                printf("Choix non reconnu\n");
        }
    }

    return 0;
}
