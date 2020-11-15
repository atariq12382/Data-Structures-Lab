#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node()
	{
		data = 0;
		left = right = NULL;
	}
};
class BST
{
public:
	int contering = 1;
	Node* root;
	BST()
	{
		root = NULL;
	}
	void insert(int value)
	{
		bool condition = 1;
		Node* temp;
		Node* ptr;
		if (root == NULL)
		{
			ptr = new Node;
			ptr->data = value;
			root = ptr;
		}
		else
		{
			ptr = root;
			while (condition)
			{
				if (value < ptr->data)
				{
					temp = ptr->left;
					if (temp == NULL)
					{
						temp = new Node;
						temp->data = value;
						ptr->left = temp;
						condition = 0;
					}
					else
					{
						ptr = ptr->left;
					}
				}
				else if (value > ptr->data)
				{
					temp = ptr->right;
					if (temp == NULL)
					{
						temp = new Node;
						temp->data = value;
						ptr->right = temp;
						condition = 0;
					}
					else
					{
						ptr = ptr->right;
					}

				}
				else
				{
					cout << "This value already existed" << endl;
				}
			}
		}
	}
	Node* Find(int value)
	{
		Node* ptr;
		int c = 0;
		bool condition = 1;
		if (root == NULL)
		{
			return NULL;
		}
		else
		{
			ptr = root;
			while (condition)
			{
				c++;
				if (ptr->data == value)
				{
					return ptr;
				}
				else if (value > ptr->data)
				{
					ptr = ptr->right;
				}
				else if (value < ptr->data)
				{
					ptr = ptr->left;
				}
				if (ptr == NULL)
				{
					condition = 0;
					return NULL;
				}
			}
		}
	}
	void Display(Node* r)
	{
		if (r == NULL)
			return;
		cout << r->data << " ";
		Display(r->left);
		Display(r->right);
	}
	Node* minValueNode(Node* node)
	{
		while (node->left != NULL)
		{
			node = node->left;
		}
		return node;
	}
	Node* maxValueNode(Node* node)
	{
		while (node->right != NULL)
		{
			node = node->right;
		}
		return node;
	}
	Node* Delete(Node* node, int value)
	{
		Node* temp;
		if (node == NULL)
			return NULL;
		if (value < node->data)
			node->left = Delete(node->left, value);
		else if (value > node->data)
			node->right = Delete(node->right, value);
		else
		{
			if (node->left == NULL)
			{
				temp = node->right;
				delete(node);
				return temp;
			}
			else if (node->right == NULL)
			{
				temp = node->left;
				delete(node);
				return temp;
			}
			else
			{
				temp = minValueNode(node->right);
				node->data = temp->data;
				node->right = Delete(node->right, temp->data);
			}
		}
		return node;
	}
	int Countnodes = 0;
	void CountTotalNodes(Node* ptr)
	{
		if (ptr == NULL)
			return;
		CountTotalNodes(ptr->left);
		Countnodes++;
		CountTotalNodes(ptr->right);
	}
};
int countBSt = 1;
void isBST(Node* root)
{
	if (root == NULL)
		return;
	if (root->left != NULL)
	{
		if (root->left->data < root->data)
			countBSt++;
	}
	if (root->right != NULL)
	{
		if (root->right->data > root->data)
			countBSt++;
	}
	isBST(root->left);
	isBST(root->right);
}

int main()
{
	BST b;
	b.insert(5);
	b.insert(8);
	b.insert(1);
	b.insert(7);
	b.insert(9);
	b.insert(3);
	b.CountTotalNodes(b.root);
	isBST(b.root);
	if (countBSt == b.Countnodes)
		cout << "It is a Binary Search Tree" << endl;
	else
		cout << "It is not a Binary Search Tree" << endl;
}