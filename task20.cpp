#include <array>
#include <cstddef>
#include <iostream>

struct Battery
{
    int charge;
    int capacity;
};

struct Charger
{
    std::array<Battery*, 3> slots;
};

void chargeBattery(
    Charger* charger,
    size_t slotIndex,
    int amount)
{
    charger->slots[slotIndex]->charge += amount;
}

void swapBatteries(
    Charger* charger,
    size_t firstIndex,
    size_t secondIndex)
{
    Battery* temp{ charger->slots[firstIndex] };

    charger->slots[firstIndex] = charger->slots[secondIndex];
    charger->slots[secondIndex] = temp;
}

int main()
{
    Battery battery1{ 40, 100 };
    Battery battery2{ 70, 100 };
    Battery battery3{ 20, 100 };

    Charger charger{
        .slots{
            &battery1,
            &battery2,
            &battery3
        }
    };

    chargeBattery(&charger, 0, 30);

    swapBatteries(&charger, 0, 2);

    std::cout << charger.slots[2]->charge << std::endl;
}