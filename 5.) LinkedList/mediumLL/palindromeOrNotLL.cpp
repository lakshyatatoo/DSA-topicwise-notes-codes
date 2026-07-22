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

bool brutePalindromeCheck(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;
    stack<int> st;
    Node *temp = head;
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        if (temp->data != st.top())
            return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

bool optimalPalindromeCheck(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;
    Node *slow = head;
    Node *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newNode = optimalReverseLL(slow->next);
    Node *first = head;
    Node *second = newNode;
    while (second != nullptr)
    {
        if (first->data != second->data)
        {
            optimalReverseLL(newNode);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    optimalReverseLL(newNode);
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    // head = bruteReverseLL(head);
    // head = optimalReverseLL(head);
    // head = recursiveReverseLL(head);
    cout << optimalPalindromeCheck(head) << endl;
    // printLL(head);
    return 0;
}
