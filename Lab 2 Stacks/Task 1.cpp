#include<iostream>
using namespace std;

class Stack
{
public:
	int top;
	int* arr;
	int maxIndex;
	Stack(int size)
	{
		arr = new int[size];
		top = -1;
		maxIndex = size - 1;
	}
	bool isFull()
	{
		if (top == maxIndex)
			return 1;
		else
			return 0;
	}
	bool isEmpty()
	{
		if (top == -1)
			return 1;
		else
			return 0;
	}
	void Push(int data)
	{
		if (isFull())
		{
			cout << "Error: Stack is already full." << endl;
			return;
		}
		top++;
		arr[top] = data;
	}
	int Pop()
	{
		if (isEmpty())
		{
			cout << "Error: Stack is already empty." << endl;
			return INT_MIN;
		}
		int ret = arr[top];
		arr[top] = INT_MIN;
		top--;
		return ret;
	}
	int Top()
	{
		if (isEmpty())
		{
			cout << "Error: Stack is empty." << endl;
			return INT_MIN;
		}
		return arr[top];
	}
};

int main()
{
	int size;
	cout << "Please enter the size of the stack:";
	cin >> size;
	Stack S(size);
	int choice;
	int data;
	bool condition = 1;
	while (condition)
	{
		system("CLS");
		cout << "Please select from the following:\n1. Check if stack is full.\n2. Check if stack is empty.\n3. Push a data in stack.\n4. Pop a data in stack.\n5. View the data at top of stack.\nPlease enter the number of selected option:";
		cin >> choice;
		system("CLS");
		switch (choice)
		{
		case 1:
			if (S.isFull())
				cout << "Stack is full." << endl;
			else
				cout << "Stack is not full." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		case 2:
			if (S.isEmpty())
				cout << "Stack is empty." << endl;
			else
				cout << "Stack is not empty." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		case 3:
			cout << "Please enter the data you want to push in the stack:";
			cin >> data;
			S.Push(data);
			cout << data << " has been pushed into the stack." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		case 4:
			data = S.Pop();
			cout << data << " has been poped from the stack." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		case 5:
			data = S.Top();
			cout << data << " is at the top of stack." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		default:
			cout << "Error: Wrong number of option." << endl;
			cout << "If you want to perform any other function press 1 or to exit press 0:";
			cin >> condition;
			break;
		}
	}
}
