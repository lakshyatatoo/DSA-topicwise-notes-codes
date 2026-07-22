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

class LinkedList
{
    // to return a node ie head of LL
public:
    static Node *convertToLL(const vector<int> &arr)
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
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = LinkedList::convertToLL(arr);
    cout << head->data << endl;
    return 0;
}
