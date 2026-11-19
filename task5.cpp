#include <array>
#include <cstddef>
#include <iostream>

struct TicketPrices
{
    std::array<double, 3> prices;
};

struct Passenger
{
    size_t categoryIndex;
};

struct Purchase
{
    int ticketCount;
    double payment;
    double change;
};

double buyTickets(
    TicketPrices* prices,
    Passenger passenger,
    Purchase* purchase)
{
    double total{
        prices->prices[passenger.categoryIndex] * purchase->ticketCount
    };

    purchase->change = purchase->payment - total;

    return purchase->change;
}

int main()
{
    TicketPrices prices{
        .prices{ 5.0, 3.0, 2.0 }
    };

    Passenger passenger{ 1 };

    Purchase purchase{
        .ticketCount{ 2 },
        .payment{ 10.0 },
        .change{ 0.0 }
    };

    buyTickets(&prices, passenger, &purchase);

    std::cout << purchase.change << std::endl;
}