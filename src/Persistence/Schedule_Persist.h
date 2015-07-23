/*************************************************************************
	> File Name: Schedule_Persist.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Wed 01 Jul 2015 03:00:02 AM EDT
 ************************************************************************/

#ifndef _SCHEDULE_PERSIST_H
#define _SCHEDULE_PERSIST_H
#define p pe
#include"../Service/Schedule.h"
void Schedule_Perst_SelectByPlay(int id);
void Schedule_Perst_Insert(const schedule_t data);
void Schedule_Perst_Update(void);
void Schedule_Perst_DeleteByID(void);
void Schedule_Perst_SelectByID(int id);
void Schedule_Perst_SelectAll(void);

#endif
