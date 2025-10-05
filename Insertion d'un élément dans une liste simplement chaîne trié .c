# <stdio.h>
#include <stdlib.h>

/* Définition d'un noeud de la liste */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Fonction de création d'un nouveau noeud */
Node* creerNoeud(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

/* Fonction d'insertion triée */
Node* insererTrie(Node* head, int val) {
    Node* newNode = creerNoeud(val);

    // Cas 1 : liste vide ou insertion en tête
    if (head == NULL || val < head->data) {
        newNode->next = head;
        return newNode; // devient la nouvelle tête
    }

    // Cas 2 : recherche de la bonne position
    Node* current = head;
    while (current->next != NULL && current->next->data < val) {
        current = current->next;
    }

    // insertion
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

/* Fonction d'affichage de la liste */
void afficherListe(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Programme principal */
int main() {
    Node* liste = NULL;
    int n, val;

    printf("Combien d'elements voulez-vous inserer ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez l'element %d : ", i + 1);
        scanf("%d", &val);
        liste = insererTrie(liste, val);
    }

    printf("\nListe simplement chainee triee : ");
    afficherListe(liste);

    return 0;
}
