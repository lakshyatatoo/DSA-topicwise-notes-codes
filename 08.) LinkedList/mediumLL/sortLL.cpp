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

Node *convertToLL(const vector<int> &arr)
{
    Node *head = new Node(arr[0], nullptr);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}




//brute
Node *bruteSortLL(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    return convertToLL(arr);
}


//optimal
Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *mergeSortedLL(Node *head1, Node *head2)
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
        temp->next = t1;
    else
        temp->next = t2;

    return dummy->next;
}

Node *sortLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *mid = findMid(head);
    Node *leftHead = head;
    Node *rightHead = mid->next;
    mid->next = nullptr;
    leftHead = sortLL(leftHead);
    rightHead = sortLL(rightHead);
    return mergeSortedLL(leftHead, rightHead);
}


