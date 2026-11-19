#include <array>
#include <iostream>

struct Audio
{
    std::array<double, 3> samples;
};

Audio mixAudio(Audio first, Audio second)
{
    return Audio{
        .samples{
            first.samples[0] * 0.25 + second.samples[0] * 0.75,
            first.samples[1] * 0.25 + second.samples[1] * 0.75,
            first.samples[2] * 0.25 + second.samples[2] * 0.75
        }
    };
}

int main()
{
    Audio first{
        .samples{ 0.8, 0.4, -0.2 }
    };

    Audio second{
        .samples{ -0.4, 0.4, 0.7 }
    };

    Audio result{ mixAudio(first, second) };

    std::cout << result.samples[0] << std::endl;
    std::cout << result.samples[1] << std::endl;
    std::cout << result.samples[2] << std::endl;
}