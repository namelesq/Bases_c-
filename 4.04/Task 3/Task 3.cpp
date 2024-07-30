#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <string>

std::string generateSecretNumber() 
{
    std::set<int> digits;
    std::string secret;
    while (secret.length() < 4) 
    {
        int digit = rand() % 10;
        if (digits.find(digit) == digits.end() && digit != 0 || secret.length() > 0) 
        {
            digits.insert(digit);
            secret += std::to_string(digit);
        }
    }
    return secret;
}

void bullsAndCows(const std::string& secret, int attemptCount, const int size) {
    std::string guess;
    std::cout << "\nВведите четырехзначное число (попытка " << attemptCount + 1 << "): ";
    std::cin >> guess;

    if (guess.length() != 4 || guess[0] == '0') 
    {
        std::cout << "Некорректный ввод. Пожалуйста, введите 4-х значное число, не начинающееся с 0.";
        bullsAndCows(secret, attemptCount,size); 
        return;
    }

    int bulls = 0;
    int cows = 0;


    for (int i = 0; i < size; i++)
    {
        if (guess[i] == secret[i])
        {
            bulls++;
        }
        else if (secret.find(guess[i]) != std::string::npos) 
        {
            cows++;
        }
    }

    std::cout << bulls << " быков, " << cows << " коров.";

    if (bulls == 4) 
    {
        std::cout << "Поздравляем! Вы угадали число " << secret << " за " << attemptCount + 1 << " попыток.";
    }
    else 
    {
        bullsAndCows(secret, attemptCount + 1,size); 
    }
}

int main() {
    const int SizeNumber=4;
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    std::string secret = generateSecretNumber();
    std::cout << "Игра началась! Я загадал четырехзначное число.";
    bullsAndCows(secret, 0,SizeNumber);
    return 0;
}