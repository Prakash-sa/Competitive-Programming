#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

// Function to find level of given node x
void Level(Node* root, Node* x, int index, int &level)
{
    // return if tree is empty or level is already found
	if (root == nullptr || level)
		return;

    // if given node is found, update its level
	if (root == x)
		level = index;

    // recur for left and right subtree
	Level(root->left, x, index + 1, level);
	Level(root->right, x, index + 1, level);
}

void printLevel(Node* root, Node *node, int level)
{
    // base case
	if (root == nullptr)
		return;

    // print cousins
	if (level == 1)
	{
		cout << root->key << " ";
		return;
	}

    // recur for left and right subtree if given node is not child of the root
	if (!(root->left && root->left == node ||
			root->right && root->right == node))
	{
		printLevel(root->left, node, level - 1);
		printLevel(root->right, node, level - 1);
	}
}

// Function to print all cousins of given node
void printAllCousins(Node *root, Node *node)
{
	int level = 0;

	// find level of given node
	Level(root, node, 1, level);

	// print all cousins of given node using its level number
	printLevel(root, node, level);
}

// main function
int main()
{
	Node* root = nullptr;

	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
    root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	printAllCousins(root, root->right->left);

	return 0;
}
