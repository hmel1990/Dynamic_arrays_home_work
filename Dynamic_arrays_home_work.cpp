#include <iostream>
using namespace std;


int main()
{
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
		array[i][j] = 10;
		cout << array[i][j] << "  ";
		}
	cout << "\n\n";
}
}

