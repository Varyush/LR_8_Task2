#include "func.h"
const char fileName[17] = "output.txt";

void addFlightsToFile() 
{
    std::fstream workFile(fileName);

    if (!workFile) 
    {
        std::cout << "Ошибка открытия" << '\n';
        return;
    }

    int newCount;
    std::cout << "Введите количество рейсов для добавления: ";
    newCount = check();
    std::cout << '\n';

    Flights flight;
    int fileSize = fs::file_size(fileName) / sizeof(Flights);

    flightsArr = (Flights*) realloc(flightsArr, (fileSize + newCount) * sizeof(Flights));

    if (!flightsArr) 
    {
        std::cout << "Ошибка выделения памяти" << '\n';
        workFile.close();
        return;
    }
    
    workFile.seekg(0, workFile.end);

    for (int i = 0; i < newCount; ++i) 
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

        workFile << flight.d.number << " "
                 << flight.type << " "
                 << flight.destination << " "
                 << flight.time << '\n';

        flightsArr[fileSize + i] = flight;
    }

    workFile.close();
}