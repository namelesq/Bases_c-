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

int binarySearch(int arr[10], int key, const int size) {
    int left = 0;
    int right = size;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (arr[mid] == key) {
            return mid; 
        }

        else if (arr[mid] < key) {
            left = mid + 1;
        }

        else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() 
{
    const int size = 10;
    int arr[10];
    int key;
    std::cout << "Enter key for search: ";
    std::cin >> key;
    FillingArray(arr, size);
    PrintArray(arr, size);
    int result = binarySearch(arr, key,size);
    if (result != -1)
    {
        std::cout << "The element " << key << " was found on the " << result << " index";
    }
    else
    {
        std::cout << "The element" << key << " was not found";
    }
    return 0;
}