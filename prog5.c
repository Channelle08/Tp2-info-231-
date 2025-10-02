#include <stdio.h>
#include <stdlib.h>

// Définition du nœud
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Création d’un nœud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = newNode; // circulaire
    newNode->next = newNode; // circulaire
    return newNode;
}

// Insertion en tête
Node* insertHead(Node* last, int data) {
    Node* newNode = createNode(data);

    if (last == NULL) {
        return newNode; // premier élément
    }

    Node* head = last->next;

    newNode->next = head;
    newNode->prev = last;
    head->prev = newNode;
    last->next = newNode;

    return last; // le dernier reste inchangé
}

// Insertion en queue
Node* insertTail(Node* last, int data) {
    Node* newNode = createNode(data);

    if (last == NULL) {
        return newNode;
    }

    Node* head = last->next;

    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;

    return newNode; // nouveau devient le dernier
}

// Affichage avant
void displayForward(Node* last) {
    if (last == NULL) {
        printf("Liste vide\n");
        return;
    }

    Node* temp = last->next; // tête
    printf("Avant: ");
    while (1) {
        printf("%d ", temp->data);
        temp = temp->next;
        if (temp == last->next) break;
    }
    printf("\n");
}

// Affichage arrière
void displayBackward(Node* last) {
    if (last == NULL) {
        printf("Liste vide\n");
        return;
    }

    Node* temp = last; // dernier
    printf("Arrière: ");
    while (1) {
        printf("%d ", temp->data);
        temp = temp->prev;
        if (temp == last) break;
    }
    printf("\n");
}

// Libérer mémoire
void freeList(Node** last) {
    if (*last == NULL) return;

    Node* current = (*last)->next;
    Node* nextNode;

    while (current != *last) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(*last);
    *last = NULL;
}

// Programme principal
int main() {
    Node* last = NULL;
    int choice, value, n, i;

    printf("Combien d'éléments voulez-vous dans la liste ? ");
    scanf("%d", &n);

    printf("Entrez les valeurs : \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        last = insertTail(last, value); // on construit en queue
    }

    printf("\nListe initiale :\n");
    displayForward(last);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insertion en tête\n");
        printf("2. Insertion en queue\n");
        printf("3. Afficher avant\n");
        printf("4. Afficher arrière\n");
        printf("5. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Valeur à insérer en tête: ");
                scanf("%d", &value);
                last = insertHead(last, value);
                displayForward(last);
                break;
            case 2:
                printf("Valeur à insérer en queue: ");
                scanf("%d", &value);
                last = insertTail(last, value);
                displayForward(last);
                break;
            case 3:
                displayForward(last);
                break;
            case 4:
                displayBackward(last);
                break;
            case 5:
                freeList(&last);
                printf("Mémoire libérée. Fin du programme.\n");
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while (choice != 5);

    return 0;
}
