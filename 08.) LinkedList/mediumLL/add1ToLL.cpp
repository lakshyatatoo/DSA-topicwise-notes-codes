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

Node *add1ToLL(Node *head)
{
    head = optimalReverseLL(head);
    Node *temp = head;
    int carry = 1;
    while (temp != nullptr)
    {
        temp->data = temp->data + carry;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {

            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if (carry == 1)
    {
        Node *newNode = new Node(carry);
        head = optimalReverseLL(head);
        newNode->next = head;
        return newNode;
    }
    head = optimalReverseLL(head);
    return head;
}
int helper(Node* temp){
    if(temp==nullptr) return 1;

    int carry=helper(temp->next);

    temp->data+=carry;

    if(temp->data<10){
        return 0;
    }
    temp->data=0;
    return 1;
}
Node *recursiveAdd1ToLL(Node *head)
{
  int carry=helper(head);

    if(carry==1){
        Node *newNode=new Node(carry);
        newNode->next=head;
        return newNode;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    Node *head = convertToLL(arr);
    printLL(head);
    head = add1ToLL(head);
    printLL(head);
    return 0;
}
