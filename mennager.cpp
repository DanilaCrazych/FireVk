#include "manager.h"
#include <iostream>

Manager::Manager(const std::string& marka, const std::string& model, const std::string& color, int age, float volume)
    : marka(marka), model(model), color(color), age(age), volume(volume) {}

Manager::Manager() {}

void Manager::addCar(std::vector<Manager>& inventory) {
    try {
        std::string markaV, modelV, colorV;
        int ageV;
        float volumeV;

        std::cout << "Введите название марки: ";
        std::cin >> markaV;

        std::cout << "Введите название модели: ";
        std::cin >> modelV;

        std::cout << "Введите цвет автомобиля: ";
        std::cin >> colorV;

        std::cout << "Введите год производства: ";
        std::cin >> ageV;

        std::cout << "Введите объем двигателя: ";
        std::cin >> volumeV;

        Manager car(markaV, modelV, colorV, ageV, volumeV);
        inventory.push_back(car);
        std::cout << "Автомобиль добавлен!" << std::endl;
    }
    catch (...) {
        std::cout << "Ошибка!" << std::endl;
    }
}

void Manager::viewCars(const std::vector<Manager>& inventory) {
    try {
        for (size_t i = 0; i < inventory.size(); ++i) {
            std::cout << "Номер: " << i + 1
                      << "\nМарка: " << inventory[i].marka
                      << "\nМодель: " << inventory[i].model
                      << "\nЦвет: " << inventory[i].color
                      << "\nГод: " << inventory[i].age
                      << "\nОбъем двигателя: " << inventory[i].volume
                      << "\n--------" << std::endl;
        }
    }
    catch (...) {
        std::cout << "Ошибка!" << std::endl;
    }
}