//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    if (argc < 3 || ((argc - 1) % 2) != 0) {
        fprintf(stderr, "Usage: %s id name [id name]...\n", argv[0]);
        return 1;
    }

    typedef struct student Student;
    Student *head = NULL, *tail = NULL;

    for (int i = 1; i < argc; i += 2) {
        int id = atoi(argv[i]);
        const char *name = argv[i + 1];

        Student *n = malloc(sizeof *n);
        if (!n) { perror("malloc"); return 1; }
        n->id = id;
        strncpy(n->name, name, NAME_MAX - 1);
        n->name[NAME_MAX - 1] = '\0';
        n->next = NULL;

        if (!head) head = tail = n;
        else { tail->next = n; tail = n; }
    }

    /* Print all data in the linked list */
    printf("Linked list contents:\n");
    Student *cur = head;
    while (cur) {
        printf("id=%d name=%s\n", cur->id, cur->name);
        cur = cur->next;
    }

    /* Delete / free all linked list nodes */
    cur = head;
    while (cur) {
        Student *next = cur->next;
        free(cur);
        cur = next;
    }

    return 0;
}

