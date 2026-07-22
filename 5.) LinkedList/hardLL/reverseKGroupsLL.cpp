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

Node *optimalReverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node *findKth(Node *temp, int k)
{
    k -= 1;
    while (temp != nullptr && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

// above are for declarationa and reversal

Node *groupK(Node *head, int k)
{
    Node *temp = head;
    Node *nextNode = nullptr;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        Node *kNode = findKth(temp, k);
        if (kNode == nullptr)
        {
            if (prev)
            {
                prev->next = temp;
            }
            break;
        }
        nextNode = kNode->next;
        kNode->next = nullptr;
        Node *newHead = optimalReverseLL(temp);
        if (temp == head)
            head = newHead;
        else
            prev->next = newHead;
        prev = temp;
        temp = nextNode;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    // head = bruteReverseLL(head);
    // head = optimalReverseLL(head);
    // head = recursiveReverseLL(head);
    printLL(head);
    return 0;
}
