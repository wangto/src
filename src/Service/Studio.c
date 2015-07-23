#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include"Studio.h"
/*
 *正确
 */
studio_list_t p = NULL; //头结点
void initiate(void)
{        
    p = (studio_list_t)malloc(sizeof(studio_node_t));    
    p->next = NULL;
    p->prev = NULL;
}

int Studio_Srv_Add(void)
{
    char choice;
    studio_t data0, *data = &data0;
    studio_list_t  p1, p2, p3;        
    p1 = (studio_list_t)malloc(sizeof(studio_node_t));  
    printf("请输入演出厅的id(不能为0)、名称、行数、列数：");
    scanf("%d%s%d%d", &(p1->data).id, (p1->data).name, &(p1->data).rowsCount, &(p1->data).colsCount);
    Studio_Perst_Insert(p1->data);
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
         printf("请输入演出厅的id，名称，行数、列数:");
         scanf("%d%s%d%d", &(p2->data).id, (p2->data).name, &(p2->data).rowsCount, &(p2->data).colsCount);
         Studio_Perst_Insert(p2->data);
        
         p2->next = p->next; 
         p->next = p2;   
         p2->prev = p;
         p3->prev = p2;
    }   
    printf("添加成功\n");
    return 0;
}


int Studio_Srv_DeleteByID(int id)
{
    studio_list_t p1, p2, p3, p4 = p;
    int temp = (p4->data).id, iid = 0;
    while(1){
            p3 = p4->next;
            p1 = p4->next->next;
            p2 = p4;
        if((p4->next->data).id == id ){
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
    

    if(iid == 0)
    {
        
        printf("删除失败\n");
    }
    Studio_Perst_Update();
    return 0;
    }
}

int Studio_Srv_Modify(int id)
{
    studio_list_t p1 = p, p2;
    int temp = (p->data).id;                                    //座位
    while(1){
        if((p1->data).id == id){
            printf("演出厅已存在,请输入演出厅新名称:");
            rewind(stdin);
            scanf("%s", (p1->data).name);
            break;
        }

        p1 = p1->next;
        if((p1->data).id == temp){
                printf("演出厅不存在\n");
            break;
        }
    }
    Studio_Perst_Update();
    return 0;
}



    
