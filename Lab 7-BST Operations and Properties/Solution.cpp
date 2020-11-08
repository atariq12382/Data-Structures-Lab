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
	void Delete(int value)
	{
		Node* ptr;
		bool condition = 1;
		if (root == NULL)
		{
			cout << "Tree is already empty" << endl;
			return;
		}
		else
		{
			ptr = root;
			while (condition)
			{
				if (ptr->data == value)
				{
					delete(ptr);
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
	void Postorder(Node* ptr)
	{
		if (ptr == NULL)
			return;
		Postorder(ptr->left);
		Postorder(ptr->right);
		cout << ptr->data << " ";
	}
	void Inorder(Node* ptr)
	{
		if (ptr == NULL)
			return;
		Inorder(ptr->left);
		cout << ptr->data << " ";
		Inorder(ptr->right);
	}
	void Preorder(Node* ptr)
	{
		if (ptr == NULL)
			return;
		cout << ptr->data << " ";
		Preorder(ptr->left);
		Preorder(ptr->right);
	}
	void traverse()
	{
		Node* ptr;
		ptr = root;
		int choice;
		cout << "Please select from the following:\n1.Pre Order.\n2.In Order.\n3.Post Order.\nPlease enter  the number of selected option";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Preorder(ptr);
			break;
		case 2:
			Inorder(ptr);
			break;
		case 3:
			Postorder(ptr);
			break;
		default:
			cout << "You enter a wrong number of input" << endl;
			break;
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
	void Display(Node* r, int space) {
		if (r == NULL)
			return;
		space += 20;
		Display(r->right, space);
		cout << endl;
		for (int i = 20; i < space; i++)
			cout << " ";
		cout << r->data << "\n";
		Display(r->left, space);
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
	int levelOfNode = 0;
	void levelNode(Node* node,int val)
	{
		if (node == NULL)
			return;
		else
		{
			if (node->data == val)
			{
				levelOfNode++;
				return;
			}
			levelOfNode++;
			levelNode(node->left, val);
			levelNode(node->right, val);
		}

	}
	int DegreeOfNode(Node* node)
	{
		int d=0;
		if (node->left != NULL)
			d++;
		if (node->right != NULL)
			d++;
		return d;
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
	bool isLeaf(Node* node)
	{
		if (node->left == NULL && node->right == NULL)
		{
			return 1;
		}
		else
			return 0;
	}
	bool isNonLeaf(Node* node)
	{
		if (node->left == NULL && node->right == NULL)
		{
			return 0;
		}
		else
			return 1;
	}
	bool isParent(Node* checkParent, Node* checkChild)
	{
		if (checkParent->left == checkChild)
			return 1;
		else if (checkParent->right == checkChild)
			return 1;
		else
			return 0;
	}
	bool isChild(Node* checkChild, Node* checkParent)
	{
		if (checkParent->left == checkChild)
			return 1;
		else if (checkParent->right == checkChild)
			return 1;
		else
			return 0;
	}
	bool isDS = 0;
	void isDescendent(Node* foreFather,Node*newGen)
	{
		if (foreFather == NULL)
			return;
		isDescendent(foreFather->left,newGen);
		if (foreFather == newGen)
		{
			cout << "Yes it is descendent" << endl;
			isDS = 1;
		}
		isDescendent(foreFather->right,newGen);
	}
	void isSuccessor(Node* foreFather, Node* newGen)
	{
		if (foreFather == NULL)
			return;
		isSuccessor(foreFather->left, newGen);
		if (foreFather == newGen)
		{
			cout << "Yes it is successor" << endl;
			isDS = 1;
		}
		isSuccessor(foreFather->right, newGen);
	}
	void isSibling(Node* child1, Node* child2, Node* root)
	{
		if (root == NULL)
			return;
		isSibling(child1, child2, root->left);
		if (root->left == child1 && root->right == child2)
		{
			isDS = 1;
			cout << "Yes they are sibling" << endl;
		}
		else if (root->left == child2 && root->right == child1)
		{
			isDS = 1;
			cout << "Yes they are sibling" << endl;
		}
		isSibling(child1, child2, root->right);
	}
	int Lcount2x = 0;
	void Leafcount2x(Node* root)
	{
		if (root == NULL)
		{
			Lcount2x++;
			return;
		}
		Leafcount2x(root->left);
		Leafcount2x(root->right);
	}
	int Internalnodes = 0;
	void InternalNodescount(Node* root)
	{
		if (root == NULL)
			return;
		InternalNodescount(root->left);
		Internalnodes++;
		InternalNodescount(root->right);
	}
};

int main()
{
	int ans;
	Node* node;
	Node* node2;
	int h;
	BST b;
	int choice;
	int val;
	bool condition = 1;
	while (condition)
	{
		cout << "Welcome to the binary search tree program.\nPlease select from the following option:\n1.Insert value\n2.delete value\n3.Traverse\n4.Search value\n5.Display\n6.Height of a tree\n7.Level of a node\n8.Degree of a node\n9.Total number of nodes\n10.Is node a leaf\n11.Is node a non-leaf\n12.Is a Parent node\n13.Is a Child node\n14.Is Descendent Node\n15.Is successor node\n16.Is sibling of other node\n17.Total number of leaf nodes\n18.Total number of internal nodes\nEnter the number of selected option:";
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
			cout << "Please enter the value you want to delete:";
			cin >> val;
			b.Delete(val);
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 3:
			b.traverse();
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 4:
			cout << "Please enter the value you want to search:";
			cin >> val;
			b.Search(val);
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 5:
			b.Display(b.root, 10);
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 6:
			h = b.height(b.root);
			cout << "Height of tree is " << h << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 7:
			cout << "Please enter the data of node which's level you want to find:";
			cin >> h;
			b.levelOfNode = 0;
			b.levelNode(b.root, h);
			cout << "Level of the node at which data "<<h<<" exist is " << b.levelOfNode << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 8:
			cout << "Please enter the data of node which's degree you want to find:";
			cin >> ans;
			node = b.Find(ans);
			if (node != NULL)
			{
				h = b.DegreeOfNode(b.root);
				cout << "degree of a node is " << endl;
			}
			else
				cout << "There is no node with this value." << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 9:
			b.Countnodes = 0;
			b.CountTotalNodes(b.root);
			cout << "Total nodes = " << b.Countnodes << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 10:
			cout << "Please enter the data of node which you want to know if it is a leaf:";
			cin >> ans;
			node = b.Find(ans);
			if (node != NULL)
			{
				if (b.isLeaf(node))
					cout << "It is a leaf node" << endl;
				else
					cout << "It is not a leaf node" << endl;
			}
			else
				cout << "There is no node with this value." << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 11:
			cout << "Please enter the data of node which you want to know if it is a non-leaf:";
			cin >> ans;
			node = b.Find(ans);
			if (node != NULL)
			{
				if (b.isNonLeaf(node))
					cout << "It is a non-leaf node" << endl;
				else
					cout << "It is not a non-leaf node" << endl;
			}
			else
				cout << "There is no node with this value." << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 12:
			cout << "Please enter the data of node which you want to know if it is a parent:";
			cin >> ans;
			node = b.Find(ans);
			cout << "Please enter the data of node which you want to know if it is a child:";
			cin >> ans;
			node2 = b.Find(ans);
			if (node != NULL && node2 != NULL)
			{
				if (b.isParent(node,node2))
					cout << "It is a parent of the other" << endl;
				else
					cout << "It is not a parent of the other" << endl;
			}
			else
				cout << "There is no node with this value." << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 13:
			cout << "Please enter the data of node which you want to know if it is a parent:";
			cin >> ans;
			node = b.Find(ans);
			cout << "Please enter the data of node which you want to know if it is a child:";
			cin >> ans;
			node2 = b.Find(ans);
			if (node != NULL && node2 != NULL)
			{
				if (b.isChild(node2,node))
					cout << "It is a child of the other" << endl;
				else
					cout << "It is not a child of the other" << endl;
			}
			else
				cout << "There is no node with this value." << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 14:
			cout << "Please enter the data of node which you want to know if it is a descendent:";
			cin >> ans;
			node = b.Find(ans);
			cout << "Please enter the data of node which you want to know if it is a successor:";
			cin >> ans;
			node2 = b.Find(ans);
			if (node != NULL && node2 != NULL)
			{
				b.isDS = 0;
				b.isDescendent(node, node2);
				if (b.isDS == 0)
					cout << "It is not a descendent" << endl;
			}
			else
				cout << "There is no node with this value." << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 15:
			cout << "Please enter the data of node which you want to know if it is a descendent:";
			cin >> ans;
			node = b.Find(ans);
			cout << "Please enter the data of node which you want to know if it is a successor:";
			cin >> ans;
			node2 = b.Find(ans);
			if (node != NULL && node2 != NULL)
			{
				b.isDS = 0;
				b.isSuccessor(node, node2);
				if (b.isDS == 0)
					cout << "It is not a successor" << endl;
			}
			else
				cout << "There is no node with this value." << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 16:
			cout << "Please enter the data of node which you want to know if it is a sibling:";
			cin >> ans;
			node = b.Find(ans);
			cout << "Please enter the data of node which you want to know if it is a sibling:";
			cin >> ans;
			node2 = b.Find(ans);
			if (node != NULL && node2 != NULL)
			{
				b.isDS = 0;
				b.isSibling(node, node2,b.root);
				if (b.isDS == 0)
					cout << "It is not a sibling" << endl;
			}
			else
				cout << "There is no node with this value." << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 17:
			b.Lcount2x = 0;
			b.Leafcount2x(b.root);
			cout << "Total number of leaf nodes:" << b.Lcount2x / 2 << endl;
			cout << "If you want to perform any other operation press \"1\" else press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 18:
			b.Internalnodes = 0;
			b.InternalNodescount(b.root);
			b.Lcount2x = 0;
			b.Leafcount2x(b.root);
			b.Lcount2x = b.Lcount2x / 2;
			cout << "Total number of internal nodes:" << b.Internalnodes - b.Lcount2x << endl;
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