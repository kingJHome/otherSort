#ifdef _OTHER_SORT_AL
#define _OTHER_SORT_AL

typedef struct{
	int *array;
	int length;
}SqList;

//希尔排序
void ShellSort(SqList *l,int *delta,int t);

//希尔插入排序
void ShellInsert(SqList *l,int dk);

#endif
