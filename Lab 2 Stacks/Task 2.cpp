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
	int Top()
	{
		top = l.returnHead();
		return top->data;
	}
};


int main()
{
	stack S;
	int choice;
	int data;
	bool condition = 1;
	while (condition)
	{
		system("CLS");
		cout << "Please select from the following:\n1. Check if stack is full.\n2. Check if stack is empty.\n3. Push a data in stack.\n4. Pop a data in stack.\n5. View the data at top of stack.\nPlease enter the number of selected option:";
		cin >> choice;
		system("CLS");
		switch (choice)
		{
		case 1:
			if (S.isFull())
				cout << "Stack is full." << endl;
			else
				cout << "Stack is not full." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		case 2:
			if (S.isEmpty())
				cout << "Stack is empty." << endl;
			else
				cout << "Stack is not empty." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		case 3:
			cout << "Please enter the data you want to push in the stack:";
			cin >> data;
			S.Push(data);
			cout << data << " has been pushed into the stack." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		case 4:
			data = S.Pop();
			cout << data << " has been poped from the stack." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		case 5:
			data = S.Top();
			cout << data << " is at the top of stack." << endl;
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