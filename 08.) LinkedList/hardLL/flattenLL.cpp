#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;

public:
    Node(int data1, Node *next1, Node *child1)
    {
        data = data1;
        next = next1;
        child = child1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        child = nullptr;
    }
};

Node *bruteFlattenLL(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *t1 = temp;
        while (t1 != nullptr)
        {
            arr.push_back(t1->data);
            t1 = t1->child;
        }
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    //use dummy node to create new linked list
    return head;
}

Node *mergeTwoNodes(Node *l1, Node *l2)
{
    Node *dummy = new Node(-1);
    Node *res = dummy;
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->data < l2->data)
        {
            res->child = l1;
            res = l1;
            l1 = l1->child;
        }
        else
        {
            res->child = l2;
            res = l2;
            l2 = l2->child;
        }
        res->next = nullptr;
    }
    if (l1 != nullptr)
    {
        res->child = l1;
    }
    if (l2 != nullptr)
    {
        res->child = l2;
    }
    return dummy->child;
}
Node *optimalRecursiveFlattenLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *mergeHead = optimalRecursiveFlattenLL(head->next);
    head = mergeTwoNodes(head, mergeHead);
    return head;
}
