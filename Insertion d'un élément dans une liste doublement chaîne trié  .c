#include <stdio.h>
#include <stdlib.h>

/* Définition d'une cellule de la liste doublement chaînée */
typedef struct Cellule {
    int data;
    struct Cellule *prec;
    struct Cellule *suiv;
} Cellule;

/* Fonction de création d'une nouvelle cellule */
Cellule* creerCellule(int val) {
    Cellule* nouveau = (Cellule*)malloc(sizeof(Cellule));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    nouveau->data = val;
    nouveau->prec = NULL;
    nouveau->suiv = NULL;
    return nouveau;
}

/* Insertion triée dans une liste doublement chaînée */
Cellule* insererTrie(Cellule* tete, int val) {
    Cellule* nouveau = creerCellule(val);

    // Cas 1 : liste vide
    if (tete == NULL) {
        return nouveau;
    }

    // Cas 2 : insertion avant la tête
    if (val < tete->data) {
        nouveau->suiv = tete;
        tete->prec = nouveau;
        return nouveau; // devient la nouvelle tête
    }

    // Cas 3 : recherche de la position d'insertion
    Cellule* courant = tete;
    while (courant->suiv != NULL && courant->suiv->data < val) {
        courant = courant->suiv;
    }

    // Insertion après "courant"
    nouveau->suiv = courant->suiv;
    nouveau->prec = courant;
    if (courant->suiv != NULL) {
        courant->suiv->prec = nouveau;
    }
    courant->suiv = nouveau;

    return tete;
}

/* Affichage de la liste en ordre croissant */
void afficherListe(Cellule* tete) {
    Cellule* temp = tete;
    printf("Liste (croissant) : ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        if (temp->suiv == NULL) break; // on garde le dernier pour parcours inverse
        temp = temp->suiv;
    }
    printf("NULL\n");
}

/* Affichage de la liste en ordre décroissant */
void afficherListeInverse(Cellule* tete) {
    if (tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    // aller au dernier élément
    Cellule* temp = tete;
    while (temp->suiv != NULL) {
        temp = temp->suiv;
    }

    printf("Liste (décroissant) : ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prec;
    }
    printf("NULL\n");
}

/* Programme principal */
int main() {
    Cellule* liste = NULL;
    int n, val;

    printf("Combien d'elements voulez-vous inserer ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez l'element %d : ", i + 1);
        scanf("%d", &val);
        liste = insererTrie(liste, val);
    }

    printf("\n");
    afficherListe(liste);
    afficherListeInverse(liste);

    return 0;
}
