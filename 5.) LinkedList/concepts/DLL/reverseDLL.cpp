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

void bruteReverseDLL(Node *head)
{
    Node *temp = head;
    Node *temp2 = head;
    stack<int> st;
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    while (temp2 != nullptr)
    {
        temp2->data = st.top();
        st.pop();
        temp2 = temp2->next;
    }
}
Node *optimalReverseDLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *prev = nullptr;
    Node *current = head;
    while (current != nullptr)
    {
        prev = current->back;
        current->back = current->next;
        current->next = prev;
        current = current->back;
    }
    return prev->back;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArrToDLL(arr);
    // bruteReverseDLL(head);
    head = optimalReverseDLL(head);
    cout << head->data << endl;
    printDLL(head);

    return 0;
}