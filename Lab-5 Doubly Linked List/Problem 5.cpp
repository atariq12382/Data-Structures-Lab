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
	void Consective()
	{
		Node* temp;
		Node* PTR;
		Node* next1;
		Node* help;
		Node* help2;
		int tdata, pdata;
		temp = head;
		while (temp != NULL)
		{
			PTR = temp->next;
			next1 = PTR;
			while (PTR != NULL)
			{
				tdata = temp->data;
				pdata = PTR->data;
				pdata--;
				if (tdata == pdata)
				{
					if (PTR->previous == temp)
					{
						PTR = PTR->next;
						continue;
					}
					else
					{
						help = temp->next;
						temp->next = PTR;
						help2 = PTR->previous;
						PTR->previous = temp;
						help2->next = PTR->next;
						if (PTR->next != NULL)
							PTR->next->previous = help2;
						PTR->next = help;
						help->previous = PTR;
					}
				}
				PTR = PTR->next;
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
	for (int i = 1; i <= 8; i++)
	{
		d.append();
	}
	cout << "Before combining consecitive:" << endl;
	d.Display();
	d.Consective();
	cout<<"After combining consecitive:"<<endl;
	d.Display();
}