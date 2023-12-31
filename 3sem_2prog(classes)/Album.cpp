#include "Album.h"
#include <iostream>

Album::Album(const std::string& title, const std::string& artist, int year, int numTracks, std::vector<Track> tracks)
    : title(title), artist(artist), year(year), numTracks(numTracks), tracks(tracks) {}

Album::Album(const Album& other) {
    title = other.title;
    artist = other.artist;
    year = other.year;
    numTracks = other.numTracks;
    tracks = other.tracks;
}

Album::Album() {};

Album* Album::InputAlbum() {
    std::string title, artist;
    int year, num_tracks;

    std::cout << "\n�������� �������: ";
    std::getline(std::cin, title);

    std::cout << "��� �����������: ";
    std::getline(std::cin, artist);

    std::cout << "��� ������ �������: ";
    std::cin >> year;

    std::cout << "���-�� ������ � �������: ";
    std::cin >> num_tracks;

    //�������� ������� ����� ������� ������ InputShortTrack � ����������� � ������ tracks
    for (int i = 0; i < num_tracks; ++i) {
        std::cout << "������� ���������� � ����� #" << (i + 1) << std::endl;
        Track track = Track::InputShortTrack();
        tracks.push_back(track);
    }

    //������� ������ ��� newAlbum
    Album* newAlbum = new Album(title, artist, year, num_tracks, tracks);
    newAlbum->SetTracks(tracks);
    return newAlbum;
}

void Album::SetTracks(const std::vector<Track>& newTracks) {
    tracks = newTracks;
}

void Album::OutputAlbum() const {
    std::cout << "\n��������: " << title << std::endl;
    std::cout << "�����������: " << artist << std::endl;
    std::cout << "��� ������: " << year << std::endl;
    std::cout << "���-�� ������: " << numTracks << std::endl;
    for (const Track& track : tracks) {
        track.OutputShortTrack();
    }
}

Album::~Album() {};