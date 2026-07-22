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

// brute
// store all nodes in a vector and start updating links using 2 pointers one from start and one from end
// TC: O(n) SC: O(n)

// better
// using stack access back node from top and front from traversal
// code later

// optimal
// finding the mid ele reverse second half and update in place
// avoid extra memory overhead

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //
        ListNode *temp = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;
        while (temp!=nullptr)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        //
        ListNode *start = head;
        while (prev != nullptr)
        {
            ListNode *next1 = start->next;
            ListNode *next2 = prev->next;

            start->next = prev;
            prev->next = next1;

            start = next1;
            prev = next2;
        }
    }
};

// tc=o(n)n for mid point , n/2 for merging n/2 for reversal sc=o(1)