/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node
{
    int data;
    Node *next;
};

void traverse(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; // move to next node
    }
}

int main()
{
    Node *head = new Node{10, NULL};
    Node *second = new Node{20, NULL};
    Node *third = new Node{30, NULL};

    head->next = second;
    second->next = third;

    traverse(head);

    return 0;
}