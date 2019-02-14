#include<stdio.h>

unsigned a[100 + 10];

int main()
{
    int size = 0;
    while (~scanf("%d ", &a[size++]));
    for (int i = size - 3; i >= 0; --i)
        printf("%d ", a[i]);
}