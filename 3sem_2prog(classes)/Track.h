#pragma once

#include <string>

class Track {
private:

    std::string title;
    std::string artist;
    int duration;
    int year;
    std::string genre;

public:

    Track(const std::string& title, const std::string& artist, int duration, int year, const std::string& genre);
    Track(const Track& other);
    Track();

    static Track InputTrack();
    static Track InputShortTrack();

    void OutputTrack() const;
    void OutputShortTrack() const;

    ~Track() = default;
};
 