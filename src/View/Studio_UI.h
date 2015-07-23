/*************************************************************************
	> File Name: Studio_UI.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Fri 26 Jun 2015 05:28:59 PM EDT
 ************************************************************************/

#ifndef _STUDIO_UI_H
#define _STUDIO_UI_H
#include"../Service/Studio.h"
void Studio_UI_MgtEntry(void);
int Studio_UI_Add(void);
int Studio_UI_Modify(int id);
int Studio_Srv_Add(void);
int Studio_Srv_DeleteByID(int id);
int Studio_Srv_Modify(int id);
int Studio_UI_Delete(int id);
extern studio_list_t pw;
void initiate(void);
int Studio_Perst_Insert(const studio_t *data);
int Studio_Perst_Update(const studio_t *data);
int Studio_Perst_DeletebyID(int ID);
#endif
