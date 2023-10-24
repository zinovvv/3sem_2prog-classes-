#pragma once

#include "Album.h"
#include <string>
#include <vector>
class Playlist {
private:
    std::string title;
    int numTracks;
    int numAlbums;
    std::vector<Track> tracks;
    std::vector<Album> albums;

public:
    Playlist(const std::string& title, int numTracks, int numAlbums);

    Playlist(const Playlist& other) {};

    Playlist();

    void AddTrack(Track& track);

    void SetTracks(const std::vector<Track>& newTracks);

    void PrintTracks() const;

    void DeleteTrack();

    void AddAlbum(Album& album);

    void SetAlbums(const std::vector<Album>& newAlbums);

    void PrintAlbums() const;

    void DeleteAlbum();

    ~Playlist();
};