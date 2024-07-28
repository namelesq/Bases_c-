#include <iostream>
#include <string>
#include <cmath>

int binaryToDecimal(const std::string& binary) {
    int decimal = 0;
    int length = binary.length();

    for (int i = 0; i < length; ++i) {

        if (binary[length - 1 - i] == '1') {
            decimal += std::pow(2, i);
        }
    }

    return decimal;
}

int main() {
    std::string binaryNumber;

    std::cout << "Enter a binary number: ";
    std::cin >> binaryNumber;

    int decimalNumber = binaryToDecimal(binaryNumber);

    std::cout << "Decimal representation: " << decimalNumber << std::endl;

    return 0;
}

