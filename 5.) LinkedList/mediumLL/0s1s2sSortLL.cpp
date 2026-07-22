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

Node *bruteSort012(Node *head)
{
    Node *temp = head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    while (temp != nullptr)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else
            cnt2++;
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        if (cnt0)
        {
            temp->data = 0;
            cnt0--;
        }
        else if (cnt1)
        {
            temp->data = 1;
            cnt1--;
        }
        else
        {
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}

Node *optimalSort012(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *temp = head;
    Node *zH = new Node(-1);
    Node *oH = new Node(-1);
    Node *tH = new Node(-1);
    Node *z = zH;
    Node *o = oH;
    Node *t = tH;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            z->next = temp;
            z = z->next;
        }
        else if (temp->data == 1)
        {
            o->next = temp;
            o = o->next;
        }
        else
        {
            t->next = temp;
            t = t->next;
        }
        temp = temp->next;
    }
    z->next = (oH->next) ? oH->next : tH->next;
    o->next = tH->next;
    t->next = nullptr;
    Node* newHead = zH->next;
    delete zH;
    delete oH;
    delete tH;
    return newHead;
}

int main()
{
    vector<int> arr = {1, 2, 2, 0, 0};
    Node *head = convertToLL(arr);
    // head = bruteSort012(head);
    head = optimalSort012(head);
    printLL(head);
    return 0;
}
