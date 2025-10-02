#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

Node* insertHead(Node* last, int data) {
    Node* newNode = createNode(data);
    
    if (last == NULL) {
        return newNode;
    }
    
    Node* head = last->next;
    
    newNode->next = head;
    newNode->prev = last;
    head->prev = newNode;
    last->next = newNode;
    
    return last;
}

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
    
    return newNode; // Nouveau dernier
}

void displayForward(Node* last) {
    if (last == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    Node* temp = last->next; // Premier élément
    printf("Avant: ");
    
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

void displayBackward(Node* last) {
    if (last == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    Node* temp = last;
    printf("Arrière: ");
    
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("\n");
}

void freeList(Node* last) {
    if (last == NULL) return;
    
    Node* current = last->next;
    Node* nextNode;
    
    while (current != last) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(last);
}

int main() {
    Node* last = NULL;
    int choice, value;
    
    do {
        printf("\n1. Insertion en tête\n");
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
                break;
            case 2:
                printf("Valeur à insérer en queue: ");
                scanf("%d", &value);
                last = insertTail(last, value);
                break;
            case 3:
                displayForward(last);
                break;
            case 4:
                displayBackward(last);
                break;
            case 5:
                freeList(last);
                break;
            default:
                printf("Choix invalide!\n");
        }
    } while (choice != 5);
    
    return 0;
}