#include <bits/stdc++.h>
using namespace std;

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

// try other levels apart from level order traversal like inorder, preorder, postorder etc.
lass Codec{
    public :
        // Encodes a tree to a single string.
        string serialize(TreeNode * root){
            if (root == nullptr) return "";
string s = "";
queue<TreeNode *> q;
q.push(root);
while (!q.empty())
{
    TreeNode *node = q.front();
    q.pop();

    if (node == nullptr)
        s.append("#,");
    else
    {
        s.append(to_string(node->val) + ',');
    }
    if (node != nullptr)
    {
        q.push(node->left);
        q.push(node->right);
    }
}
return s;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return nullptr;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
            node->left = nullptr;
        else
        {
            TreeNode *left = new TreeNode(stoi(str));
            node->left = left;
            q.push(left);
        }
        getline(s, str, ',');
        if (str == "#")
            node->right = nullptr;
        else
        {
            TreeNode *right = new TreeNode(stoi(str));
            node->right = right;
            q.push(right);
        }
    }
    return root;
}
}
;
