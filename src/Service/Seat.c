/*************************************************************************
	> File Name: Seat.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Mon 29 Jun 2015 02:02:13 AM EDT
 ************************************************************************/

#include"Seat.h"
#include<stdio.h>
#include<malloc.h>

//seat_s_t 
studio_list_t p = NULL; //头结点

void initiatee(void)
{        
    p = (studio_list_t)malloc(sizeof(studio_node_t));    
    p->next = NULL;
    p->prev = NULL;
}

void Seat_Srv_Add(void)
{
    int i;
    char choice;
    studio_list_t  p1, p2, p3;        
    p1 = (studio_list_t)malloc(sizeof(studio_node_t));  
    printf("请输入座位的id(不能为0)、所在演出厅ID、座位行号、座位列号：");
    scanf("%d%d%d%d", &(p1->data).id, &(p1->data).roomID, &(p1->data).row, &(p1->data).column);
    (p1->data).status = (seat_status_t) 0;
   Seat_Perst_Insert(p1->data);
   /*data->id = (p1->data).id, strcpy(data->name, (p1->data).name), data->rowsCount = (p1->data).rowsCount,
    data->colsCount = (p1->data).colsCount;
    Studio_Perst_Insert(data);*/
    p->next = p1;
    p->prev = p1;
    p1->next = p;
    p1->prev = p;
    while(1){
            getchar();
            printf("是否继续添加：（y/n?）");
            choice = getchar();
            if(choice == 'n')
                break;
         p3 = p->next;
         p2 = (studio_list_t)malloc(sizeof(studio_node_t));
         printf("请输入座位的id(不能为0)、所在演出厅ID、座位行号、座位列号：");
         scanf("%d%d%d%d", &(p2->data).id, &(p2->data).roomID, &(p2->data).row, &(p2->data).column);
         (p2->data).status = (seat_status_t) 0;
        Seat_Perst_Insert(p2->data); 
        p2->next = p->next; 
         p->next = p2;   
         p2->prev = p;
         p3->prev = p2;
    printf("添加成功\n");
    }
}

void Seat_Srv_AddBatch(void)
{    
    int i = 1, x, y, z, t, n;
    printf("要添加多少座位:");
    scanf("%d", &x);
    studio_list_t  p1, p2, p3;        
    p1 = (studio_list_t)malloc(sizeof(studio_node_t));  
    printf("请输入座位的起始id(不能为0)、所在演出厅ID、座位行号、座位列号：");
    scanf("%d%d%d%d", &(p1->data).id, &(p1->data).roomID, &(p1->data).row, &(p1->data).column);
    (p1->data).status = (seat_status_t) 0;
   Seat_Perst_Insert(p1->data);
    y = (p1->data).id, z = (p1->data).roomID, t = (p1->data).row, n = (p1->data).column;
    /*data->id = (p1->data).id, strcpy(data->name, (p1->data).name), data->rowsCount = (p1->data).rowsCount,
    data->colsCount = (p1->data).colsCount;
    Studio_Perst_Insert(data);*/
    p->next = p1;
    p->prev = p1;
    p1->next = p;
    p1->prev = p;
    while(i < x){
         p3 = p->next;
         p2 = (studio_list_t)malloc(sizeof(studio_node_t));  
        (p2->data).status = (seat_status_t) 0;
        (p2->data).id = y++, (p2->data).roomID = z, (p2->data).row = t, (p2->data).column = n++;
         Seat_Perst_Insert(p2->data);
        if(n == 11){
            t++;
            n = 1;
        }
        p2->next = p->next; 
         p->next = p2;   
         p2->prev = p;
         p3->prev = p2;
         i++;
    }
    printf("添加成功\n");
}


void Seat_Srv_DeleteByID(int id)
{
    studio_list_t p1, p2, p3, p4 = p;
    int temp = (p4->data).id, iid = 0, di;
    printf("请输入座位所在的演出厅ID：");
    scanf("%d", &di);
    while(1){
            p3 = p4->next;
            p1 = p4->next->next;
            p2 = p4;
        if((p4->next->data).id == id && di == (p4->next->data).roomID){
                p4->next = p1;
                 p1->prev = p2;
                iid = 1;
                break;
            }
            else if(temp == (p4->next->data).id)
                break;
    p4 = p4->next;
    }
    if(iid == 1){
    free(p3);
    printf("删除成功\n");
    Seat_Perst_Update();
    }

    if(iid == 0)
    {
        printf("删除失败\n");
    }
}

void Modify(studio_list_t p1)
{
    int i, j;
    printf("********************************\n");
    printf("**\t1、修改座位ID    \t\b*\n");
    printf("**\t2、修改所在演出厅ID    *\n");
    printf("**\t3、修改座位行号        *\n");
    printf("**\t4、修改作为列号        *\n");
    printf("**\t5、修改座位状态        *\n");
    printf("********************************\n");
    printf("请选择:");
    scanf("%d", &i);
    switch(i){
        case 1:
        printf("请输入座位ID：");
                scanf("%d", &(p1->data).id);
                break;
        case 2:
                printf("请输入所在演出厅ID：");
                scanf("%d", &(p1->data).roomID);
                break;

        case 3:
                printf("请输入座位行号：");
                scanf("%d", &(p1->data).row);
                break;
    
        case 4:
                printf("请输入座位列号：");
                scanf("%d", &(p1->data).column);
                break;
    
        case 5:
                printf("请输入座位状态：");
                scanf("%d", &j);
                (p1->data).status = (seat_status_t) j;
                 break;
    }
    printf("修改成功\n");
}


int Seat_Srv_Modify(int id)
{
    studio_list_t p1 = p, p2;
    int temp = (p->data).id;                                    //座位
    while(1){
        if((p1->data).id == id){
            printf("座位已存在,请修改信息：\n");
            Modify(p1);
            break;
        }
        p1 = p1->next;
        if((p1->data).id == temp){
            printf("座位不存在\n");
            break;
        }
    }
    Seat_Perst_Update();
    return 0;
}

void Seat_Srv_DeleteAllByroomID(int id)
{







}

