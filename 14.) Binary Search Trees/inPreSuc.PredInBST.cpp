#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// brute
// inorder can do same for preorder
class Solution
{
public:
    void inorder(Node *root, vector<Node *> &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root);
        inorder(root->right, ans);
    }
    vector<Node *> findPreSuc(Node *root, int key)
    {
        vector<Node *> ans;
        inorder(root, ans);
        int n = ans.size(), low = 0, high = n - 1, pos = n;
        Node *pre = nullptr, *suc = nullptr;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (ans[mid]->data >= key)
            {
                pos = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (pos < n && ans[pos]->data == key)
        {
            if (pos > 0)
                pre = ans[pos - 1];
            if (pos < n - 1)
                suc = ans[pos + 1];
        }
        else
        {
            if (pos > 0)
                pre = ans[pos - 1];
            if (pos < n)
                suc = ans[pos];
        }

        return {pre, suc};
    }
};

// better
// inorder
class Solution
{
public:
    void inorder(Node *root, Node *&pre, Node *&suc, int key)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, pre, suc, key);
        if (root->data < key)
            pre = root;
        if (root->data > key && suc == nullptr)
            suc = root;
        inorder(root->right, pre, suc, key);
    }

    vector<Node *> findPreSuc(Node *root, int key)
    {
        Node *pre = nullptr;
        Node *suc = nullptr;
        inorder(root, pre, suc, key);
        return {pre, suc};
    }
};

// optimal
// using concept of floor and ceil
class Solution
{
public:
    vector<Node *> findPreSuc(Node *root, int key)
    {
        Node *temp = root;
        Node *pre = nullptr;
        Node *suc = nullptr;
        while (temp)
        {
            if (temp->data < key)
            {
                pre = temp;
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        temp = root;
        while (temp)
        {
            if (temp->data > key)
            {
                suc = temp;
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return {pre, suc};
    }
};

// optimal in single traversal

class Solution
{
public:
    vector<Node *> findPreSuc(Node *root, int key)
    {
        Node *pre = nullptr;
        Node *suc = nullptr;
        while (root)
        {
            if (root->data < key)
            {
                pre = root;
                root = root->right;
            }
            else if (root->data > key)
            {
                suc = root;
                root = root->left;
            }
            else
            {
                Node *temp = root->left;
                while (temp)
                {
                    pre = temp;
                    temp = temp->right;
                }

                temp = root->right;
                while (temp)
                {
                    suc = temp;
                    temp = temp->left;
                }
                break;
            }
        }
        return {pre, suc};
    }
};