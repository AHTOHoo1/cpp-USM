#include <array>
#include <cstddef>
#include <iostream>

struct TrainCar
{
    int capacity;
    int passengers;
};

struct Train
{
    std::array<TrainCar, 3> cars;
};

void movePassengers(
    Train* train,
    size_t sourceIndex,
    size_t destinationIndex)
{
    int freeSeats{
        train->cars[destinationIndex].capacity -
        train->cars[destinationIndex].passengers
    };

    int availablePassengers{
        train->cars[sourceIndex].passengers
    };

    int movedPassengers{
        freeSeats < availablePassengers
            ? freeSeats
            : availablePassengers
    };

    train->cars[sourceIndex].passengers -= movedPassengers;
    train->cars[destinationIndex].passengers += movedPassengers;
}

int getFreeSeats(TrainCar car)
{
    return car.capacity - car.passengers;
}

int main()
{
    Train train{
        .cars{
            TrainCar{ 10, 6 },
            TrainCar{ 10, 4 },
            TrainCar{ 10, 8 }
        }
    };

    movePassengers(&train, 0, 1);

    std::cout << getFreeSeats(train.cars[0]) << std::endl;
    std::cout << getFreeSeats(train.cars[1]) << std::endl;
}