#include "func.h"
const char fileName[17] = "output.txt";

void readFromFile() 
{
    std::ifstream workFile(fileName);
    
    if (!workFile) 
    {
        std::cerr << "Ошибка при открытии файла!" << '\n';
        return;
    }
    
    Flights flight;
    while (workFile >> flight.d.number >> flight.type >> flight.destination >> flight.time) 
    {
        std::cout << "Рейс номер: " << flight.d.number 
                  << ", Тип: " << flight.type 
                  << ", Направление: " << flight.destination 
                  << ", Время: " << flight.time << '\n';
    }
    
    workFile.close();
}