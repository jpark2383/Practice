#include <iostream>
#include <climits>
#include <string.h>

using namespace std;

/* Rotate a NxN matrix by 90 degrees counter clockwise*/

void rotate(int ** matrix, int N)
{
	for(int i = 0; i < N/2; i++)
	{
		for(int j = i; j < N - i - 1; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][N-i-1];
			matrix[j][N-i-1] = matrix[N-i-1][N-j-1];
			matrix[N-i-1][N-j-1] = matrix[N-j-1][i];
			matrix[N-j-1][i] = temp;
		}
	}
}

void printMatrix(int ** matrix, int N)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int N;
	cout << "Enter N for NxN matrix:";
	cin >> N;
	int ** matrix = new int*[N];
	for(int i = 0; i < N; i++)
	{
		matrix[i] = new int[N];
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << "Rotated matrix by 90 degrees (CCW):\n";
	rotate(matrix, N);
	printMatrix(matrix, N);
	return 0;
}