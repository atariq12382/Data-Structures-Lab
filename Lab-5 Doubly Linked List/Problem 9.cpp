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
	void DeleteAt(int index)
	{
		Node* del;
		Node* temp;
		int c = 1;
		temp = head;
		while (temp != NULL)
		{
			if (index == c)
			{
				if (temp == head)
					head = head->next;
				del = temp;
				if (temp->previous != NULL)
					temp->previous->next = temp->next;
				if (temp->next != NULL)
					temp->next->previous = temp->previous;
				delete(del);
				return;
			}
			c++;
			temp = temp->next;
		}
		if (temp == NULL)
			cout << "Invalid index number" << endl;
	}
	void DeleteAfter(int request)
	{
		Node* del;
		Node* temp;
		temp = head;
		while (temp != NULL)
		{
			if (request == temp->data)
			{
				temp = temp->next;
				del = temp;
				if(temp->previous!=NULL)
					temp->previous->next = temp->next;
				if(temp->next!=NULL)
					temp->next->previous = temp->previous;
				delete(del);
				return;
			}
			temp = temp->next;
		}
		if (temp == NULL)
			cout << "Invalid index number" << endl;
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
	cout << "Before deleting at:" << endl;
	d.Display();
	d.DeleteAt(2);
	cout << "After deleting at:" << endl;
	d.Display();
	cout << "Before deleting after:" << endl;
	d.Display();
	d.DeleteAfter(3);
	cout << "After deleting after:" << endl;
	d.Display();
}