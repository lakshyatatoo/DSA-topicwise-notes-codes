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

Node *bruteReverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *temp = head;
    stack<int> st;
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
Node *optimalReverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *temp = head;
    Node *prev = nullptr;
    Node *front = nullptr;
    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node *recursiveReverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *newHead = recursiveReverseLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    // head = bruteReverseLL(head);
    // head = optimalReverseLL(head);
    head = recursiveReverseLL(head);
    printLL(head);
    return 0;
}
