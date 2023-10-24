#include "Track.h"
#include <iostream>
#include <iomanip>

Track::Track(const std::string& title, const std::string& artist, int duration, int year, const std::string& genre)
    :title(title), artist(artist), duration(duration), year(year), genre(genre) {}

Track::Track(const Track& other) {
    title = other.title;
    artist = other.artist;
    duration = other.duration;
    year = other.year;
    genre = other.genre;
}

Track::Track() {};

Track Track::InputTrack() {
    std::string title, artist, genre;
    int duration, year;

    std::cout << "\nНазвание трека: ";
    std::getline(std::cin, title);

    std::cout << "Имя исполнителя: ";
    std::getline(std::cin, artist);

    std::cout << "Жанр трека: ";
    std::getline(std::cin, genre);

    std::cout << "Длительность трека: ";
    std::cin >> duration;

    std::cout << "Год выхода трека: ";
    std::cin >> year;


    return Track(title, artist, duration, year, genre);
}

Track Track::InputShortTrack() {
    std::string title, artist, genre;
    int duration;

    std::cout << "\nНазвание трека: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Жанр трека: ";
    std::getline(std::cin, genre);

    std::cout << "Длительность трека: ";
    std::cin >> duration;

    return Track(title, "", duration, 0, genre);
}

void Track::OutputTrack() const {
    std::cout << "Название: " << title << std::endl;
    std::cout << "Исполнитель: " << artist << std::endl;
    std::cout << "Длительность: " << duration << " seconds" << std::endl;
    std::cout << "Год выхода: " << year << std::endl;
    std::cout << "Жанр: " << genre << std::endl;
}

void Track::OutputShortTrack() const {
    std::cout << std::left << "Название: " << std::setw(25) << title;
    std::cout << std::left << "Длительность: " << duration << std::setw(10) << " сек";
    std::cout << "Жанр: " << genre << std::endl;
}