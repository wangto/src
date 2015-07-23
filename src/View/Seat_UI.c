/*************************************************************************
	> File Name: Seat_UI.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Thu 02 Jul 2015 11:48:33 AM EDT
 ************************************************************************/

#include<stdio.h>
#include"Seat_UI.h"

void Seat_UI_MgtEntry(void)
{
    int choice;
    initiatee();
    while(1){
    printf("**************************\n");
    printf("*\t1、添加座位     *\n");
    printf("*\t2、修改座位     *\n");
    printf("*\t3、删除座位     *\n");
    printf("*\t4、返回上一级   *\n");
    printf("**************************\n");
    printf("请选择:");
    scanf("%d", &choice);
    switch(choice){
        case 1:
                Seat_UI_Add();
                break;
        case 2:
                printf("请输入座位ID：");
                scanf("%d", &choice);
                Seat_UI_Modify(choice);
                break;
        case 3:
                printf("请输入座位ID：");
                scanf("%d", &choice);
                Seat_UI_Delete(choice);
                break;
        case 4:
                return;
        }
    }
}



void Seat_UI_Add(void)
{
    Seat_Srv_AddBatch();
}


void Seat_UI_Modify(int id)
{
    Seat_Srv_Modify(id);
}

void Seat_UI_Delete(int id)
{
    Seat_Srv_DeleteByID(id);
}

/*int main()
{
    Seat_UI_MgtEntry();
}*/


