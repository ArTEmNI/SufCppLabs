#include <iostream>

#include <ctime>

// Функция для вычисления возраста
int Age(int b_year, int b_mon, int b_day) {

    // Получаем текущую дату
    std::time_t t = std::time(nullptr); //Переменная для хранения времени (в секундах с 1970)
    std::tm* now = std::localtime(&t); //Преобразуем время в структуру tm (удобная стуктура с полями)

    //Преобразуем дату в переменные
    int cur_year = now->tm_year + 1900; //Содержит этот год
    int cur_month = now->tm_mon + 1; //Содержит этот месяц
    int cur_day = now->tm_mday; //Содержит этот день

    // Вычисляем возраст
    int age = cur_year - b_year;
    int age_mon = cur_month - b_mon;
    int age_day = cur_day - b_day;

    // Проверяем если день рождения не наступил в этом году
    if (cur_month < b_mon ||
        (cur_month == b_mon && cur_day < b_day)) {
        age = age--;
        }

    return age;
}

//Проверяем на день рождения
bool birthday(int b_mon, int b_day) {

    bool birthday = false; //Флаг дня рождения

    //Получение этого месяца и дня
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int cur_mon = now->tm_mon + 1;
    int cur_day = now->tm_mday;

    if (b_day == cur_day && b_mon == cur_mon) {birthday = true;}

    return birthday;
}

int main() {
    int year, mon, day;
    std::cin >> year >> mon >> day;
    if (birthday(mon, day)) {std::cout << "s dr";}
    else if (Age(year, mon, day) >= 18) {std::cout << "zbc";}
    else {std::cout << "ne zbc";}
}