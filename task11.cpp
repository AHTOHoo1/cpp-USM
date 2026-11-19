#include <array>
#include <cstddef>
#include <iostream>

struct Track
{
    int duration;
};

struct Playlist
{
    std::array<Track, 5> tracks;
};

struct Player
{
    size_t currentTrack;
    int elapsedSeconds;
};

void seek(Player* player, int newTime)
{
    player->elapsedSeconds = newTime;
}

int getRemainingTime(Playlist playlist, Player player)
{
    return playlist.tracks[player.currentTrack].duration
        - player.elapsedSeconds;
}

void playTrack(Player* player, size_t trackIndex)
{
    player->currentTrack = trackIndex;
    player->elapsedSeconds = 0;
}

int main()
{
    Playlist playlist{
        .tracks{
            Track{ 180 },
            Track{ 200 },
            Track{ 150 },
            Track{ 210 },
            Track{ 190 }
        }
    };

    Player player{ 2, 30 };

    seek(&player, 45);

    std::cout << getRemainingTime(playlist, player) << std::endl;

    playTrack(&player, 4);

    std::cout << player.currentTrack << std::endl;
    std::cout << player.elapsedSeconds << std::endl;
}