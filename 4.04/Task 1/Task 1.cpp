#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
using namespace std;

void initializeMatrix(int** matrix, int size)
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            matrix[i][j] = rand()%20;
        }
    }
}

void initializeMatrix(double** matrix, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            matrix[i][j]= static_cast<double>(rand() % 100) / 10;
        }
    }
}


void initializeMatrix(char** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) 
        {
            matrix[i][j]= rand()%256;
        }
    }
}

void printMatrix(int** matrix, int size) 
{
    std::cout << "Matrix of integers numbers: \n";
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void printMatrix(double** matrix, int size) 
{
    std::cout << "Matrix of fractional numbers: \n";
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++)
        {
            std::cout<<matrix[i][j]<<"  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void printMatrix(char** matrix, int size) 
{
    std::cout << "Matrix of symbols: \n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void findMinMaxDiagonal(int** matrix, int size) 
{
    int min = numeric_limits<int>::max();
    int max = numeric_limits<int>::min();

    for (int i = 0; i < size; i++)
    {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }

    std::cout << "The minimum element on the main diagonal: " << min<<"\n";
    std::cout << "The maximal element on the main diagonal: " << max;
}

void findMinMaxDiagonal(double** matrix, int size)
{
    double min = numeric_limits<int>::max();
    double max = numeric_limits<int>::min();

    for (int i = 0; i < size; i++)
    {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }

    std::cout << "The minimum element on the main diagonal: " << min << "\n";
    std::cout << "The maximal element on the main diagonal: " << max;
}

void findMinMaxDiagonal(char** matrix, int size)
{
    char min = numeric_limits<int>::max();
    char max = numeric_limits<int>::min();

    for (int i = 0; i < size; i++)
    {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }

    std::cout << "The minimum element on the main diagonal: " << min << "\n";
    std::cout << "The maximal element on the main diagonal: " << max;
}

void sortRows(int** matrix, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        sort(matrix[i], matrix[i] + size);
    }
    std::cout << "\nSorted matrix of string: \n";
    printMatrix(matrix, size);
}

void sortRows(double** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        sort(matrix[i], matrix[i] + size);
    }
    std::cout << "\nSorted matrix of string: \n";
    printMatrix(matrix, size);
}

void sortRows(char** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        sort(matrix[i], matrix[i] + size);
    }
    std::cout << "\nSorted matrix of string: \n";
    printMatrix(matrix, size);
}

int main() 
{
    int size;
    cout << "Enter the size of the matrix: ";
    cin >> size;
    int** intMatrix = new int* [size];
    for (int i = 0; i < size; ++i)
    {
        intMatrix[i] = new int[size];
    }
    initializeMatrix(intMatrix, size);
    printMatrix(intMatrix, size);
    findMinMaxDiagonal(intMatrix, size);
    sortRows(intMatrix, size);
    for (int i = 0; i < size; ++i)
    {
        delete[] intMatrix[i];
    }
    delete[] intMatrix;

    double** DoubleMatrix = new double* [size];
    for (int i = 0; i < size; ++i)
    {
        DoubleMatrix[i] = new double[size];
    }
    initializeMatrix(DoubleMatrix, size);
    printMatrix(DoubleMatrix, size);
    findMinMaxDiagonal(DoubleMatrix, size);
    sortRows(DoubleMatrix, size);
    for (int i = 0; i < size; ++i)
    {
        delete[] DoubleMatrix[i];
    }
    delete[] DoubleMatrix;

    char** CharMatrix = new char* [size];
    for (int i = 0; i < size; ++i)
    {
        CharMatrix[i] = new char[size];
    }
    initializeMatrix(CharMatrix, size);
    printMatrix(CharMatrix, size);
    findMinMaxDiagonal(CharMatrix, size);
    sortRows(CharMatrix, size);
    for (int i = 0; i < size; ++i)
    {
        delete[] CharMatrix[i];
    }
    delete[] CharMatrix;

    return 0;
}