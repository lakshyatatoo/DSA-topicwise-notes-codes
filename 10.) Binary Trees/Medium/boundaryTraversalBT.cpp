#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Solution
{
public:
    bool isLeaf(Node *node)
    {
        if (node->left == nullptr && node->right == nullptr)
            return true;
        return false;
    }
    void addLeft(Node *node, vector<int> &res)
    {
        Node *temp = node->left;
        while (temp)
        {
            if (!isLeaf(temp))
                res.push_back(temp->data);
            if (temp->left)
                temp = temp->left;
            else
                temp = temp->right;
        }
    }
    void addLeaf(Node *node, vector<int> &res)
    {
        if (isLeaf(node))
        {
            res.push_back(node->data);
            return;
        }

        if (node->left)
            addLeaf(node->left, res);
        if (node->right)
            addLeaf(node->right, res);
    }
    void addRight(Node *node, vector<int> &res)
    {
        Node *temp = node->right;
        vector<int> tp;
        while (temp)
        {
            if (!isLeaf(temp))
                tp.push_back(temp->data);
            if (temp->right)
                temp = temp->right;
            else
            {
                temp = temp->left;
            }
        }
        for (int i = tp.size() - 1; i >= 0; i--)
        {
            res.push_back(tp[i]);
        }
    }
    vector<int> boundaryTraversal(Node *root)
    {

        vector<int> res;
        if (root == nullptr)
            return res;
        if (!isLeaf(root))
            res.push_back(root->data);
        addLeft(root, res);
        addLeaf(root, res);
        addRight(root, res);
        return res;
    }
};
