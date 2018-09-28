#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortCollection.h"

void readFileHander(char *filename,void *wrap,char *keyword);
void commonSetData(char *ch,SqList *data);
void visitSqList(SqList sl);

int main(int argc,char *argv[]){
	if( argc >= 2){
		if( strcmp(argv[1],"-shs")==0 ){//希尔排序
			SqList nSort = {NULL,0},arr = {NULL,0};

			readFileHander("data.txt",&nSort,"shellSortData");
			readFileHander("data.txt",&arr,"shellSortArr");
			printf("希尔排序\nbefore sort:");
			visitSqList(nSort);
			ShellSort(&nSort,arr.array,arr.length);
			printf("\nafter sort:");
			visitSqList(nSort);
			printf("\n");
		}else if( strcmp(argv[1],"-bs")==0 ){//冒泡排序
			SqList bubble = {NULL,0};

			readFileHander("data.txt",&bubble,"bubbleSortData");
			printf("冒泡排序\nbefore sort:");
			visitSqList(bubble);
			BubbleSort(&bubble);
			printf("\nafter sort:");
			visitSqList(bubble);
			printf("\n");
		}else if( strcmp(argv[1],"-qs")==0 ){//快速排序
			SqList qsl = {NULL,0};

			readFileHander("data.txt",&qsl,"quickSortData");
			printf("快速排序\nbefore sort:");
			visitSqList(qsl);
			QSort(&qsl, 0, qsl.length-1);
			printf("\nafter sort:");
			visitSqList(qsl);
			printf("\n");
		}else if( strcmp(argv[1],"-ses")==0 ){//选择排序
			SqList qsl = {NULL,0};

			readFileHander("data.txt",&qsl,"selectSortData");
			printf("选择排序\nbefore sort:");
			visitSqList(qsl);
			SelectionSort(&qsl);
			printf("\nafter sort:");
			visitSqList(qsl);
			printf("\n");
		}
	}

	return 0;
}

void readFileHander(char *filename,void *wrap,char *keyword){
	FILE *fp = fopen(filename,"r");

	if( fp ){
		char *read = NULL;
		size_t getSize = 0;

		while( getline(&read, &getSize, fp) != -1 ){
			getSize = 0;
			if( strstr(read,keyword)==read ){
				char *start = strchr(read,':');
				SqList *data = (SqList*)wrap;

				commonSetData( start+1, data);
				break;
			}
		}
	}
}

void commonSetData(char *ch,SqList *data){
	char seperator[] = " \n";
	size_t curlen = 0,
		   dslen = strlen(ch);
	
	for(size_t i = 0; i < dslen; ++i){
		if( ch[i]==' ' || ch[i]=='\n' ){
			curlen++;
		}
	}
	
	data->array = (int*)malloc(curlen * sizeof(int));
	if( data->array ){
		char *delim = NULL;
		
		data->length = curlen;
		curlen = 0;//此处做为数组序号
		delim = strtok(ch, seperator);
		if( delim ){
			data->array[curlen++] = atoi(delim);
			while( delim = strtok(NULL, seperator) ){
				data->array[curlen++] = atoi(delim);
			}
		}				
	}
}

void visitSqList(SqList sl){
	for(int i = 0; i < sl.length; ++i){
		printf("%-3d", sl.array[i]);
	}
}
