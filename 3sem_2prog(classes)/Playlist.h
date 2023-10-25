#pragma once

#include "Album.h"
#include <string>
#include <vector>

//Класс "Плейлист", содержит вектор треков и вектор альбомов
class Playlist {
private:
    std::string title;
    int numTracks;
    int numAlbums;
    std::vector<Track> tracks;
    std::vector<Album> albums;

public:
    //Конструкторы
    Playlist(const std::string& title, int numTracks, int numAlbums);
    Playlist(const Playlist& other);
    Playlist();

    //Добавление трека в плейлист
    void AddTrack(Track& track);

    //Заполнение вектора tracks
    void SetTracks(const std::vector<Track>& newTracks);

    //Вывод треков
    void PrintTracks() const;

    //Удаление трека
    void DeleteTrack();

    //Добавление альбома
    void AddAlbum(Album& album);

    //Заполнение вектора albums
    void SetAlbums(const std::vector<Album>& newAlbums);

    //Вывод альбомов
    void PrintAlbums() const;

    //Удаление альбома
    void DeleteAlbum();

    //Деструктор
    ~Playlist() = default;
};