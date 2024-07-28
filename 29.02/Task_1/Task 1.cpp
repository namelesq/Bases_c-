#include <iostream>

void FillingArray(const int size, int array[10])
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 20;
	}
}

void FillingFirstSmallArray(int array[10], int first_array[5], const int size)
{
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		first_array[i] = array[k];
		k++;
	}
}

void FillingSecondSmallArray(int array[10], int second_array[5], const int size_1, const int size_2)
{
	int k = size_1 - size_2;
	for (int i = 0; i < size_2; i++)
	{
		second_array[i] = array[k];
		k++;
	}
}

void PrintBigArray(int array[10], const int size)
{
	std::cout << "Big massive:\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "\n";
}

void PrintArray(int array[5],const int size)
{
	std::cout << "\n small massive: \n";
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
}
int main()
{
	const int size = 10;
	const int size_1 = 5;
	int array_1[size];
	FillingArray(size, array_1);
	PrintBigArray(array_1, size);
	int first_array[size_1];
	int second_array[size_1];
	FillingFirstSmallArray(array_1, first_array, size_1);
	FillingSecondSmallArray(array_1, second_array, size, size_1);
	PrintArray(first_array,size_1);
	PrintArray(second_array,size_1);
	return 0;
}