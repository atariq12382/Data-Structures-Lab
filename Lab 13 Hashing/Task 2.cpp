#include<iostream>
using namespace std;

class Hashing
{
public:
	const int size = 10;
	int data;
	int i;
	int* arr;
	Hashing()
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
		}
	}
};


int main()
{
	Hashing H;
	bool cond = 1;
	int choi;
	int data;
	while (cond)
	{
		system("cls");
		cout << "Select from the following:\n1. Insert Data.\n2. Search Data.\n3. Delete Data.\n4. Exit\nEnter the number of selected option:";
		cin >> choi;
		system("cls");
		switch (choi)
		{
		case 1:
			cout << "Enter data you want to insert:";
			cin >> data;
			H.Insert(data);
			cout << "Enter 1 for menu and enter 0 for exit:";
			cin >> cond;
			break;
		case 2:
			cout << "Enter data you want to search:";
			cin >> data;
			if (H.Search(data))
				cout << "Yes it exist" << endl;
			else
				cout << "No it doesnot exist" << endl;
			cout << "Enter 1 for menu and enter 0 for exit:";
			cin >> cond;
			break;
		case 3:
			cout << "Enter data you want to delete:";
			cin >> data;
			H.Delete(data);
			cout << "Enter 1 for menu and enter 0 for exit:";
			cin >> cond;
			break;
		case 4:
			cond = 0;
			break;
		default:
			cout << "Wrong input" << endl;
			cout << "Enter 1 for menu and enter 0 for exit:";
			cin >> cond;
			break;
		}
	}
}