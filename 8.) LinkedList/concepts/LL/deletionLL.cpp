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
Node *deleteHead(Node *head)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp; // for del head
    return head;
}
Node *deleteTail(Node *head)
{
    Node *temp = head;
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next; // for del tail
    temp->next = nullptr;
    // return temp;
    return head;
}
Node *deleteK(Node *head, int k)
{
    if (head == nullptr)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deleteVal(Node *head, int element)
{
    if (head == nullptr)
        return head;
    if (head->data == element)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {

        if (temp->data == element)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    head = deleteHead(head);
    // cout << head->data << endl;
    head = deleteTail(head); // for temp as tail rest alw
    // cout << head->data << endl;
    head = deleteK(head, 3);
    // cout << head->data << endl;
    head = deleteVal(head, 1);
    cout << head->data << endl;
    return 0;
}