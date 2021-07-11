#include <bits/stdc++.h>
using namespace std;

// class of Node
class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data);
};

//--------------------------------------------------------
// class of List
class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList();
    void insert_node(int node_data);
};

void free_singly_linked_list(SinglyLinkedListNode* node);

// Output the list
void printLinkedList(SinglyLinkedListNode* head);

// Output the list in reversed order
void reversePrint(SinglyLinkedListNode* head);

// Insert a node at the tail
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data);

// Insert a node at the head
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* head, int data);

// Insert a node at ad specific position
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position);

// Delete a node at a specific position
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position);

// Compare 2 lists
// Equal: the same length and all data are equal
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);

// Merge 2 sorted lists into a single ascending-sorted list
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);

// Get a node value at a specific position, in which the tail is at position 0, its parent is at 1 and so on.
int getNode(SinglyLinkedListNode* head, int positionFromTail);

// If the lists share a common node, return that node's data value.
/*
[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
     [List #2] p--->q
*/
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);

// delete duplicate-value nodes from a sorted linked list
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head);


// cycle detection
// 1->2->3->null --> Output: 0, means no cycle
// 1->2->3->1->null --> Output: 1, means a cycle
bool has_cycle(SinglyLinkedListNode* head);