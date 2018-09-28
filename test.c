#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortCollection.h"

typedef struct{
	SqList data;
	SqList sarr;
}readData;

void readFileHander(char *filename,void *wrap);
void commonSetData(char *ch,SqList *data);
void getShellData(char *ch,void *dArr);
void getShellArr(char *ch,void *sArr);
void getBubbleData(char *ch,void *bll);
void visitSqList(SqList sl);

int main(int argc,char *argv[]){
	if( argc >= 2){
		if( strcmp(argv[1],"-shs")==0 ){//希尔排序
			readData wrap = {{NULL,0},{NULL,0}};

			readFileHander("data.txt",&wrap);
			printf("希尔排序\nbefore sort:");
			visitSqList(wrap.data);
			ShellSort(&wrap.data,wrap.sarr.array,wrap.sarr.length);
			printf("\nafter sort:");
			visitSqList(wrap.data);
			printf("\n");
		}else if( strcmp(argv[1],"-bs")==0 ){//冒泡排序
			SqList bubble = {NULL,0};

			readFileHander("data.txt",&bubble);
			printf("冒泡排序\nbefore sort:");
			visitSqList(bubble);
			BubbleSort(&bubble);
			printf("\nafter sort:");
			visitSqList(bubble);
			printf("\n");
		}
	}

	return 0;
}

void readFileHander(char *filename,void *wrap){
	FILE *fp = fopen(filename,"r");

	if( fp ){
		char *read = NULL;
		size_t getSize = 0;

		while( getline(&read, &getSize, fp) != -1 ){
			getSize = 0;
			getShellData(read,wrap);
			getShellArr(read,wrap);
			getBubbleData(read,wrap);
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

void getShellData(char *ch,void *dArr){
	if( strstr(ch,"shellSortData")==ch ){//获取待排数组
		char *dataStr = strchr(ch,':');
		SqList *data = &((readData*)dArr)->data;

		if( dataStr ){
			commonSetData(dataStr+1, data);
		}
	}
}

void getShellArr(char *ch,void *sArr){
	if( strstr(ch,"shellSortArr")==ch ){//获取分组间隔数组
		char *dataStr = strchr(ch,':');
		SqList *data = &((readData*)sArr)->sarr;

		if( dataStr ){
			commonSetData(dataStr+1, data);
		}
	}
}

void getBubbleData(char *ch,void *bll){
	if( strstr(ch,"bubbleSortData")==ch ){
		char *dataStr = strchr(ch,':');
		SqList *sl = (SqList*)bll;

		if( dataStr ){
			commonSetData(dataStr+1, sl);
		}
	}
}

void visitSqList(SqList sl){
	for(int i = 0; i < sl.length; ++i){
		printf("%-3d", sl.array[i]);
	}
}
