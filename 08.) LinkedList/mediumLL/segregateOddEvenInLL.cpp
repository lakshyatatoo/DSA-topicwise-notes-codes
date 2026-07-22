#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *bruteSegOddEven(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    vector<int> total;
    Node *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        total.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp != nullptr)
        total.push_back(temp->data);
    temp = head->next;
    while (temp != nullptr && temp->next != nullptr)
    {
        total.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp != nullptr)
        total.push_back(temp->data);

    int i = 0;
    temp = head;
    while (temp != nullptr)
    {
        temp->data = total[i];
        temp = temp->next;
        i++;
    }
    return head;
}
Node *optimalSegOddEven(Node *head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = even;
    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
