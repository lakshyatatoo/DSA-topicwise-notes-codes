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

Node *deleteKeyOcc(Node *head, int key)
{
    if (head == nullptr)
    {
        return head;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            if (temp == head)
                head = head->next;
            Node *back = temp->prev;
            Node *front = temp->next;
            if (!back)
                back->next = front;
            if (!front)
                front->prev = back;
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;
            temp = front;
        }
        else
        {
            temp = temp->next;
        }
        return head;
    }
}

int main()
{
    return 0;
}