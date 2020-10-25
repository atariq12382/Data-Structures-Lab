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
	void insert()
	{
		int d;
		cout << "Enter a number:";
		cin >> d;
		Node* temp;
		Node* ptr2;
		bool condition = 1;
		if (head == NULL)
		{
			ptr = new Node;
			ptr->data = d;
			head = ptr;
			return;
		}
		else
		{
			ptr = new Node;
			ptr->data = d;
			if (ptr->data < head->data)
			{
				ptr->next = head;
				head->previous = ptr;
				head = ptr;
				return;
			}
			else
			{
				temp = head;
				ptr2 = head->next;
				while (condition)
				{
					if (ptr2 == NULL)
					{
						temp->next = ptr;
						ptr->previous = temp;
						condition = 0;
						return;
					}
					else
					{
						if (ptr->data < ptr2->data)
						{
							temp->next = ptr;
							ptr->previous = temp;
							ptr->next = ptr2;
							ptr2->previous = ptr;
							condition = 0;
							return;
						}
					}
					temp = temp->next;
					ptr2 = ptr2->next;
				}
			}
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
		d.insert();
	}
	cout<<"After insertion:"<<endl;
	d.Display();
}