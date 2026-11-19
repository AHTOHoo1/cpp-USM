#include <array>
#include <cstddef>
#include <iostream>

struct Product
{
    int quantity;
};

struct MiniBar
{
    std::array<Product, 4> products;
};

struct Hotel
{
    std::array<double, 4> prices;
};

struct RoomBill
{
    double total;
};

void takeProduct(
    MiniBar* miniBar,
    Hotel hotel,
    RoomBill* bill,
    size_t productIndex,
    int quantity)
{
    miniBar->products[productIndex].quantity -= quantity;

    bill->total +=
        hotel.prices[productIndex] * quantity;
}

int main()
{
    MiniBar miniBar{
        .products{
            Product{ 5 },
            Product{ 4 },
            Product{ 6 },
            Product{ 3 }
        }
    };

    Hotel hotel{
        .prices{ 2.0, 1.5, 3.0, 2.5 }
    };

    RoomBill bill{ 0.0 };

    takeProduct(&miniBar, hotel, &bill, 0, 2);
    takeProduct(&miniBar, hotel, &bill, 1, 1);

    std::cout << miniBar.products[0].quantity << std::endl;
    std::cout << miniBar.products[1].quantity << std::endl;
    std::cout << bill.total << std::endl;
}