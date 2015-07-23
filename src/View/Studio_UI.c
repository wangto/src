/*************************************************************************
	> File Name: Studio_UI.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Thu 02 Jul 2015 09:28:21 AM EDT
 ************************************************************************/

#include<stdio.h>
#include"Studio_UI.h"
//studio_list_t p;
void Studio_UI_MgtEntry(void)
{
    initiate();
    int choice, i;
    while(1){
    printf("********************************\n");
    printf("*\t1、添加新演出厅        *\n");
    printf("*\t2、根据ID修改演出厅    *\n");
    printf("*\t3、根据ID删除演出厅    *\n");
    printf("*\t4、返回上一级          *\n");
    printf("********************************\n");
    printf("请选择:");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
                Studio_UI_Add();
                break;
        case 2:
                printf("请输入ID：");
                scanf("%d", &i);
                Studio_UI_Modify(i);
                break;
        case 3:
                printf("请输入ID：");
                scanf("%d", &i);
                Studio_UI_Delete(i);
                break;
        case 4:
                return;
    }
    }
}


int Studio_UI_Add(void)
{
    Studio_Srv_Add();
    return 0;
}

int Studio_UI_Modify(int id)
{
    Studio_Srv_Modify(id);
    return 0;
}

int Studio_UI_Delete(int id)
{
    Studio_Srv_DeleteByID(id);
    return 0;
}

