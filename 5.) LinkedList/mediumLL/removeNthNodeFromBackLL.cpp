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

Node *bruteRemoveNthNode(Node *head, int n)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    if (n == cnt)
    {
        Node *newHead = head->next;
        head->next = nullptr;
        delete head;
        return newHead;
    }
    int res = cnt - n;
    temp = head;
    while (temp != nullptr)
    {
        res--;
        if (res == 0)
            break;
        temp = temp->next;
    }
    Node *delNode = temp->next;
    temp->next = delNode->next;
    delNode->next = nullptr;
    delete delNode;
    return head;
}

Node *optimalRemoveNthNode(Node *head, int n)
{
    Node *fast = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if (fast == nullptr)
    {
        Node *newHead = head->next;
        head->next = nullptr;
        delete head;
        return newHead;
    }
    Node *slow = head;
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *delNode = slow->next;
    slow->next = delNode->next;
    delNode->next = nullptr;
    delete delNode;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 2, 0, 0};
    Node *head = convertToLL(arr);
    head = optimalRemoveNthNode(head, 2);
    printLL(head);
    return 0;
}
