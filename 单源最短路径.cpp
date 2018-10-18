#include<iostream>
#include<fstream>
using namespace std;
#define N 3
int COST[N + 1][N + 1];
int A[N + 1][N + 1];
void ReadData(char* filename)
{
	ifstream fin;
	fin.open(filename);
	for (int i = 1; i <= N; i++)
	for (int j = 1; j <= N; j++)
		fin >> COST[i][j];
}
void ALL_PATHS()
{
	int i, j, k;
	for (i = 1; i <= N; i++)
	for (j = 1; j <= N; j++)
		A[i][j] = COST[i][j];
	for (k = 1; k <= N; k++)
	for (i = 1; i <= N; i++)
	for (j = 1; j <= N; j++)
	if (A[i][k] + A[k][j]<A[i][j]) A[i][j] = A[i][k] + A[k][j];
}
void main()
{
	ReadData("Êý¾Ý.txt");
	ALL_PATHS();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}

}