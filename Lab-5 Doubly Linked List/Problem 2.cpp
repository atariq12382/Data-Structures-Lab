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
	void Delete(int value)
	{
		Node* del;
		del = head;
		while (del != NULL)
		{
			if (del->data == value)
				break;
			del = del->next;
		}
		if (del == NULL)
			return;
		if (del == head)
		{
			head = del->next;
			delete(del);
			return;
		}
		del->previous->next = del->next;
		del->next->previous = del->previous;
		delete(del);
	}
	void DelSame1()
	{
		Node* temp;
		Node* del;
		temp = head;
		while (temp != NULL)
		{
			del = temp->next;
			while (del != NULL)
			{
				if (del->data == temp->data)
				{
					Delete(del->data);
					temp = del->previous;
				}
				del = del->next;
			}
			temp = temp->next;
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
int main()
{
	doubleLinkedList d;
	d.append();
	d.append();
	d.append();
	d.append();
	d.append();
	d.append();
	d.append();
	cout << "Before deleting same data:" << endl;
	d.Display();
	d.DelSame1();
	cout << "After deleting same data:" << endl;
	d.Display();
}