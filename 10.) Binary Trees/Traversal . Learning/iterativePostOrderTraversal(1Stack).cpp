#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> postOrder;
        if (root == nullptr)
            return postOrder;
        TreeNode *curr = root;
        while (!st.empty() || curr != nullptr)
        {
            if (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode *temp = st.top()->right;
                if (temp == nullptr)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp->val);
                    }
                }
                else
                {
                    curr = temp;
                }
            }
        }
        return postOrder;
    }
};