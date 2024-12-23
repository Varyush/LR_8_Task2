#include "func.h"
const char fileName[17] = "output.txt";

void menu()
{
    int choice;
    do
    {    
        std::cout << "Выберите, что вы хотите сделать" << '\n'
                  << "1. Ввод данных о рейсах" << '\n' 
                  << "2. Просмотр данных о рейсах" << '\n'
                  << "3. Добавить рейс" << '\n'
                  << "4. Удалить рейс" << '\n'
                  << "5. Изменить данные о рейсе" << '\n'
                  << "0. Выход" << '\n';
        std::cin >> choice;

        switch(choice)
        {
            case 1:
                inputFlights();
                break;
            case 2:
                readFromFile();
                break;
            case 3:
                addFlightsToFile();
                break;
            case 4:
                testFile();
                break; 
            case 5:
                testFile1();
                break;
            default: 
                break;
        }

    } while (choice != 0);
}