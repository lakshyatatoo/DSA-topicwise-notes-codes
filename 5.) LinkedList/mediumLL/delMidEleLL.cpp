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

Node *bruteDelMidEle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    int mid = cnt / 2;
    temp = head;
    while (temp != nullptr)
    {
        mid--;
        if (mid == 0)
        {
            Node *midEle = temp->next;
            temp->next = temp->next->next;
            delete midEle;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node *optimalDelMidEle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *slow = head;
    Node *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *midEle = slow->next;
    slow->next = slow->next->next;
    delete midEle;
    return head;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 8, 9};
    Node *head1 = convertToLL(arr1);
    // head1 = bruteDelMidEle(head1);
    head1 = optimalDelMidEle(head1);
    printLL(head1);
    return 0;
}
