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
	void Search(int value)
	{
		Node* ptr;
		int c = 0;
		bool condition = 1;
		if (root == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		else
		{
			ptr = root;
			while (condition)
			{
				c++;
				if (ptr->data == value)
				{
					cout << "It is in tree" << endl;
					cout << "Found after " << c << " iterations" << endl;
					return;
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
					cout << "Not found in the tree" << endl;
					condition = 0;
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
	void Merge(Node* OtherRoot)
	{
		if (OtherRoot == NULL)
			return;
		insert(OtherRoot->data);
		Merge(OtherRoot->left);
		Merge(OtherRoot->right);
	}
};

int main()
{
	BST b;
	BST a;
	b.insert(5);
	b.insert(8);
	b.insert(1);
	b.insert(7);
	b.insert(9);
	b.insert(3);
	a.insert(12);
	a.insert(10);
	a.insert(4);
	a.insert(6);
	b.Merge(a.root);
	b.Display(b.root);
}