#include "sortCollection.h"

void switchData(int *arr,int a,int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

//希尔排序
void ShellSort(SqList *l,int *delta,int t){
	for(int i = 0; i < t; ++i){
		ShellInsert(l, delta[i]);
	}
}

//希尔插入排序
void ShellInsert(SqList *l,int dk){
	for(int i = dk; i < l->length; ++i){
		if( LT(l->array[i], l->array[i-dk]) ){
			int temp = l->array[i],
				j = i - dk;

			for( ; j>=0 && LT(temp, l->array[j]); j -= dk ){
				l->array[j+dk] = l->array[j];
			}
			l->array[j+dk] = temp;
		}
	}
}

//冒泡排序
void BubbleSort(SqList *l){
	for(int i = 0; i < l->length; ++i){
		for(int j = l->length - 1; j > i; --j){
			if( LT(l->array[j], l->array[j-1]) ){
				int temp = l->array[j];
				l->array[j] = l->array[j-1];
				l->array[j-1] = temp;
			}
		}
	}
}

/*快速排序*/
int partition(SqList *l,int low,int high){
	int cur = l->array[low];

	while( low < high ){
		for( ; low<high && GQ(l->array[high], cur); --high);
		switchData(l->array,low,high);
		for( ; low<high && LQ(l->array[low], l->array[high]); ++low);
		switchData(l->array,low,high);
	}
	l->array[low] = cur;
	
	return low;
}

void QSort(SqList *l,int low,int high){
	if( low < high ){
		int ptin = partition(l, low, high);
		QSort(l, low, ptin-1);
		QSort(l, ptin+1, high);
	}
}

/************************选择排序***********************/
int selectionMinKey(SqList *l,int start){
	int minIndex = start;

	for(int i = start+1; i < l->length; ++i){
		if( LT(l->array[i], l->array[minIndex]) ){
			minIndex = i;
		}
	}

	return minIndex;
}

void SelectionSort(SqList *l){
	for(int i = 0; i < l->length; ++i){
		int j = selectionMinKey(l, i);

		if( j != i ){
			switchData(l->array, i, j);
		}
	}
}

