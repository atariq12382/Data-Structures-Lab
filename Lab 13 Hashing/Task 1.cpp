#include<iostream>
using namespace std;

class Node
{
public:
	long long int data;
	Node* next;
	Node()
	{
		data = 0;
		next = NULL;
	}
};

class List
{
public:
	Node* head;
	Node* temp;
	List()
	{
		head = NULL;
		temp = NULL;
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
		Node* temp;
		try
		{
			temp = new Node;
			delete temp;
			return 0;
		}
		catch (bad_alloc exception)
		{
			return 1;
		}
	}
	void append(long long int a)
	{
		Node* ptr;
		if (isFull())
		{
			cout << "List is Full" << endl;
			return;
		}
		else
		{
			if (isEmpty())
			{
				ptr = new Node;
				head = ptr;
				head->data = a;
			}
			else
			{
				temp = new Node;
				ptr = head;
				while (ptr->next != NULL)
				{
					ptr = ptr->next;
				}
				temp->data = a;
				ptr->next = temp;
			}
		}
	}
	bool search(long long int a)
	{
		Node* ptr;
		ptr = head;
		int c = 0;
		while (ptr != NULL)
		{
			if (ptr->data == a)
				c++;
			ptr = ptr->next;
		}
		if (c != 0)
			return 1;
		else
			return 0;
	}
	void Delete(long long int a)
	{
		Node* temp;
		Node* temp2;
		if (isEmpty())
		{
			cout << "List is already Empty." << endl;
			return;
		}
		if (a == head->data)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			temp = head;
			while (temp != NULL)
			{
				if (a == temp->data)
					break;
				temp = temp->next;
			}
			temp2 = head;
			while (temp2->next != temp)
			{
				temp2 = temp2->next;
			}
			temp2->next = temp->next;
			delete temp;
		}
	}
};

class Hashing
{
public:
	const int size = 10;
	long long int data;
	List* L;
	Hashing()
	{
		data = 0;
		L = new List[size];
	}
	void Insert(long long int a)
	{
		data = a;
		a = a % size;
		L[a].append(data);
	}
	bool Search(long long int a)
	{
		data = a;
		a = a % 10;
		if (L[a].search(data))
			return 1;
		else
			return 0;
	}
	void Delete(long long int a)
	{
		data = a;
		a = a % 10;
		if (L[a].search(data))
		{
			L[a].Delete(data);
		}
		else
			cout << "Data does not exist" << endl;
	}
};

int main()
{
	bool cond1, cond2, cond3;
	cond1 = cond2 = cond3 = 1;
	int choi1, choi2;
	long long int data;
	Hashing H1, H2;
	while (cond1)
	{
		system("cls");
		cout << "Select from the following:\n1. Roll Number of Students.\n2. CNIC of Pakistani Citizen.\n3. Exit.\nEnter the number of selected option:";
		cin >> choi1;
		system("cls");
		switch (choi1)
		{
		case 1:
			cond2 = 1;
			while (cond2)
			{
				system("cls");
				cout << "Select from the following:\n1. Insert a Roll Number.\n2. Search a Roll Number.\n3. Delete a Roll Number.\n4. To return to main menu.\nEnter the number of selected option:";
				cin >> choi2;
				system("cls");
				switch (choi2)
				{
				case 1:
					cout << "Enter the roll number you want to insert     (roll number must be in between 17551 - 18000 ):";
					cin >> data;
					while (cond3)
					{
						if (data >= 17551 && data <= 18000)
							cond3 = 0;
						else
						{
							cout << "Roll number out of range";
							cout << "Enter the roll number you want to insert     (roll number must be in between 17551 - 18000 ):";
							cin >> data;
						}
					}
					H1.Insert(data);
					cout << "If you want to return to Roll Number Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond2;
					break;
				case 2:
					cout << "Enter the roll number you want to search     (roll number must be in between 17551 - 18000 ):";
					cin >> data;
					if (H1.Search(data))
						cout << "Yes it exist in Hashing Table" << endl;
					else
						cout << "No it doesnot exist in Hashing Table" << endl;
					cout << "If you want to return to Roll Number Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond2;
					break;
				case 3:
					cout << "Enter the roll number you want to search     (roll number must be in between 17551 - 18000 ):";
					cin >> data;
					H1.Delete(data);
					cout << "If you want to return to Roll Number Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond2;
					break;
				case 4:
					cond2 = 0;
					break;
				default:
					cout << "Wrong number option" << endl;
					cout << "If you want to return to Roll Number Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond2;
					break;
				}
			}
			break;
		case 2:
			cond3 = 1;
			while (cond3)
			{
				system("cls");
				cout << "Select from the following:\n1. Insert a CNIC.\n2. Search a CNIC\n3. Delete a CNIC.\n4. To return to main menu.\nEnter the number of selected option:";
				cin >> choi2;
				system("cls");
				switch (choi2)
				{
				case 1:
					cout << "Enterthe number of CNIC you want to insert:";
					cin >> data;
					H2.Insert(data);
					cout << "If you want to return to CNIC Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond3;
					break;
				case 2:
					cout << "Enterthe number of CNIC you want to search:";
					cin >> data;
					if (H2.Search(data))
						cout << "Yes it exist in Hashing Table" << endl;
					else
						cout << "No it doesnot exist in Hashing Table" << endl;
					cout << "If you want to return to CNIC Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond3;
					break;
				case 3:
					cout << "Enterthe number of CNIC you want to delete:";
					cin >> data;
					H2.Delete(data);
					cout << "If you want to return to CNIC Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond3;
					break;
				case 4:
					cond3 = 0;
					break;
				default:
					cout << "Wrong number option" << endl;
					cout << "If you want to return to CNIC Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond3;
					break;
				}
			}
			break;
		case 3:
			cond1 = 0;
			break;
		default:
			cout << "Wrong number option" << endl;
			cout << "If you want to return to Main Menu press \"1\" or to exit press \"0\" :";
			cin >> cond2;
			break;
		}
	}
}