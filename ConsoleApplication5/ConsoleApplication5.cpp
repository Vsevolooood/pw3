#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
void printMatrix(int* p, int b)
{
	system("cls");
	int* endArray = p + b * b;
	for (int* i = p; i < endArray; i++)
	{
		if ((i - p) % b == 0 && i != p)
			cout << '\n';
		cout << '[' << setw(4) << left << *i << ']' << ' ';
	}
	cout << '\n';
	cout << '\n';
	Sleep(500);
}
void zero(int* p, int b)
{
	cout << '\n';
	cout << "Матрица " << b << "x" << b << '\n';
	int* endArray = p + b * b;
	for (int* i = p; i < endArray; i++)
	{
		*i = 0;
		if ((i - p) % b == 0 && i != p)
			cout << '\n';
		cout << '[' << *i << ']' << ' ';
	}
	cout << '\n';
	cout << '\n';
}
// заполнение матрицы как пружинка
void slinky(int* p, int b)
{
	for (int i = 0; i < b / 2; i++)
	{
		for (int j = i; j < b - i; j++)
		{
			*(p + j + b * i) = rand() % 199 - 99;
			printMatrix(p, b);
		}
		for (int j = i + 1; j < b - i; j++)
		{
			*(p + b - 1 - i + b * j) = rand() % 199 - 99;
			printMatrix(p, b);
		}
		for (int j = b - i - 1; j > i; j--)
		{
			*(p + (j - 1) + (b) * (b - i - 1)) = rand() % 199 - 99;
			printMatrix(p, b);
		}
		for (int j = b - i - 2; j >= 1 + i; j--)
		{
			*(p + i + b * j) = rand() % 199 - 99;
			printMatrix(p, b);
		}
	}
}
// заполнение матрицы змейкой
void snake(int* p, int b)
{
	for (int i = 0; i < b; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < b; j++)
			{
				*(p + i + b * j) = rand() % 199 - 99;
				printMatrix(p, b);
			}
		}
		else
		{
			for (int j = b - 1; j >= 0; j--)
			{
				*(p + i + b * j) = rand() % 199 - 99;
				printMatrix(p, b);
			}
		}
	}
}
// выор заполнения матрицы
void generate(int* p, int b)
{
	cout << "Выберете тип заполнения" << '\n';
	cout << "1 - пружинка, 2 - змейка:\t";
	int a;
	cin >> a;
	zero(p, b);
	switch (a)
	{
	case 1:
		slinky(p, b);
		break;
	case 2:
		snake(p, b);
		break;
	}
}
void surcle(int* p, int b)
{
	for (int j = 0; j < b / 2; j++)
	{
		for (int i = 0; i < b / 2; i++)
		{
			swap(*(p + j + b * i), *(p + j + b * j + b / 2));
			swap(*(p + j + b * i), *(p + j + b / 2 + b * (i + b / 2)));
			swap(*(p + j + b * i), *(p + j + b * (i + b / 2)));
		}
	}
	printMatrix(p, b);
}
void cros(int* p, int b)
{
	for (int j = 0; j < b / 2; j++)
	{
		for (int i = 0; i < b / 2; i++)
		{
			swap(*(p + j + b * i), *(p + j + b / 2 + b * (i + b / 2)));
			swap(*(p + j + b / 2 + b * i), *(p + j + b * (i + b / 2)));

		}
	}
	printMatrix(p, b);
}
void up_down(int* p, int b)
{
	for (int j = 0; j < b / 2; j++)
	{
		for (int i = 0; i < b / 2; i++)
		{
			swap(*(p + j + b * i), *(p + j + b * (i + b / 2)));
			swap(*(p + j + b / 2 + b * i), *(p + j + b / 2 + b * (i + b / 2)));
		}
	}
	printMatrix(p, b);
}
void left_right(int* p, int b)
{
	for (int j = 0; j < b / 2; j++)
	{
		for (int i = 0; i < b / 2; i++)
		{
			swap(*(p + j + b * i), *(p + j + b / 2 + b * i));
			swap(*(p + j + b / 2 + b * (i + b / 2)), *(p + j + b / 2 + b * (i + b / 2)));
		}
	}
	printMatrix(p, b);
}
// переещение блоков матрицы
void swapp(int* p, int b)
{
	int a;
	bool h;
	h = true;
	cout << "Выберете метод преобразования" << '\n';
	cout << "1 - по кругу, 2 - по диагонили, 3 - верх-низ, 4 - право-лево\t";
	while (h)
	{
		cin >> a;
		switch (a)
		{
		case 1:
			surcle(p, b);
			cout << "0 - выход\t";
			break;
		case 2:
			cros(p, b);
			cout << "0 - выход\t";
			break;
		case 3:
			up_down(p, b);
			cout << "0 - выход\t";
			break;
		case 4:
			left_right(p, b);
			cout << "0 - выход\t";
			break;
		case 0:
			h = false;
			break;
		}
	}
}
void task()
{
	cout << "Выберете задание" << '\n';
	cout << "1) Создать матрицу" << '\n';
	cout << "2) Преобразование матриц" << '\n';
	cout << "3) сортировать матрицу" << '\n';
	cout << "4) Математические преобразования матриц" << '\n';
	cout << "5) ИДЗ 10" << '\n';
	cout << "0) Сменить размер матрици" << '\n';
}
void shaker_sort(int* p, int b)
{
	int* endArray = p + b * b;
	for (int i = 0; i < b * b / 2; i++)
	{
		for (int c = i; c < b * b - i - 1; c++)
		{
			if (*(p + c) > *(p + c + 1))
			{
				swap(*(p + c), *(p + c + 1));
			}
		}
		for (int c = b * b - 2 - i; c >= i; c--)
		{
			if (*(p + c) > *(p + c + 1))
			{
				swap(*(p + c), *(p + c + 1));
			}
		}
	}
	printMatrix(p, b);
}
void math(int* p, int b)
{
	int* endArray = p + b * b;
	char c;
	cout << "Выберете действие " << '\n';
	cout << "+; -; *; /" << '\n';
	cin >> c;
	cout << "Введите число" << '\n';
	int a;
	cin >> a;
	cout << '\n';
	switch (c)
	{
	case '+':
		for (int* i = p; i < endArray; i++)
		{
			*i += a;
			if ((i - p) % b == 0 && i != p)
				cout << '\n';
			cout << '[' << *i << ']' << ' ';
		}
		break;
	case '-':
		for (int* i = p; i < endArray; i++)
		{
			*i += -a;
			if ((i - p) % b == 0 && i != p)
				cout << '\n';
			cout << '[' << *i << ']' << ' ';
		}
		break;
	case '*':
		for (int* i = p; i < endArray; i++)
		{
			*i *= a;
			if ((i - p) % b == 0 && i != p)
				cout << '\n';
			cout << '[' << *i << ']' << ' ';
		}
		break;
	case '/':
		for (int* i = p; i < endArray; i++)
		{
			*i /= a;
			if ((i - p) % b == 0 && i != p)
				cout << '\n';
			cout << '[' << *i << ']' << ' ';
		}
		break;
	}
	cout << '\n';
}
void idz()
{
	int a[3][3];
	int* h;
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			a[i][k] = rand() % 61 - 30;
		}
	}
	h = *a;
	printMatrix(h, 3);
	cout << "detA = a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1] - a[0][2] * a[1][1] * a[2][0] - a[0][1] * a[1][0] * a[2][2] - a[2][1] * a[1][2] * a[0][0]\n";
	cout << "detA = " << a[0][0] << " * " << a[1][1] << " * " << a[2][2] << " + " << a[0][1] << " * " << a[1][2] << " * " << a[2][0] << " + " << a[0][2] << " * " << a[1][0] << " * " << a[2][1] << " - " << a[0][2] << " * " << a[1][1] << " * " << a[2][0] << " - " << a[0][1] << " * " << a[1][0] << " * " << a[2][2] << " - " << a[2][1] << " * " << a[1][2] << " * " << a[0][0] << "\n";
	int det;
	det = a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1] - a[0][2] * a[1][1] * a[2][0] - a[0][1] * a[1][0] * a[2][2] - a[2][1] * a[1][2] * a[0][0];
	cout << "detA = " << det << '\n';
}
void menu(int* p, int b)
{
	zero(p, b);
	bool h;
	h = true;
	while (h)
	{
		task();
		int k;
		cin >> k;
		switch (k)
		{
		case 1:
			generate(p, b);
			break;
		case 2:
			swapp(p, b);
			break;
		case 3:
			shaker_sort(p, b);
			break;
		case 4:
			math(p, b);
			break;
		case 5:
			idz();
			break;
		case 0:
			h = false;
			system("cls");
			break;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "RU");
	int enterButton;
	bool h;
	h = true;
	while (h)
	{
		cout << "Меню\n";
		cout << "Выберете порядок матрици(6, 8, 10): ";
		cout << "\n\n";
		cin >> enterButton;
		int m6[6][6], m8[8][8], m10[10][10];
		int* p = NULL;
		switch (enterButton)
		{
		case 6:
			p = *m6;
			break;
		case 8:
			p = *m8;
			break;
		case 10:
			p = *m10;
			break;
		case 0:
			exit(0);
			break;
		}
		menu(p, enterButton);
	}
}