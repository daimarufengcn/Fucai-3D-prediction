/*�������ļ�*/
#include <stdio.h>
#include <stdlib.h>
#include "kill_num.h"

#define INPUT_FILEPATH "G:\\WORK_PROJECTS\\����3D��Ʊѡ�ų���\\Debug\\history.txt"
/*************
���ݽṹ����
*************/
/*�������ݵĽṹ*/
typedef int **PPDATAS;
/*�������п��ܺ��������*/
int numbers[1000][4];

/*****************/
/*�����̺������� */
/*****************/

/*1����ʼ����Ҫ�����ݽṹ*/
void init(int nums[1000][4])
{
	/*���ɺ��룬����numbers*/
	/*���򣺵�һ���Ǳ��λ��Ĭ����0������λΪ���ɵĺ��룬��000��999*/

	int num = 0;
	for (int i = 0; i < 1000; i++)
	{
		nums[i][0] = 0;
		nums[i][1] = i / 100;
		nums[i][2] = (i % 100) / 10;
		nums[i][3] = i % 100 % 10;
	}

}
/*2����ȡ���ڿ�������
���룺�����ļ���·�����������ݵ�����ָ��
����ֵ����ȡ�ɹ�����ʧ�ܣ��ɹ�1��ʧ��0
*/
int read_data(char path[],int **input[4], int *length)
{
	FILE* fp_input = NULL;
	if ( (fp_input = fopen(path, "r")) == NULL )
	{
		printf("���ļ�ʧ�ܣ�\n");
		return 0;
	}
	*length = 0;
	int arr_length = 100;
	
	int** pp_datas = *input;
	pp_datas = (int **)malloc(sizeof(int *)*arr_length);
	char buf[20];
	while (!feof(fp_input))
	{
		if (arr_length <= *length)
		{
			arr_length += 10;
			pp_datas = (int **)realloc(pp_datas, sizeof(int *) * arr_length);
		}
		pp_datas[*length] = (int*)malloc(sizeof(int) * 4);
		fscanf(fp_input, "%s\t%d\t%d\t%d\t%d\n", 
			buf,
			&(pp_datas[*length][0]),
			&(pp_datas[*length][1]),
			&(pp_datas[*length][2]),
			&(pp_datas[*length][3]));
		(*length)++;
	}

	fclose(fp_input);
	*input = pp_datas;
	return 1;
}
/*3��ɸѡ����
���룺�������ݡ���ѡ����
�����ѡ�õ�����
����ֵ������ɹ�����ʧ��,�ɹ�1��ʧ��0
*/
int filt_data( int* input[4], int datas[][4], int **out[4], int* length )
{
	*length = 0;
	
	//int** pp_datas = *out;

	km_h_m3a3(input,datas);
	km_h_m7a7(input, datas);
	km_t_taila4(input, datas);
	km_t_t(input, datas);
	km_u_sumtaila4(input, datas);
	km_u_t(input, datas);

	/*�����������*/
	int arr_length = 10;
	//pp_datas = (int **)malloc(sizeof(int *) * arr_length );
	*out = (int **)malloc(sizeof(int *)* arr_length);
	int** pp_datas = *out;
	for (int i = 0; i < 1000; i++)
	{
		if (arr_length <= *length)
		{
			arr_length += 10;
			pp_datas = (int **)realloc(pp_datas, sizeof(int *) * arr_length);
		}
		if (datas[i][0] == 0)
		{
			pp_datas[*length] = (int*)malloc(sizeof(int)* 4);
			pp_datas[*length][0] = *length;
			pp_datas[*length][1] = datas[i][1];
			pp_datas[*length][2] = datas[i][2];
			pp_datas[*length][3] = datas[i][3];
			(*length)++;
		}
	}
	*out = pp_datas;
	return 0;
}
/*4���������
���룺ѡ�õ�����
���������̨�������
*/
void output_data(int *numbers[4], int length)
{
	int** pp_tmp = numbers;
	for (int i = 0; i < length; i++)
	{
		printf("��ţ�%d\t���룺[%d][%d][%d]\n", (*pp_tmp)[0], (*pp_tmp)[1], (*pp_tmp)[2], (*pp_tmp)[3]);
		pp_tmp++;
	}
}

void free_array(int **arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		free((arr)[i]);
	}
	free(arr);
}

int main(int argc, char** argv)
{
	PPDATAS pp_input = NULL;
	PPDATAS pp_output = NULL;
	int input_num = 0;/*�������ݵ�����*/
	int output_num = 0;
	/*1����ʼ����Ҫ�����ݽṹ*/
	init(numbers);

	/*2����ȡ���ڿ�������*/
	if ( !read_data(INPUT_FILEPATH, &pp_input, &input_num))
	{
		system("pause");
		return -1;
	}
	/*3��ɸѡ����*/
	filt_data(pp_input, numbers, &pp_output, &output_num);

	/*4���������*/
	output_data(pp_output, output_num);

	/*5���ͷ��ڴ�*/
	//free_array(pp_input, input_num);
	//free_array(pp_output, output_num);


	system("pause");
	return 0;
}

