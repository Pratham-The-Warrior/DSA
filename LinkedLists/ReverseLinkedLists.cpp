/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
    int data;
    node *next;
};

node *insertEnd(node *head, int val)
{
    node *newNode = new node{val, NULL};

    if (head == NULL)
        return newNode;

    node *ptr = head;

    while (ptr->next)
        ptr = ptr->next;

    ptr->next = newNode;

    return head;
}

// Traverse list
void traverse(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *ReverseLinkedLists(node *head)
{

    // 1->2->3->4
    // 4->3->2->1
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next; // store next node
        curr->next = prev; // reverse pointer
        prev = curr;       // move prev forward
        curr = next;       // move curr forward
    }
    return prev; // last node
}

int main()
{
    node *head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    traverse(head);

    head = ReverseLinkedLists(head);

    traverse(head);
}