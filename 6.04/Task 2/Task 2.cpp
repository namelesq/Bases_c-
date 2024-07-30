#include <iostream>

void reverseArray(int* arr, int size)
{
    int* start = arr;
    int* end = arr + size - 1;

    while (start < end) 
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() 
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, size);

    std::cout << "Inverted array: \n";
    for (int i = 0; i < size; i++) 
    {
        std::cout << *(arr + i) << " ";
    }

    return 0;
}