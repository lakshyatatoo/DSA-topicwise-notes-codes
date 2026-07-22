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
Node *insertAtHead(Node *head, int data)
{
    Node *temp = new Node(data, head);
    return temp;
}
Node *insertAtTail(Node *head, int data)
{
    if (head == nullptr)
    {
        Node *temp = new Node(data, nullptr);
        return temp;
    }
    Node *tempo = new Node(data, nullptr);
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = tempo;
    return head;
}
Node *insertAtKth(Node *head, int data, int k)
{
    if (head == nullptr)
    {
        if (k == 1)
        {
            Node *temp = new Node(data, nullptr);
            return temp;
        }
        else
        {
            return head;
        }
    }
    if (k == 1)
    {
        Node *temp = new Node(data, head);
        return temp;
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr) // for k>=2
    {
        cnt++;
        if (cnt == k - 1)
        {
            Node *tempo = new Node(data, temp->next);
            temp->next = tempo;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

Node *insertBeforeVal(Node *head, int data, int x)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->data == x)
    {
        return new Node(data, head);
    }
    Node *temp = head;
    bool flag = false;            // for checking if x is present in the linked list or not
    while (temp->next != nullptr) // for k>=2
    {
        if (temp->next->data == x)
        {
            Node *tempo = new Node(data, temp->next);
            temp->next = tempo;
            flag = true;
            return head;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);

    head = insertAtHead(head, 0);
    // cout<<head->data<<endl;
    head = insertAtTail(head, 6);
    // cout << head->data << endl;
    head = insertAtKth(head, 16, 3);
    // cout << head->data << endl;
    head = insertBeforeVal(head, 17, 4);
    cout << head->data << endl;

    Node *mover = head;
    while (mover->next != nullptr)
    {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;

    return 0;
}