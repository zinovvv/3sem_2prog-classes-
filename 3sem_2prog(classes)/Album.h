#pragma once

#include <string>
#include <vector>
#include "Track.h"  // ¬ключаем заголовочный файл класса Track

class Album {
private:
    std::string title;
    std::string artist;
    int year;
    int numTracks;
    std::vector<Track> tracks;

public:
    Album(const std::string& title, const std::string& artist, int year, int numTracks, std::vector<Track> tracks);

    Album InputAlbum();
    void SetTracks(const std::vector<Track>& newTracks);
    void OutputAlbum() const;
    ~Album();
};