#include <iostream>

void FillingArray(int array[10], const int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 20;
	}
}

void FillingThirdArray(int array_1[10], int array_2[10], int array_3[5], const int size)
{
	for (int i = 0; i < size; i++)
	{
		array_3[i] = array_1[i] + array_2[i];
	}
}

void PrintArray(int array[10], const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "\n\n";
}

int main()
{
	const int size = 10;
	int array_1[size];
	int array_2[size];
	int array_3[size];
	FillingArray(array_1,size);
	FillingArray(array_2,size);
	PrintArray(array_1, size);
	PrintArray(array_2, size);
	FillingThirdArray(array_1, array_2, array_3, size);
	PrintArray(array_3, size);
	return 0;

}
