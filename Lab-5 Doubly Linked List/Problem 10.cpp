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
	void append(int value)
	{
		
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
	void preappend(int value)
	{

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
	void reverse()
	{
		Node* temp;
		temp = NULL;
		ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		head = ptr;
		while (ptr != NULL)
		{
			temp = ptr->next;
			ptr->next = ptr->previous;
			ptr->previous = temp;
			ptr = ptr->next;
		}
	}
};
int main()
{
	doubleLinkedList d;
	int v;
	for (int i = 1; i <= 5; i++)
	{
		cout << "Enter a value:";
		cin >> v;
		d.append(v);
	}
	cout << "Before reversing:-" << endl;
	d.Display();
	d.reverse();
	cout << "After reversing:-" << endl;
	d.Display();
}