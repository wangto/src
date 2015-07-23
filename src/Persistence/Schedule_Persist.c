/*************************************************************************
	> File Name: Schedule_Persist.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Wed 01 Jul 2015 02:58:03 AM EDT
 ************************************************************************/

#include<stdio.h>
#include"Schedule_Persist.h"
#include<stdlib.h>
extern schedule_list_t p;
void Schedule_Perst_SelectByPlay(int id)
{

}


void Schedule_Perst_Insert(const schedule_t data)
{
    FILE *fp;
    if((fp = fopen("SCHEDULE_DATA_FILE", "a+")) == NULL){
        printf("打开文件失败\n");
        exit(0);
    }
     fwrite(&data, sizeof(schedule_t), 1, fp);
    fclose(fp);
}


void Schedule_Perst_Update(void)
{
    FILE *fp;
    if((fp = fopen("SCHEDULE_DATA_FILE", "w")) == NULL){
        printf("打开文件失败\n");
        exit(0);
    }
    fclose(fp);
    fp = fopen("SCHEDULE_DATA_FILE", "a");
    studio_list_t p1 = p->next;               
    int id = (p1->data).id;
    p1 = p->next;
    while(id != (p1->data).id){
    p1 = p1->next;
    fwrite(&p1->data, sizeof (schedule_t), 1, fp);
    }
    fclose(fp);


}


void Schedule_Perst_DeleteByID(void)
{
    Schedule_Perst_Update();

}


void Schedule_Perst_SelectByID(int id)
{

}


void Schedule_Perst_SelectAll(void)
{
    
}


