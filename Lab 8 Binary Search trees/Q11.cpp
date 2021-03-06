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
	int* arr;
	int contering = 1;
	Node* root;
	int i;
	BST()
	{
		i = 0;
		arr = NULL;
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
	void arrayset()
	{
		int a = height(root);
		i = 1;
		for (int l = 1; l <= a; l++)
		{
			i = i * 2;
		}
		arr = new int[i];
		for (int j = 0; j < i; j++)
		{
			arr[j] = -1111;
		}
	}
	void arrayconvert(Node* node)
	{
		if (node == NULL)
			return;
		arrImplementationinsert(node->data);
		arrayconvert(node->left);
		arrayconvert(node->right);
	}
	void arrImplementationinsert(int val)
	{
		bool cond = 1;
		int k = 0;
		if (arr[k] == -1111)
			arr[k] = val;
		else
		{
			while (cond)
			{
				if (val > arr[k])
				{
					k = ((2 * k) + 2);
					if (k > i)
					{
						cout << "Tree is full" << endl;
						return;
					}
					if (arr[k] == val)
					{
						cout << "Value already exist" << endl;
						cond = 0;
					}
					if (arr[k] == -1111)
					{
						arr[k] = val;
						cond = 0;
					}
				}
				if (val < arr[k])
				{
					k = ((2 * k) + 1);

					if (k > i)
					{
						cout << "Tree is full" << endl;
						return;
					}
					if (arr[k] == val)
					{
						cout << "Value already exist" << endl;
						cond = 0;
					}
					if (arr[k] == -1111)
					{
						arr[k] = val;
						cond = 0;
					}
				}
			}
		}
	}
	int arrheight()
	{
		int k1 = 0;
		int k2 = 0;
		int c2 = 0;
		int c1 = 0;
		bool cond = 1;
		for (k1 = 0; k1 < i; k1 = ((2 * k1) + 1))
		{
			c1++;
		}
		for (k2 = 0; k2 < i; k2 = ((2 * k2) + 2))
		{
			c2++;
		}
		if (c2 < c1)
		{
			return c2;
		}
		else
		{
			return c1;
		}
	}
};

int main()
{
	BST b;
	b.insert(5);
	b.insert(8);
	b.insert(1);
	b.insert(7);
	b.insert(9);
	b.insert(3);
	b.arrayset();
	b.arrayconvert(b.root);
	cout << "Height of a Array implemented Tree:" << b.arrheight() << endl;
}