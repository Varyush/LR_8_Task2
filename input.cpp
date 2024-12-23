#include "func.h"
const char fileName[17] = "output.txt";

int checkNum()
{
    int a;

    while(true)
    {
        std::cin >> a;

        if(std::cin.fail())
        {
            std::cout << '\n' << "Вы ввели неправильное значение, попробуйте ещё раз" << '\n';
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        } 
        else return a;
    }
}

int check()
{
    int a;

    while(true)
    {
        std::cin >> a;

        if(std::cin.fail() || a > 30)
        {
            std::cout << '\n' << "Вы ввели неправильное значение, попробуйте ещё раз" << '\n';
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        } 
        else return a;
    }
}

void inputFlights() 
{
    std::ofstream workFile(fileName);
    
    if (!workFile) 
    {
        std::cout << "Ошибка открытия файла для записи.";
        return;
    }

    int count;
    std::cout << "Введите количество рейсов: ";
    std::cin >> count;

    flightsArr = (Flights*)malloc(count * sizeof(Flights));

    for(int i = 0; i < count; ++i) 
    {
        Flights flight;
        std::cout << "Введите номер рейса: ";
        flight.d.number = checkNum();
        std::cout << "Введите тип самолета: ";
        std::cin >> flight.type;
        std::cout << "Введите пункт назначения: ";
        std::cin >> flight.destination;
        std::cout << "Введите время вылета (HH:MM): ";
        std::cin >> flight.time;
        flightsArr[i] = flight;

        workFile << flight.d.number << " "
                 << flight.type << " "
                 << flight.destination << " "
                 << flight.time << '\n';
    }

    workFile.close();
    std::cout << "Данные успешно сохранены в файл." << '\n';
}