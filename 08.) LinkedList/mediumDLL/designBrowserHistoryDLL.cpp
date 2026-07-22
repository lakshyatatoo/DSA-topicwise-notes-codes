#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string data;
    Node *next;
    Node *prev;

    Node(string data1, Node *next1 = nullptr, Node *prev1 = nullptr)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

class Browser
{
public:
    Node *current;
    Browser(string homepage)
    {
        current = new Node(homepage);
    }
    void visit(string url)
    {
        Node *temp = current->next;
        while (temp != nullptr)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        current->next = nullptr;

        Node *newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    string back(int steps)
    {
        while (current->prev != nullptr && steps > 0)
        {
            current = current->prev;
            steps--;
        }

        return current->data;
    }
    string forward(int steps)
    {
        while (current->next != nullptr && steps > 0)
        {
            current = current->next;
            steps--;
        }
        return current->data;
    }
};

int main()
{
    return 0;
}