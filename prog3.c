#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef Node* Liste;

// Créer un nouveau nœud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Erreur d'allocation");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insertion triée dans la liste doublement chaînée
Node* insertSorted(Node* head, int data) {
    Node* newNode = createNode(data);

    // Cas 1 : liste vide
    if (head == NULL) return newNode;

    // Cas 2 : insertion en tête
    if (data < head->data) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    // Cas 3 : insertion au milieu ou en fin
    Node* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    return head;
}

// Affichage avant
void displayForward(Node* head) {
    Node* temp = head;
    printf("Avant : ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Affichage arrière
void displayBackward(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;

    printf("Arrière : ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Libération mémoire
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Liste head = NULL;
    int n, value;

    printf("=== Création d'une liste doublement chaînée triée ===\n");

    // Lecture de la liste initiale
    printf("Combien d'éléments dans la liste initiale ? ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Entrez les valeurs en ordre croissant :\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &value);
            head = insertSorted(head, value);
        }
    }

    printf("\nListe initiale :\n");
    displayForward(head);
    displayBackward(head);

    // Insertion d'une nouvelle valeur
    printf("\nEntrez une nouvelle valeur à insérer : ");
    scanf("%d", &value);
    head = insertSorted(head, value);

    printf("\nListe après insertion :\n");
    displayForward(head);
    displayBackward(head);

    freeList(head);
    return 0;
}
