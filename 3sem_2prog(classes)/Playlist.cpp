#include "Playlist.h"
#include <iostream>

Playlist::Playlist(const std::string& title, int numTracks, int numAlbums)
    : title(title), numTracks(numTracks), numAlbums(numAlbums) {}

Playlist::Playlist() {}

void Playlist::AddTrack(Track& track) {
    tracks.push_back(track);
}

void Playlist::SetTracks(const std::vector<Track>& newTracks) {
    tracks = newTracks;
}

void Playlist::PrintTracks() const {
    for (const Track& track : tracks) {
        track.OutputTrack();
        std::cout << std::endl;
    }
}

void Playlist::DeleteTrack() {
    int number;
    std::cout << "¬ведите номер трека, который хотите удалить:" << std::endl;
    std::cin >> number;
    tracks.erase(tracks.begin() + number - 1);
}

void Playlist::AddAlbum(Album& album) {
    albums.push_back(album);
}

void Playlist::SetAlbums(const std::vector<Album>& newAlbums) {
    albums = newAlbums;
}

void Playlist::PrintAlbums() const {
    for (const Album& album : albums) {
        album.OutputAlbum();
        std::cout << std::endl;
    }
}

void Playlist::DeleteAlbum() {
    int number;
    std::cout << "¬ведите номер альбома, который хотите удалить: " << std::endl;
    std::cin >> number;
    albums.erase(albums.begin() + number - 1);
}

Playlist::~Playlist() = default;
