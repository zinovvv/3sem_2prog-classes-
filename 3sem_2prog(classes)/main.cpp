#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
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

    static Track InputShortTrack() {
        std::string title, artist,genre;
        int duration,year;

        std::cout << "\n�������� �����: ";
        std::cin.ignore();
        std::getline(std::cin, title);

        std::cout << "���� �����: ";
        std::getline(std::cin, genre);

        std::cout << "������������ �����: ";
        std::cin >> duration;

        return Track(title,"", duration, 0,genre );
    }

    void OutputTrack() const {
        std::cout << "��������: " << title << std::endl;
        std::cout << "�����������: " << artist << std::endl;
        std::cout << "������������: " << duration << " seconds" << std::endl;
        std::cout << "��� ������: " << year << std::endl;
        std::cout << "����: " << genre << std::endl;
    }

    void OutputShortTrack() const {
        std::cout << std::left << "��������: " << std::setw(25)<< title;
        std::cout << std::left  << "������������: " <<duration << std::setw(10) << " ���";
        std::cout << "����: " << genre << std::endl;
    }

    ~Track() = default;
};

class Album {
private:
    std::string title;
    std::string artist;
    int year;
    int numTracks;
    std::vector<Track> tracks;

public:
    Album(const std::string& title, const std::string& artist, int year, int numTracks, std::vector<Track> tracks)
        : title(title), artist(artist), year(year), numTracks(numTracks), tracks(tracks) {}

    Album() {};


    Album InputAlbum() {
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

        for (int i = 0; i < num_tracks; ++i) {
            std::cout << "������� ���������� � ����� #" << (i + 1) << std::endl;
            Track track = Track::InputShortTrack();
            tracks.push_back(track);
        }
        return Album(title, artist, year, num_tracks,tracks);
    }

    void SetTracks(const std::vector<Track>& newTracks) {
        tracks = newTracks;
    }

    void OutputAlbum() const {
        std::cout << "��������: " << title << std::endl;
        std::cout << "�����������: " << artist << std::endl;
        std::cout << "��� ������: " << year << std::endl;
        std::cout << "���-�� ������: " << numTracks << std::endl;
        for (const Track& track : tracks) {
            track.OutputShortTrack();
        }
    }

    ~Album() = default;
};

class Artist {
private:
    std::string name;
    int numAlbums;
    std::vector<Album> albums;

public:
    Artist(const std::string& name, int numAlbums)
        : name(name), numAlbums(numAlbums) {};

    Artist() {};

    void SetAlbums(const std::vector<Album>& newAlbums) {
        albums = newAlbums;
    }

    void PrintAlbums()  const{
        for (const Album& album : this->albums) {
            album.OutputAlbum();
            std::cout << std::endl;
        }
    }

    void DeleteAlbum() {
        int number;
        std::cout << "������� ����� �������, ������� ������ �������: " << std::endl;
        std::cin >> number;
        albums.erase(albums.begin() + number - 1);
    }

    ~Artist() = default;
};

class Playlist {
private:
    std::string title;
    int numTracks;
    int numAlbums;
    std::vector<Track> tracks;
    std::vector<Album> albums;

public:
    Playlist(const std::string& title, int numTracks, int numAlbums) : title(title), numTracks(numTracks), numAlbums(numAlbums) {};

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
        std::cout << "������� ����� �����, ������� ������ �������:" << std::endl;
        std::cin >> number;
        tracks.erase(tracks.begin() + number-1);
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

    void DeleteAlbum() {
        int number;
        std::cout << "������� ����� �������, ������� ������ �������: " << std::endl;
        std::cin >> number;
        albums.erase(albums.begin() + number - 1);
    }

    ~Playlist() = default;
};

class MusicLibrary {
private:
    int numArtists;
    int numPlaylists;
    std::vector<Artist> allArtists;
    std::vector<Playlist> allPlaylists;

public:
    MusicLibrary(int numArtists, int numPlaylists)
        : numArtists(numArtists), numPlaylists(numPlaylists) {};

    MusicLibrary() {};


    void AddArtist(const Artist& artist) {
        allArtists.push_back(artist);
    }

    void AddPlaylist(const Playlist& playlist) {
        allPlaylists.push_back(playlist);
    }

    Playlist GetPlaylist(int index) {
        return allPlaylists.at(index);
    }

    Artist GetArtist(int index) {
        return allArtists.at(index);
    }

    ~MusicLibrary() = default;
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
    Album album1("���������� ����", "���", 2023, 12, {});
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
    Album album2("��� ����", "������", 2023, 13,{});
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
        {"��������", "������", 100, 2023, "������������"},
        {"�������� � ����������", "������", 155, 2023, "������������"},
        {"������ �����", "������", 238, 2023, "������������"}
    };
    album2.SetTracks(tracks2);
    std::vector<Album> albums = { album1,album2 };
    myPlaylist.SetAlbums(albums);
    Album albumLsp1("Magic City", "���", 2015, 9, {});
    std::vector<Track> tracksLsp1 =
    { {"Bullet", "���", 130, 2015, "���"},
    {"���-�� ���", "���", 423, 2015, "���"},
    {"����", "���", 412, 2015, "���"},
    {"�������", "���", 258, 2015, "���"},
    {"�����", "���", 258, 2015, "���"},
    {"�����", "���", 258, 2015, "���"},
    {"�����", "���", 258, 2015, "���"},
    {"��", "���", 258, 2015, "���"},
    {"������", "���", 258, 2015, "���"} };
    Album albumLsp2("Tragic City", "���", 2017, 10, {});
    std::vector<Track> tracksLsp2  =
    { {"�����������", "���", 130, 2015, "���"},
    {"�������", "���", 423, 2015, "���"},
    {"����", "���", 412, 2015, "���"},
    {"�������� ���������", "���", 258, 2015, "���"},
    {"����� �����", "���", 258, 2015, "���"},
    {"����� �����", "���", 258, 2015, "���"},
    {"��� ���� ����", "���", 258, 2015, "���"},
    {"������", "���", 258, 2015, "���"},
    {"�������", "���", 258, 2015, "���"},
    {"������ �� ��������", "���", 258, 2015, "���"}};
    albumLsp1.SetTracks(tracksLsp1);
    albumLsp2.SetTracks(tracksLsp2);
    std::vector<Album> albumsLsp = { albumLsp1,albumLsp2 };
    Artist myArtist("���", 2);
    myArtist.SetAlbums(albumsLsp);
    myMusicLibrary.AddPlaylist(myPlaylist);

    myPlaylist = myMusicLibrary.GetPlaylist(0);
    myPlaylist.PrintTracks();
    myPlaylist.DeleteTrack();
    myPlaylist.PrintTracks();
    //Track newTrack;
    //newTrack = newTrack.InputTrack();
    //myPlaylist.AddTrack(newTrack);
    //myPlaylist.PrintTracks();
    myPlaylist.PrintAlbums();
    myPlaylist.DeleteAlbum();
    myPlaylist.PrintAlbums();
    //Album newAlbum;
    //newAlbum = newAlbum.InputAlbum();
    //myPlaylist.AddAlbum(newAlbum);
    //myPlaylist.PrintAlbums();

    myMusicLibrary.AddArtist(myArtist);

    myArtist = myMusicLibrary.GetArtist(0);
    myArtist.PrintAlbums();
    myArtist.DeleteAlbum();
    myArtist.PrintAlbums();

    return 0;
}
