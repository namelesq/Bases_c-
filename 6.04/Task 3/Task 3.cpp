#include <iostream>

int main() 
{
    const int size = 5;
    int source[size] = { 1, 2, 3, 4, 5 };
    int destination[size];

    int* srcPtr = source;
    int* destPtr = destination + size - 1;

    for (int i = 0; i < size; ++i)
    {
        *destPtr = *srcPtr;
        srcPtr++;
        destPtr--;
    }
    std::cout << "Copied array in reverse order: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << destination[i] << " ";
    }

    return 0;
}
