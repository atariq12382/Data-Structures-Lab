#include<iostream>
using namespace std;

class Node
{
public:
	Node* next;
	int data;
	Node()
	{
		next = NULL;
		data = 0;
	}
};

class List
{
public:
	Node* head;
	List()
	{
		head = NULL;
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
		try {
			temp = new Node;
			delete temp;
			return false;
		}
		catch (bad_alloc exception)
		{
			return true;
		}
	}

	void preappend(int a)
	{
		Node* ptr;
		if (isFull())
		{
			cout << "Stack is FUll";
			return;
		}
		else
		{
			if (isEmpty())
			{
				ptr = new Node();
				ptr->data = a;
				head = ptr;
			}
			else
			{
				ptr = new Node();
				ptr->data = a;
				ptr->next = head;
				head = ptr;
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

class stack
{
public:
	Node* top;
	List l;
	stack()
	{
		top = NULL;
	}
	bool isFull()
	{
		bool ret;
		ret = l.isFull();
		if (ret)
			return 1;
		else
			return 0;
	}
	bool isEmpty()
	{
		top = l.returnHead();
		if (top == NULL)
			return 1;
		else
			return 0;
	}
	void Push(int data)
	{
		if (isEmpty())
		{
			l.preappend(data);
			top = l.returnHead();
		}
		else
		{
			l.preappend(data);
		}
	}
	int Pop()
	{
		int res;
		if (isEmpty())
		{
			cout << "Stack is empty" << endl;
			return -1111;
		}
		else
		{
			res = l.nodeValue();
			return res;
		}
		top = l.returnHead();
	}
	Node* Top()
	{
		top = l.returnHead();
		return top;
	}
};

class Queue
{
public:
	stack s1, s2;
	Queue()
	{
		cout << "This a queue made from combination of two stacks." << endl;
	}
	void Enqueue(int data)
	{
		int t;
		Node* ptr;
		ptr = s2.Top();
		while (ptr != NULL)
		{
			t = s2.Pop();
			s1.Push(t);
			ptr = ptr->next;
		}
		s1.Push(data);
	}
	int Dequeue()
	{
		int t;
		Node* ptr;
		ptr = s1.Top();
		while (ptr != NULL)
		{
			t = s1.Pop();
			s2.Push(t);
			ptr = ptr->next;
		}
		t = s2.Pop();
		return t;
	}
	bool isFull()
	{
		int t;
		Node* ptr;
		ptr = s2.Top();
		while (ptr != NULL)
		{
			t = s2.Pop();
			s1.Push(t);
		}
		bool ret;
		ret = s1.isFull();
		return ret;
	}
	bool isEmpty()
	{
		int t;
		Node* ptr;
		ptr = s2.Top();
		while (ptr != NULL)
		{
			t = s2.Pop();
			s1.Push(t);
		}
		bool ret;
		ret = s1.isEmpty();
		return ret;
	}
};
int main()
{
	Queue Q;
	int choice;
	bool condition = 1;
	int data;
	while (condition)
	{
		system("cls");
		cout << "Please select from the following:\n1. Enqueue a value.\n2. Dequeue a value.\n3. Check if queue is full.\n4. Check if queue is empty.\nPlease enter the numer of selected option:";
		cin >> choice;
		system("CLS");
		switch (choice)
		{
		case 1:
			cout << "Please enter the value you want to enqueue:";
			cin >> data;
			Q.Enqueue(data);
			cout << data << " has been enqueued." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		case 2:
			data = Q.Dequeue();
			cout << data << " has been dequeued." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		case 3:
			if (Q.isFull())
				cout << "Queue is full." << endl;
			else
				cout << "Queue is not full." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		case 4:
			if (Q.isEmpty())
				cout << "Queue is empty." << endl;
			else
				cout << "Queue is not empty." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		default:
			cout << "Error: Wrong number of option." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		}
	}
}
