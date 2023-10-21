#include <iostream>
#include <string>
#include <vector>

class Track {
private:
    std::string title;
    std::string artist;
    int duration;
    int year;
    std::string genre;

public:
    Track(const std::string& title, const std::string& artist, int duration, int year, const std::string& genre)
        : title(title), artist(artist), duration(duration), year(year), genre(genre) {}

    Track() {};


    static Track InputTrack() {

        std::string title, artist, genre;
        int duration, year;

        std::cout << "\n�������� �����: ";
        std::getline(std::cin, title);

        std::cout << "��� �����������: ";
        std::getline(std::cin, artist);

        std::cout << "���� �����: ";
        std::getline(std::cin, genre);

        std::cout << "������������ �����: ";
        std::cin >> duration;

        std::cout << "��� ������ �����: ";
        std::cin >> year;

        return Track(title, artist, duration, year, genre);
    }

    void OutputTrack() const {
        std::cout << "��������: " << title << std::endl;
        std::cout << "�����������: " << artist << std::endl;
        std::cout << "������������: " << duration << " seconds" << std::endl;
        std::cout << "��� ������: " << year << std::endl;
        std::cout << "����: " << genre << std::endl;
    }

    ~Track() {}
};

class Album {
private:
    std::string title;
    std::string artist;
    int year;
    int num_tracks;
    std::vector<Track> tracks;

public:
    Album(const std::string& title, const std::string& artist, int year, int num_tracks)
        : title(title), artist(artist), year(year), num_tracks(num_tracks) {}

    Album() {};


    Album InputAlbum() {
        std::string title, artist;
        int year, num_tracks;

        std::cout << "\n�������� �����: ";
        std::getline(std::cin, title);

        std::cout << "��� �����������: ";
        std::getline(std::cin, artist);

        std::cout << "��� ������ �������: ";
        std::cin >> year;

        std::cout << "���-�� ������ � �������: ";
        std::cin >> num_tracks;

        for (int i = 0; i < num_tracks; ++i) {
            std::cout << "������� ���������� � ����� #" << (i + 1) << std::endl;
            Track track = Track::InputTrack();
            tracks.push_back(track);
        }
        return Album(title, artist, year, num_tracks);
    }
    ~Album() {}
};

class Artist {
private:
    std::string name;
    int num_albums;
    std::vector<Album> albums;

public:
    Artist(const std::string& name, int num_albums)
        : name(name), num_albums(num_albums) {};

    Artist() {};


    void AddAlbum(Album& album) {
        albums.push_back(album);
    }

    ~Artist() {}
};

class Playlist {
private:
    std::string title;
    int num_tracks;
    int num_albums;
    std::vector<Track> tracks;
    std::vector<Album> albums;

public:
    Playlist(const std::string& title, int num_tracks, int num_albums) : title(title), num_tracks(num_tracks), num_albums(num_albums) {};

    Playlist() {};


    void AddTrack(Track& track) {
        tracks.push_back(track);
    }

    void AddAlbum(Album& album) {
        albums.push_back(album);
    }

    ~Playlist(){}
};

class MusicLibrary {
private:
    int num_artists;
    int num_playlists;
    std::vector<Artist> all_artists;
    std::vector<Playlist> all_playlists;

public:
    MusicLibrary(int num_artists, int num_playlists)
        : num_artists(num_artists), num_playlists(num_playlists) {};

    MusicLibrary() {};


    void AddArtist(const Artist& artist) {
        all_artists.push_back(artist);
    }

    void AddPlaylist(const Playlist& playlist) {
        all_playlists.push_back(playlist);
    }

    ~MusicLibrary() {};
};

int main() {

    return 0;
}
