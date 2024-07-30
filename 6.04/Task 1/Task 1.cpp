#include <iostream>
int main() 
{
    const int size = 5;
    int source[size] = { 1, 2, 3, 4, 5 };
    int destination[size];
    int* srcPtr = source; 
    int* destPtr = destination; 
    for (int i = 0; i < size; ++i) 
    {
        *(destPtr + i) = *(srcPtr + i); 
    }
    std::cout << "Elements of the destination array: \n";
    for (int i = 0; i < size; ++i) 
    {
        std::cout << *(destPtr + i) << " ";
    }
    return 0;
}