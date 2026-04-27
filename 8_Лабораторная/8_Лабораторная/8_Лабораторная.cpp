// Лабораторная работа 8
// Выполнила студентка группы 25ВВВ3
// Иванова С.А.

#include <stdio.h>	
#include <conio.h>	
#include <locale.h> 
#include <stdlib.h>	
#include <math.h>
#include <time.h>  

void vvod1(int* m){
printf("Введите диапазон значений: ");
	scanf_s("%d", m);
}

void vivod1(int m,int* ptr) {
	for (int i = 0; i < 10; i++)
	{
		*(ptr + i) = rand() % (m + 1);
		if (*(ptr + i) == 0) {
			*(ptr + i) = 1;
		}
		printf("%d ", *(ptr + i));
	}
}

void vivod11(double s) {
	printf("%.3f \n", s);
}

void obrabotka1(int* ptr) {
	double s = 1.0;
	printf("\nСреднее геометрическое:\n");
	for (int i = 0; i < 10; i++)
	{
		s = s * *(ptr + i);
	}
	s = pow(s, 0.1);
	vivod11(s);
}

////////////////////////////////////////////////////////////////////////

void vvod2(int* n2, int* m2, int* min, int* max) {
	printf("Введите минимальное значение: ");
	scanf_s("%d", min);

	printf("Введите максимальное значение: ");
	scanf_s("%d", max);

	printf("Введите высоту масива: ");
	scanf_s("%d", n2);

	printf("Введите ширину масива: ");
	scanf_s("%d", m2);
}

void vivod2(int n2, int m2, int min, int max, int* ptr2) {
	printf("Исходный массив:\n");
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			*(ptr2 + i * m2 + j) = min + rand() % (max - min + 1);
			if (*(ptr2 + i * m2 + j) == 0) {
				*(ptr2 + i * m2 + j) = 1;
			}
			printf(" %d  ", *(ptr2 + i * m2 + j));
		}
		printf("\n");
	}
}

void vivod22(int x) {
	printf("Количество смен знака: %d ", x);
}
void obrabotka2(int n2, int m2, int* ptr2) {
	int zn1;
	int x = 0;
	int zn2 = 0;
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			if (*(ptr2 + i * m2 + j) > 0) {
				zn1 = 1;
			}
			else {
				zn1 = -1;
			}

			if (zn2 != 0 && zn1 != zn2) {
				x++;
			}

			zn2 = zn1;
		}
	}
	vivod22(x);
}
void main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "Rus");

	int a[10];
	int i;
	int m;
	int * ptr; // ptr - указатель на массив a, используется для передачи массива в функции
	ptr = a;
	vvod1(&m);
	vivod1(m, ptr);
	obrabotka1(ptr);
	if (a[0] > 0) {
		printf("Переменная a[0] положительна\n"); //проверяем что первый элемент массива положительный
	}

	int с[100][100], n2, j, m2, min, max, * ptr2;
	ptr2 = &с[0][0];
	vvod2(&n2, &m2, &min, &max);
	vivod2(n2, m2, min, max, ptr2);
	obrabotka2(n2, m2, ptr2);

	_getch();
}

