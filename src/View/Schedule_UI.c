/*************************************************************************
	> File Name: Schedule_UI.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Thu 02 Jul 2015 09:37:26 PM EDT
 ************************************************************************/

#include<stdio.h>
#include"../Service/Schedule.h"
#include"../Persistence/Schedule_Persist.h"
#include"Schedule_UI.h"

void Schedule_UI_MgtEntry(void)
{
    int choice;
    initiateq();
    while(1){
    printf("********************************\n");
    printf("*\t1、添加演出计划        *\n");
    printf("*\t2、修改演出计划        *\n");
    printf("*\t3、据ID删除演出计划    *\n");
    printf("*\t4、据ID获取演出计划    *\n");
    printf("*\t5、获取所有演出计划    *\n");
    printf("*\t6、返回上一层          *\n");
    printf("********************************\n");
    printf("请选择:");
    scanf("%d", &choice);
    switch(choice){
                    case 1:
                            Schedule_UI_Add();
                            break;
                    case 2:
                            printf("请输入要修改的演出计划ID：");
                            scanf("%d", &choice);
                            Schedule_UI_Modify(choice);
                            break;
                    case 3:
                            printf("请输入要删除的演出计划ID：");
                            scanf("%d", &choice);
                            Schedule_UI_Delete(choice);
                            break;
                    case 4:
                            printf("请输入要获取的演出计划ID：");
                            scanf("%d", &choice);
                            Schedule_UI_Query(choice);
                            break;
                    case 5:
                            Schedule_UI_FetchAll();
                            break;
                    case 6:
                            return;
    }

    }
}

void Schedule_UI_Add()
{
 Schedule_Srv_Add();
    
}


void Schedule_UI_Modify(int choice)
{
 Schedule_Srv_Modify(choice);
    
}


void Schedule_UI_Delete(int choice)
{
 Schedule_Srv_DeleteByID(choice);
    
}


void Schedule_UI_Query(int choice)
{
    
Schedule_Srv_FetchByID(choice);
}

void Schedule_UI_FetchAll(void)
{
   Schedule_Srv_FetchAll(); 
}

/*int main()
{
    Schedule_UI_MgtEntry();

}*/
