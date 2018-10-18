#include<iostream>
#include<fstream>
using namespace std;
#define N 6
int mincost = 0, COST[N + 1][N + 1];
int P[N + 1] = { -1 }, T[N][3];
struct EDGE   
{
	int sour; 
	int dest;    
	int weight;  
};
EDGE E[ (N*N - N) / 2 + 1];
int edgenum = 0;  
void InputData()   
{
	ifstream fin;
	fin.open("数据.txt");
	for (int i = 1; i <= N; i++)
	for (int j = 1; j <= N; j++)
		fin >> COST[i][j];
	for (int i = 1; i <= N; i++)
	for (int j = i + 1; j <= N; j++)
	if (COST[i][j]>0 && COST[i][j]<100){ E[edgenum].sour = i; E[edgenum].dest = j; E[edgenum].weight = COST[i][j]; edgenum++; }
}

void CreatHeap(EDGE a[], int n, int head)
{
	int i = head, j = 2 * i + 1, flag = 0; EDGE temp = a[i];
	while (j<n && flag != 1)
	{
		if (j<n - 1 && a[j].weight>a[j + 1].weight) j++;  
		if (temp.weight < a[j].weight) flag = 1;   
		else{ a[i] = a[j]; i = j; j = 2 * i + 1; }   
	}
	a[i] = temp;  
}
int FIND(int i)
{
	int j = i, k, t;
	while (P[j]>0)j = P[j];
	k = i;
	while (k != j){ t = P[k];	P[k] = j;	k = t; }
	return j;
}

int UNION(int i, int j)
{
	int x = P[i] + P[j];
	if (P[i]>P[j]){ P[i] = j; P[j] = x; }
	else{ P[j] = i; P[i] = x; }
	return 1;
}
void main()
{
	int u, v, m, n;
	InputData();
	
	for (int i = (edgenum - 1) / 2; i >= 0; i--)   
		CreatHeap(E, edgenum, i);
	int j = 0;
	cout << "选择的边信息:" << endl;
	for (int i = edgenum - 1; i >= 0; i--)  
	{
		EDGE temp = E[0];
		E[0] = E[i];
		E[i] = temp;
		CreatHeap(E, i, 0);

		m = temp.sour; n = temp.dest;
		u = FIND(m);
		v = FIND(n);
		if (u != v)   
		{
			T[j][1] = u; T[j][2] = v;
			  j++;
			 cout << m << "\t" << n << "\t" << temp.weight << endl;  
			mincost = mincost + temp.weight;
			UNION(u, v);
		}
	}
	cout << "最小生成树路径长度:" << mincost << endl;
}