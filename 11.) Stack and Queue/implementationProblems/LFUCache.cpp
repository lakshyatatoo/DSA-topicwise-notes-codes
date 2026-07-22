#include <bits/stdc++.h>
using namespace std;

// optimal only
class LFUCache
{
public:
    struct Node
    {
        int key;
        int data;
        int cnt;
        Node *next;
        Node *prev;

    public:
        Node(int key1, int data1)
        {
            key = key1;
            data = data1;
            cnt = 1;
            next = NULL;
            prev = NULL;
        }
    };
    struct List
    {
        int size;
        Node *head;
        Node *tail;
        List()
        {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void delNode(Node *temp)
        {
            Node *after = temp->next;
            Node *prevNode = temp->prev;
            prevNode->next = after;
            after->prev = prevNode;
            size--;
        }
        void nodeAfterHead(Node *temp)
        {
            Node *after = head->next;
            head->next = temp;
            temp->prev = head;
            temp->next = after;
            after->prev = temp;
            size++;
        }
    };
    unordered_map<int, Node *> keynode;
    unordered_map<int, List *> freqListMap;
    int maxSize, minFreq, curSize;

    LFUCache(int capacity)
    {
        this->maxSize = capacity;
        this->minFreq = 0;
        this->curSize = 0;
    }
    void updateFfreqListMap(Node *node)
    {
        keynode.erase(node->key);
        freqListMap[node->cnt]->delNode(node);
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        {
            minFreq++;
        }
        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end())
        {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt++;
        nextHigherFreqList->nodeAfterHead(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keynode[node->key] = node;
    }
    int get(int key)
    {
        if (keynode.find(key) != keynode.end())
        {
            Node *temp = keynode[key];
            updateFfreqListMap(temp);
            return temp->data;
        }
        return -1;
    }
    void put(int key, int value)
    {
        if (maxSize == 0)
            return;

        if (keynode.find(key) != keynode.end())
        {
            Node *node = keynode[key];
            node->data = value;
            updateFfreqListMap(node);
        }
        else
        {
            if (curSize == maxSize)
            {
                List *list = freqListMap[minFreq];
                keynode.erase(list->tail->prev->key);
                freqListMap[minFreq]->delNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List *list = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
            {
                list = freqListMap[minFreq];
            }
            Node *node = new Node(key, value);
            list->nodeAfterHead(node);
            freqListMap[minFreq] = list;
            keynode[key] = node;
        }
    }
};
