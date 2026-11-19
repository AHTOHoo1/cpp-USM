#include <iostream>

struct CargoCar
{
    int cargoWeight;
    CargoCar* next;
};

void addCargo(CargoCar* car, int weight)
{
    car->cargoWeight += weight;
}

int main()
{
    CargoCar secondCar{ 8, nullptr };
    CargoCar firstCar{ 12, nullptr };

    firstCar.next = &secondCar;

    addCargo(firstCar.next, 5);

    std::cout << firstCar.next->cargoWeight << std::endl;
}