#include <array>
#include <iostream>

struct Runner
{
    double finishTime;
    double distance;
};

struct Race
{
    std::array<Runner, 3> runners;
};

double getRemainingDistance(Runner runner, double elapsedTime)
{
    double speed{ runner.distance / runner.finishTime };

    double coveredDistance{ speed * elapsedTime };

    return runner.distance - coveredDistance;
}

int main()
{
    Race race{
        .runners{
            Runner{ 10.0, 100.0 },
            Runner{ 12.0, 100.0 },
            Runner{ 15.0, 100.0 }
        }
    };

    double elapsedTime{ 10.0 };

    std::cout << getRemainingDistance(race.runners[1], elapsedTime)
              << std::endl;

    std::cout << getRemainingDistance(race.runners[2], elapsedTime)
              << std::endl;
}