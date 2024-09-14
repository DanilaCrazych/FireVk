#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>

class Manager {
public:
    std::string marka;
    std::string model;
    std::string color;
    int age;
    float volume;

    Manager(const std::string& marka, const std::string& model, const std::string& color, int age, float volume);
    Manager();

    void addCar(std::vector<Manager>& inventory);
    void viewCars(const std::vector<Manager>& inventory);
};

#endif // MANAGER_H