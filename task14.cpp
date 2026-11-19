#include <array>
#include <cstddef>
#include <iostream>

struct Position
{
    int x;
    int y;
};

struct DeliveryMap
{
    std::array<Position, 4> destinations;
};

struct Robot
{
    Position position;
};

struct Movement
{
    int deltaX;
    int deltaY;
};

Movement moveTo(Robot* robot, Position destination)
{
    Movement movement{
        destination.x - robot->position.x,
        destination.y - robot->position.y
    };

    robot->position = destination;

    return movement;
}

int main()
{
    DeliveryMap map{
        .destinations{
            Position{ 2, 5 },
            Position{ 4, 1 },
            Position{ 6, 7 },
            Position{ 8, 3 }
        }
    };

    Robot robot{
        .position{ 0, 3 }
    };

    Movement first{ moveTo(&robot, map.destinations[0]) };
    Movement second{ moveTo(&robot, map.destinations[2]) };

    std::cout << first.deltaX << " " << first.deltaY << std::endl;
    std::cout << second.deltaX << " " << second.deltaY << std::endl;

    std::cout << robot.position.x << " " << robot.position.y << std::endl;
}