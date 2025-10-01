#include <stdio.h>
#include <stdlib.h>

/* ======== Définition des structures ======== */

// Liste simplement chaînée
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Liste doublement chaînée
typedef struct DNode {
    int data;
    struct DNode *prev, *next;
} DNode;

// Liste simplement chaînée circulaire
typedef struct CNode {
    int data;
    struct CNode *next;
} CNode;

// Liste doublement chaînée circulaire
typedef struct DCNode {
    int data;
    struct DCNode *prev, *next;
} DCNode;


/* ======== Fonctions pour listes simples ======== */

// Suppression de toutes les occurrences d’un élément
void supprimerOcc(Node **head, int val) {
    Node *temp = *head, *prev = NULL;

    while (temp != NULL && temp->data == val) {
        *head = temp->next;
        free(temp);
        temp = *head;
    }

    while (temp != NULL) {
        if (temp->data == val) {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

// Insertion triée dans liste simple
void insererTrieSimple(Node **head, int val) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= val) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL && temp->next->data < val) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Affichage liste simple
void afficherSimple(Node *head) {
    printf("Liste simple : ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


/* ======== Fonctions pour listes doubles ======== */

void insererTrieDouble(DNode **head, int val) {
    DNode *newNode = malloc(sizeof(DNode));
    newNode->data = val;
    newNode->next = newNode->prev = NULL;

    if (*head == NULL || (*head)->data >= val) {
        newNode->next = *head;
        if (*head) (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    DNode *temp = *head;
    while (temp->next != NULL && temp->next->data < val) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    if (temp->next) temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
}

void afficherDouble(DNode *head) {
    printf("Liste double : ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


/* ======== Fonctions pour listes circulaires simples ======== */

void insererTeteCirculaire(CNode **last, int val) {
    CNode *newNode = malloc(sizeof(CNode));
    newNode->data = val;

    if (*last == NULL) {
        *last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
    }
}

void insererQueueCirculaire(CNode **last, int val) {
    CNode *newNode = malloc(sizeof(CNode));
    newNode->data = val;

    if (*last == NULL) {
        *last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode;
    }
}

void afficherCirculaire(CNode *last) {
    if (last == NULL) {
        printf("Liste circulaire vide\n");
        return;
    }
    printf("Liste circulaire simple : ");
    CNode *p = last->next;
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != last->next);
    printf("(retour au début)\n");
}


/* ======== Fonctions pour listes circulaires doubles ======== */

void insererTeteDoubleCirculaire(DCNode **head, int val) {
    DCNode *newNode = malloc(sizeof(DCNode));
    newNode->data = val;

    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        DCNode *last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insererQueueDoubleCirculaire(DCNode **head, int val) {
    DCNode *newNode = malloc(sizeof(DCNode));
    newNode->data = val;

    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        DCNode *last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

void afficherDoubleCirculaire(DCNode *head) {
    if (head == NULL) {
        printf("Liste double circulaire vide\n");
        return;
    }
    printf("Liste double circulaire : ");
    DCNode *p = head;
    do {
        printf("%d <-> ", p->data);
        p = p->next;
    } while (p != head);
    printf("(retour au début)\n");
}


/* ======== Programme principal (menu) ======== */

int main() {
    Node *listeSimple = NULL;
    DNode *listeDouble = NULL;
    CNode *listeCircSimple = NULL;
    DCNode *listeCircDouble = NULL;

    int choix, val;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Insertion dans liste simple triée\n");
        printf("2. Suppression occurrences dans liste simple\n");
        printf("3. Insertion dans liste double triée\n");
        printf("4. Insertion tete liste circulaire simple\n");
        printf("5. Insertion queue liste circulaire simple\n");
        printf("6. Insertion tete liste circulaire double\n");
        printf("7. Insertion queue liste circulaire double\n");
        printf("8. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Valeur a inserer : ");
                scanf("%d", &val);
                insererTrieSimple(&listeSimple, val);
                afficherSimple(listeSimple);
                break;
            case 2:
                printf("Valeur a supprimer : ");
                scanf("%d", &val);
                supprimerOcc(&listeSimple, val);
                afficherSimple(listeSimple);
                break;
            case 3:
                printf("Valeur a inserer : ");
                scanf("%d", &val);
                insererTrieDouble(&listeDouble, val);
                afficherDouble(listeDouble);
                break;
            case 4:
                printf("Valeur a inserer en tete circulaire simple : ");
                scanf("%d", &val);
                insererTeteCirculaire(&listeCircSimple, val);
                afficherCirculaire(listeCircSimple);
                break;
            case 5:
                printf("Valeur a inserer en queue circulaire simple : ");
                scanf("%d", &val);
                insererQueueCirculaire(&listeCircSimple, val);
                afficherCirculaire(listeCircSimple);
                break;
            case 6:
                printf("Valeur a inserer en tete double circulaire : ");
                scanf("%d", &val);
                insererTeteDoubleCirculaire(&listeCircDouble, val);
                afficherDoubleCirculaire(listeCircDouble);
                break;
            case 7:
                printf("Valeur a inserer en queue double circulaire : ");
                scanf("%d", &val);
                insererQueueDoubleCirculaire(&listeCircDouble, val);
                afficherDoubleCirculaire(listeCircDouble);
                break;
            case 8:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 8);

    return 0;
}
