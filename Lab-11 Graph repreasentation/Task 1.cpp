#include<iostream>
using namespace std;

class AdjacencyMatrix
{
public:
	int Vertices;
	int Edges;
	int** mat;
	AdjacencyMatrix(int n, int m)
	{
		Vertices = n;
		Edges = m;
		mat = new int* [Vertices + 1];
		for (int i = 0; i < Vertices + 1; i++)
		{
			mat[i] = new int[Vertices + 1];
		}
		for (int i = 1; i < Vertices + 1; i++)
		{
			for (int j = 1; j < Vertices + 1; j++)
			{
				mat[i][j] = 0;
			}
		}
	}
	void AddEdge(int n1, int n2)
	{
		mat[n1][n2] = 1;
		mat[n2][n1] = 1;
	}
	void Display()
	{
		cout << "Adjcancy Matrix of the given graph is:-" << endl;
		cout << "   ";
		for (int j = 1; j < Vertices + 1; j++)
			cout << j << "    ";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
			cout << "-----";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
		{
			cout << j << "| ";
			for (int k = 1; k < Vertices + 1; k++)
			{
				cout << mat[j][k] << "    ";
			}
			cout << endl << endl;
		}
	}

};

class Node
{
public:
	int data;
	Node* next;
	Node()
	{
		data = 0;
		next = NULL;
	}
};

class List
{
public:
	Node* head;
	Node* temp;
	List()
	{
		head = NULL;
		temp = NULL;
	}
	bool isEmpty()
	{
		if (head == NULL)
			return 1;
		else
			return 0;
	}
	bool isFull()
	{
		Node* temp;
		try
		{
			temp = new Node;
			delete temp;
			return 0;
		}
		catch (bad_alloc exception)
		{
			return 1;
		}
	}
	void append(int a)
	{
		Node* ptr;
		if (isFull())
		{
			cout << "Stack is Full" << endl;
			return;
		}
		else
		{
			if (isEmpty())
			{
				head = new Node;
				head->data = a;
			}
			else
			{
				temp = new Node;
				ptr = head;
				while (ptr->next != NULL)
				{
					ptr = ptr->next;
				}
				temp->data = a;
				ptr->next = temp;
			}
		}
	}
	int nodeValue()
	{
		int val;
		Node* del;
		del = head;
		val = del->data;
		head = del->next;
		delete(del);
		return val;
	}
	Node* returnHead()
	{
		return head;
	}
};

class AdjacencyList
{
public:
	int Vertices;
	int Edges;
	List* AdjList;
	AdjacencyList(int n, int m)
	{
		Vertices = n;
		Edges = m;
		AdjList = new List[n + 1];
	}
	void AddEdge(int n1, int n2)
	{
		AdjList[n1].append(n2);
		AdjList[n2].append(n1);
	}
	void Display()
	{
		cout << "Adjcency List of the given Graph is:-" << endl;
		for (int i = 1; i < Vertices + 1; i++)
		{
			cout << i << " ---> ";
			while (!AdjList[i].isEmpty())
			{
				cout << AdjList[i].nodeValue() << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	int n, m;
	int n1, n2;
	int choice;
	cout << "Please Enter the Number of vertices of the graph:";
	cin >> n;
	cout << "Please Enter the number of edges of the graph:";
	cin >> m;
	system("cls");
	cout << "Please Select from the following\n1. To Find Adjcency Matrix of the graph.\n2. To Find Adjacency list of the graph.\nEnter the number of selected option:";
	cin >> choice;
	system("cls");
	if (choice == 2)
	{
		AdjacencyList L(n, m);
		for (int i = 0; i < m; i++)
		{
			cout << "Please Enter the Vertice by pressing space, in between the edge exist:";
			cin >> n1;
			cin >> n2;
			L.AddEdge(n1, n2);
		}
		system("cls");
		L.Display();
	}
	else
	{
		AdjacencyMatrix M(n, m);
		for (int i = 0; i < m; i++)
		{
			cout << "Please Enter the Vertice by pressing space, in between the edge exist:";
			cin >> n1;
			cin >> n2;
			M.AddEdge(n1, n2);
		}
		system("cls");
		M.Display();
	}
}
