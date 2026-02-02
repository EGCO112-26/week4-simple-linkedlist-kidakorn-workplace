//
//  node.h
//  simple linkedlist
//
//

#ifndef node_h
#define node_h

#define NAME_MAX 64

/* Student node used for exercises: id and name */
struct student {
    int id;
    char name[NAME_MAX];
    struct student *next;
};

#endif /* node_h */
