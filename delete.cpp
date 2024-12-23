#include "func.h"
const char fileName[17] = "output.txt";

void deletionFlight(int deleteNumber)
{
    std::ofstream workFile(fileName);
    std::fstream outFile("temp.txt");
    Flights flight;

    while (outFile >> flight.d.number >> flight.type >> flight.destination >> flight.time) 
    {
        workFile << flight.d.number << " "
                 << flight.type << " "
                 << flight.destination << " "
                 << flight.time << '\n';
    }

    std::cout << "Рейс с номером " << deleteNumber << " удалён." << '\n';
    workFile.close();
    std::remove("temp.txt"); 
}

void testFile()
{
    std::fstream workFile(fileName);

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

    int deleteNumber;
    std::cout << "Введите номер рейса для удаления" << '\n';
    deleteNumber = checkNum();

    Flights flight;
    int i = 0;

    while (workFile >> flight.d.number >> flight.type >> flight.destination >> flight.time) 
    {
        if (flight.d.number == deleteNumber) 
        {
            continue;
        }
        outFile << flight.d.number << " "
                << flight.type << " "
                << flight.destination << " "
                << flight.time << '\n';
    }

    workFile.close();
    outFile.close();
    deletionFlight(deleteNumber);
}