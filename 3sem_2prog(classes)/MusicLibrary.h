#pragma once

#include "Artist.h"
#include "Playlist.h"
#include <string>
#include <vector>
class MusicLibrary {
private:
    int numArtists;
    int numPlaylists;
    std::vector<Artist> allArtists;
    std::vector<Playlist> allPlaylists;

public:
    MusicLibrary(int numArtists, int numPlaylists);
    MusicLibrary(const MusicLibrary& other);
    MusicLibrary();

    void AddArtist(const Artist& artist);
    void AddPlaylist(const Playlist& playlist);

    Artist* GetArtist(int index);
    Playlist GetPlaylist(int index);

    ~MusicLibrary() = default;
};