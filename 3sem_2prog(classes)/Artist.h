#pragma once

#include "Album.h"
#include <string>
#include <vector>

//Класс "Артист", содержит вектор альбомов
class Artist {
private:
    std::string name;
    int numAlbums;
    std::vector<Album> albums;

public:
    //Конструкторы
    Artist(const std::string& name, int numAlbums);
    Artist(const Artist& other);
    Artist();

    //Заполнение вектора albums
    void SetAlbums(const std::vector<Album>& newAlbums);

    //Вывод альбомов
    void PrintAlbums() const;

    //Удаление альбома
    void DeleteAlbum();

    //Деструктор
    ~Artist() = default;
};