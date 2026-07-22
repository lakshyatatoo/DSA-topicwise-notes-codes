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

// to return a node ie head of LL
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
int length(Node *head)
{
    int count = 0;
    Node *mover = head;
    while (mover != nullptr)
    {
        count++;
        mover = mover->next;
    }
    return count;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    Node *mover = head;
    // while mover not null print the data and move to next node
    while (mover->next != nullptr)
    { // for saferty direct safe too
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
    cout << "Length of the linked list: " << length(head) << endl;
    return 0;
}
