/* 3.Creating a Printing Linked List with stacks
* File name: list.c
* Date June 2023
* Author: Luis Gamboa 
* https://github.com/LGcanada
* Description: This program implements the data structure 
*called simple Linked list
*/
#include<stdio.h>


typedef struct node{
    int value;
    struct node *next;
}Node;
/*Function definition*/
void print_list (Node *head);

int main()
{
    Node a,b,c;
    a.value = 5;
    b.value = 6;
    c.value = 7;
    a.next =&b; //gets the memory address of b or a points to b.
    b.next =&c; // gives the memory address of c or b points to c.
    c.next = NULL; // c points to nothing or it is the tail.
    print_list( &a ); //  prints memory address of a
}

/* 
*Function Name:print_list
* Description: Traversing the list  
* Returns: Nothing
*/
void print_list (Node *head)
{
    Node *current; //pointer to a node
    current = head;

    int i = 0;    
    while (current !=NULL)
    {
        printf("Node: %d: %d\n",i, current->value);
        i++;
        current = current ->next;// points to the struct
    }

}