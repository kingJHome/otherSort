#include "sortCollection.h"

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
