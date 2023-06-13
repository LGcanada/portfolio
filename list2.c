/* 4.Inserting Nodes into a Linked List
* File name: list2.c
* Date June 2023
* Author: Luis Gamboa 
* https://github.com/LGcanada
* Description: Heap= apilar inserts a new node to the head
*called simple Linked list
*/
#include<stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}Node;
/*Function definition*/
void print_list (Node *head);
Node *insert_at_tail(Node *head, int new_value);
Node *insert_at_head (Node *head, int new_value);

int main()
{
    Node *list1_head = NULL;// starts with an empty list
    list1_head = insert_at_head(list1_head, 7);
    list1_head = insert_at_head(list1_head, 5);
    list1_head = insert_at_head(list1_head, 3);
    list1_head = insert_at_tail(list1_head,10);
    list1_head = insert_at_tail(list1_head,12);
    list1_head = insert_at_tail(list1_head,14);


   
    print_list (list1_head);
}
/* 
*Function Name:insert_at_tail
* Description:   
*Parameters-Arg: Node *head, int new_value
* Returns: new_node
*/
Node *insert_at_tail(Node *head, int new_value)
{
    Node *new_node = calloc(1, sizeof(Node));
    new_node->value = new_value;
    if (head==NULL) return new_node;
    else
    {
        Node *current = head;
        while (current->next !=NULL) current = current->next; //traversing the list until the node is the tail
        current->next = new_node;
        return head;


    }


}
/* 
*Function Name:insert_at_head
* Description:   
*Parameters-Arg: Node *head, int new_value
* Returns: new_node
*/
Node *insert_at_head (Node *head, int new_value)
{
    Node *new_node = calloc(1, sizeof(Node)); // allocates space for one node
    new_node->value = new_value; 
    if (head==NULL) return new_node;
    else
    {
        new_node->next = head;
        return new_node;
    }

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

