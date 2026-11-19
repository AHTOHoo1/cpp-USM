#include <array>
#include <cstddef>
#include <iostream>

struct FileLine
{
    int characterCount;
};

struct TextFile
{
    std::array<FileLine, 5> lines;
};

void addCharacters(TextFile* file, size_t lineIndex, int amount)
{
    file->lines[lineIndex].characterCount += amount;
}

void swapLines(TextFile* file, size_t firstIndex, size_t secondIndex)
{
    FileLine temp{ file->lines[firstIndex] };
    file->lines[firstIndex] = file->lines[secondIndex];
    file->lines[secondIndex] = temp;
}

int main()
{
    TextFile file{
        .lines{ FileLine{ 10 }, FileLine{ 15 }, FileLine{ 20 },
                FileLine{ 12 }, FileLine{ 18 } }
    };

    addCharacters(&file, 2, 8);
    swapLines(&file, 0, 4);

    std::cout << file.lines[2].characterCount << std::endl;
    std::cout << file.lines[0].characterCount << std::endl;
    std::cout << file.lines[4].characterCount << std::endl;
}