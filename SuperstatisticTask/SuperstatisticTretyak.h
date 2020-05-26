#ifndef STRUCT_ARRAY_
#define STRUCT_ARRAY_

#define SIZE 5

typedef struct StructArray
{
	double arr[SIZE];
} StructArray;

extern StructArray add_sa(StructArray sa1, StructArray sa2); // Додаємо структуру
extern StructArray sub_sa(StructArray sa1, StructArray sa2); // Віднімаємо структуру
extern StructArray mul_sa(StructArray sa1, StructArray sa2); // Множимо на структуру
extern StructArray div_sa(StructArray sa1, StructArray sa2); // Ділимо на структуру

extern StructArray add_double(StructArray sa1, double d); // Додаємо число (до всіх елементів масиву)
extern StructArray add_arr(StructArray sa1, double arr[], int n); // Додаємо масив (поелементно) довжиною n

extern void print_sa(StructArray sa1, FILE * fd); // Друкуємо структуру
extern void read_sa(StructArray * sa1, FILE * fd); // Читаємо структуру з файлу

extern void SetOutFormat(FILE * fd); // Встановлюємо формат введення / виведення
extern void SetInFormat(FILE * fd);

extern void Sort(FILE * fd, StructArray sa);

#endif
