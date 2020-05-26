#include <stdio.h>
#include <string.h>
#include "SuperstatisticTretyak.h"

char out_format[16]; // Форматна стрічка для виведення
char * in_format;

void SetOutFormat(FILE * fd) // В даній функції формується
{							 // форматна стрічка виведення
	char fmt[16];
	strncat(out_format, "%1.", 3);
	printf("Enter ammount of digits after comma in output: "); // Вводимо кількість знаків після коми
	fscanf(fd, "%s", fmt);
	strncat(out_format, fmt, 15);
	printf("Enter output format (d for decimal / s for scientific): ");
	
	char f = 'q';
	while (f != 'd' && f != 's') // Обираємо формат введення (науковий / десятковий)
		fscanf(fd, "%c", &f);
	
	if (f == 'd')
		strncat(out_format, "lf ", 3);
	else if (f == 's')
		strncat(out_format, "le ", 3);
}

void SetInFormat(FILE * fd) // В даній функції формується
{							 // форматна стрічка введення
	printf("Enter input format (d for decimal / s for scientific): ");
	
	char f = 'q';
	while (f != 'd' && f != 's') // Обираємо формат введення (науковий / десятковий)
		fscanf(fd, "%c", &f);
	
	if (f == 'd')
		in_format = "%lf";
	else if (f == 's')
		in_format = "%le";
}

StructArray add_sa(StructArray sa1, StructArray sa2)
{
	StructArray temp;
	for (int i = 0; i < SIZE; i++)
		temp.arr[i] = sa1.arr[i] + sa2.arr[i];
		
	return temp;
}

extern StructArray sub_sa(StructArray sa1, StructArray sa2)
{
	StructArray temp;
	for (int i = 0; i < SIZE; i++)
		temp.arr[i] = sa1.arr[i] - sa2.arr[i];
		
	return temp;
}

extern StructArray mul_sa(StructArray sa1, StructArray sa2)
{
	StructArray temp;
	for (int i = 0; i < SIZE; i++)
		temp.arr[i] = sa1.arr[i] * sa2.arr[i];
		
	return temp;
}

extern StructArray div_sa(StructArray sa1, StructArray sa2)
{
	StructArray temp;
	for (int i = 0; i < SIZE; i++)
		temp.arr[i] = sa1.arr[i] / sa2.arr[i];
		
	return temp;
}

StructArray add_double(StructArray sa1, double d)
{
	StructArray temp;
	for (int i = 0; i < SIZE; i++)
		temp.arr[i] = sa1.arr[i] + d;
		
	return temp;
}

StructArray add_arr(StructArray sa1, double arr[], int n)
{
	StructArray temp;
	int min = SIZE > n ? n : SIZE;
	
	for (int i = 0; i < min; i++)
		temp.arr[i] = sa1.arr[i] + arr[i];
		
	for (int i = min; i < SIZE; i++)
	{
		temp.arr[i] = sa1.arr[i];
	}
	return temp;
}

void print_sa(StructArray sa1, FILE * fd)
{
	for (int i = 0; i < SIZE; i++)
		fprintf(fd, out_format, sa1.arr[i]);
		
	
}
void read_sa(StructArray * sa1, FILE * fd)
{
	for (int i = 0; i < SIZE; i++)
		fscanf(fd, in_format, &(sa1->arr[i]));
}

extern void Sort(FILE * fd, StructArray sa)
{
	double arr[SIZE];
	
	for (int i = 0; i < SIZE; i++)
		arr[i] = sa.arr[i];
		
	int pass, j, hold;

	for (pass = 0; pass < SIZE-1; pass++){
		for (j = pass+1; j < SIZE; j++){
			if (arr[pass] > arr[j]){
				hold = arr[j];
				arr[j] = arr[pass];
				arr[pass] = hold;
			}
		}
	}
	fprintf(fd, "\nSorted array: ");
	for (int i = 0; i < SIZE; i++)
		fprintf(fd, out_format, arr[i]);
}





























