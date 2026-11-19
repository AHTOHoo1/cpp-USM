#include <array>
#include <cstddef>
#include <iostream>

struct Tool
{
    int durability;
};

struct Backpack
{
    std::array<Tool, 3> tools;
};

struct QuickAccess
{
    std::array<Tool*, 3> slots;
};

void useTool(QuickAccess* panel, size_t slotIndex, int damage)
{
    panel->slots[slotIndex]->durability -= damage;
}

int main()
{
    Backpack backpack{
        .tools{
            Tool{ 100 },
            Tool{ 80 },
            Tool{ 60 }
        }
    };

    QuickAccess panel{
        .slots{
            &backpack.tools[0],
            &backpack.tools[0],
            &backpack.tools[2]
        }
    };

    useTool(&panel, 0, 10);

    std::cout << backpack.tools[0].durability << std::endl;
    std::cout << panel.slots[0]->durability << std::endl;
    std::cout << panel.slots[1]->durability << std::endl;
}