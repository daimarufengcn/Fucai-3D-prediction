#include "kill_num.h"


/*������ʷ���ݺ͹����ڿ��ܵ����ݼ��д���ɾ�����*/
/*�����ŵİ�λ����3��3��ȡ��λɱ���ڰ�λ*/
void km_h_m3a3(int *history[4], int numbers[][4])
{
	/*�������*/
	int num = 0;
	num = (history[0][hundreds] * 3 + 3) % 10;
	/*��ʼɱ��*/
	tool_kill( num, hundreds, numbers, 1000);
	printf("hundreds %d", num);
}

/*�����ŵİ�λ����7��7��ȡ��λɱ���ڰ�λ*/
void km_h_m7a7(int *history[4], int numbers[][4])
{
	/*�������*/
	int num = 0;
	num = (history[0][hundreds] * 7 + 7) % 10;
	/*��ʼɱ��*/
	tool_kill(num, hundreds, numbers,1000);
	printf("hundreds %d", num);
}

/*��������β+4��ɱʮλ*/
void km_t_taila4(int *history[4], int numbers[][4])
{
	/*�������*/
	int num = 0;
	num = ( history[0][0] + 1 + 4) % 10;
	/*��ʼɱ��*/
	tool_kill(num, ten_digit, numbers, 1000);
	printf("ten_digit %d", num);
}
/*����ʮλɱ����ʮλ*/
void km_t_t(int *history[4], int numbers[][4])
{
	/*�������*/
	int num = 0;
	num = history[0][ten_digit];
	/*��ʼɱ��*/
	tool_kill(num, ten_digit, numbers, 1000);
	printf("ten_digit %d", num);
}
/*
ɱ��λ
*/

/*��ֵβ + 4, ɱ��λ*/
void km_u_sumtaila4(int *history[4], int numbers[][4])
{
	/*�������*/
	int num = 0;
	num = ( (history[0][hundreds] + history[0][ten_digit] + history[0][units_digit]) + 4 ) % 10;
	/*��ʼɱ��*/
	tool_kill(num, ten_digit, numbers, 1000);
	printf("units_digit %d", num);
}
/*����ʮλɱ���ڸ�λ*/
void km_u_t(int *history[4], int numbers[][4])
{
	/*�������*/
	int num = 0;
	num = history[0][ten_digit];
	/*��ʼɱ��*/
	tool_kill(num, units_digit, numbers, 1000);
	printf("units_digit %d", num);
}
