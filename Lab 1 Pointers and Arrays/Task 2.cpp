#include<iostream>
using namespace std;

void displayMatrix(int** mat)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

void additionmat(int** mat1, int** mat2)
{
	int** mat3 = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		mat3[i] = new int[3];
	}
	cout << "Matrix A is " << endl;
	displayMatrix(mat1);
	cout << "Matrix B is " << endl;
	displayMatrix(mat2);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mat3[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	cout << "Matrix A+B is " << endl;
	displayMatrix(mat3);
}

void multiplicationMat(int** mat1, int** mat2)
{
	int** mat3 = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		mat3[i] = new int[3];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mat3[i][j] = 0;
		}
	}
	cout << "Matrix A is " << endl;
	displayMatrix(mat1);
	cout << "Matrix B is " << endl;
	displayMatrix(mat2);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int u = 0; u < 3; u++)
				mat3[i][j] += mat1[i][u] * mat2[u][j];
		}
	}
	cout << "Matrix A*B is " << endl;
	displayMatrix(mat3);
}

int main()
{
	int** mat1 = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		mat1[i] = new int[3];
	}
	int** mat2 = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		mat2[i] = new int[3];
	}
	cout << "Please enter the value in matrix A:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> mat1[i][j];
		}
	}
	cout << "Please enter the value in matrix B:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> mat2[i][j];
		}
	}
	system("cls");
	cout << endl;
	additionmat(mat1, mat2);
	cout << endl;
	multiplicationMat(mat1, mat2);
}