/*************************************************************************
	> File Name: Play_Persist.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Wed 01 Jul 2015 03:10:44 AM EDT
 ************************************************************************/

#include<stdio.h>
#include"Play_Persist.h"
#include"../Service/Play.h"
//#include<Play.c>
extern play_list_t p;

void Play_Perst_Insert(play_t data)
{

    FILE *fp;
    int id = (p->data).id;
    fp = fopen("Play_Data_File", "a");
            fwrite(&data, sizeof (play_t), 1, fp);
        fclose(fp);

}


void Play_Perst_Update(void)
{
    FILE *fp;
    int id = (p->data).id;
    play_list_t p1 = p->next;
    fp = fopen("Play_Data_File", "w");
    while(1){
            if((p1->data).id == id)
                break;
            fwrite(&p1->data, sizeof (play_t), 1, fp);
            p1 = p1->next;
    }
    fclose(fp);
}


void Play_Perst_DeleteByID(void)
{
    FILE *fp;
    int id = (p->data).id;
    play_list_t p1 = p->next;
    fp = fopen("Play_Data_File", "w");
    while(1){
            if((p1->data).id == id)
                break;
            fwrite(&p1->data, sizeof (play_t), 1, fp);
            p1 = p1->next;
    }
    fclose(fp);
    

}


void Play_Perst_SelectByID(int id)
{
    


}


void Play_Perst_SelectAll(void)
{
    
 

}
