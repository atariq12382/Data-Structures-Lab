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
	void insert()
	{
		bool choice;
		cout << "If you wnt to insert at the end press \"1\" else for insert at the start press \"0\" :";
		cin >> choice;
		if (choice == 1)
			append();
		else
			preappend();
	}
	void Delete()
	{
		Node* del;
		del = head;
		head = del->next;
		delete(del);
	}
};
int main()
{
	bool Return;
	doubleLinkedList d;
	bool condition = 1;
	int choice;
	while (condition)
	{
		cout << "Welcome to the Doubly Linked List menu.\nPlease select from the following:-\n1. Insert a Node.\n2. Delete a Node(from the top).\n3. To check if the list is empty.\n4. To check if the list is full.\nPlease enter the number of the selected option:";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			d.insert();
			cout << "If you want to perform any other operation press \"1\" else for exit press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 2:
			d.Delete();
			cout << "If you want to perform any other operation press \"1\" else for exit press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 3:
			Return = d.isEmpty();
			if (Return)
				cout << "List is Empty" << endl;
			else
				cout << "List is not Empty" << endl;
			cout << "If you want to perform any other operation press \"1\" else for exit press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		case 4:
			Return = d.isFull();
			if (Return)
				cout << "List is Full" << endl;
			else
				cout << "List is not Full" << endl;
			cout << "If you want to perform any other operation press \"1\" else for exit press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		default:
			cout << "You have entered a wrong number of option" << endl;
			cout << "If you want to perform any other operation press \"1\" else for exit press \"0\" :";
			cin >> condition;
			system("cls");
			break;
		}
	}
	cout << "Have a Nice Day..\nGood Bye!!";
}