#include <bits/stdc++.h>
#include "doublylinklist.h"

using namespace std;

//class DoublyLinkedListNode;

DoublyLinkedListNode::DoublyLinkedListNode(int node_data)
{
    this->data = node_data;
    this->next = nullptr;
    this->prev = nullptr;
}

//class DoublyLinkedList;  

DoublyLinkedList::DoublyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

void DoublyLinkedList::insert_node(int node_data)
{
    DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

    if (!this->head) {
        this->head = node;
    } else {
        this->tail->next = node;
        node->prev = this->tail;
    }

    this->tail = node;
}


void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout)
{
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}


void free_doubly_linked_list(DoublyLinkedListNode* node)
{
    while (node)
    {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}



DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data)
{
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
    
    if (head == nullptr)
    {        
        head = newNode;
    }
    else
        if (data < head->data)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else        
        {
            DoublyLinkedListNode *p = head;
            
            while (p->next != nullptr)
            {
                if (p->next->data < data) p = p->next; else break;
            }
            
            if (p->next == nullptr)
            {
                p->next =  newNode;
                newNode->prev = p;
            }
            else
            {                
                newNode->next = p->next;
                newNode->prev = p;
                (p->next)->prev = newNode;
                p->next = newNode;
            }
        }
    return head;
}

//--------------------------------------------------------------------
// reverse the doubly-linked list
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head)
{
    DoublyLinkedListNode *newHead;    
    DoublyLinkedListNode *p1 = head;
    
    while (p1 != nullptr)
    {
        // init
        DoublyLinkedListNode *p2 = p1->prev;
        
        // modify p1
        p1->prev = p1->next;
        p1->next = p2;        
        
        // set newHead;
        newHead = p1;
        
        // go on
        p1 = p1->prev;
    }
    
    return newHead;
}
