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
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;
        vector<ListNode *> nodes;
        ListNode *temp = head;
        while (temp)
            nodes.push_back(temp), temp = temp->next;
        int i = 0, j = nodes.size() - 1;
        while (i < j)
        {
            nodes[i]->next = nodes[j], i++;
            if (i == j)
                break;
            nodes[j]->next = nodes[i], j--;
        }
        nodes[i]->next = nullptr;
    }
};

// better
// using stack access back node from top and front from traversal
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;
        stack<ListNode *> st;
        ListNode *temp = head;
        int n = 0;
        while (temp)
            st.push(temp), temp = temp->next, n++;
        temp = head;
        for (int i = 0; i < n / 2; i++)
        {
            ListNode *nextNode = temp->next, *lastNode = st.top();
            st.pop();
            temp->next = lastNode, lastNode->next = nextNode, temp = nextNode;
        }
        temp->next = nullptr;
    }
};

// optimal
// finding the mid ele reverse second half and update in place
// avoid extra memory overhead

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;
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
        while (temp != nullptr)
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