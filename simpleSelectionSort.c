/*********************************
    > File Name: simpleSelectionSort.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月09日 星期三 21时00分36秒
 ********************************/
#include<stdio.h>
void selectSort(int array[], int length);
int selectMinKey(int array[], int length, int currentPosition);
int main()
{
	int i = 0;
	int arr[9] = {9, 8, 7, 6,  5, 4, 3, 2, 1};
	selectSort(arr, 9);
	for(i = 0; i < 9; i++)
		printf("%d\t", arr[i]);
	printf("\n");
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
	printf("%d\t", minPos);
	printf("\n");
	return minPos;
}
