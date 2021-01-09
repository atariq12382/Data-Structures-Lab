#include<iostream>
using namespace std;

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
	Node* returnTemp()
	{
		return temp;
	}
};

class Queue
{
public:
	List l;
	Node* front;
	Node* rear;
	Queue()
	{
		front = rear = NULL;
	}
	bool isEmpty()
	{
		if (front == NULL && rear == NULL)
			return 1;
		else
			return 0;
	}
	void enqueue(int a)
	{
		if (isEmpty())
		{
			l.append(a);
			front = l.returnHead();
			rear = l.returnHead();
		}
		else
		{
			l.append(a);
			rear = l.returnTemp();
		}
	}
	int dequeue()
	{
		int val;
		if (isEmpty())
		{
			cout << "Stack is Empty" << endl;
			return -1111;
		}
		else
		{
			val = l.nodeValue();
			front = l.returnHead();
			if (front == NULL)
				rear = NULL;
			return val;
		}
	}
	int frontValue()
	{
		return front->data;
	}
	int rearValue()
	{
		return rear->data;
	}
	int middleValue()
	{
		Node* ptr;
		ptr = front;
		int c = 0;
		while (ptr != NULL)
		{
			ptr = ptr->next;
			c++;
		}
		c = c / 2;
		int i = 1;
		ptr = front;
		while (i != c)
		{
			ptr = ptr->next;
			i++;
		}
		return ptr->data;
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
		AdjList = new List[n];
	}
	void AddEdge(int n1, int n2)
	{
		AdjList[n1].append(n2);
		AdjList[n2].append(n1);
	}
	void Display()
	{
		cout << "Adjcency List of the given Graph is:-" << endl;
		for (int i = 0; i < Vertices ; i++)
		{
			cout << i << " ---> ";
			while (!AdjList[i].isEmpty())
			{
				cout << AdjList[i].nodeValue() << " ";
			}
			cout << endl;
		}
	}
	void DfS(int v, bool* vistor)
	{
		vistor[v] = true;
		cout << v << " ";
		int i;
		while (!AdjList[v].isEmpty())
		{
			i = AdjList[v].nodeValue();
			if (!vistor[i])
				DfS(i, vistor);
		}
	}
	void DFSCaller(int s)
	{
		bool* Visitor = new bool[Vertices];
		for (int i = 0; i < Vertices; i++)
		{
			Visitor[i] = false;
		}
		DfS(s, Visitor);
	}
	void BFS(int s)
	{
		bool* Visitor = new bool[Vertices];
		for (int i = 0; i < Vertices; i++)
			Visitor[i] = false;
		Queue queue;
		Visitor[s] = true;
		queue.enqueue(s);
		int j;
		while (!queue.isEmpty())
		{
			s = queue.dequeue();
			cout << s << " ";
			while (!AdjList[s].isEmpty())
			{
				j = AdjList[s].nodeValue();
				if (!Visitor[j])
				{
					Visitor[j] = true;
					queue.enqueue(j);
				}
			}
		}
	}
};

int main()
{
	int choice1, choice2;
	AdjacencyList G1(7, 6);
	G1.AddEdge(0, 1);
	G1.AddEdge(1, 2);
	G1.AddEdge(2, 3);
	G1.AddEdge(0, 4);
	G1.AddEdge(0, 5);
	G1.AddEdge(5, 6);
	AdjacencyList G2(6, 7);
	G2.AddEdge(0,1);
	G2.AddEdge(0,2);
	G2.AddEdge(0,3);
	G2.AddEdge(1,4);
	G2.AddEdge(4,3);
	G2.AddEdge(3,5);
	G2.AddEdge(1,2);
	int s;
	cout << "Select For Graph 1 :\n 1.Breadth First Search.\n2. Depth First Search.\n Enter the number of selected option:";
	cin >> choice1;
	if (choice1 == 1)
	{
		cout << "Please enter the number of starting vertex:";
		cin >> s;
		cout << "Breadth First Search traversal starting from " << s << " of graph 1: ";
		G1.BFS(s);
	}
	else
	{

		cout << "Please enter the number of starting vertex:";
		cin >> s;
		cout << "Depth First Search traversal starting from " << s << " of graph 1: ";
		G1.DFSCaller(s);
	}
	cout << endl;
	cout << "Select For Graph 2 :\n 1.Breadth First Search.\n2. Depth First Search.\n Enter the number of selected option:";
	cin >> choice2;
	if (choice2 == 1)
	{
		cout << "Please enter the number of starting vertex:";
		cin >> s;
		cout << "Breadth First Search traversal starting from " << s << " of graph 2: ";
		G2.BFS(s);
	}
	else
	{

		cout << "Please enter the number of starting vertex:";
		cin >> s;
		cout << "Depth First Search traversal starting from " << s << " of graph 2: ";
		G2.DFSCaller(s);
	}
}
