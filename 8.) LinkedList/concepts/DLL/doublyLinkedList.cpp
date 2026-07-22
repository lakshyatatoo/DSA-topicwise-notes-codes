#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = NULL;
        back = NULL;
    }
};

Node *convertArrToDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node *deleteHead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *prev = head;
    head = head->next;
    prev->next = nullptr;
    head->back = nullptr;
    delete prev;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;
    prev->next = nullptr;
    delete tail;
    return head;
}

Node *deleteAtKth(Node *head, int k)
{
    Node *temp = head;

    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;
    if (front == nullptr)
    {
        return deleteTail(head);
    }
    else if (prev == nullptr)
    {
        return deleteHead(head);
    }
    else if (front == nullptr || prev == nullptr)
    {
        delete temp;
        return nullptr;
    }

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

void deleteNode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == nullptr)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    delete temp;
}

Node *insertAtHead(Node *head, int val)
{
    Node *temp = new Node(val, head, nullptr);
    head->back = temp;
    return temp;
}
Node *insertAtTail(Node *head, int val)
{
    if (head->next == nullptr)
    {
        insertAtHead(head, val);
        return head;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *nn = new Node(val, temp, prev);
    prev->next = nn;
    temp->back = nn;
    return head;
}

Node *insertAtkth(Node *head, int k, int val)
{
    Node *temp = head;
    int cnt = 0;
    if (k == 1)
    {
        return insertAtHead(head, val);
    }
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *nn = new Node(val, temp, prev);
    prev->next = nn;
    temp->back = nn;
    return head;
}

void insertAtNode(Node *node, int val)
{
    Node *prev = node->back;
    Node *nn = new Node(val, node, prev);
    prev->next = nn;
    node->back = nn;
}
void printDLL(Node *head)
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
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArrToDLL(arr);
    // cout << head->data << endl;
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteAtKth(head, 2);
    // deleteNode(head->next->next->next);
    head = insertAtHead(head, 0);
    head = insertAtTail(head, 44);
    head = insertAtkth(head, 3, 33);
    insertAtNode(head->next->next, 11);
    printDLL(head);

    return 0;
}