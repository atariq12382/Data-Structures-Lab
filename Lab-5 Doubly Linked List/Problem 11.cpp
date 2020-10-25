#include<iostream>
using namespace std;

class Node
{
public:
	Node* next;
	Node* previous;
	int data;
	Node()
	{
		data = 0;
		next = previous = NULL;
	}
};

class circularList
{
public:
	Node* head;
	Node* last;
	Node* temp;
	circularList()
	{
		head = temp = last = NULL;
	}
	bool isFull()
	{
		Node* ptr;
		try
		{
			ptr = new Node;
			delete ptr;
			return 0;
		}
		catch (bad_alloc exception)
		{
			return 1;
		}
	}
	bool isEmpty()
	{
		if (head == NULL)
			return 1;
		else
			return 0;
	}
	void append(int a)
	{
		Node* ptr;
		if (isFull())
		{
			cout << "List is full" << endl;
			return;
		}
		else
		{
			if (isEmpty())
			{
				ptr = new Node();
				head = ptr;
				head->data = a;
				head->next = head;
				head->previous = head;
			}
			else
			{
				ptr = head;
				while (ptr->next != head)
				{
					ptr = ptr->next;
				}
				temp = new Node;
				temp->data = a;
				temp->next = head;
				temp->previous = ptr;
				ptr->next = temp;
				head->previous = temp;
			}
		}
	}
	void preappend(int a)
	{
		Node* ptr;
		if (isFull())
		{
			cout << "List is full" << endl;
			return;
		}
		else
		{
			if (isEmpty())
			{
				ptr = new Node();
				head = ptr;
				head->data = a;
				head->next = head;
				head->previous = head;
			}
			else
			{
				temp = new Node;
				temp->next = head;
				temp->data = a;
				head->previous->next = temp;
				head->previous = temp;
				head = temp;
			}
		}
	}
	int top()
	{
		return head->data;
	}
	void display()
	{
		Node* ptr;
		ptr = head;
		cout << ptr->data << "->";
		ptr = ptr->next;
		while (ptr != head)
		{
			cout << ptr->data << "->";
			ptr = ptr->next;
		}
		cout << "Again from the top" << endl;
	}
};
int main()
{
	int v;
	circularList c;
	for (int i = 1; i <= 5; i++)
	{
		cout << "Enter a value:";
		cin >> v;
		c.append(v);
	}
	cout << "List is:-" << endl;
	c.display();
}