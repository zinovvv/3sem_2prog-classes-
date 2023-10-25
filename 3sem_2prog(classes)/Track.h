#pragma once

#include <string>

//Класс "Трек"
class Track {
private:

    std::string title;
    std::string artist;
    int duration;
    int year;
    std::string genre;

public:
    //Конструктор с параметрами
    Track(const std::string& title, const std::string& artist, int duration, int year, const std::string& genre);

    //Конструктор копирования с одним параметром
    Track(const Track& other);

    //Пустой конструктор
    Track();

    //Ввод трека
    static Track InputTrack();

    //Короткй вариант ввода
    static Track InputShortTrack();

    //Вывод трека
    void OutputTrack() const;

    //Короткий вывод трека
    void OutputShortTrack() const;

    //Деструктор
    ~Track() = default;
};
 