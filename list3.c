/* 5.Deleting Nodes from Linked List
* File name: list3.c
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
Node *delete_at_head(Node *head);
Node *delete_at_tail(Node *head);

int main()
{
    /*inserting nodes*/
    Node *list1_head = NULL;// starts with an empty list
    list1_head = insert_at_head(list1_head, 7);
    list1_head = insert_at_head(list1_head, 5);
    list1_head = insert_at_head(list1_head, 3);
    list1_head = insert_at_tail(list1_head,10);
    list1_head = insert_at_tail(list1_head,12);
    list1_head = insert_at_tail(list1_head,14);

    /*deleting */
    printf("Before delete...\n\n");
    print_list (list1_head);
    list1_head = delete_at_tail(list1_head);
   
    printf("After delete...\n\n");
    print_list (list1_head);
}

/* 
*Function Name:delete_at_tail
* Description:   
*Parameters-Arg: Node *head
* Returns: head / NULL
*/
Node *delete_at_tail(Node *head)
{
    if (head ==NULL) return NULL;
    else if (head->next ==NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        Node *current = head;
        Node *prev = NULL;

        while (current->next !=NULL)
        {
            prev = current;
            current = current->next;
        }

        prev->next = NULL;
        free(current);
        return head;


    }





}
/* 
*Function Name:delete_at_head
* Description:   
*Parameters-Arg: Node *head
* Returns: to_return / NULL
*/

Node *delete_at_head(Node *head)
{
    if (head ==NULL) return NULL;
    else
    {
        Node *to_return = head->next;
        free(head); //makes memory available again
        return to_return;
    }
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

