#include <stdio.h>
#include <Windows.h>

#define LENGTH 10

void QuickSort(int[], int, int);
void PrintArray(int [], int, int, int, int, int);

void main()
{
	int arr[LENGTH] = { 10, 2, 20, 15, 7, 3, 4, 1, 9, 5 };
	int i;

	for (i = 0; i < LENGTH; i++)
		printf("%02d ", arr[i]);

	printf("\n");
	Sleep(3000);

	QuickSort(arr, 0, 9);

	system("cls");
	printf("Result : ");
	for (i = 0; i < LENGTH; i++)
		printf("%02d ", arr[i]);
	printf("\n");
}

void QuickSort(int arr[], int start, int end)
{
	int flag = start;
	int left = start + 1;
	int right = end;
	int temp;

	if (start == end)
		return;

	while (1){
		PrintArray(arr, left, right, start, end, flag);

		for (; left <= end; left++){
			if (arr[left] > arr[flag])	break;
			PrintArray(arr, left, right, start, end, flag);
		}

		for (; right > start; right--){
			if (arr[right] < arr[flag])	break;
			PrintArray(arr, left, right, start, end, flag);
		}

		if (left >= right)
			break;

		else{
			PrintArray(arr, left, right, start, end, flag);
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			PrintArray(arr, left, right, start, end, flag);
		}
	}

	PrintArray(arr, left, right, start, end, flag);
	temp = arr[flag];
	arr[flag] = arr[right];
	arr[right] = temp;
	PrintArray(arr, left, right, start, end, flag);

	//좌우로 분산해서 다시 정렬
	QuickSort(arr, start, right == start? right : right - 1);
	QuickSort(arr, right + 1, end);
}

void PrintArray(int arr[], int left, int right, int start, int end, int flag)
{
	int cnt;

	system("cls");
	for (cnt = 0; cnt < LENGTH; cnt++){
		if (cnt == left)	printf("[%02d] ", arr[cnt]);
		else if (cnt == flag)	printf("|%02d| ", arr[cnt]);
		else if (cnt == right)	printf("[%02d] ", arr[cnt]);
		else	printf("%02d   ", arr[cnt]);
	}
	printf("\n");
	for (cnt = 0; cnt < start; cnt++)
		printf("     ");
	for (cnt = start; cnt <= end; cnt++)
		printf("^^^^^");
	Sleep(2000);
}