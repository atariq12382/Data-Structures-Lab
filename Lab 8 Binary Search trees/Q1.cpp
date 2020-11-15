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
	bool isDS = 0;
	void isDescendent(Node* foreFather, int val)
	{
		if (foreFather == NULL)
			return;
		isDescendent(foreFather->left, val);
		if (foreFather->data == val)
		{
			isDS = 1;
		}
		isDescendent(foreFather->right, val);
	}
	void ancestors(Node* root, int val)
	{
		if (root == NULL)
			return;
		if (root == this->root)
			cout << root->data << " ";
		isDS = 0;
		isDescendent(root->left, val);
		if (isDS == 1)
		{
			cout << root->left->data<<" ";
			ancestors(root->left, val);
		}
		isDS = 0;
		isDescendent(root->right, val);
		if (isDS == 1)
		{
			cout << root->right->data << " ";
			ancestors(root->right, val);
		}

	}
};

int main()
{
	BST b;
	bool condition = 1;
	int choice;
	int val;
	while (condition)
	{
		cout << "Please select from the following:\n1.Insert a Node.\n2.Search a Node.\n3.Display all Nodes.\n4.Show ancestors of a Node.\nPlease enter the selected option number:";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			cout << "Please enter the value you want to insert:";
			cin >> val;
			b.insert(val);
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 2:
			cout << "Please enter the value you want to search:";
			cin >> val;
			b.Search(val);
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 3:
			b.Display(b.root);
			cout << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 4:
			cout << "Please enter the value you want to see ancestors:";
			cin >> val;
			b.ancestors(b.root, val);
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		default:
			cout << "Wrong input" << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		}
	}
}