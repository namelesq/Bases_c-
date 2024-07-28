#include <iostream>

void FillingArray(int array[10], const int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 10;
	}
}

void PrintArray(int array[10], const int size)
{
	std::cout << "You array:\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "\n\n";
}

int LinearSearch(int array[10], const int size, int key)
{
	int check = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == key)
		{
			return i;
		}
		else
		{
			check++;
		}
	}
	if (check == size)
	{
		return -1;
	}
}
int main()
{
	const int size = 10;
	int array[size];
	int key;
	std::cout << "Enter key for search: ";
	std::cin >> key;
	FillingArray(array, size);
	PrintArray(array, size);
	int result= LinearSearch(array, size, key);
	if (result != -1) 
	{
		std::cout << "The element " << key << " was found on the " << result<<" index";
	}
	else 
	{
		std::cout << "The element" << key << " was not found";
	}
	return 0;
}