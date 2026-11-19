#include <array>
#include <cstddef>
#include <iostream>

struct Product
{
    double price;
    int quantity;
};

struct Shop
{
    std::array<Product, 3> products;
    double cash;
};

struct Showcase
{
    std::array<Product*, 3> products;
};

void sellProduct(
    Shop* shop,
    Showcase showcase,
    size_t productIndex)
{
    Product* product{ showcase.products[productIndex] };

    product->quantity -= 1;
    shop->cash += product->price;
}

int main()
{
    Shop shop{
        .products{
            Product{ 2.0, 10 },
            Product{ 3.0, 15 },
            Product{ 5.0, 8 }
        },
        .cash{ 100.0 }
    };

    Showcase firstShowcase{
        .products{
            &shop.products[0],
            &shop.products[1],
            &shop.products[2]
        }
    };

    Showcase secondShowcase{
        .products{
            &shop.products[2],
            &shop.products[0],
            &shop.products[1]
        }
    };

    sellProduct(&shop, secondShowcase, 1);

    std::cout << firstShowcase.products[0]->quantity << std::endl;
    std::cout << shop.cash << std::endl;
}