#ifndef  __QUEUE_BUF_LIB__
#define  __QUEUE_BUF_LIB__

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
/*
���ܣ����а��нڵ��������
*/
#define QUEUE_NODE_MAX_NUM  10   

/*
�ڵ�����
*/
typedef struct QueuNode{
	int bufLen;
	void *buf;
}QueuNode,*pQueuNode;
/*
�����ͣ�һ��������N���ڵ�
*/
typedef struct QueuePack{
	pQueuNode node[QUEUE_NODE_MAX_NUM];
	int nodeNum;
	int typeSize;	
}QueuePack,*pQueuePack;
/*
���ܣ���ʼ������ 
������
	typeSize������������ռ�ڴ�ռ�ĳߴ�
����ֵ�����а�ָ��

*/
pQueuePack  queue_init(int typeSize);
/*
���ܣ��ж϶����Ƿ�Ϊ��
�βΣ�
	qPack�����а�ָ��
����ֵ��0����ʾ�ǿ�  ��0����ʾ��

*/

int queue_isEmpty(pQueuePack qPack);
/*
���ܣ��ж϶����Ƿ���
�βΣ�
	qPack�����а�ָ��
����ֵ��0����ʾ����  ��0����ʾ��

*/
int queue_isFull(pQueuePack qPack);
/*
���ܣ�ɾ������β��
�βΣ�
	qPack�����а�ָ��
����ֵ��void
*/

void queue_deleteTail(pQueuePack qPack);
/*
���ܣ���ȡһ���ڵ������
�βΣ�
	qPack�����а�ָ��
����ֵ������һ���ڵ��ָ�룬��ʹ�������ͷţ�
*/ 

pQueuNode queue_peek(pQueuePack qPack);
/*
���ܣ����һ���ڵ�����ݣ����ݵ�ַ+���ݳ��ȣ�
�βΣ�
	qPack�����а�ָ��
	buf�������׵�ַ
	bufLen�����ݳ���
����ֵ��0����ӳɹ�  ��0�����ʧ��
*/

int  queue_push(pQueuePack qPack,const void *buf,int bufLen);
/*
���ܣ���ȡ�����нڵ�ĸ���
������
	qPack�����а�ָ��
����ֵ��> 0:����  <0:��ȡʧ��
*/

int queue_getNodeNum(pQueuePack qPack);
/*
���ܣ�������������
������
	qPack�����а�ָ��ĵ�ַ
����ֵ��void
*/
void queue_destroy(pQueuePack * qPack);

#endif