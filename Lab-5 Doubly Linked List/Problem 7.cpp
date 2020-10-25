#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node* previous;
	Node()
	{
		data = 0;
		next = NULL;
		previous = NULL;
	}
};

class doubleLinkedList
{
public:
	Node* ptr;
	Node* head;
	doubleLinkedList()
	{
		ptr = NULL;
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
		Node* pt;
		try
		{
			pt = new Node;
			delete pt;
			return 0;
		}
		catch (bad_alloc exception)
		{
			return 1;
		}
	}
	void append()
	{
		int value;
		cout << "Please Enter the value you want to enter:";
		cin >> value;
		Node* N = new Node();
		if (isEmpty())
		{
			N->data = value;
			head = N;
			ptr = N;
		}
		else
		{
			N->data = value;
			N->previous = ptr;
			ptr->next = N;
			ptr = N;
		}
	}
	void preappend()
	{
		int value;
		cout << "Please Enter the value you want to enter:";
		cin >> value;
		Node* N = new Node();
		if (isEmpty())
		{
			N->data = value;
			head = N;
			ptr = N;
		}
		else
		{
			N->data = value;
			N->next = head;
			head->previous = N;
			head = N;
		}
	}
	void Display()
	{
		Node* temp;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};
doubleLinkedList combine(doubleLinkedList L1, doubleLinkedList L2);
doubleLinkedList combine(doubleLinkedList L1, doubleLinkedList L2)
{
	Node* ptr;
	if (L1.head == NULL)
		return L2;
	else if (L2.head == NULL)
		return L1;
	else
	{
		ptr = L1.head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = L2.head;
		L2.head->previous = ptr;
		return L1;
	}
}
int main()
{
	doubleLinkedList d1,d2;
	for (int i = 1; i <= 5; i++)
	{
		d1.append();
	}
	for (int i = 1; i <= 5; i++)
	{
		d2.append();
	}
	d1 = combine(d1, d2);
	cout<<"After combining:"<<endl;
	d1.Display();
}