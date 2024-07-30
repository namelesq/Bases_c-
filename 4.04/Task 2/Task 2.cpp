#include <iostream>

int gcd(int num1, int num2)
{
	if (num2 == 0)
	{
		return num1;
	}
	return gcd(num2, num1 % num2);
}

int main()
{
	int number_1, number_2;

	std::cout << "Enter first number: ";
	std::cin >> number_1;
	std::cout << "Enter second number: ";
	std::cin >> number_2;
	int result = gcd(number_1, number_2);
	std::cout << "The laggest common divisor " << number_1 << " and " << number_2 << " = " << result;
	return 0;
}