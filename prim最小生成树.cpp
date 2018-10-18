#include<iostream>
#include<fstream>
using namespace std;
#define N 6  
int COST[N + 1][N + 1], mincost = 1000;
int T[N][3], NEAR[N + 1];
void InputData() 
{
	ifstream fin;
	fin.open("数据.txt");
	for (int i = 1; i <= N; i++)
	for (int j = 1; j <= N; j++)
		fin >> COST[i][j];
}
void main()
{
	InputData();
	int k, l;
	for (int i = 1; i <= N; i++)
	for (int j = 1; j <= N; j++)
	if (COST[i][j]<mincost&&COST[i][j]>0){ mincost = COST[i][j]; k = i; l = j; }
	T[1][1] = k; T[1][2] = l;
	for (int i = 1; i <= N; i++)   
	if (COST[i][l]>0 && COST[i][k]>0)
	{
		if (COST[i][l]<COST[i][k]) NEAR[i] = l;
		else NEAR[i] = k;
	}
	NEAR[k] = 0; NEAR[l] = 0;
	for (int i = 2; i<N; i++)
	{
		int min = 1000, flag;
		for (int j = 1; j <= N; j++) 
		{
			if (NEAR[j] != 0)
			{
				if (COST[j][NEAR[j]]<min && COST[j][NEAR[j]]>0)
				{
					min = COST[j][NEAR[j]]; flag = j;
				}
			}
		}
		
		T[i][1] = flag; T[i][2] = NEAR[flag];
		mincost = mincost + COST[flag][NEAR[flag]];
		NEAR[flag] = 0;
		for (int m = 1; m <= N; m++)   
		{
			if (NEAR[m] != 0 && COST[m][NEAR[m]]>COST[m][flag] && COST[m][NEAR[m]]>0)
				NEAR[m] = flag;
		}
	}
	

	cout << "T数组(点-点-权值):\n";
	for (int m = 1; m<N; m++)
	{
		cout << T[m][1] << " " << T[m][2] << " " << COST[T[m][1]][T[m][2]] << endl;
	}


	if (mincost>1000) cout << "没有生成树!";   
	else cout << "最小生成树总路径长度:" << mincost << endl;
}