#include <bits/stdc++.h>
using namespace std;

// optimal only
class LRUCache
{
public:
    struct Node
    {
        int key;
        int data;
        Node *next;
        Node *back;

    public:
        Node(int key1, int data1, Node *next1, Node *back1)
        {
            key = key1;
            data = data1;
            next = next1;
            back = back1;
        }

    public:
        Node(int key1, int data1)
        {
            key = key1;
            data = data1;
            next = NULL;
            back = NULL;
        }
    };
    void delNode(Node *temp)
    {
        Node *after = temp->next;
        Node *prevNode = temp->back;
        prevNode->next = after;
        after->back = prevNode;
    }
    void nodeAfterHead(Node *temp)
    {
        Node *after = head->next;
        head->next = temp;
        temp->back = head;
        temp->next = after;
        after->back = temp;
    }

    unordered_map<int, Node *> mp;
    int capacity = 0;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->back = head;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        Node *temp = mp[key];
        delNode(temp);
        nodeAfterHead(temp);
        return temp->data;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            node->data = value;
            delNode(node);
            nodeAfterHead(node);
        }
        else
        {
            if (mp.size() == capacity)
            {
                Node *node = tail->back;
                mp.erase(node->key);
                delNode(node);
            }
            Node *node = new Node(key, value);
            mp[key] = node;
            nodeAfterHead(node);
        }
    }
};
