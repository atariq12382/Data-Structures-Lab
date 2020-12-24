#include<iostream>
using namespace std;

void swaparr(int* arr1, int s1, int* arr2, int s2)
{
	int i;
	int temp = 0;
	if (s1 > s2)
		i = s2;
	else
		i = s1;
	for (int k = 0; k < i; k++)
	{
		arr1[k] = temp;
		arr1[k] = arr2[k];
		arr2[k] = temp;
	}
	cout << "Values of both of arrayshave been swapped." << endl;
}

int main()
{
	int s1, s2;
	int input;
	int* arr1 = new int[20];
	int* arr2 = new int[20];
	bool condition = 1;
	s1 = s2 = 0;
	while (condition)
	{
		cout << "Please enter the " << s1 << " index value of array 1 or to end enter -111:";
		cin >> input;
		if (input == -111)
		{
			break;
			condition = 0;
		}
		arr1[s1] = input;
		s1++;
	}
	condition = 1;
	while (condition)
	{
		cout << "Please enter the " << s1 << " index value of array 2 or to end enter -111:";
		cin >> input;
		if (input == -111)
		{
			break;
			condition = 0;
		}
		arr2[s2] = input;
		s2++;
	}
	swaparr(arr1, s1, arr2, s2);
}