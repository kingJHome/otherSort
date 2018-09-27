#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortCollection.h"

typedef void (*fileHander)(char *content,void *setData);

typedef struct{
	SqList data;
	SqList sarr;
}readData;

void readFileHander(char *filename,readData *wrap,fileHander __hander,fileHander __ohander);
void getShellData(char *ch,void *dArr);
void getShellArr(char *ch,void *sArr);

int main(int argc,char *argv[]){
	if( argc >= 2){
		if( strcmp(argv[2],"-shs")==0 ){//希尔排序
			readData *wrap = (readData*)malloc(sizeof(readData));

			if( wrap ){
				wrap->data = {NULL,0};
				wrap->sarr = {NULL,0};
				readFileHander("data.txt",wrap,getShellData,getShellArr);
			}
		}
	}

	return 0;
}

void readFileHander(char *filename,readData *wrap,fileHander __hander,fileHander _ohander){
	FILE *fp = fopen(filename,"r");

	if( fp ){
		char *read = NULL;
		size_t getSize = 0;

		while( getline(&read, &getSize, fp) != -1 ){
			getSize = 0;
			__hander(read,&wrap->data);
			__ohander(read,&wrap->sarr);
		}
	}
}

void getShellData(char *ch,void *dArr){
	if( strstr(ch,"shellSortData")==ch ){//获取待排数组
	}
}

void getShellArr(char *ch,void **sArr){
	if( strstr(ch,"shellSortArr")==ch ){//获取分组间隔数组
	}
}
