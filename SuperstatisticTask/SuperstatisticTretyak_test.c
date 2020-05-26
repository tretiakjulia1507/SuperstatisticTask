#include <stdio.h>
#include <stdlib.h>
#include "SuperstatisticTretyak.h"

extern char * in_format;
int main()
{
	printf ("Choose the source (f for file / s for stdin): ");
	char choice = 'q';
	while (choice != 'f' && choice != 's') // ������� ����� ��������
		scanf("%c", &choice);
	
	FILE * fd;
	if (choice == 'f')
	{
		fd = fopen("SuperstisticTretyak_test.txt", "r"); // ���� ������ �������� � ����� �� ��������� ����
		if (fd == NULL)
		{
			printf("Can't open the file. Exiting.\n");
			exit(5);
		}
	}
	else if (choice == 's') // ���� ������ �������� � ��������, �� ������ �������� � ����������� ���� ��������
	{
		fd = stdin;
	}
	
	printf ("Choose the output (f for file / s for stdout): ");
	choice = 'q';
	while (choice != 'f' && choice != 's') // ������� ����� ���������
		scanf("%c", &choice);
	
	FILE * fd_out;
	if (choice == 'f')
	{
		fd_out = fopen("SuperstisticTretyak_output.txt", "w"); // ���� ������ ��������� � ���� �� ��������� ����
		if (fd == NULL)
		{
			printf("Can't open the file. Exiting.\n");
			exit(5);
		}
	}
	else if (choice == 's') // ���� ������ �������� � ��������, �� ������ ��������� � ����������� ���� ���������
	{
		fd_out = stdout;
	}
	
	SetOutFormat(fd);
	SetInFormat(fd);
	
	StructArray sa;
	printf("Enter your structure: "); // �������� ���������
	read_sa(&sa, fd);
	fprintf(fd_out, "Your structure: "); // ��������� ���������
	print_sa(sa, fd_out);
	
	printf("\nNow let's do some tests...\n");
	printf("Adding double number. Enter this number: ");
	double d;
	fscanf(fd, in_format, &d);
	StructArray sa2 = add_double(sa, d); // ������� ������� add_double()
	fprintf(fd_out, "\nResult of adding a double number: ");
	print_sa(sa2, fd_out);
	
	printf("\nAdding structure. Enter this structure: ");
	StructArray sa1;
	read_sa(&sa1, fd);
	sa2 = add_sa(sa, sa1); // ������� ������� add_sa()
	fprintf(fd_out, "\nResult of adding a structure: ");
	print_sa(sa2, fd_out);
	
	printf("\nSubtracting structure. Enter this structure: ");
	read_sa(&sa1, fd);
	sa2 = sub_sa(sa, sa1); // ������� ������� sub_sa()
	fprintf(fd_out, "\nResult of subtracting a structure: ");
	print_sa(sa2, fd_out);
	
	printf("\nMultiplying structures. Enter this structure: ");
	read_sa(&sa1, fd);
	sa2 = mul_sa(sa, sa1); // ������� ������� mul_sa()
	fprintf(fd_out, "\nResult of multiplication: ");
	print_sa(sa2, fd_out);
	
	printf("\nDividing structure. Enter this structure: ");
	read_sa(&sa1, fd);
	sa2 = div_sa(sa, sa1); // ������� ������� div_sa()
	fprintf(fd_out, "\nResult of dividing: ");
	print_sa(sa2, fd_out);
	
	printf("\nAdding array with length 3. Enter this array: ");
	double arr1[3];
	for (int i = 0; i < 3; i++)
		fscanf(fd, in_format, &arr1[i]);
		
	sa2 = add_arr(sa, arr1, 3); // ������� ������� add_arr() � �������
						   // �������� 3 (����� ������� ������ ���������)
	fprintf(fd_out, "\nResult of adding an array[3]: ");
	print_sa(sa2, fd_out);
	
	printf("\nAdding array with length 7. Enter this array: ");
	double arr2[7];
	for (int i = 0; i < 7; i++)
		fscanf(fd, in_format, &arr2[i]);
		
	sa2 = add_arr(sa, arr2, 7); // ������� ������� add_arr() � �������
								// �������� 7 (����� ������� ������ ���������)
	fprintf(fd_out, "\nResult of adding an array[7]: ");
	print_sa(sa2, fd_out);
	Sort(fd_out, sa);
}

























