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

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *dummy = new Node(-1);
    Node *current = dummy;
    Node *temp1 = num1;
    Node *temp2 = num2;
    int carry = 0;
    while (temp1 != nullptr || temp2 != nullptr)
    {
        int sum = carry;
        if (temp1 != nullptr)
            sum += temp1->data;
        if (temp2 != nullptr)
            sum += temp2->data;
        carry = sum / 10;
        Node *newNode = new Node(sum % 10);
        current->next = newNode;
        current = current->next;
        if (temp1 != nullptr)
            temp1 = temp1->next;
        if (temp2 != nullptr)
            temp2 = temp2->next;
    }
    if (carry)
    {
        Node *newNode = new Node(carry);
        current->next = newNode;
    }
    return dummy->next;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    head = addTwoNumbers(head, head);
    printLL(head);
    return 0;
}
