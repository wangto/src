/*************************************************************************
	> File Name: Play_Persist.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Wed 01 Jul 2015 03:11:33 AM EDT
 ************************************************************************/

#ifndef _PLAY_PERSIST_H
#define _PLAY_PERSIST_H
#include"../Service/Play.h"
void Play_Perst_Insert(play_t data);
void Play_Perst_Update(void);
void Play_Perst_DeleteByID(void);
void Play_Perst_SelectByID(int id);
void Play_Perst_SelectAll(void);

#define p py






#endif
