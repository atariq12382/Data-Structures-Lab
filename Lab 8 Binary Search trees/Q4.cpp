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
	int height(Node* node)
	{
		int leftH, rightH;
		if (node == NULL)
		{
			return 0;
		}
		else
		{
			leftH = height(node->left);
			rightH = height(node->right);
			leftH++;
			rightH++;
			if (leftH > rightH)
				return leftH;
			else
				return rightH;
		}
	}
};

int main()
{
	Node* n;
	BST b;
	Node* a;
	b.insert(5);
	b.insert(8);
	b.insert(1);
	b.insert(7);
	b.insert(9);
	b.insert(3);
	n = b.Find(8);
	cout << b.height(n);

}