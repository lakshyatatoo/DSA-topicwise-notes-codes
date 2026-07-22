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

Node *bruteFindStartPointLoop(Node *head)
{
    map<Node *, int> mp;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (mp.find(temp) != mp.end())
        {
            return temp;
        }
        mp[temp] = 1;
        temp = temp->next;
    }
    return nullptr;
}

Node *optimalFindStartPointLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 8, 9};
    Node *head1 = convertToLL(arr1);
    // head1 = bruteDelMidEle(head1);
    head1 = optimalFindStartPointLoop(head1);
    printLL(head1);
    return 0;
}
