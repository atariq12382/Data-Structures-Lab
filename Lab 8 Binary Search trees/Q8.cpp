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
class Stack {

public:
	int top;
	Node* arr[20];
	Stack() {
		top = -1;
		for (int i = 0; i < 20; i++) {
			arr[i] = NULL;
		}
	}

	bool isEmpty() {
		if (top == -1)
			return true;
		else
			return false;
	}


	void push(Node* val)
	{
			top++; 
			arr[top] = val;
	}

	Node* pop() 
	{
		if (isEmpty()) 
		{
			cout << "stack underflow" << endl;
			return 0;
		}
		else
		{
			Node* popValue = arr[top];
			arr[top] = NULL;
			top--;
			return popValue;
		}
	}
};


class BST
{
public:
	Stack S1, S2, S3;
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
	void PostOrder(Node* node)
	{
		Node* n;
		S1.push(node);
		while (S1.isEmpty() != 1)
		{
			n = S1.pop();
			S2.push(n);
			if(n->left!=NULL)
				S1.push(n->left);
			if(n->right!=NULL)
				S1.push(n->right);
		}
		while (S2.isEmpty() != 1)
		{
			n = S2.pop();
			cout << n->data << " ";
		}
	}
	void PreOrder(Node* node)
	{
		Node* n;
		S3.push(node);
		while (S3.isEmpty() != 1)
		{
			n = S3.pop();
			cout << n->data << " ";
			if (n->right != NULL)
				S3.push(n->right);
			if (n->left != NULL)
				S3.push(n->left);
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
	cout << "Post Order:";
	b.PostOrder(b.root);
	cout << endl;
	cout << "Pre Order:";
	b.PreOrder(b.root);

}