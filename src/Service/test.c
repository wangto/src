/*************************************************************************
	> File Name: test.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Thu 02 Jul 2015 05:28:41 PM EDT
 ************************************************************************/

#include<stdio.h>
typedef struct{
                int id;
                char name[30];
                int rowsCount;
                int colsCount;
}studio_t;

int main()
{
    FILE *fp;
    studio_t data;
    fp = fopen("STUDIO_DATA_FILE","r");
    fread(&data, sizeof(studio_t), 1, fp);
    printf("%d%s%d%d",data.id,data.name,data.rowsCount,data.colsCount);   

}
