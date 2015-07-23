#include<stdio.h>
#include"Sale_UI.h"
void Sale_UI_MgtEntry(void)
{
    int choice;
    initiatec();
    while(1){
    printf("*********************************\n");
    printf("*\t1、售票                 *\n");
    printf("*\t2、退票                 *\n");
    printf("*\t3、据演出ID显示演出票   *\n");
    printf("*\t4、据剧目ID显示演出计划 *\n");
    printf("*\t5、返回上一级           *\n");
    printf("*********************************\n");
    printf("请选择：");
    scanf("%d", &choice);
    switch(choice){
            case 1:
                    Sale_UI_SellTicket();
                    break;
            case 2:
                    printf("请输入票ID：");
                    scanf("%d", &choice);
                    Sale_UI_ReturnTicket(choice);
                    break;
            case 4:
                    printf("请输入剧目ID：");
                    scanf("%d", &choice);
                    Sale_UI_ShowScheduler(choice);
                    break;
            case 3:
                    printf("请输入计划演出ID：");
                    scanf("%d", &choice);
                    Sale_UI_ShowTicket(choice);
                    break;
            case 5:
                    return;
    }
    }
}

void Sale_UI_SellTicket(void)
{
     Sale_Srv_Add();
}

 
void Sale_UI_ReturnTicket(int choice)
{
    
 Sale_Srv_DeleteByID(choice);
}

void Sale_UI_ShowScheduler(int choice)
{
    

}

void Sale_UI_ShowTicket(int choice)
{
    
}
/*int main()
{
    
 Sale_UI_MgtEntry();
    return 0;
}*/
