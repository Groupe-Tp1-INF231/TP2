#include <stdio.h>
#include <stdlib.h>

typedef struct Cellule {
    int data;
    struct Cellule *suiv;
} Cellule;

Cellule* insererFin(Cellule *tete, int valeur) {
    Cellule *nouv = malloc(sizeof *nouv);
    nouv->data = valeur;
    nouv->suiv = NULL;
    if (tete == NULL)
        return nouv;
    Cellule *p = tete;
    while (p->suiv) p = p->suiv;
    p->suiv = nouv;
    return tete;
}

void afficher(Cellule *tete) {
    for (Cellule *p = tete; p; p = p->suiv)
        printf("%d -> ", p->data);
    printf("NULL\n");
}

Cellule* supprimerOcc(Cellule *tete, int v) {
    Cellule **p = &tete;
    while (*p) {
        if ((*p)->data == v) {
            Cellule *tmp = *p;
            *p = (*p)->suiv;
            free(tmp);
        } else
            p = &(*p)->suiv;
    }
    return tete;
}

// Vérifier si une valeur existe dans la liste
int existe(Cellule *tete, int v) {
    for (Cellule *p = tete; p; p = p->suiv) {
        if (p->data == v) return 1; // trouvé
    }
    return 0; // pas trouvé
}

int main() {
    Cellule *tete = NULL;
    int n, x, cible;

    printf("Combien d'elements ? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Entrer element %d: ", i+1);
        scanf("%d", &x);
        tete = insererFin(tete, x);
    }

    printf("\nListe avant suppression:\n");
    afficher(tete);

    // Redemander jusqu'à ce que la valeur existe
    do {
        printf("\nEntrer l'element a supprimer: ");
        scanf("%d", &cible);
        if (!existe(tete, cible)) {
            printf("Erreur: l'element %d n'existe pas dans la liste. Reessayez.\n", cible);
        }
    } while (!existe(tete, cible));

    // Supprimer toutes les occurrences
    tete = supprimerOcc(tete, cible);

    printf("\nListe apres suppression:\n");
    afficher(tete);

    // Libération mémoire
    while (tete) {
        Cellule *t = tete;
        tete = tete->suiv;
        free(t);
    }
    return 0;
}
