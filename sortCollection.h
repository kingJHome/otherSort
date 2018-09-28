#ifndef _OTHER_SORT_AL
#define _OTHER_SORT_AL

#define LT(a,b) ((a) < (b))
#define LQ(a,b) ((a) <= (b))
#define GT(a,b) ((a) > (b))
#define GQ(a,b) ((a) >= (b))

typedef struct{
	int *array;
	int length;
}SqList;

//希尔排序
void ShellSort(SqList *l,int *delta,int t);

//希尔插入排序
void ShellInsert(SqList *l,int dk);

//冒泡排序
void BubbleSort(SqList *l);

/***********************快速排序***********************/
int partition(SqList *l,int low,int high);

void QSort(SqList *sl,int low,int high);
/******************************************************/

/************************选择排序***********************/
int selectionMinKey(SqList *l,int start);

void SelectionSort(SqList *l);
/*******************************************************/
#endif
