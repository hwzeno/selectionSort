/*********************************
    > File Name: simpleSelectionSort_randomNum.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月11日 星期五 15时02分01秒
 ********************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000
int arr[N] = {0};
void selectSort(int array[], int length);
int selectMinKey(int array[], int length, int currentPosition);
int main()
{
	int i = 0;
	FILE *fr;
	fr = fopen("randomNum.txt", "r");
	if(fr == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	for(i = 0; i < N; i++)
	{
		fscanf(fr, "%d", &arr[i]);
	}
	clock_t bg, ed;
	bg = clock();
	selectSort(arr, N);
	ed = clock();
	printf("cost time for: %.15f\n", (double)(ed - bg)/CLOCKS_PER_SEC);
	FILE *fw;
	fw = fopen("aftersort.txt", "w");
	for(i = 0; i < N; i++)
	{
		fprintf(fw,"%d\t", arr[i]);
		if((i+1)%10 == 0)
			fprintf(fw, "%c", '\n');
	}
	return 0;
}
void selectSort(int array[], int length)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < length; ++i)
	{
		j = selectMinKey(array,length, i);
		if(j != 0 && i != j)
		{
			int temp = 0;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}
}
int selectMinKey(int array[], int length, int currentPosition)
{
	int i = 0;
	int minPos = 0;
	int temp = array[currentPosition];
	for(i = currentPosition + 1; i < length; i++)
	{
		if(array[i]  < temp)
		{
			temp = array[i];
			minPos = i;
		}

	}
	return minPos;
}
