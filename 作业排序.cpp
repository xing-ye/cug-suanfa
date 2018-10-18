#include<iostream>
using namespace std;
#define MIN(x,y) x>y?y:x
int V[8] = { 0, 35, 30, 25, 20, 15, 10, 5 };  
int D[8] = { 0, 4, 2, 4, 3, 4, 8, 3 };   
int J[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };     
int P[8];    
int F[8];   
int k = 0;
int n = 8;    
int FIND(int i)
{
	int j, k, t;
	j = i;
	while (P[j]>0)
		j = P[j];
	k = i;
	while (k != j)
	{
		t = P[k];
		P[k] = j;
		k = t;
	}
	return j;
}
int UNION(int i, int j)
{
	int x;
	x = P[i] + P[j];
	if (P[i]>P[j])
	{
		P[i] = j;   
		P[j] = x;
	}
	else
	{
		P[j] = i;    
		P[i] = x;
	}
	return 1;
}
void FJS()
{
	int j, l;
	for (int i = 0; i<n; i++) 
	{
		F[i] = i;
		P[i] = -1;
	}
	k = 0;
	for (int i = 1; i<n; i++)             
	{
		j = FIND(MIN(n, D[i]));
		if (F[j] != 0)                 
		{
			k = k + 1;
			J[k] = i;
			l = FIND(F[j] - 1);
			UNION(l, j);
			F[j] = F[l];
		}
	}
}
void main()
{
	FJS();
	cout << "选择的作业数:  " << k << endl;
	cout << "选择作业序号:  ";
	for (int i = 1; i<n; i++)
		cout << J[i] << "\t";
	cout << endl;
}