/* 7. Deleting a mathing node  from a Linked Lists (in the middle of the list)
* File name: list3.c
* Date June 2023
* Author: Luis Gamboa 
* https://github.com/LGcanada
* Description: Heap= apilar inserts a new node to the head
*called simple Linked list
*/
#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
bool is_member (Node *node, int find_value);
int count_matches (Node*node, int find_value);
void replace_matches (Node *node, int find_value,
                        int replace_value);
Node *delete_first_match(Node *head, int delete_value,
                                bool *was_deleted);
Node *delete_all_matches(Node *head, int delete_value,
                         int *num_deleted);


int main()
{
    /*inserting nodes*/
    Node *list1_head = NULL;// starts with an empty list
    list1_head = insert_at_head(list1_head, 7);
    list1_head = insert_at_head(list1_head, 5);
    list1_head = insert_at_head(list1_head, 3);
    list1_head = insert_at_head(list1_head, 5);
    list1_head = insert_at_head(list1_head, 5);
    list1_head = insert_at_head(list1_head, 3);
    
    printf("List before any deletions...\n");
    print_list(list1_head);
    bool deleted;
    list1_head =delete_first_match(list1_head, 3, &deleted);
    if (deleted)
        printf("A node with value 3 was deleted!\n");
    else
        printf("A node with value 3 was not deleted!\n");
    printf("List after any deletions...\n");
    print_list(list1_head);     
    list1_head =delete_first_match(list1_head, 8, &deleted);
    if (deleted)
        printf("A node with value 3 was deleted!\n");
    else
        printf("A node with value 3 was not deleted!\n");

}

/* 
*Function Name:replace_matches
* Description:  replaces matching values in a linked list with another value
*Parameters-Arg: Node *node, int find_value, int replace_value
* Returns: Nothing
*/

void replace_matches (Node *node, int find_value,
                        int replace_value)
{
    if (node !=NULL)
    {
        if (node->value ==find_value)
        node->value = replace_value;

        replace_matches(node->next, find_value,
                            replace_value);
    }

}
/* 
*Function Name:delete_all_matches
* Description:  Deleting a middle node 
*Parameters-Arg: Node *node, int find_value
* Returns: temp, NULL,head
*/
Node *delete_all_matches(Node *head, int delete_value,
                         int *num_deleted)
{
    Node *current = head;
    bool deleted = false;
    *num_deleted = 0;

    do 
    {
        current = delete_first_match(current, delete_value, 
                                 &deleted);
        if (deleted) *num_deleted = *num_deleted + 1;
    } while (deleted);

    return current;
}
/* 
*Function Name:delete_first_match
* Description:  Deleting a middle node 
*Parameters-Arg: Node *node, int find_value
* Returns: temp, NULL,head
*/
Node *delete_first_match(Node *head, int delete_value,
                                bool *was_deleted)
{
    if (head ==NULL) // if the list is empty, return false
    {
        *was_deleted = false;
        return NULL;
    }

    if (head->value == delete_value)
    {
        Node * temp = head->next;
        free(head);
        *was_deleted = true;
        return temp;
    }

    Node *current = head-> next; // for the node after the head
    Node *prev = head;

    while (current != NULL) // traversing the list
    {
        if (current->value == delete_value)
        {
            prev->next = current->next;
            free(current);
            *was_deleted = true;
            return head;

        }    

        prev = current;
        current = current->next;
    }
        *was_deleted = false;
        return head;


}






/* 
*Function Name:count_matches
* Description:  counting the number of nodes with a matching value 
*Parameters-Arg: Node *node, int find_value
* Returns: boolean
*/
int count_matches (Node*node, int find_value)
{
    if (node==NULL) return 0; //base case
    else if (node->value == find_value)
        return 1+ count_matches(node->next, find_value);
    else return count_matches(node->next, find_value);    
}

/* 
*Function Name:is_member
* Description:  searching a value that matches the linked list
*Parameters-Arg: Node *node, int find_value
* Returns: boolean
*/

bool is_member (Node *node, int find_value)
{
    if (node ==NULL) return false;// empty list case
    else if (node->value == find_value) return true; 
    else return is_member (node->next, find_value);


}

/* 
*Function Name:length
* Description:  how many elements has the linked list
*Parameters-Arg: Node *head
* Returns: length
*/
int length(Node*head)
{
    Node *current;
    current = head;
    int length = 0;
    while (current != NULL)
    {
        length++;
        current =current->next;

    }
    return length;

}
/* 
*Function Name:recursive_length
* Description: calls itself or recursive itself plus based case  
*Parameters-Arg: Node *head
* Returns: head / NULL
*/
int recursive_length(Node *node)
{
    if (node== NULL ) return 0;// based case returns 0
    else return 1+ recursive_length(node->next); //function calling itself+
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

