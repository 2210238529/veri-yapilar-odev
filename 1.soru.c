#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* ekleNode(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

void tekCiftSiralama() {
    struct Node* head = NULL;
    int num;

    while (1) {
        printf("Bir sayi girin (cikis icin -1 giriniz): ");
        scanf("%d", &num);
        if (num == -1) {
            break;
        } else if (num % 2 == 1) { 
            head = ekleNode(head, num);
        } else {
            struct Node* temp = head;
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = num;
            newNode->next = NULL;
            if (head == NULL) {
                head = newNode;
            } else {
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }


    printf("Siralanmis Liste: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");


    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    tekCiftSiralama();
    return 0;
}
