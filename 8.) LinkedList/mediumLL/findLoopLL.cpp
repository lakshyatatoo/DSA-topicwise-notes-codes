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
bool bruteFindLoop(Node *head)
{
    map<Node *, int> mp;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (mp.find(temp) != mp.end())
        {
            return true;
        }
        mp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

bool OptimalFindLoop(Node *head)
{
    if (head == nullptr)
    {
        return false;
    }
    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 7, 8, 9};
    Node *head1 = convertToLL(arr1);
    cout << OptimalFindLoop(head1) << endl;
    return 0;
}
