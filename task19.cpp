#include <array>
#include <cstddef>
#include <iostream>

struct Racer
{
    double balance;
};

struct Race
{
    std::array<Racer, 3> racers;
};

struct Podium
{
    std::array<size_t, 3> positions;
};

void swapPositions(Podium* podium, size_t first, size_t second)
{
    size_t temp{ podium->positions[first] };
    podium->positions[first] = podium->positions[second];
    podium->positions[second] = temp;
}

void awardPrize(
    Race* race,
    Podium podium,
    size_t positionIndex,
    double prize)
{
    size_t racerIndex{ podium.positions[positionIndex] };

    race->racers[racerIndex].balance += prize;
}

int main()
{
    Race race{
        .racers{
            Racer{ 100.0 },
            Racer{ 200.0 },
            Racer{ 300.0 }
        }
    };

    Podium podium{
        .positions{ 0, 1, 2 }
    };

    swapPositions(&podium, 0, 1);

    awardPrize(&race, podium, 2, 30.0);

    std::cout << race.racers[podium.positions[2]].balance << std::endl;
}