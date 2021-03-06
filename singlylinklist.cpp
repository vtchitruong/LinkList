#include <bits/stdc++.h>
#include "singlylinklist.h"

using namespace std;

// class of Node
SinglyLinkedListNode::SinglyLinkedListNode(int node_data)
{
    this->data = node_data;
    this->next = nullptr;
}

//--------------------------------------------------------
// class of List

SinglyLinkedList::SinglyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

void SinglyLinkedList::insert_node(int node_data)
{
    SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

    if (!this->head)
    {
        this->head = node;
    }
    else
    {
        this->tail->next = node;
    }
    this->tail = node;
}

//--------------------------------------------------------------
void free_singly_linked_list(SinglyLinkedListNode* node)
{
    while (node)
    {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

//------------------------------------------------------
// Output the list
void printLinkedList(SinglyLinkedListNode* head)
{
    cout << "Output the singly linked list:\n";
    for (SinglyLinkedListNode *p = head; p; p = p->next)
    {
        cout << p->data << "->";
    }
}

//--------------------------------------------------------
// Output the list in reversed order
void reversePrint(SinglyLinkedListNode* head)
{
    cout << "Output the singly linked list in reversed order:\n";
    if (head != nullptr)
    {
        reversePrint(head->next);
        cout << head->data << "->";
    }
}

//-----------------------------------------------------------
// Insert a node at the tail
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data)
{
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);    

    SinglyLinkedListNode *p;
    for (p = head; p->next != NULL; p = p->next);
    p->next = newNode;
    return head;   
}

//-----------------------------------------------------------
// Insert a node at the head
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* head, int data)
{
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    
    newNode->next = head;
    head = newNode;
    return head;
}

//-----------------------------------------------------------
// Insert a node at ad specific position
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position)
{
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    
    if (head == NULL)
    {
        head = newNode;
    }
    else {
        SinglyLinkedListNode *p = head;
        for (int i = 0; i < position - 1; ++i)
        {
            p = p->next;
        }
        
        newNode->next = p->next;
        p->next = newNode;
    }
    return head;    
}

//-----------------------------------------------------------
// Delete a node at a specific position
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position)
{
    if (head != nullptr)
    {
        if (position == 0)
        {
            SinglyLinkedListNode *tmpNode = head;
            head = head->next;
            free(tmpNode);
        }
        else {
            SinglyLinkedListNode *p = head;
            for (int i = 1; i < position; ++i)
            {
                p = p->next;
            }
            
            SinglyLinkedListNode *tmpNode = p->next;
            p->next = tmpNode->next;
            free(tmpNode);
        }        
    }    
    return head;
}

//-----------------------------------------------------------
// Compare 2 lists
// Equal: the same length and all data are equal
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
   
    while (head1 != nullptr && head2 != nullptr && head1->data == head2->data)
    {            
        head1 = head1->next;
        head2 = head2->next;            
    }
    return head1 == head2;
}

//--------------------------------------------------------------------------
// Merge 2 sorted lists into a single ascending-sorted list
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    if (head1 == nullptr)
    {
        return head2;
    }
    else
    {
        if (head2 == nullptr)
        {
            return head1;
        }
    }
    
    if (head1->data < head2->data)
    {
        head1->next = mergeLists(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = mergeLists(head1, head2->next);
        return head2;
    }  
}

//---------------------------------------------------------------------------------
// Get a node value at a specific position, in which the tail is at position 0, its parent is at 1 and so on.
int getNode(SinglyLinkedListNode* head, int positionFromTail)
{
    SinglyLinkedListNode *lead = head;
    SinglyLinkedListNode *follow = head;
    
    int distance = 0;
    while (lead != nullptr)
    {
        lead = lead->next;
        
        if (distance++ > positionFromTail)
        {
            follow = follow->next;            
        }
    }
    return follow->data; 
}


//----------------------------------------------------------------------------------
// If the lists share a common node, return that node's data value.
/*
[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
     [List #2] p--->q
*/

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{   
    SinglyLinkedListNode *pa= head1;
    SinglyLinkedListNode *pb = head2;
    
    while (pa != pb)
    {
        if (pa->next == nullptr)
        {
            pa = head2;
        }
        else
        {
            pa = pa->next;
        }
        
        if (pb->next == nullptr)
        {
            pb = head1;
        }
        else
        {
            pb = pb->next;
        }
        
    }
    
    return pa->data;
}

//----------------------------------------------------------------------
// delete duplicate-value nodes from a sorted linked list
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode *currentNode = head;
    SinglyLinkedListNode *followNode = currentNode->next;
    
    while (currentNode != nullptr)
    {
        while (followNode != nullptr && followNode->data == currentNode->data)
        {
            followNode = followNode->next;
        }
        
        // skip duplicate nodes
        currentNode->next = followNode;
        
        // jump to the node of new data
        currentNode = followNode;
    }
    
    return head;
}


//----------------------------------------------------------
// cycle detection
bool has_cycle(SinglyLinkedListNode* head)
{
    if (head == nullptr)
    {
        return 0;
    }
    
    SinglyLinkedListNode *slowNode = head;
    SinglyLinkedListNode *fastNode = head;
    
    while (fastNode != nullptr && fastNode->next != nullptr)
    {
        slowNode = slowNode->next;
        fastNode = (fastNode->next)->next;
        
        if (slowNode == fastNode)
        {
            return 1;
        }
    }
    return 0;
}

