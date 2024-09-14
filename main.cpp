#include <iostream>
#include <vector>
#include "manager.h"

int main() {
    std::vector<Manager> inventory;
    Manager manager;
    int choice;

    while (true) {
        std::cout << "\n1. Добавить автомобиль\n2. Просмотреть автомобили\n3. Выйти\nВыберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                manager.addCar(inventory);
                break;
            case 2:
                manager.viewCars(inventory);
                break;
            case 3:
                return 0;
            default:
                std::cout << "Неверный выбор, попробуйте снова." << std::endl;
                break;
        }
    }

    return 0;
}