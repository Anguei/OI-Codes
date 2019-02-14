
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<fstream>
#include<ctime>
#include<sstream> 
#include<cstring>

short run = 0;
int number;
int GetBitLength(int n);
int GetNumber();
double GetBitofZero(int z);
char* Initialize(int);
void PrintValue(char *a, int size);
char* GetValue(int val);
char* SubGetValue(char*, int);
int size_tmp;
int factor5_count = 0;//0个数 

using namespace std;

stringstream ss;
string fn,s_value;
string title="title yyf+zyf ";

int main()
{
	int T;
	cin>>T;
	while(T--){
	int value = GetNumber();
	int n=value;
	int size = GetBitLength(value);
	char *pa = Initialize(size);
	pa = GetValue(value);
	PrintValue(pa, size);
	delete[]pa;}
	return 0;
}

char* GetValue(int val)
{
	int VALUE = val;
	int length = GetBitLength(VALUE);
	char *arrValue = new char[length];
	arrValue[0] = 1;
	for (int i = 1; i<length; i++)
		arrValue[i] = 0;
	arrValue = SubGetValue(arrValue, VALUE);
	return arrValue;
}
char* SubGetValue(char* arrValue, int n)
{
	int index = 0;
	long carrier = 0;
	double bitCount = 1;
	int begin = 0;

	for (index = 2; index <= n; ++index)
	{
		long multiValue = 0;
		bitCount += log10((long double)index);
		if (arrValue[begin] == 0)
			begin++;

		for (int j = begin; j<int(bitCount); ++j)
		{
			multiValue += (index*arrValue[j]);
			arrValue[j] = char(multiValue % 10);
			multiValue /= 10;
		}
	}
	return arrValue;
}
int GetNumber()
{
	int n;
	cin>>n;
	return n;
}
void PrintValue(char *buff, int buffLen)
{
	int nCol = 0;
	for (int i = buffLen - 1; i >= 0; i--)
	{
		cout << int(buff[i]);
	}
	cout<<endl;
}
char * Initialize(int size)
{
	char *arrValue = new char[size];
	size_tmp=size;
	arrValue[0] = 1;
	for (int i = 1; i<size; i++)
		arrValue[i] = 0;
	return arrValue;
}
int GetBitLength(int n)
{
	double sum = 1.0;
	for (int i = 1; i <= n; i++)
		sum += log10((long double)i);
	return int(sum);
}