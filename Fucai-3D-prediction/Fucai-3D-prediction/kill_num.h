#ifndef __KILL_NUM_H__
#define __KILL_NUM_H__
#include "tools.h"

/*������ʷ���ݺ͹����ڿ��ܵ����ݼ��д���ɾ�����*/
/*���������淶
1�����е�ɱ�ź�������km_��ͷ
2���������ĵڶ�����h��t��u��ͷ���ֱ��ʾ�����λ��ʮλ����λ�������
3������������Ϊ����ɱ�ź���������������ʱҪ��������
*/

/*
ɱ��λ
*/

/*�����ŵİ�λ����3��3��ȡ��λɱ���ڰ�λ*/
void km_h_m3a3(int *history[4], int numbers[][4]);

/*�����ŵİ�λ����7��7��ȡ��λɱ���ڰ�λ*/
void km_h_m7a7(int *history[4], int numbers[][4]);

/*
ɱʮλ
*/
/*��������β+4��ɱʮλ*/
void km_t_taila4(int *history[4], int numbers[][4]);
/*����ʮλɱ����ʮλ*/
void km_t_t(int *history[4], int numbers[][4]);
/*
ɱ��λ
*/

/*��ֵβ + 4, ɱ��λ*/
void km_u_sumtaila4(int *history[4], int numbers[][4]);
/*����ʮλɱ���ڸ�λ*/
void km_u_t(int *history[4], int numbers[][4]);

#endif __KILL_NUM_H__