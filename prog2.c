#include <stdio.h>
#include <stdlib.h>

// Définition d’un nœud de la liste
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Création d’un nouveau nœud
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insertion en fin de liste (pas forcément trié)
void insertEnd(Node** head, int value) {
    Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Tri de la liste simplement chaînée (méthode bubble sort)
void sortList(Node* head) {
    if (head == NULL) return;

    Node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // échange des valeurs
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Affichage de la liste
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Programme principal
int main() {
    Node* head = NULL;
    int n, val;

    printf("Combien d'elements voulez-vous inserer ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez la valeur %d : ", i+1);
        scanf("%d", &val);
        insertEnd(&head, val);  // insertion simple
    }

    printf("\nListe avant tri :\n");
    printList(head);

    // Tri de la liste pour corriger les positions
    sortList(head);

    printf("\nListe après tri :\n");
    printList(head);

    return 0;
}