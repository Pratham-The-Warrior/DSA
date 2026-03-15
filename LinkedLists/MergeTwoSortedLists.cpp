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

void traverse(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *mergeSortedLists(node *head1, node *head2)
{

    node temp;

    node *tail = &temp;
    temp.next = NULL;

    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if (head1)
        tail->next = head1;
    if (head2)
        tail->next = head2;

    return temp.next;
}

int main()
{

    node *head1 = NULL;
    node *head2 = NULL;

    // First sorted list
    head1 = insertEnd(head1, 10);
    head1 = insertEnd(head1, 30);
    head1 = insertEnd(head1, 50);

    // Second sorted list
    head2 = insertEnd(head2, 20);
    head2 = insertEnd(head2, 40);
    head2 = insertEnd(head2, 60);

    node *merged = mergeSortedLists(head1, head2);

    traverse(merged);
}