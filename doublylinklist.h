#include <bits/stdc++.h>
using namespace std;

class DoublyLinkedListNode
{
public:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;

    DoublyLinkedListNode(int node_data);
};

class DoublyLinkedList
{
public:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;
    
    DoublyLinkedList();
    void insert_node(int node_data);    

};


void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout);
void free_doubly_linked_list(DoublyLinkedListNode* node);
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data);