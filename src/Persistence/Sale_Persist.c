/*************************************************************************
	> File Name: Sale_Persist.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Wed 01 Jul 2015 03:06:42 AM EDT
 ************************************************************************/

#include<stdio.h>
#include"Sale_Persist.h"
extern sale_list_t p;
void Sale_Perst_Insert(sale_t data)
{
    FILE *fp;
    int i = 0,id = (p->data).id;
    fp = fopen("Sale_Data_File", "a");
   // sale_list_t p1 = p->next;
   // while(1){
     //       if((p1->data).id == id)
       //         break;
            fwrite(&data, sizeof (sale_t), 1, fp);
         //   p1 = p1->next;
            
 //   }
        fclose(fp);
}


void Sale_Perst_DeleteByID(void)
{
    FILE *fp;
    int i = 0,id = (p->data).id;
    fp = fopen("Sale_Data_File", "w");
    sale_list_t p1 = p->next;
    while(1){
            if((p1->data).id == id)
                break;
            fwrite(&p1->data ,sizeof (sale_t), 1, fp);
            p1 = p1->next;
            
    }
        fclose(fp);
}
