#include<iostream>
using namespace std;

class maxHeap
{
public:
	int* arr;
	int currentSize;
	int maxSize;
	maxHeap(int size)
	{
		currentSize = 0;
		maxSize = size;
		arr = new int[size];
	}
	int parentIndex(int i)
	{
		int a = (i - 1);
		a = a / 2;
		return a;
	}
	int leftChildIndex(int i)
	{
		int a = (2 * i + 1);
		return a;
	}
	int rightChildIndex(int i)
	{
		int a = (2 * i + 2);
		return a;
	}
	void insert(int data)
	{
		int temp;
		int index;
		if (currentSize == maxSize)
		{
			cout << "Heap is already full." << endl;
			return;
		}
		currentSize++;
		index = currentSize - 1;
		arr[index] = data;
		while (index != 0 && arr[parentIndex(index)] < arr[index])
		{
			temp = arr[parentIndex(index)];
			arr[parentIndex(index)] = arr[index];
			arr[index] = temp;
			index = parentIndex(index);
		}
	}
	void maxHeapyfy(int index)
	{
		int temp;
		int left = leftChildIndex(index);
		int right = rightChildIndex(index);
		int largest = index;
		if (left < currentSize && arr[left] > arr[index])
			largest = left;
		if (right < currentSize && arr[right] > arr[largest])
			largest = right;
		if (largest != index)
		{
			temp = arr[index];
			arr[index] = arr[largest];
			arr[largest] = temp;
			maxHeapyfy(largest);
		}
	}
	int extractMax()
	{
		if (currentSize <= 0)
			return -1111;
		if (currentSize == 1)
		{
			currentSize--;
			return arr[currentSize];
		}
		int ret = arr[0];
		arr[0] = arr[currentSize - 1];
		currentSize--;
		maxHeapyfy(0);
		return ret;
	}
	int getMax()
	{
		return arr[0];
	}
	void increaseKey(int index,int newValue)
	{
		int temp;
		arr[index] = newValue;
		while (index != 0 && arr[parentIndex(index)] > arr[index])
		{
			temp = arr[parentIndex(index)];
			arr[parentIndex(index)] - arr[index];
			arr[index] = temp;
			index = parentIndex(index);
		}
	}
	void Delete(int index)
	{
		increaseKey(index, INT_MAX);
		extractMax();
	}
	void K_LargestValues(int k)
	{
		int value;
		cout << k << " Largest values are ";
		for (int i = 0; i < k; i++)
		{
			value = extractMax();
			cout << value << " ";
		}
	}
};

int main()
{
	int size, index;
	cout << "Please enter the size of Heap:";
	cin >> size;
	bool condition = 1;
	int choice;
	maxHeap H(size);
	system("cls");
	while (condition)
	{
		system("cls");
		cout << "Please select from the following option:\n1.Get maximum value from heap.\n2.Deletes maximum value from heap.\n3.Inccrease the value at any index.\n4.Insert a value.\n5.Delete a value.\n6.K-Largest values.\nPlease enter the numer of selected option:";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			index = H.getMax();
			cout << "Minimum value in the heap is " << index << endl;
			cout << "If you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		case 2:
			index = H.extractMax();
			cout << "The value " << index << " has been extracted from the heap." << endl;
			cout << "If you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		case 3:
			cout << "Please enter the index at which you want to decrease value:";
			cin >> index;
			cout << "Please enter new decreased value for index " << index << " :";
			cin >> size;
			H.increaseKey(index, size);
			cout << "If you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		case 4:
			cout << "Please enter the value you want to insert in heap:";
			cin >> index;
			H.insert(index);
			cout << "If you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		case 5:
			cout << "Please enter the index number which's value you want to delete:";
			cin >> index;
			H.Delete(index);
			cout << "If you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		case 6:
			cout << "How many largest vale you want to find:";
			cin>>index;
			H.K_LargestValues(index);
			cout << "\nIf you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		default:
			cout << "Wrong Input!!" << endl;
			cout << "If you want to perform any other function press 1 else press 0 :";
			cin >> condition;
			break;
		}
	}
}