/*************************************************************************
	> File Name: Studio_Persist.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Sat 27 Jun 2015 04:30:55 AM EDT
 ************************************************************************/

#include<stdio.h>
#include"Studio_Persist.h"
#include<stdlib.h>
int Studio_Perst_Insert(const studio_t data)
{
    FILE *fp;
    if((fp = fopen("STUDIO_DATA_FILE", "a+")) == NULL){
        printf("打开文件失败\n");
        exit(0);
    }
     fwrite(&data,sizeof(studio_t),1,fp);
    fclose(fp);
     return 0;
}


int Studio_Perst_Update(void)
{
    FILE *fp;
    if((fp = fopen("STUDIO_DATA_FILE", "w")) == NULL){
        printf("打开文件失败\n");
        exit(0);
    }
    fclose(fp);
    fp = fopen("STUDIO_DATA_FILE", "a");
    studio_list_t p1 = p->next;                  //p in  Studio.c
    int id = (p1->data).id;
    p1 = p->next;
    while(id != (p1->data).id){
    p1 = p1->next;
    fwrite(&p1->data, sizeof (studio_t), 1, fp);
    }
    fclose(fp);
    return 0;
}
    


int Studio_Perst_DeletebyID(void)
{
    Studio_Perst_Update();
    return 0;
}

