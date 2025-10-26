#include <iostream>
#include <ctime>

int main() {
    long tmday_inp, tmmon_inp, tmyear_inp;

    std::cin >> tmyear_inp, tmmon_inp, tmday_inp;

    std::time_t now = std::time(nullptr);
    std::tm * local = std::localtime(&now);

    if ((local->tm_year + 1900) - tmyear_inp >= 18) {
        int o = ((local->tm_year + 1900) - tmyear_inp) + ((local->tm_mon + 1) - tmmon_inp) + (local->tm_mday - tmday_inp);
        std::cout << o;
        std::cout << (local->tm_year + 1900) - tmyear_inp << std::endl;
        std::cout << (local->tm_mon + 1) - tmmon_inp << std::endl;
        std::cout << local->tm_mday - tmday_inp << std::endl;
    }

    return 0;
}