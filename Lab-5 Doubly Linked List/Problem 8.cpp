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
	void insertAt(int index,int value)
	{
		Node* temp;
		Node* PTR;
		Node* help;
		int c = 1;
		temp = head;
		if (index == 1)
		{
			preappend(value);
			return;
		}
		index--;
		while (temp != NULL)
		{
			if (c == index)
			{
				PTR = new Node;
				PTR->data = value;
				PTR->previous = temp;
				PTR->next = temp->next;
				temp->next->previous = PTR;
				temp->next = PTR;
				return;
			}
			c++;
			temp = temp->next;
		}
		if (temp == NULL)
			append(value);
		return;
	}
	void insertAfter(int request, int value)
	{
		Node* PTR;
		Node* temp;
		temp = head;
		while (temp != NULL)
		{
			if (temp->data == request)
			{
				PTR = new Node;
				PTR->data = value;
				PTR->previous = temp;
				PTR->next = temp->next;
				temp->next->previous = PTR;
				temp->next = PTR;
				return;
			}
			temp = temp->next;
		}
		if (temp == NULL)
			cout << "There is no node with this data" << endl;
	}
};
int main()
{
	doubleLinkedList d;
	int v;
	for (int i = 1; i <= 3; i++)
	{
		cout << "Enter a value:";
		cin >> v;
		d.append(v);
	}
	cout << "Before inserting at:" << endl;
	d.Display();
	d.insertAt(2, 2);
	cout << "After inserting at:" << endl;
	d.Display();
	cout << "Before inserting after:" << endl;
	d.Display();
	d.insertAfter(3, 4);
	cout << "After inserting after:" << endl;
	d.Display();
}