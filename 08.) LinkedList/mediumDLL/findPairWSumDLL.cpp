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

vector<pair<int, int>> bruteFindPair(Node *head, int target)
{
    Node *temp1 = head;
    vector<pair<int, int>> res;
    while (temp1 != nullptr)
    {
        Node *temp2 = temp1->next;
        while (temp2 != nullptr)
        {
            if (temp1->data + temp2->data == target)
            {
                res.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return res;
}

Node *findTail(Node *head)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    return temp;
}
vector<pair<int, int>> optimalFindPair(Node *head, int target)
{
    vector<pair<int, int>> res;
    Node *left = head;
    Node *right = findTail(head);
    while (left != right && right->next != left)
    {

        if (left->data + right->data == target)
        {
            res.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < target)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    return res;
}
int main()
{
    return 0;
}