#include <iostream>
#include <functional>

double findMax(double* A, int size) 
{
    double maxVal = A[0];
    for (int i = 1; i < size; ++i) {
        if (A[i] > maxVal) {
            maxVal = A[i];
        }
    }
    return maxVal;
}

double findMin(double* A, int size) 
{
    double minVal = A[0];
    for (int i = 1; i < size; ++i) {
        if (A[i] < minVal) {
            minVal = A[i];
        }
    }
    return minVal;
}

double findAvg(double* A, int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += A[i];
    }
    return sum / size;
}

double Action(double* A, int sizeA, double* B, int sizeB, double(*func)(double*, int)) 
{
    return func(A, sizeA);
}

int main() 
{
    const int sizeA = 5;
    double A[sizeA] = { 1.5, 2.3, 3.7, 0.9, 4.6 };

    std::cout << "Enter action:\n";
    std::cout << "1. find maximal (max)\n";
    std::cout << "2. find minimal (min)\n";
    std::cout << "3. find middle (avg)\nEnter: ";

    int choice;
    std::cin >> choice;

    double result;
    switch (choice) {
    case 1:
        result = Action(A, sizeA, nullptr, 0, findMax);
        std::cout << "Maximal: " << result;
        break;
    case 2:
        result = Action(A, sizeA, nullptr, 0, findMin);
        std::cout << "Minimal: " << result;
        break;
    case 3:
        result = Action(A, sizeA, nullptr, 0, findAvg);
        std::cout << "Middle: " << result;
        break;
    default:
        std::cerr << "Error. Uncorrect action!";
        break;
    }

    return 0;
}