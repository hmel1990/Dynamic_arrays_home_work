#include <string>
#include <windows.h>
using namespace std;

void start_randomize();
int my_random(int min, int max);
bool check_diapazone(const int value);
void set_int_value(int& size);
void allocate_1D_array_memory(int*& ar, const int size);
void random_fill_1D_array(int* ar, const int size);
void user_fill_1D_array(int* ar, const int size);
void print_1D_array(int* ar, const int size);
//____________________________________________________
void add_element_to_end(int*& ar, int& size, const int& value);
void add_element_to_middle(int*& ar, int& size, const int& value, const int& index);
void add_element_to_start(int*& ar, int& size, const int& value);
void remove_element_from_end(int*& ar, int& size);
void remove_element_from_middle(int*& ar, int& size, const int& index);
void remove_element_from_start(int*& ar, int& size);
//____________________________________________________
void free_memory(int*& ar);


void start_randomize() {
	srand(time(0));
	rand();
}

int my_random(int min, int max) {
	int k = max - min + 1;
	return rand() % k + min;
}

// ��������� ������: �������� ���������
bool check_diapazone(const int value) {
	int min = 1;
	int max = 1000000000;
	return value >= min && value <= max;
}

// ������ ������� - ������ �������� � ���������� � ����������
void set_int_value(int& size) {
	// TO DO:
	// ������� �������� �� ���� ����� ������ 2147000000 ��� ���� ����� ������
	int number = -1;
	do {
		cout << "Please, enter size of array: ";
		string attempt;
		cin >> attempt;
		try {
			number = stoi(attempt); // stoi = string to int
		}
		catch (...) {
			cout << "ERROR!\n";
		}
	} while (!check_diapazone(number));

	size = number;
}

// int* - ��� ��������� �� ������ (� �������� ����� �����)
// int*& - ������ �� ��������� �� ������ (� �������� ����� ��������)

void allocate_1D_array_memory(int*& ar, const int size) {
	// size = 100; // ������� ��������� ��� const �� �������� �������� �������� ��������� � ���� �������
	ar = new int[size];
}

void random_fill_1D_array(int* ar, const int size) {
	for (int i = 0; i < size; i++)
		ar[i] = my_random(0, 100);
}

void user_fill_1D_array(int* ar, const int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter value for element # " << i << ": ";
		cin >> ar[i];
	}
}

void print_1D_array(int* ar, const int size) {
	cout << "\n\n======================================\n\n";
	for (int i = 0; i < size; i++) {
		cout << ar[i] << ", ";
	}
	cout << "\n\n======================================\n\n";
}

void free_memory(int*& ar) {
	delete[] ar; // ������� ������ �� �������
	ar = nullptr; // ���������� ����� ��������� � ������
}

//________________________________________________________________________________________________________________________________________
// � ������ ��������� ��������� ���������� � &, ������ ��� ����������� ������������� ������, ������ ������ ������ � ���������, � �������� �������� �� � ����������
// ������ �������� ���� ��������� � & - ������ ���������, � ����� ����� ����� ������ � ��������
void add_element_to_end(int*& ar, int& size, const int& value) {
	// 1) ����� ����� ������� ��� ���� ������, �.�. ����� ������, ���������� ��������� � �� ����� �� 1 ������� ������, ��� � ������
	// 2) ar - ��������� �� ������ ������������ ������, ����� ��� ���� ��������� �� ����� ������
	int* temp = new int[size + 1];
	// 3) ����� ��������� ��� �������� �������� �� ������� ������� � �����
	for (int i = 0; i < size; i++) {
		temp[i] = ar[i];
	}
	// 4) � ����� ������ ������� ������� �� ����� ����� �� �������� ��������� ������� (������� ����� ���������� �� ������)
	temp[size] = value;
	// 5) ������ ������ ������ �� �����, ������ ��� ���� ����� � �������������� ��������� � �����
	delete[] ar;
	// 6) ������������ ��������� ar ����� ����������� �� ������� ������������� ������� �� �����
	ar = temp;
	// 7) �������� ������ �������, �� ������� ���������� ������� �������� � �������������� (������ ��� ������� ������ �� ������)
	size++;
}


void add_element_to_middle(int*& ar, int& size, const int& value, const int& index)
{
	int* temp = new int[size + 1];
	for (int i = 0; i < index; i++)
	{
		temp[i] = ar[i];
	}

	temp[index] = value;

	for (int i = index; i < size; i++)
	{
		temp[i + 1] = ar[i];
	}
	delete[] ar;
	ar = temp;
	size++;
}

void add_element_to_start(int*& ar, int& size, const int& value)
{
	int* temp = new int[size + 1];
	temp[0] = value;

	for (int i = 0; i < size; i++)
	{
		temp[i + 1] = ar[i];
	}
	delete[] ar;
	ar = temp;
	size++;
}

void remove_element_from_end(int*& ar, int& size)
{
	int* temp = new int[size - 1];

	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = ar[i];
	}
	delete[] ar;
	ar = temp;
	size--;
}

void remove_element_from_middle(int*& ar, int& size, const int& index)
{
	int* temp = new int[size - 1];
	for (int i = 0; i < index; i++)
	{
		temp[i] = ar[i];
	}

	for (int i = index; i < size; i++)
	{
		temp[i] = ar[i + 1];
	}
	delete[] ar;
	ar = temp;
	size--;
}

void remove_element_from_start(int*& ar, int& size)
{
	int* temp = new int[size - 1];

	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = ar[i + 1];
	}
	delete[] ar;
	ar = temp;
	size--;
}

//________________________________________________________________________________________________________________________________________
