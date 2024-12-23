#include "func.h"
const char fileName[17] = "output.txt";

void changeFlight()
{
    std::ofstream workFile(fileName);
    std::fstream outFile("temp.txt");
    Flights flight;

    if (!workFile) 
    {
        std::cout << "Ошибка открытия" << '\n';
        return;
    }
    
    while (outFile >> flight.d.number >> flight.type >> flight.destination >> flight.time) 
    {
        workFile << flight.d.number << " "
                 << flight.type << " "
                 << flight.destination << " "
                 << flight.time << '\n';
    }

    workFile.close();
    std::remove("temp.txt");
}

void testFile1()
{
    std::ifstream workFile(fileName);

    if (!workFile) 
    {
        std::cout << "Ошибка открытия" << '\n';
        return;
    }

    std::ofstream outFile("temp.txt");

    if (!outFile) 
    {
        std::cerr << "Ошибка открытия временного файла для записи" << '\n';
        return;
    }

    int changeNumber;
    std::cout << "Введите номер рейса, который хотите изменнить" << '\n';
    changeNumber = checkNum();

    Flights flight;
    bool flightFound = false;

    while (workFile >> flight.d.number >> flight.type >> flight.destination >> flight.time) {
        if (flight.d.number == changeNumber) {
            flightFound = true;
            std::cout << "Введите новый тип рейса: ";
            std::cin >> flight.type;
            std::cout << "Введите новое направление: ";
            std::cin >> flight.destination;
            std::cout << "Введите новое время: ";
            std::cin >> flight.time;
        }

        outFile << flight.d.number << ' ' << flight.type << ' ' 
                << flight.destination << ' ' << flight.time << '\n';
    }

    workFile.close();
    outFile.close();

    if (!flightFound) {
        std::cout << "Рейс не найден." << '\n';
        std::remove("temp.txt");
        return;
    }

    workFile.close();
    outFile.close();
    changeFlight();
}