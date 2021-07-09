#include <bits/stdc++.h>

using namespace std;

// class of Node
class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

//--------------------------------------------------------
// class of List
class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        } else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

void printLinkedList(SinglyLinkedListNode* head)
{
    cout << "\nOutput the singly linked list:\n";
    for (SinglyLinkedListNode *p = head; p; p = p->next)
    {
        cout << p->data << "->";
    }
}




bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    bool res = true;
    
    
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1 == nullptr || head2 == nullptr || head1->data != head2->data)
        {
            return false;
        }
            
        head1 = head1->next;
        head2 = head2->next;            
    }
    return res;
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    printLinkedList(llist->head);

    return 0;
}