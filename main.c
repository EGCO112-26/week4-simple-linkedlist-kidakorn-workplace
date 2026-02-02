//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,*head ;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    struct node d;
    b.next =&d;
    d.value=11;
    d.next=NULL;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    printf("%d\n", head ->next->next->value ); //what value for 11
   
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */

 printf("insert in front\n");
 struct node e;//start at 2
    e.value=2;
    e.next=&a;
    head=&e;    


 struct node f;
 f.value=7;
    f.next=&b;
    a.next=&f;
 printf("%d\n", head ->value ); //what value for 2
    printf("%d\n", head ->next->value ); //what value for 5
    printf("%d\n", head ->next->next->value ); //what value for 7
    printf("%d\n", head ->next->next->next->value ); //what value for 8
    printf("%d\n", head ->next->next->next->next->value ); //what value for 11
   
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        printf("print using loop\n");
        //use loop to print all value
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
            tmp=tmp->next; 

        }
        printf("\n");   
        
    /*  Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }
    */
    
   /*  Exercise IV change to while loop!! (you can use NULL to help) */
       
         while(tmp!=NULL){
            printf("%3d", tmp->value);
            tmp=tmp->next; // What is missing???
        }
    
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
     */
        printf("\nCreate all nodes using malloc\n");
        typedef struct node* NodePtr;
        NodePtr temp;
        head=(NodePtr) malloc (sizeof(struct node));
        temp=head;
        n=5;
        for(i=0;i<n;i++){
            temp->value=7+i*2; // 5,7,9,11,13
            temp->next=(NodePtr) malloc (sizeof(struct node));
            temp=temp->next;
            
        }
        temp->value=7+i*2; //terminate value
        temp->next=NULL; //terminate next

        //printf("print using while loop\n");
        temp=head;
        while(temp!=NULL){
            printf("%3d", temp->value);
            temp=temp->next; // What is missing???
            printf("\n");   
            
        }

        // Free all nodes
        while(head != NULL) {
            NodePtr temp = head;
            head = head->next;
            free(temp);
        }
    return 0;
    }

