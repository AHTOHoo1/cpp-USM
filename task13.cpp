#include <array>
#include <cstddef>
#include <iostream>

struct Seat
{
    int ticketNumber;
};

struct Theater
{
    std::array<std::array<Seat, 4>, 3> rows;
};

void assignTicket(
    Theater* theater,
    size_t rowIndex,
    size_t seatIndex,
    int ticketNumber)
{
    theater->rows[rowIndex][seatIndex].ticketNumber = ticketNumber;
}

void moveTicket(
    Theater* theater,
    size_t sourceRow,
    size_t sourceSeat,
    size_t destinationRow,
    size_t destinationSeat)
{
    theater->rows[destinationRow][destinationSeat].ticketNumber =
        theater->rows[sourceRow][sourceSeat].ticketNumber;

    theater->rows[sourceRow][sourceSeat].ticketNumber = 0;
}

int main()
{
    Theater theater{};

    assignTicket(&theater, 0, 1, 42);

    moveTicket(&theater, 0, 1, 2, 3);

    std::cout << theater.rows[0][1].ticketNumber << std::endl;
    std::cout << theater.rows[2][3].ticketNumber << std::endl;
}