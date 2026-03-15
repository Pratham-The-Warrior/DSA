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

node *InsertNewNodeEND(node *head, int val)
{
    node *newNode = new node{val, NULL};

    if (head == NULL)
        return newNode;

    node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newNode;

    return head;
}

node *InsertNewNodeSTART(node *head, int val)
{
    node *newNode = new node{val, NULL};

    newNode->next = head;

    head = newNode;

    return head;
}

node *InsertNewNodeANYWHERE(node *head, int val, int pos)
{
    node *newNode = new node{val, NULL};

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
    }

    node *ptr = head;

    for (int i = 1; i < pos - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;

    return head;
}

node *deleteNode(node *head, int pos)
{

    if (head == NULL || pos <= 0)
        return head;

    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp; // this deletes the head location
        return head; // new updated hesd after deleteion
    }

    node *ptr = head;

    for (int i = 1; i < pos - 1; i++)
    {
        ptr = ptr->next;

        node *temp = ptr->next; // temporarily store the location of to be deleted node
        ptr->next = temp->next; // next of node which is goin to be deleted ko previous node mai add kkiya

        delete temp; // delete the location od node at pos

        return head;
    }
}

void traverse(node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{

    node *head = NULL;

    head = InsertNewNodeEND(head, 10);
    head = InsertNewNodeEND(head, 20);
    head = InsertNewNodeSTART(head, 30);
    head = InsertNewNodeEND(head, 40);
    head = InsertNewNodeANYWHERE(head, 50, 3);
    head = deleteNode(head, 3);

    traverse(head);
    return 0;
}