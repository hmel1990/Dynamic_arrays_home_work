#include <iostream>
#include "arrays.h"


int main()
{
	start_randomize();

	int size;
	set_int_value(size);

	int* ar;
	allocate_1D_array_memory(ar, size);

	random_fill_1D_array(ar, size); 
	print_1D_array(ar, size);

	// добавление 1 элемента в конец
	add_element_to_end(ar, size, 100);
	print_1D_array(ar, size);

	add_element_to_middle(ar, size, 100, 3);
	print_1D_array(ar, size);

	add_element_to_start(ar, size, 100);
	print_1D_array(ar, size);

	remove_element_from_end(ar, size);
	print_1D_array(ar, size);


	remove_element_from_middle(ar, size, 4);
	print_1D_array(ar, size);

	remove_element_from_start(ar, size);
	print_1D_array(ar, size);

	free_memory(ar);



	//________________________________________________________________________________________________________________________________________
	//________________________________________________________________________________________________________________________________________
	int width = 10; 
	cin >> width;
	int height = 4;
	cin >> height;
	int** array = new int* [height]; // создание указателя на массив указателей

	for (int i = 0; i < height; i++)
	{
		array[i] = new int [width]; //выделение памяти для массивов
	}
	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++) 
		{
		array[i][j] = 10;//заполнение массивов
		cout << array[i][j] << "  ";
		}
	cout << "\n\n";
	}

	for (int i = 0; i < height; i++)
	{
		delete[] array[i]; // очистка памяти от массивов
	}
	delete[] array; // очистка памяти от массива указателей
}

