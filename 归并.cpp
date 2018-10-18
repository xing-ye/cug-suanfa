#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;
#define NUM 500
char filename[] = "数据.txt";
int data[NUM + 1];
int LINK[NUM + 1] = { 0 };
#define INFINITE 10000  
void Readdata()   
{
	ifstream fin;
	fin.open(filename);
	for (int i = 1; i<NUM + 1; i++)
		fin >> data[i];
	cout << "初始数据:\n";
	for (int i = 1; i<NUM + 1; i++)
	{
		cout.width(4);
		cout << data[i] << " ";
	}
	cout << endl;
}

void INSERTSORT(int low, int high, int &p)  
{
	int MIN = data[low], item = INFINITE;
	p = low;                                
	for (int i = low; i<high; i++)
	{
		item = INFINITE; LINK[i] = 0;
		if (data[i]<MIN) { p = i; MIN = data[i]; }
		for (int j = low; j<high; j++)
		{
			if (data[i]<data[j] && data[j]<item)
			{
				LINK[i] = j;
				item = data[j];
			}
		}
	}
}
void MERGE1(int q, int r, int &p)
{
	int i = q, j = r, k = 0;
	while (i != 0 && j != 0)          
	{
		if (data[i] <= data[j]) 	 
		{
			LINK[k] = i;
			k = i;
			i = LINK[i];
		}                     
		else
		{
			LINK[k] = j;
			k = j;
			j = LINK[j];
		}
	}
	if (i == 0) LINK[k] = j;
	else LINK[k] = i;
	p = LINK[0];
}
void MERGESORT1(int low, int high, int &p)
{
	int mid, q, r;
	if (high - low <= 10)
		INSERTSORT(low, high, p);
	else
	{
		mid = (low + high) / 2;
		MERGESORT1(low, mid, q);
		MERGESORT1(mid, high, r);
		MERGE1(q, r, p);
	}
}
void main()
{
	ofstream fout;
	fout.open("结果.txt");   
	int p;
	Readdata();
	MERGESORT1(1, NUM + 1, p);
	cout << "排序后值:" << endl;
	for (int i = 1; i<NUM + 1; i++)
	{
		cout << data[p] << "\t";
		p = LINK[p];
		fout << data[p] << "\t";
	}
}