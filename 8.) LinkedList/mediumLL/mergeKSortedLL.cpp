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
Node *covnertToLL(vector<int> &arr)
{
    if (arr.size() == 0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}
Node *mergeTwoLists(Node *head1, Node *head2)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    Node *t1 = head1;
    Node *t2 = head2;
    while (t1 != nullptr && t2 != nullptr)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if (t1 != nullptr)
    {
        temp->next = t1;
    }
    if (t2 != nullptr)
    {
        temp->next = t2;
    }
    return dummy->next;
}

Node *bruteKMerge(vector<Node *> &lists)
{
    vector<int> arr;

    for (int i = 0; i < lists.size(); i++)
    {
        Node *temp = lists[i];
        while (temp)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
    }
    if (arr.size() == 0)
        return nullptr;
    sort(arr.begin(), arr.end());
    Node *head = covnertToLL(arr);
    return head;
}

Node *betterKMerge(vector<Node *> list)
{
    Node *head = list[0];
    for (int i = 1; i < list.size(); i++)
    {
        head = mergeTwoLists(head, list[i]);
    }
    return head;
}

Node *optimalKMerge(vector<Node *> &list)
{
    priority_queue<pair<int, Node *>,
                   vector<pair<int, Node *>>,
                   greater<pair<int, Node *>>>
        pq;

    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] != nullptr)
        {
            pq.push({list[i]->data, list[i]});
        }
    }

    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        temp->next = it.second;
        temp = temp->next;

        if (it.second->next != nullptr)
        {
            pq.push({it.second->next->data, it.second->next});
        }
    }

    return dummy->next;
}


int main()
{
    return 0;
}
