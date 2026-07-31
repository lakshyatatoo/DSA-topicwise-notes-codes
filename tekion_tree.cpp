#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
};

Node *buildTree(int arr[], int n)
{
    Node *root = new Node{arr[0]};
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n)
    {
        Node *node = q.front();
        q.pop();
        if (i < n)
        {
            if (arr[i] == -1)
            {
                node->left = nullptr;
            }
            else
            {
                Node *l = new Node{arr[i]};
                node->left = l;
                q.push(l);
            }
            i++;
        }
        if (i < n)
        {
            if (arr[i] == -1)
            {
                node->right = nullptr;
            }
            else
            {
                Node *r = new Node{arr[i]};
                node->right = r;
                q.push(r);
            }
            i++;
        }
    }
    return root;
}

// mirror check
bool isMirror(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    return (root1->val == root2->val) && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}

// node count
int countNodes(Node *root)
{
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// leaf level check
bool checkLeaves(Node *root, int x, int &leafLvl)
{
    if (root == nullptr)
        return true;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (leafLvl == -1)
            leafLvl = x;
        return (leafLvl == x);
    }
    return checkLeaves(root->left, x + 1, leafLvl) && checkLeaves(root->right, x + 1, leafLvl);
}

int main()
{
    int n;
    cin >> n;

    int arr[20];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *root = buildTree(arr, n);

    bool mirror = (!root) || isMirror(root->left, root->right);
    int count = countNodes(root);

    int leafLevel = -1;
    bool sameLevel = checkLeaves(root, 0, leafLevel);

    cout << "Mirror Structure: " << (mirror ? "YES" : "NO") << endl;
    cout << "Node Count: " << count << endl;
    cout << "All Leaves Same Level: " << (sameLevel ? "YES" : "NO") << endl;

    return 0;
}