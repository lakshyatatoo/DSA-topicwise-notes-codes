#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// better
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *temp = head;
        int len = 1;
        while (temp->next)
        {
            temp = temp->next;
            len++;
        }
        k %= len;
        if (k == 0)
            return head;
        temp->next = head;
        len = len - k;
        while (len--)
        {
            temp = temp->next;
        }
        ListNode *newHead = temp->next;
        temp->next = nullptr;
        return newHead;
    }
};

// longer
ListNode *findNewTail(ListNode *temp, int k)
{
    int cnt = 1;
    while (temp != nullptr)
    {
        if (cnt == k)
            return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}

ListNode *rotateByK(ListNode *head, int k)
{
    if (head == nullptr || k == 0)
        return head;
    ListNode *tail = head;
    int len = 1;
    while (tail->next != nullptr)
    {
        tail = tail->next;
        len++;
    }
    if (k % len == 0)
        return head;
    k = k % len;
    tail->next = head;
    ListNode *newTail = findNewTail(head, len - k);
    ListNode *newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}
