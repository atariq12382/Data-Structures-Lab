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
	bool isPrime(int c)
	{
		if (c % 2 == 0)
		{
			if (c == 2)
				return 1;
			return 0;
		}
		else if (c % 3 == 0)
		{
			if (c == 3)
				return 1;
			return 0;
		}
		else
			return 1;
	}
	void ProductPrime1()
	{
		int counter = 0;
		int product = 1;
		Node* temp;
		temp = head;
		while (temp != NULL)
		{
			counter++;
			if (isPrime(counter))
				product = product * temp->data;
			temp = temp->next;
		}
		cout << "Product of prime numbers of nodes is:" << product << endl;
	}
};
int main()
{
	doubleLinkedList d;
	for (int i = 1; i <= 8; i++)
	{
		d.append();
	}
	d.ProductPrime1();
}