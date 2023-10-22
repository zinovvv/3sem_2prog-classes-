#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

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

    void SetTracks(const std::vector<Track>& newTracks) {
        tracks = newTracks;
    }

    void OutputAlbum() const {
        std::cout << "��������: " << title << std::endl;
        std::cout << "�����������: " << artist << std::endl;
        std::cout << "��� ������: " << year << std::endl;
        std::cout << "���-�� ������: " << num_tracks << std::endl;
        for (const Track& track : tracks) {
            track.OutputTrack();
        }
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

    void SetTracks(const std::vector<Track>& newTracks) {
        tracks = newTracks;
    }

    void PrintTracks() const {
        for (const Track& track : tracks) {
            track.OutputTrack();
            std::cout << std::endl;
        }
    }

    void DeleteTrack() {
        int number;
        std::cout << "������� ����� �����, ������� ������ �������:";
        std::cin >> number;
        tracks.erase(tracks.begin() + number-1);
    }

    void InputTrack() {
            Track track = Track::InputTrack();
            tracks.push_back(track);
    }

    void AddAlbum(Album& album) {
        albums.push_back(album);
    }

    void SetAlbums(const std::vector<Album>& newAlbums) {
        albums = newAlbums;
    }

    void PrintAlbums() const {
        for (const Album& album : albums) {
            album.OutputAlbum();
            std::cout << std::endl;
        }
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
    SetConsoleCP(1251);
    setlocale(LC_ALL, "rus");

    MusicLibrary myMusicLibrary(1, 1);

    Playlist myPlaylist("������� �����", 3, 2);
    std::vector<Track> tracks = {
    {"�������", "������ ���", 400, 1986, "���"},
    {"������", "��-2", 345, 1998, "���"},
    {"���� � ������", "���� ����", 328, 2012, "���"}
    };
    myPlaylist.SetTracks(tracks);
    myPlaylist.PrintTracks();
    //myPlaylist.DeleteTrack();
    //myPlaylist.PrintTracks();
    //myPlaylist.InputTrack();
    //myPlaylist.PrintTracks();

    Album album1("���������� ����", "���", 2023, 12);
    std::vector<Track> tracks1 = {
        {"��������", "���", 180, 2023, "��� ���-���"},
        {"��������� ����", "���", 200, 2023, "��� ���-���"},
        {"���������", "���", 198, 2023, "��� ���-���"},
        {"������� ������", "���", 222, 2023, "��� ���-���"},
        {"���������� ����", "���", 210, 2023, "��� ���-���"},
        {"������ �����", "���", 195, 2023, "��� ���-���"},
        {"�������", "���", 189, 2023, "��� ���-���"},
        {"�� ������", "���", 240, 2023, "��� ���-���"},
        {"����", "���", 200, 2023, "��� ���-���"},
        {"������ ����", "���", 192, 2023, "��� ���-���"},
        {"������ �����", "���", 203, 2023, "��� ���-���"},
        {"���� ����", "���", 240, 2023, "��� ���-���"}
    };
    album1.SetTracks(tracks1);

    Album album2("��� ����", "������", 2023, 13);
    std::vector<Track> tracks2 = {
         {"� �������", "������", 171, 2023, "������������"},
        {"����� ���", "������", 224, 2023, "������������"},
        {"������", "������", 161, 2023, "������������"},
        {"���������", "������", 330, 2023, "������������"},
        {"�� �������", "������", 239, 2023, "������������"},
        {"���������", "������", 167, 2023, "������������"},
        {"���� ����", "������", 225, 2023, "������������"},
        {"��� ��� ��", "������", 258, 2023, "������������"},
        {"Spirit of the World", "������", 217, 2023, "������������"},
        {"������", "������", 266, 2023, "������������"},
        {"��������", "������", 97, 2023, "������������"},
        {"�������� � ����������", "������", 155, 2023, "������������"},
        {"������ �����", "������", 238, 2023, "������������"}
    };
    album2.SetTracks(tracks2);

    std::vector<Album> albums = { {album1},{album2} };

    myPlaylist.SetAlbums(albums);
    myPlaylist.PrintAlbums();

    /*ml = DeletePlaylistAlbum(ml);*/
    //ml = AlbumInputPlaylist(ml);
    /*OutputPlaylistAlbums(ml);*/

    return 0;
}
