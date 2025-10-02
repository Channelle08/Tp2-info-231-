#include <stdio.h>
#include <stdlib.h>

// Définition du nœud
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Création d’un nouveau nœud
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d’allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = newNode; // par défaut, circulaire sur lui-même
    return newNode;
}

// Insertion en tête
Node *insertHead(Node **last, int data) {
    Node *newNode = createNode(data);

    if (*last == NULL) {
        *last = newNode;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
    }
    return *last;
}

// Insertion en queue
Node *insertTail(Node **last, int data) {
    Node *newNode = createNode(data);

    if (*last == NULL) {
        *last = newNode;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode; // mise à jour du dernier élément
    }
    return *last;
}

// Affichage de la liste
void displayList(Node *last) {
    if (last == NULL) {
        printf("Liste vide\n");
        return;
    }

    Node *temp = last->next; // premier élément
    printf("Liste: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(retour au début)\n");
}

// Libération mémoire
void freeList(Node **last) {
    if (*last == NULL) return;

    Node *current = (*last)->next;
    Node *nextNode;

    while (current != *last) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(*last);
    *last = NULL; // sécurité
}

int main() {
    Node *last = NULL;
    int choice, elt, value, i, rep, nbre;

    printf("-----INSERTION EN TETE ET EN QUEUE DANS UNE LISTE SIMPLEMENT CHAINEE CIRCULAIRE----\n");
    printf("Entrez le nombre d'éléments de votre liste : ");
    scanf("%d", &nbre);

    printf("Entrez les valeurs : \n");
    for (i = 0; i < nbre; i++) {
        scanf("%d", &elt);
        insertTail(&last, elt);
    }

    printf("Votre liste initiale :\n");
    displayList(last);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insérer un élément en tête\n");
        printf("2. Insérer un élément en queue\n");
        printf("3. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Valeur à insérer en tête : ");
            scanf("%d", &value);
            last = insertHead(&last, value);
            displayList(last);
            break;
        case 2:
            printf("Valeur à insérer en queue : ");
            scanf("%d", &value);
            last = insertTail(&last, value);
            displayList(last);
            break;
        case 3:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix invalide !\n");
        }

        if (choice != 3) {
            printf("Voulez-vous continuer ? (1 = oui, 0 = non) : ");
            scanf("%d", &rep);
        } else {
            rep = 0;
        }
    } while (rep == 1);

    freeList(&last); // libération mémoire
    return 0;
}
