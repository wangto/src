/*************************************************************************
	> File Name: EntityKey.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Fri 26 Jun 2015 08:39:09 PM EDT
 ************************************************************************/

#ifndef _ENTITYKEY_H
#define _ENTITYKEY_H

typedef struct{
                char entryName[4];
                long key;
}entity_key_t;

typedef struct entity_key_node{
                entity_key_t data;
                struct entity_key_node *prev;
                struct entity_key_node *next;
}entkey_node_t, *entkey_list_t;





#endif
