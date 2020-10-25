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
	void sort()
	{
		Node* temp;
		Node* PTR;
		Node* tnext;
		Node* tprev;
		Node* nect1;
		temp = head;
		while (temp != NULL)
		{
			PTR = temp->next;
			nect1 = PTR;
			while (PTR != NULL)
			{
				if (PTR->data < temp->data)
				{
					if (temp == head)
						head = PTR;
					tnext = PTR->next;
					tprev = PTR->previous;
					PTR->next = temp;
					PTR->previous = temp->previous;
					temp->next = tnext;
					if (temp->previous != NULL)
						temp->previous->next = PTR;
					if (PTR->next != NULL)
						PTR->next->previous = temp;
					temp->previous = PTR;
					
				}
				PTR = PTR->next;
			}
			temp = nect1;
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
	for (int i = 1; i <= 8; i++)
	{
		d.append();
	}
	cout << "Before sorting:" << endl;
	d.Display();
	d.sort();
	cout<<"After sorting"<<endl;
	d.Display();
}