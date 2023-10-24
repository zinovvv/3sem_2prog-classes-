#include "Artist.h"
#include <iostream>

Artist::Artist(const std::string& name, int numAlbums)
    : name(name), numAlbums(numAlbums) {}

Artist::Artist(const Artist& other) {
    name = other.name;
    numAlbums = other.numAlbums;
    albums = other.albums;
}

Artist::Artist() {}

void Artist::SetAlbums(const std::vector<Album>& newAlbums) {
    albums = newAlbums;
}

void Artist::PrintAlbums() const {
    for (const Album& album : albums) {
        album.OutputAlbum();
        std::cout << std::endl;
    }
}

void Artist::DeleteAlbum() {
    int number;
    std::cout << "¬ведите номер альбома, который хотите удалить: " << std::endl;
    std::cin >> number;
    albums.erase(albums.begin() + number - 1);
}
