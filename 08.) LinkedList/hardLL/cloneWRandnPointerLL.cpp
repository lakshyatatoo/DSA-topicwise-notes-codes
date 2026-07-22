#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;

public:
    Node(int data1, Node *next1, Node *random1)
    {
        data = data1;
        next = next1;
        random = random1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        random = nullptr;
    }
};

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

Node *convertToLL(const vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *nn = new Node(arr[i]);
        temp->next = nn;
        temp = nn;
    }
    return head;
}

Node *bruteClone(Node *head)
{
    unordered_map<Node *, Node *> mp;
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *nn = new Node(temp->data);
        mp[temp] = nn;
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        Node *copyNode = mp[temp];
        copyNode->next = mp[temp->next];
        copyNode->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
}
Node *optimalClone(Node *head)
{
    // can create 3 fucntion but call here only
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *nn = new Node(temp->data);
        nn->next = temp->next;
        temp->next = nn;
        temp = temp->next->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        Node *copyNode = temp->next;
        copyNode->random = (temp->random != nullptr) ? temp->random->next : nullptr;
        temp = temp->next->next;
    }
    temp = head;
    Node *dNode = new Node(-1);
    Node *res = dNode;
    while (temp != nullptr)
    {
        res->next = temp->next;
        res = res->next;
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dNode->next;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    printLL(head);
    return 0;
}
