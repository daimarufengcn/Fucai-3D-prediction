#ifndef __TOOLS_H__
#define __TOOLS_H__

/*��λ���*/
typedef enum
{
	hundreds = 1,	/*��λ��*/
	ten_digit = 2,		/*ʮλ��*/
	units_digit = 3		/*��λ��*/
}digit;

/*ͳһɱ�ź���*/
void tool_kill(int num, digit type, int numbers[][4], int num_lenth);


#endif // !__TOOLS_H__TOOL
