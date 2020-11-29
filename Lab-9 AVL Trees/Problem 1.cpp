#include<iostream>
using namespace std;

class Node
{
public:
	int Data;
	int Height;
	Node* Left;
	Node* Right;
	Node()
	{
		Data = 0;
		Height = 1;
		Left = Right = NULL;
	}
};

class AVL_Tree
{
public:
	Node* Root;
	AVL_Tree()
	{
		Root = NULL;
	}
	int Height_Node(Node* node)//This function calculates the height of the given node.
	{
		int leftH, rightH;
		if (node == NULL)
		{
			return 0;
		}
		else
		{
			leftH = Height_Node(node->Left);
			rightH = Height_Node(node->Right);
			leftH++;
			rightH++;
			if (leftH > rightH)
				return leftH;
			else
				return rightH;
		}
	}
	void updateHeight(Node* n)//Update the height of a every node.
	{
		if (n == NULL)
			return;
		n->Height=Height_Node(n);
		updateHeight(n->Left);
		updateHeight(n->Right);
	}
	int Balance_Factor(Node* n)//This function gives the balance factor of the given node.
	{
		if (n == NULL)
			return 0;
		if (n->Left != NULL && n->Right != NULL)
			return n->Left->Height - n->Right->Height;
		else if (n->Left != NULL && n->Right == NULL)
			return n->Left->Height - 0;
		else if (n->Left == NULL && n->Right != NULL)
			return 0 - n->Right->Height;
		else if (n->Left == NULL && n->Right == NULL)
			return 0;
	}
	Node* Left_Left_Rotation(Node* n)//This function is performing Right rotation on left tree.
	{
		Node* temp;
		temp = n->Left;
		n->Left = temp->Right;
		temp->Right = n;
		return temp;
	}
	Node* Right_Right_Rotation(Node* n)//This function is performing Left rotstion on right tree.
	{
		Node* temp;
		temp = n->Right;
		n->Right = temp->Left;
		temp->Left = n;
		return temp;
	}
	Node* Right_Left_Rotation(Node* n)//This function is performing right rotation and then left rotation.
	{
		n->Right = Left_Left_Rotation(n->Right);
		n = Right_Right_Rotation(n);
		return n;
	}
	Node* Left_Right_Rotation(Node* n)//This function is performing left rotation and than right rotation.
	{
		n->Left = Right_Right_Rotation(n->Left);
		n = Left_Left_Rotation(n);
		return n;
	}
	void Insert_Node(int value)//This Function insert the new node and balance the AVL according to the balance factor.
	{
		bool condition = 1;
		Node* temp;
		Node* ptr;
		if (Root == NULL)
		{
			ptr = new Node;
			ptr->Data = value;
			updateHeight(ptr);
			Root = ptr;
		}
		else
		{
			ptr = Root;
			while (condition)
			{
				if (value < ptr->Data)
				{
					temp = ptr->Left;
					if (temp == NULL)
					{
						temp = new Node;
						temp->Data = value;
						ptr->Left = temp;
						updateHeight(Root);
						condition = 0;
					}
					else
					{
						ptr = ptr->Left;
					}
				}
				else if (value > ptr->Data)
				{
					temp = ptr->Right;
					if (temp == NULL)
					{
						temp = new Node;
						temp->Data = value;
						ptr->Right = temp;
						updateHeight(Root);
						condition = 0;
					}
					else
					{
						ptr = ptr->Right;
					}

				}
				else
				{
					cout << "This value already existed" << endl;
					return;
				}
			}
		}
		int BFROOT, BFRLEFT, BFRRIGHT;
		BFROOT = Balance_Factor(Root);
		BFRLEFT = Balance_Factor(Root->Left);
		BFRRIGHT = Balance_Factor(Root->Right);
		if (BFROOT == 2 && BFRLEFT == 1)
		{
			Root = Left_Left_Rotation(Root);
			updateHeight(Root);
		}
		else if (BFROOT == -2 && BFRRIGHT == -1)
		{
			Root = Right_Right_Rotation(Root);
			updateHeight(Root);
		}
		else if (BFROOT == -2 && BFRRIGHT == 1)
		{
			Root = Right_Left_Rotation(Root);
			updateHeight(Root);
		}
		else if (BFROOT == 2 && BFRLEFT == -1)
		{
			Root = Left_Right_Rotation(Root);
			updateHeight(Root);
		}
	}
	Node* Minimum_Value_Node(Node* node)//This function gives the mi9nimum value Node
	{
		while (node -> Left != NULL)
		{
			node = node -> Left;
		}
		return node;
	}
	Node* Delete_Node(Node* node, int value)//This Function delete node and balance the AVL according to the balance factor.
	{
		Node* temp;
		if (node == NULL)
			return NULL;
		if (value < node -> Data)
			node -> Left = Delete_Node(node -> Left, value);
		else if (value > node -> Data)
			node -> Right = Delete_Node(node -> Right, value);
		else
		{
			if (node -> Left == NULL)
			{
				temp = node -> Right;
				delete(node);
				return temp;
			}
			else if (node -> Right == NULL)
			{
				temp = node -> Left;
				delete(node);
				return temp;
			}
			else
			{
				temp = Minimum_Value_Node(node -> Right);
				node -> Data = temp -> Data;
				node -> Right = Delete_Node(node -> Right, temp -> Data);
			}
		}
		int BFROOT, BFRLEFT, BFRRIGHT;
		BFROOT = Balance_Factor(Root);
		BFRLEFT = Balance_Factor(Root->Left);
		BFRRIGHT = Balance_Factor(Root->Right);
		if (BFROOT == 2 && BFRLEFT == 1)
		{
			Root = Left_Left_Rotation(Root);
			updateHeight(Root);
		}
		else if (BFROOT == 2 && BFRLEFT == -1)
		{
			Root = Left_Right_Rotation(Root);
			updateHeight(Root);
		}
		else if (BFROOT == 2 && BFRLEFT == 0)
		{
			Root = Left_Left_Rotation(Root);
			updateHeight(Root);
		}
		else if (BFROOT == -2 && BFRRIGHT == -1)
		{
			Root = Right_Right_Rotation(Root);
			updateHeight(Root);
		}
		else if (BFROOT == -2 && BFRRIGHT == 1)
		{
			Root = Right_Left_Rotation(Root);
			updateHeight(Root);
		}
		else if (BFROOT == -2 && BFRRIGHT == 0)
		{
			Root = Right_Right_Rotation(Root);
			updateHeight(Root);
		}
		return node;
	}
};

int main()
{
	AVL_Tree T;
	T.Insert_Node(10);
	T.Insert_Node(5);
	T.Insert_Node(20);
	T.Insert_Node(15);
	T.Insert_Node(30);
	T.Insert_Node(17);
	T.Insert_Node(25);

}