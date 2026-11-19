#include <array>
#include <cstddef>
#include <iostream>

struct Photo
{
    int width;
    int height;
};

struct Library
{
    std::array<Photo, 3> photos;
};

struct Album
{
    std::array<Photo*, 3> photos;
};

void rotatePhoto(Album* album, size_t photoIndex)
{
    Photo* photo{ album->photos[photoIndex] };

    int temp{ photo->width };
    photo->width = photo->height;
    photo->height = temp;
}

int main()
{
    Library library{
        .photos{
            Photo{ 1920, 1080 },
            Photo{ 1280, 720 },
            Photo{ 800, 600 }
        }
    };

    Album firstAlbum{
        .photos{
            &library.photos[0],
            &library.photos[1],
            &library.photos[2]
        }
    };

    Album secondAlbum{
        .photos{
            &library.photos[1],
            &library.photos[0],
            &library.photos[2]
        }
    };

    rotatePhoto(&firstAlbum, 1);

    std::cout << secondAlbum.photos[0]->width << std::endl;
    std::cout << secondAlbum.photos[0]->height << std::endl;
}