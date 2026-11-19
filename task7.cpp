#include <array>
#include <cstddef>
#include <iostream>

struct ScrewBox
{
    int screwCount;
};

struct Cabinet
{
    std::array<ScrewBox, 4> boxes;
};

void moveScrews(
    Cabinet* cabinet,
    size_t sourceIndex,
    size_t destinationIndex)
{
    cabinet->boxes[destinationIndex].screwCount +=
        cabinet->boxes[sourceIndex].screwCount;

    cabinet->boxes[sourceIndex].screwCount = 0;
}

int main()
{
    Cabinet cabinet{
        .boxes{
            ScrewBox{ 3 },
            ScrewBox{ 4 },
            ScrewBox{ 6 },
            ScrewBox{ 0 }
        }
    };

    moveScrews(&cabinet, 2, 3);

    std::cout << cabinet.boxes[2].screwCount << std::endl;
    std::cout << cabinet.boxes[3].screwCount << std::endl;
}