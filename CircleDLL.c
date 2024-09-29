#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* NN = (Node*)malloc(sizeof(Node));
    if (NN == NULL) {
        printf("List overflow...\n");
        exit(1);
    }
    NN->data = data;
    NN->next = NN;
    NN->prev = NN;
    return NN;
}

void insert_beginning(Node** start, int data) {
    Node* NN = createNode(data);
    if (*start == NULL) {
        *start = NN;
    } else {
        Node* last = (*start)->prev;
        NN->next = *start;
        NN->prev = last;
        last->next = NN;
        (*start)->prev = NN;
    }
    *start = NN;
}

void insert_middle(Node** start, int data, int position) {
    if (position < 0) {
        printf("Invalid position...\n");
        return;
    }
    if (position == 0) {
        insert_beginning(start, data);
        return;
    }
    Node* NN = createNode(data);
    Node* temp = *start;
    for (int i = 0; i < position - 1 && temp->next != *start; i++) {
        temp = temp->next;
    }
    if (temp->next == *start && position > 1) {
        printf("Incorrect position...\n");
        free(NN);
        return;
    }
    NN->next = temp->next;
    NN->prev = temp;
    temp->next->prev = NN;
    temp->next = NN;
}

void insert_end(Node** start, int data) {
    if (*start == NULL) {
        insert_beginning(start, data);
    } else {
        Node* NN = createNode(data);
        Node* last = (*start)->prev;
        last->next = NN;
        NN->prev = last;
        NN->next = *start;
        (*start)->prev = NN;
    }
}

void delete_beginning(Node** start) {
    if (*start == NULL) {
        printf("List underflow.\n");
        return;
    }
    Node* temp = *start;
    if (temp->next == *start) {
        free(temp);
        *start = NULL;
    } else {
        Node* last = temp->prev;
        *start = temp->next;
        last->next = *start;
        (*start)->prev = last;
        free(temp);
    }
}

void delete_middle(Node** start, int position) {
    if (*start == NULL) {
        printf("List underflow.\n");
        return;
    }
    if (position == 0) {
        delete_beginning(start);
        return;
    }
    Node* temp = *start;
    for (int i = 0; i < position && temp->next != *start; i++) {
        temp = temp->next;
    }
    if (temp->next == *start && position > 0) {
        printf("Incorrect position.\n");
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void delete_end(Node** start) {
    if (*start == NULL) {
        printf("List underflow.\n");
        return;
    }
    Node* last = (*start)->prev;
    if (last == *start) {
        free(last);
        *start = NULL;
    } else {
        Node* secondLast = last->prev;
        secondLast->next = *start;
        (*start)->prev = secondLast;
        free(last);
    }
}

void display(Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = node;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != node);
    printf("(back to start)\n");
}

int main() {
    Node* start = NULL;
    int val, position, optn;
    char contn;

    printf("Circular Doubly Linked List:\n Insert:\n  1- Beginning.\n  2- Middle.\n  3- End.\n Delete:\n  4- Beginning.\n  5- Middle.\n  6- End.\n  7- Display.\n\n");

    do {
        printf("Enter option: ");
        scanf("%d", &optn);

        switch (optn) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_beginning(&start, val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &position);
                insert_middle(&start, val, position);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_end(&start, val);
                break;
            case 4:
                delete_beginning(&start);
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &position);
                delete_middle(&start, position);
                break;
            case 6:
                delete_end(&start);
                break;
            case 7:
                printf("Circular Doubly Linked List display:\n");
                display(start);
                break;
            default:
                printf("Incorrect option...\n");
                break;
        }
        printf("Do you want to continue(Y/N): ");
        scanf(" %c", &contn);
    } while (contn == 'Y' || contn == 'y');

    printf("\nProgram terminated successfully...\n");

    return 0;
}
