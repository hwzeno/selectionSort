/*********************************
    > File Name: heapAdjust.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月11日 星期五 21时12分30秒
 ********************************/
#include<stdio.h>
#define LT(a, b) ((a) < (b))

void heapAdjust(int array[], int s, int m);
int main()
{
	int i = 0;
	
	int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	heapAdjust(arr, 0, 8);
	
	for(i = 0; i < 9; ++i)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}
void heapAdjust(int array[], int s, int m)
{
	int rc = 0;
	int j = 0;
	rc = array[s];
	for(j = 2 * s; j <= m; j *=2)
	{
		if(j < m && LT(array[j], array[j + 1]))
			++j;
		if(! LT(rc, array[j]))
			break;
		array[s] = array[j];
		s = j;
	}
	array[s] = rc;
}//heapAdjust

