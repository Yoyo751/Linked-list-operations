#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory overflow: Unable to allocate new node.\n");
        return;
    }
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory overflow: Unable to allocate new node.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void traverseList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int totalElements, numElementsToInsert, data, numElementsToDelete;

    printf("Enter the total number of elements: ");
    scanf("%d", &totalElements);

    int remainingElements = totalElements;

    for (int i = 0; i < totalElements; i++) {
        printf("Enter number of elements to insert in cycle %d: ", i + 1);
        scanf("%d", &numElementsToInsert);

        if (numElementsToInsert > remainingElements) {
            printf("Cannot insert more than %d elements in this cycle.\n", remainingElements);
            numElementsToInsert = remainingElements;
        }

        for (int j = 0; j < numElementsToInsert; j++) {
            printf("Enter element %d: ", j + 1);
            scanf("%d", &data);

            if (i < 3) {
                insertAtBeginning(data);
            } else {
                insertAtEnd(data);
            }
        }

        remainingElements -= numElementsToInsert;

        if (remainingElements == 0) {
            break; 
        }
    }

    printf("Linked List after insertion:\n");
    traverseList();

    printf("Enter number of elements to delete: ");
    scanf("%d", &numElementsToDelete);

    for (int i = 0; i < numElementsToDelete; i++) {
        deleteFromBeginning();
    }

    printf("Linked List after deletion:\n");
    traverseList();

    return 0;
}