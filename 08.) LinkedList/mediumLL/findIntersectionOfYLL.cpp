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

Node *bruteFindIntersection(Node *head1, Node *head2)
{
    map<Node *, int> mp;
    Node *temp = head1;
    while (temp != nullptr)
    {
        mp[temp] = 1;
        temp = temp->next;
    }
    temp = head2;
    while (temp != nullptr)
    {
        if (mp.find(temp) != mp.end())
            return temp;

        temp = temp->next;
    }
    return nullptr;
}

Node *collisionPoint(Node *small, Node *large, int d)
{
    while (d--)
    {
        large = large->next;
    }
    while (small != large)
    {
        small = small->next;
        large = large->next;
    }
    return small;
}
Node *betterFindIntersection(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    int n1 = 0, n2 = 0;
    while (temp1 != nullptr)
    {
        n1++;
        temp1 = temp1->next;
    }
    while (temp2 != nullptr)
    {
        n2++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    if (n1 < n2)
    {
        collisionPoint(temp1, temp2, n2 - n1);
    }
    else
    {
        collisionPoint(temp2, temp1, n1 - n2);
    }
}

Node *optimalFindIntersection(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
    {
        return nullptr;
    }

    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 != temp2)
    {

        temp1 = (temp1 == nullptr) ? head2 : temp1->next;
        temp2 = (temp2 == nullptr) ? head1 : temp2->next;
    }

    return temp1; // This will be the intersection node or nullptr if there is no intersection
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 7, 8, 9};
    vector<int> arr2 = {4, 5, 6, 7, 8, 9}; // this will work with us assuming that both linked list are linking to the same node in memory and not just having same values. So we will create a common linked list and then link both the linked list to it.
    Node *head1 = convertToLL(arr1);
    Node *head2 = convertToLL(arr2);
    return 0;
}
