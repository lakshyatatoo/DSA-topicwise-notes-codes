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
int checkVal(Node *head, int val)
{
    Node *mover = head;
    while (mover != nullptr)
    {
        if (mover->data == val)
        {
            return 1;
        }
        mover = mover->next;
    }
    return 0;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    checkVal(head, 3) ? cout << "Value found in the linked list." << endl : cout << "Value not found in the linked list." << endl;
    cout << endl;
    return 0;
}
