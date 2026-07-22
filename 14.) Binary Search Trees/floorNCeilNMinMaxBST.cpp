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

// ologn
// ceil
class Solution
{
public:
	int findCeil(Node *root, int x)
	{
		int ceil = -1;
		while (root)
		{
			if (root->data == x)
			{
				ceil = root->data;
				return ceil;
			}
			if (x > root->data)
			{
				root = root->right;
			}
			else
			{
				ceil = root->data;
				root = root->left;
			}
		}
		return ceil;
	}
};
// floor
class Solution
{
public:
	int findMaxFork(Node *root, int k)
	{
		// code here
		int floor = -1;
		while (root)
		{
			if (k == root->data)
			{
				floor = root->data;
				return floor;
			}
			if (k > root->data)
			{
				floor = root->data;
				root = root->right;
			}
			else
			{
				root = root->left;
			}
		}
		return floor;
	}
};

// minmax
class Solution
{
public:
	int minValue(Node *root)
	{

		int mn = -1;
		while (root)
		{
			if (root->left == nullptr)
			{
				mn = root->data;
				return mn;
			}
			root = root->left;
		}
	}
};