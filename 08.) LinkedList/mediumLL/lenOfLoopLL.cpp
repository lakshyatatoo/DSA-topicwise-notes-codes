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

int bruteFindlen(Node *head)
{
    map<Node *, int> mp;
    Node *temp = head;
    int timer = 0;
    while (temp != nullptr)
    {
        if (mp.find(temp) != mp.end())
        {
            return timer - mp[temp];
        }
        mp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}
int findLen(Node *slow, Node *fast)
{
    int cnt = 1;
    fast = fast->next;
    while (slow != fast)
    {
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

int OptimalFindlen(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return findLen(slow, fast);
    }
    return 0;
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

int main()
{
    vector<int> arr1 = {1, 2, 3, 7, 8, 9};
    Node *head1 = convertToLL(arr1);
    cout << OptimalFindlen(head1) << endl;
    return 0;
}
