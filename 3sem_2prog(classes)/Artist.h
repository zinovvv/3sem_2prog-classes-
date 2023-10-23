#pragma once

#include "Album.h"
#include <string>
#include <vector>
class Artist {
private:
    std::string name;
    int numAlbums;
    std::vector<Album> albums;

public:
    Artist(const std::string& name, int numAlbums);
    Artist();

    void SetAlbums(const std::vector<Album>& newAlbums);
    void PrintAlbums() const;
    void DeleteAlbum();

    ~Artist() = default;
};