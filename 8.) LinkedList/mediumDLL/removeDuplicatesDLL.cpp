#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = NULL;
        prev = NULL;
    }
};

Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        Node *nextNode = temp->next;
        while (nextNode != nullptr && nextNode->data == temp->data)
        {
            Node *duplicate = nextNode;
            nextNode = nextNode->next;
            duplicate->next = nullptr;
            duplicate->prev = nullptr;
            delete duplicate;
        }
        temp->next = nextNode;
        if (nextNode != nullptr)
        {
            nextNode->prev = temp;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    return 0;
}