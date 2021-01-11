#include<iostream>
using namespace std;

class Linear
{
public:
	const int size = 10;
	int data;
	int i;
	int* arr;
	Linear()
	{
		data = 0;
		i = 0;
		arr = new int[size];
		for (int j = 0; j < size; j++)
		{
			arr[j] = -1;
		}
	}
	void Insert(int a)
	{
		data = a;
		a = a % size;
		bool cond1 = 1;
		while (cond1)
		{
			if (arr[a] != -1)
			{
				i++;
				a = data % size;
				a = a + i;
				if (a >= size)
					a = a % size;
			}
			else if (arr[a] == -1)
				cond1 = 0;
		}
		arr[a] = data;
		i = 0;
	}
	bool Search(int a)
	{
		data = a;
		a = a % size;
		bool cond2 = 1;
		while (cond2)
		{
			if (arr[a] == data)
			{
				cond2 = 0;
				return 1;
			}
			else if (arr[a] == -1)
			{
				cond2 = 0;
				return 0;
			}
			else
			{
				i++;
				a = data % size;
				a = a + i;
				if (a >= size)
					a = a % size;
			}
		}
	}
	void Delete(int a)
	{
		data = a;
		a = a % size;
		bool cond2 = 1;
		while (cond2)
		{
			if (arr[a] == data)
			{
				cond2 = 0;
				arr[a] = -1;
			}
			else if (arr[a] == -1)
			{
				cond2 = 0;
				cout << "Does not exist" << endl;
			}
			else
			{
				i++;
				a = data % size;
				a = a + i;
				if (a >= size)
					a = a % size;
			}
		}
	}
	void Dislay()
	{
		cout << "Hashing Table is" << endl;
		for (int j = 0; j < size; j++)
		{
			if(arr[j]!=-1)
				cout << arr[j] << " ";
			else
				cout << " " << " ";
		}
	}
};

class quadratic
{
public:
	const int size = 10;
	int data;
	int i;
	int* arr;
	quadratic()
	{
		data = 0;
		i = 0;
		arr = new int[size];
		for (int j = 0; j < size; j++)
		{
			arr[j] = -1;
		}
	}
	void Insert(int a)
	{
		data = a;
		a = a % size;
		bool cond1 = 1;
		while (cond1)
		{
			if (arr[a] != -1)
			{
				i++;
				a = data % size;
				a = a + (i*i);
				if (a >= size)
					a = a % size;
			}
			else if (arr[a] == -1)
				cond1 = 0;
		}
		arr[a] = data;
		i = 0;
	}
	bool Search(int a)
	{
		data = a;
		a = a % size;
		bool cond2 = 1;
		while (cond2)
		{
			if (arr[a] == data)
			{
				cond2 = 0;
				return 1;
			}
			else if (arr[a] == -1)
			{
				cond2 = 0;
				return 0;
			}
			else
			{
				i++;
				a = data % size;
				a = a + (i*i);
				if (a >= size)
					a = a % size;
			}
		}
	}
	void Delete(int a)
	{
		data = a;
		a = a % size;
		bool cond2 = 1;
		while (cond2)
		{
			if (arr[a] == data)
			{
				cond2 = 0;
				arr[a] = -1;
			}
			else if (arr[a] == -1)
			{
				cond2 = 0;
				cout << "Does not exist" << endl;
			}
			else
			{
				i++;
				a = data % size;
				a = a + (i*i);
				if (a >= size)
					a = a % size;
			}
		}
	}
	void Dislay()
	{
		cout << "Hashing Table is" << endl;
		for (int j = 0; j < size; j++)
		{
			if (arr[j] != -1)
				cout << arr[j] << " ";
			else
				cout << " " << " ";
		}
	}
};

int main()
{
	bool cond1, cond2, cond3;
	cond1 = cond2 = cond3 = 1;
	int choi1, choi2;
	long long int data;
	Linear H1;
	quadratic H2;
	while (cond1)
	{
		system("cls");
		cout << "Select from the following:\n1. Linear Probing.\n2. Quadratic Probing.\n3. Exit.\nEnter the number of selected option:";
		cin >> choi1;
		system("cls");
		switch (choi1)
		{
		case 1:
			cond2 = 1;
			while (cond2)
			{
				system("cls");
				cout << "Select from the following:\n1. Insert a data.\n2. Search a data.\n3. Delete a data.\n4. To return to main menu.\nEnter the number of selected option:";
				cin >> choi2;
				system("cls");
				switch (choi2)
				{
				case 1:
					cout << "Enter the data you want to insert:";
					cin >> data;
					H1.Insert(data);
					cout << "If you want to return to Linear Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond2;
					break;
				case 2:
					cout << "Enter the data you want to search:";
					cin >> data;
					if (H1.Search(data))
						cout << "Yes it exist in Hashing Table" << endl;
					else
						cout << "No it doesnot exist in Hashing Table" << endl;
					cout << "If you want to return to Linear Number Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond2;
					break;
				case 3:
					cout << "Enter the roll number you want to delete:";
					cin >> data;
					H1.Delete(data);
					cout << "If you want to return to Linear Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond2;
					break;
				case 4:
					cond2 = 0;
					break;
				default:
					cout << "Wrong number option" << endl;
					cout << "If you want to return to Linear Menu press \"1\" or to return to Main Menu press \"0\" :";
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
				cout << "Select from the following:\n1. Insert data.\n2. Search data.\n3. Delete data.\n4. To return to main menu.\nEnter the number of selected option:";
				cin >> choi2;
				system("cls");
				switch (choi2)
				{
				case 1:
					cout << "Enter the data you want to insert:";
					cin >> data;
					H2.Insert(data);
					cout << "If you want to return to Quadratic Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond3;
					break;
				case 2:
					cout << "Enter the data you want to search:";
					cin >> data;
					if (H2.Search(data))
						cout << "Yes it exist in Hashing Table" << endl;
					else
						cout << "No it doesnot exist in Hashing Table" << endl;
					cout << "If you want to return to Quadratic Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond3;
					break;
				case 3:
					cout << "Enter data  you want to delete:";
					cin >> data;
					H2.Delete(data);
					cout << "If you want to return to Quadratic Menu press \"1\" or to return to Main Menu press \"0\" :";
					cin >> cond3;
					break;
				case 4:
					cond3 = 0;
					break;
				default:
					cout << "Wrong number option" << endl;
					cout << "If you want to return to Quadratic Menu press \"1\" or to return to Main Menu press \"0\" :";
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