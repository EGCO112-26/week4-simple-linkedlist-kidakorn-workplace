// node.h
#ifndef NODE_H
#define NODE_H

struct student {
    int id;
    char name[50];
    struct student *next;
};

#endif
