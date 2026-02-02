#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

typedef struct student* StudentPtr;

/* function prototypes */
StudentPtr createNode(int id, char *name);
void insertEnd(StudentPtr *head, int id, char *name);
void printList(StudentPtr head);
void deleteList(StudentPtr *head);

int main(int argc, const char *argv[]) {

    StudentPtr head = NULL;

   
    for(int i = 1; i < argc; i += 2) {
        int id = atoi(argv[i]);
        char name[50];
        strcpy(name, argv[i+1]);

        insertEnd(&head, id, name);
    }

    printList(head);
    deleteList(&head);

    return 0;
}
StudentPtr createNode(int id, char *name) {
    StudentPtr newNode = (StudentPtr)malloc(sizeof(struct student));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void insertEnd(StudentPtr *head, int id, char *name) {
    StudentPtr newNode = createNode(id, name);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    StudentPtr temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
//
void printList(StudentPtr head) {
    StudentPtr temp = head;
    while (temp != NULL) {
        printf("%d %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

void deleteList(StudentPtr *head) {
    StudentPtr temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
