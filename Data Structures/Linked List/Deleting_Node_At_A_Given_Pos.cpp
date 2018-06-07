#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct LLNode
{
    int data;
    struct LLNode* next;
};

void insert(LLNode** head_ref, int data)
{
    LLNode* node = new LLNode;
    node->data = data;
    node->next = (*head_ref);
    (*head_ref) = node;
}

void deleteNode(LLNode** head_ref, int pos)
{
    LLNode* current = *head_ref, *prev;
    int count = 0;
    
    while(current != NULL && pos == 0)
    {   
        (*head_ref) = current->next;
        free(current);
        return;
    }
    
    int c = 0;
    while(current != NULL && pos != c)
    {
        c++;
        prev = current;
        current = current->next;
    }
    
    if(current == NULL || pos > c)
        return;
    
    prev->next = current->next;
    free(current);
}

void printList(LLNode* head_ref)
{
    LLNode* current = head_ref;
    while(current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    LLNode* head = NULL;
    
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 5);
    insert(&head, 3);
    insert(&head, 4);
    
    deleteNode(&head, 2);
    printList(head);
    
    return 0;
}