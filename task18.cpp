#include <array>
#include <cstddef>
#include <iostream>

struct Lamp
{
    int brightness;
};

struct ControlPanel
{
    std::array<Lamp*, 3> lamps;
};

void changeBrightness(
    ControlPanel* panel,
    size_t lampIndex,
    int amount)
{
    panel->lamps[lampIndex]->brightness += amount;
}

int getBrightness(ControlPanel panel, size_t lampIndex)
{
    return panel.lamps[lampIndex]->brightness;
}

int main()
{
    Lamp lamp1{ 50 };
    Lamp lamp2{ 60 };
    Lamp lamp3{ 70 };
    Lamp lamp4{ 40 };
    Lamp lamp5{ 80 };

    ControlPanel firstPanel{
        .lamps{ &lamp1, &lamp2, &lamp3 }
    };

    ControlPanel secondPanel{
        .lamps{ &lamp4, &lamp2, &lamp5 }
    };

    changeBrightness(&firstPanel, 1, 20);

    std::cout << getBrightness(secondPanel, 1) << std::endl;
}