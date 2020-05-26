#ifndef STRUCT_ARRAY_
#define STRUCT_ARRAY_

#define SIZE 5

typedef struct StructArray
{
	double arr[SIZE];
} StructArray;

extern StructArray add_sa(StructArray sa1, StructArray sa2); // ������ ���������
extern StructArray sub_sa(StructArray sa1, StructArray sa2); // ³������ ���������
extern StructArray mul_sa(StructArray sa1, StructArray sa2); // ������� �� ���������
extern StructArray div_sa(StructArray sa1, StructArray sa2); // ĳ���� �� ���������

extern StructArray add_double(StructArray sa1, double d); // ������ ����� (�� ��� �������� ������)
extern StructArray add_arr(StructArray sa1, double arr[], int n); // ������ ����� (�����������) �������� n

extern void print_sa(StructArray sa1, FILE * fd); // ������� ���������
extern void read_sa(StructArray * sa1, FILE * fd); // ������ ��������� � �����

extern void SetOutFormat(FILE * fd); // ������������ ������ �������� / ���������
extern void SetInFormat(FILE * fd);

extern void Sort(FILE * fd, StructArray sa);

#endif
