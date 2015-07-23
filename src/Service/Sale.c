/*************************************************************************
	> File Name: Sale.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Sun 28 Jun 2015 08:48:09 PM EDT
 ************************************************************************/
/*
 *完成
 */
#include"Sale.h"
#include<malloc.h>
studio_list_t p = NULL; //头结点
void initiatec(void)
{
    p = (studio_list_t) malloc(sizeof(studio_node_t));
    p->next = NULL;
    p->prev = NULL;
}
void Sale_Srv_Add(void)
{
    char choice;
    int x, y, z;
    studio_list_t  p1, p2, p3;        
    p1 = (studio_list_t)malloc(sizeof(studio_node_t));  
    printf("请输入销售记录ID，票ID，处理日期(年月日)，处理时间(时分秒)，票价，交易类型：");
    scanf("%ld%d%d%d%d%d%d%d%d%d", &(p1->data).id, &(p1->data).ticket_id, &(p1->data).date.year, &(p1->data).date.month, &(p1->data).date.day, &(p1->data).time.hour, &(p1->data).time.minute, &(p1->data).time.second,  &(p1->data).value, &z);
    (p1->data).type = (sale_type_t) z;
    (p1->data).user_id = 0;
    p->next = p1;
    p->prev = p1;
    p1->next = p;
    p1->prev = p;
     Sale_Perst_Insert(p1->data);
     printf("售票成功\n");
    while(1){
            getchar();
            printf("是否继续添加：（y/n?）");
            choice = getchar();
            if(choice == 'n')
                break;
         p3 = p->next;
         p2 = (studio_list_t)malloc(sizeof(studio_node_t));
    printf("请输入销售记录ID，票ID，处理日期，处理时间(时分秒)，票价，交易类型：");
    scanf("%ld%d%d%d%d%d%d%d%d%d", &(p2->data).id, &(p2->data).ticket_id, &(p2->data).date.year, &(p2->data).date.month, &(p2->data).date.day, &(p2->data).time.hour, &(p2->data).time.minute, &(p2->data).time.second,  &(p2->data).value, &z);
         (p2->data).type = (sale_type_t) z;
        (p2->data).user_id = 0;
     Sale_Perst_Insert(p2->data);
         p2->next = p->next; 
         p->next = p2;   
         p2->prev = p;
         p3->prev = p2;
    }   
    printf("售票成功\n");
}


void Sale_Srv_DeleteByID(int id)
{
    studio_list_t p1, p2, p3, p4 = p;
    int temp = (p4->data).ticket_id, iid = 0;
    while(1){
            p3 = p4->next;
            p1 = p4->next->next;
            p2 = p4;
        if((p4->next->data).ticket_id == id ){
                p4->next = p1;
                 p1->prev = p2;
                iid = 1;
                break;
            }
            else if(temp == (p4->next->data).ticket_id)
                break;
    p4 = p4->next;
    }

    if(iid == 1){
    free(p3);
    printf("退票成功\n");
     Sale_Perst_DeleteByID();
    }

    if(iid == 0)
    {       
        printf("退票失败\n");
    }
}
