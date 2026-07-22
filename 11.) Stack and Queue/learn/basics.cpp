#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
}

class stackInArray
{
    int arr[10];
    int top = -1;
    void push(int x)
    {
        top++;
        arr[top] = x;
    }
    void pop()
    {
        top--;
    }
    int top()
    {
        return arr[top];
    }
    int size()
    {
        return top + 1;
    }
};
class stackInVector
{
    vector<int> arr;
    int top = -1;

    void push(int x)
    {
        top++;
        arr.push_back(x);
    }
    void pop()
    {
        top--;
        arr.pop_back();
    }
    int top()
    {
        return arr[top];
    }
    int size()
    {
        return top + 1;
    }
};
class queueInArray
{
    int arr[10];
    int size = 10;
    int start = -1, end = -1, cs = 0;
    void push(int x)
    {
        if (cs == size)
        {
            cout << "Queue is full" << endl;
        }
        else if (cs == 0)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end++;
        }
        arr[end] = x;
        cs++;
    }
    int pop()
    {
        if (cs == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int element = arr[start];
        if (cs == 1)
        {
            start = -1;
            end = -1;
        }
        start++;
        cs--;
        return element;
    }
    int top()
    {
        if (cs == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[start];
    }
    int size()
    {
        return cs;
    }
};
class queueInVector
{
public:
    int syz = 10;
    vector<int> arr = vector<int>(10);
    int start = -1, end = -1, cs = 0;

    void push(int x)
    {
        if (cs == syz)
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (cs == 0)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % syz;
        }
        arr[end] = x;
        cs++;
    }
    int pop()
    {
        if (cs == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int element = arr[start];
        if (cs == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % syz;
        }
        cs--;
        return element;
    }
    int top()
    {
        if (cs == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[start];
    }
    int size()
    {
        return cs;
    }
};
class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
class stackInLinkedList
{

    Node *top = nullptr;
    int size = 0;
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    int top()
    {
        return top->data;
    }
    int size()
    {
        return size;
    }
};
class queueInLinkedList
{
    Node *start = nullptr;
    Node *end = nullptr;
    int size = 0;
    void push(int x)
    {
        Node *temp = new Node(x);
        if (start == nullptr)
        {
            start = end = temp;
        }
        else
        {
            end->next = temp;
            end = temp;
        }
        size++;
    }
    void pop()
    {
        if (start == nullptr)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = start;
        start = start->next;
        delete temp;
        size--;
    }
    int top()
    {
        if (start == nullptr)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return start->data;
    }
    int size()
    {
        return size;
    }
};
class stackInQueue
{
    queue<int> q;
    void push(int x)
    {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        if (q.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        q.pop();
    }
    int top()
    {
        if (q.empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();
    }
    int size()
    {
        return q.size();
    }
};
class queueInStackApproach1
{

    stack<int> s1, s2;
    void push(int x)
    {
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop()
    {
        if (s1.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        s1.pop();
    }
    int top()
    {
        if (s1.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return s1.top();
    }
    int size()
    {
        return s1.size();
    }
};
class queueInStackApproach2
{
    stack<int> s1, s2;
    void push(int x)
    {
        s1.push(x);
    }
    void pop()
    {
        if (!s2.empty())
        {
            s2.pop();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    int top()
    {
        if (!s2.empty())
        {
            return s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    int size()
    {
        return s1.size() + s2.size();
    }
};
