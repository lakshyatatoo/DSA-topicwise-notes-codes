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

void printLL(Node *head)
{
    Node *mover = head;
    while (mover != nullptr)
    {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
}

Node *bruteMege(Node *head1, Node *head2)
{
    vector<int> arr;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 != nullptr)
    {
        arr.push_back(temp1->data);
        temp1 = temp1->next;
    }
    while (temp2 != nullptr)
    {
        arr.push_back(temp2->data);
        temp2 = temp2->next;
    }
    sort(arr.begin(), arr.end());
    return convertToLL(arr);
}

Node *optimalMerge(Node *head1, Node *head2)
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

int main()
{
    vector<int> arr1 = {1, 2, 3, 8, 9};
    vector<int> arr2 = {4, 5, 6, 7, 10};
    Node *head1 = convertToLL(arr1);
    Node *head2 = convertToLL(arr2);
    Node *merged = bruteMege(head1, head2);
    printLL(merged);
    return 0;
}
