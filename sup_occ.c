#include <stdio.h>
#include <stdlib.h>

typedef struct noued {
    int val;
    struct noued *suiv;
}noued;

typedef struct liste {
    noued* tete;
}liste;

void insert(liste *L , int val){
    noued *element = (noued*)malloc(sizeof(noued));
    
    element->val = val;
    element->suiv = L->tete;
    L->tete = element;
}

void vider_liste(liste *L) {
    noued *current = L->tete;
    while (current != NULL) {
        noued *next = current->suiv;
        free(current);
        current = next;
    }
    L->tete = NULL;
}

void afficher_liste(liste *L) {
    noued *current = L->tete;
    printf("Liste: ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->suiv;
    }
    printf("\n");
}

int main(){
    int n,x,sup;
    liste *L = (liste*)malloc(sizeof(liste));
    L->tete = NULL;
    
    printf("entrer le nombre d'éléments de votre liste: ");
    scanf("%d",&n);
    
    printf("entrer les valeurs : \n");
    for (int i = 0; i < n; i++) {
        scanf("%d",&x);
        insert(L,x);
    }
    
    printf("entrer la valeur a supprimé : ");
    scanf("%d",&sup);
    
    //supprimer toute les occurence de sup
    noued *current = L->tete, *prev = NULL;
    while(current != NULL){
        if(current->val == sup){
            noued* temp = current;
            if(prev == NULL){
                L->tete = current->suiv;
            }else{
                prev->suiv = current->suiv;
            }
            current = current->suiv;
            free(temp);
        }else{
            prev = current;
            current = current->suiv;
        }
    }
    
    printf("Liste apres suppression : ");
    afficher_liste(L);
    
    vider_liste(L);
    free(L);
    
    return 0;
}