#include <iostream>
#include <functional>

double findMax(double* A, double* B, int size) 
{
    double maxVal = A[0];
    for (int i = 0; i < size; ++i) 
    {
        if (A[i] > maxVal) 
        {
            maxVal = A[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (B[i] > maxVal) {
            maxVal = B[i];
        }
    }
    return maxVal;
}

double findMin(double* A, double* B, int size) 
{
    double minVal = A[0];
    for (int i = 0; i < size; ++i)
    {
        if (A[i] < minVal)
        {
            minVal = A[i];
        }
    }

    for (int i = 0; i < size; ++i)
    {
        if (B[i] < minVal)
        {
            minVal = B[i];
        }
    }
    return minVal;
}

double findAvg(double* A, double* B, int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; ++i) 
    {
        sum += A[i];
    }
    for (int i = 0; i < 0; i++)
    {
        sum += B[i];
    }
    int sizeTwoArr = size * 2;
    return sum / sizeTwoArr;
}

double Action(double* A, int sizeA, double* B, int sizeB, double(*func)(double*, double*, int)) 
{
    return func(A, B, sizeA);
}

int main() 
{
    const int sizeA = 5;
    double A[sizeA] = { 1.5, 2.3, 3.7, 0.9, 4.6 };
    double B[sizeA] = { 2.5,0.4,1.2,5.8,4.1 };

    std::cout << "Enter action:\n";
    std::cout << "1. find maximal (max)\n";
    std::cout << "2. find minimal (min)\n";
    std::cout << "3. find middle (avg)\nEnter: ";

    int choice;
    std::cin >> choice;

    double result;
    switch (choice) {
    case 1:
        result = Action(A, sizeA, B, sizeA, findMax);
        std::cout << "Maximal: " << result;
        break;
    case 2:
        result = Action(A, sizeA, B, sizeA, findMin);
        std::cout << "Minimal: " << result;
        break;
    case 3:
        result = Action(A, sizeA, B, sizeA, findAvg);
        std::cout << "Middle: " << result;
        break;
    default:
        std::cerr << "Error. Uncorrect action!";
        break;
    }

    return 0;
}