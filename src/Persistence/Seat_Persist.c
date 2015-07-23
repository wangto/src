/*************************************************************************
	> File Name: Seat_Persist.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Wed 01 Jul 2015 02:37:57 AM EDT
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"../Service/Seat.h"
#include"Seat_Persist.h"
extern seat_list_t p; 

void Seat_Perst_Insert(seat_t data)
{
    FILE *fp;
    if((fp = fopen("Seat_DATA_FILE", "a+")) == NULL){
        printf("打开文件失败\n");
        exit(0);
    }
     fwrite(&data, sizeof(seat_t), 1, fp);
    fclose(fp);
   //  return 0;
}

void Seat_Perst_InsertBatch(void)
{
    FILE *fp;
    if((fp = fopen("Seat_DATA_FILE", "w")) == NULL){
        printf("打开文件失败\n");
        exit(0);
    }
    fclose(fp);
    fp = fopen("Seat_DATA_FILE", "a");
    studio_list_t p1 = p->next;                  //p in  Studio.c
    int id = (p1->data).id;
    p1 = p->next;
    while(id != (p1->data).id){
    p1 = p1->next;
    fwrite(&p1->data, sizeof (seat_t), 1, fp);
    }
    fclose(fp);
    //return 0;

}

void Seat_Perst_Update(void)
{
    
    FILE *fp;
    if((fp = fopen("Seat_DATA_FILE", "w")) == NULL){
        printf("打开文件失败\n");
        exit(0);
    }
    fclose(fp);
    fp = fopen("Seat_DATA_FILE", "a");
    studio_list_t p1 = p->next;                  //p in  Studio.c
    int id = (p1->data).id;
    p1 = p->next;
    while(id != (p1->data).id){
    p1 = p1->next;
    fwrite(&p1->data, sizeof (seat_t), 1, fp);
    }
    fclose(fp);
   // return 0;

}


void Seat_Perst_DeleteAllByRoomID(int id)
{
    



}

void Seat_Perst_DeleteByID(void)
{
    

}

void Seat_Perst_SelectByRoomID(int id)
{
    



}

void Seat_Perst_SelectByID(int id)
{
    

}

void Seat_Perst_SelectByAll(void)
{
    


    
}
