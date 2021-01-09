#include<iostream>
using namespace std;

class UndirectedGraph
{
public:
	int Vertices;
	int Edges;
	int** mat;
	UndirectedGraph(int n, int m)
	{
		Vertices = n;
		Edges = m;
		mat = new int* [Vertices + 1];
		for (int i = 0; i < Vertices + 1; i++)
		{
			mat[i] = new int[Vertices + 1];
		}
		for (int i = 1; i < Vertices + 1; i++)
		{
			for (int j = 1; j < Vertices + 1; j++)
			{
				mat[i][j] = 0;
			}
		}
	}
	void AddEdge(int n1, int n2)
	{
		mat[n1][n2] = 1;
		mat[n2][n1] = 1;
	}
	void Display()
	{
		cout << "Adjcancy Matrix of the given undirected graph is:-" << endl;
		cout << "   ";
		for (int j = 1; j < Vertices + 1; j++)
			cout << j << "    ";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
			cout << "-----";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
		{
			cout << j << "| ";
			for (int k = 1; k < Vertices + 1; k++)
			{
				cout << mat[j][k] << "    ";
			}
			cout << endl << endl;
		}
	}

};

class DirectedGraph
{
public:
	int Vertices;
	int Edges;
	int** mat;
	DirectedGraph(int n, int m)
	{
		Vertices = n;
		Edges = m;
		mat = new int* [Vertices + 1];
		for (int i = 0; i < Vertices + 1; i++)
		{
			mat[i] = new int[Vertices + 1];
		}
		for (int i = 1; i < Vertices + 1; i++)
		{
			for (int j = 1; j < Vertices + 1; j++)
			{
				mat[i][j] = 0;
			}
		}
	}
	void AddEdge(int n1, int n2)
	{
		mat[n1][n2] = 1;
	}
	void Display()
	{
		cout << "Adjcancy Matrix of the given directed graph is:-" << endl;
		cout << "   ";
		for (int j = 1; j < Vertices + 1; j++)
			cout << j << "    ";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
			cout << "-----";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
		{
			cout << j << "| ";
			for (int k = 1; k < Vertices + 1; k++)
			{
				cout << mat[j][k] << "    ";
			}
			cout << endl << endl;
		}
	}

};

class WeightedGraph
{
public:
	int Vertices;
	int Edges;
	int** mat;
	WeightedGraph(int n, int m)
	{
		Vertices = n;
		Edges = m;
		mat = new int* [Vertices + 1];
		for (int i = 0; i < Vertices + 1; i++)
		{
			mat[i] = new int[Vertices + 1];
		}
		for (int i = 1; i < Vertices + 1; i++)
		{
			for (int j = 1; j < Vertices + 1; j++)
			{
				mat[i][j] = 0;
			}
		}
	}
	void AddEdge(int n1, int n2,int w)
	{
		mat[n1][n2] = w;
		mat[n2][n1] = w;
	}
	void Display()
	{
		cout << "Adjcancy Matrix of the given weighted graph is:-" << endl;
		cout << "   ";
		for (int j = 1; j < Vertices + 1; j++)
			cout << j << "    ";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
			cout << "-----";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
		{
			cout << j << "| ";
			for (int k = 1; k < Vertices + 1; k++)
			{
				cout << mat[j][k] << "    ";
			}
			cout << endl << endl;
		}
	}

};

class UnweightedGraph
{
public:
	int Vertices;
	int Edges;
	int** mat;
	UnweightedGraph(int n, int m)
	{
		Vertices = n;
		Edges = m;
		mat = new int* [Vertices + 1];
		for (int i = 0; i < Vertices + 1; i++)
		{
			mat[i] = new int[Vertices + 1];
		}
		for (int i = 1; i < Vertices + 1; i++)
		{
			for (int j = 1; j < Vertices + 1; j++)
			{
				mat[i][j] = 0;
			}
		}
	}
	void AddEdge(int n1, int n2)
	{
		mat[n1][n2] = 1;
		mat[n2][n1] = 1;
	}
	void Display()
	{
		cout << "Adjcancy Matrix of the given unweighted graph is:-" << endl;
		cout << "   ";
		for (int j = 1; j < Vertices + 1; j++)
			cout << j << "    ";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
			cout << "-----";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
		{
			cout << j << "| ";
			for (int k = 1; k < Vertices + 1; k++)
			{
				cout << mat[j][k] << "    ";
			}
			cout << endl << endl;
		}
	}

};

class BipertiteGraph
{
public:
	int Vertices;
	int Edges;
	int** mat;
	BipertiteGraph(int n, int m)
	{
		Vertices = n;
		Edges = m;
		mat = new int* [Vertices + 1];
		for (int i = 0; i < Vertices + 1; i++)
		{
			mat[i] = new int[Vertices + 1];
		}
		for (int i = 1; i < Vertices + 1; i++)
		{
			for (int j = 1; j < Vertices + 1; j++)
			{
				mat[i][j] = 0;
			}
		}
	}
	void AddEdge(int n1, int n2)
	{
		mat[n1][n2] = 1;
		mat[n2][n1] = 1;
	}
	void Display()
	{
		cout << "Adjcancy Matrix of the given Bipertit graph is:-" << endl;
		cout << "   ";
		for (int j = 1; j < Vertices + 1; j++)
			cout << j << "    ";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
			cout << "-----";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
		{
			cout << j << "| ";
			for (int k = 1; k < Vertices + 1; k++)
			{
				cout << mat[j][k] << "    ";
			}
			cout << endl << endl;
		}
	}

};

class CompleteGraph
{
public:
	int Vertices;
	int Edges;
	int** mat;
	CompleteGraph(int n, int m)
	{
		Vertices = n;
		Edges = m;
		mat = new int* [Vertices + 1];
		for (int i = 0; i < Vertices + 1; i++)
		{
			mat[i] = new int[Vertices + 1];
		}
		for (int i = 1; i < Vertices + 1; i++)
		{
			for (int j = 1; j < Vertices + 1; j++)
			{
				mat[i][j] = 0;
			}
		}
	}
	void AddEdge(int n1, int n2)
	{
		mat[n1][n2] = 1;
		mat[n2][n1] = 1;
	}
	void Display()
	{
		cout << "Adjcancy Matrix of the given complete graph is:-" << endl;
		cout << "   ";
		for (int j = 1; j < Vertices + 1; j++)
			cout << j << "    ";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
			cout << "-----";
		cout << endl;
		for (int j = 1; j < Vertices + 1; j++)
		{
			cout << j << "| ";
			for (int k = 1; k < Vertices + 1; k++)
			{
				cout << mat[j][k] << "    ";
			}
			cout << endl << endl;
		}
	}

};

int main()
{
	int n, m;
	n = 6;
	m = 9;
	UndirectedGraph G1(n, m);
	G1.AddEdge(1,2);
	G1.AddEdge(1,3);
	G1.AddEdge(1,4);
	G1.AddEdge(1,5);
	G1.AddEdge(2,4);
	G1.AddEdge(2,5);
	G1.AddEdge(3,6);
	G1.AddEdge(4,6);
	G1.AddEdge(5,6);
	G1.Display();
	cout << endl;
	n = 5;
	m = 5;
	DirectedGraph G2(n, m);
	G2.AddEdge(1,4);
	G2.AddEdge(2,4);
	G2.AddEdge(2,5);
	G2.AddEdge(4,5);
	G2.AddEdge(3,5);
	G2.Display();
	cout << endl;
	n = 5;
	m = 6;
	WeightedGraph G3(n, m);
	G3.AddEdge(1,2,2);
	G3.AddEdge(1,3,3);
	G3.AddEdge(2,4,2);
	G3.AddEdge(2,3,5);
	G3.AddEdge(4,5,6);
	G3.AddEdge(5,3,7);
	G3.Display();
	cout << endl;
	n = 5;
	m = 5;
	UnweightedGraph G4(n, m);
	G4.AddEdge(1,2);
	G4.AddEdge(2,3);
	G4.AddEdge(3,4);
	G4.AddEdge(4,5);
	G4.AddEdge(5,2);
	G4.Display();
	cout << endl;
	n = 6;
	m = 7;
	BipertiteGraph G5(n, m);
	G5.AddEdge(1,4);
	G5.AddEdge(1,5);
	G5.AddEdge(1,6);
	G5.AddEdge(2,5);
	G5.AddEdge(2,6);
	G5.AddEdge(3,4);
	G5.AddEdge(3,6);
	G5.Display();
	cout << endl;
	n = 5;
	m = 10;
	CompleteGraph G6(n, m);
	G6.AddEdge(1,2);
	G6.AddEdge(1,3);
	G6.AddEdge(1,4);
	G6.AddEdge(1,5);
	G6.AddEdge(2,3);
	G6.AddEdge(2,4);
	G6.AddEdge(2,5);
	G6.AddEdge(3,4);
	G6.AddEdge(3,5);
	G6.AddEdge(4,5);
	G6.Display();
	cout << endl;
}