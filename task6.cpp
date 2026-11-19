#include <array>
#include <cstddef>
#include <iostream>

struct Recipe
{
    int flour;
    int sugar;
};

struct Bakery
{
    std::array<Recipe, 3> recipes;
    int flourStock;
    int sugarStock;
    int finishedBatches;
};

void bake(
    Bakery* bakery,
    size_t recipeIndex,
    int batchCount)
{
    Recipe recipe{ bakery->recipes[recipeIndex] };

    bakery->flourStock -= recipe.flour * batchCount;
    bakery->sugarStock -= recipe.sugar * batchCount;
    bakery->finishedBatches += batchCount;
}

int main()
{
    Bakery bakery{
        .recipes{
            Recipe{ 200, 100 },
            Recipe{ 300, 150 },
            Recipe{ 400, 200 }
        },
        .flourStock{ 2000 },
        .sugarStock{ 1000 },
        .finishedBatches{ 0 }
    };

    bake(&bakery, 1, 3);

    std::cout << bakery.flourStock << std::endl;
    std::cout << bakery.sugarStock << std::endl;
    std::cout << bakery.finishedBatches << std::endl;
}