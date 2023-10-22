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

    static Track InputShortTrack() {
        std::string title, artist,genre;
        int duration,year;

        std::cout << "\nНазвание трека: ";
        std::cin.ignore();
        std::getline(std::cin, title);

        std::cout << "Жанр трека: ";
        std::getline(std::cin, genre);

        std::cout << "Длительность трека: ";
        std::cin >> duration;

        return Track(title,"", duration, 0,genre );
    }

    void OutputTrack() const {
        std::cout << "Название: " << title << std::endl;
        std::cout << "Исполнитель: " << artist << std::endl;
        std::cout << "Длительность: " << duration << " seconds" << std::endl;
        std::cout << "Год выхода: " << year << std::endl;
        std::cout << "Жанр: " << genre << std::endl;
    }

    void OutputShortTrack() const {
        std::cout << std::left << "Название: " << std::setw(25)<< title;
        std::cout << std::left  << "Длительность: " <<duration << std::setw(10) << " сек";
        std::cout << "Жанр: " << genre << std::endl;
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
    Album(const std::string& title, const std::string& artist, int year, int num_tracks, std::vector<Track> tracks)
        : title(title), artist(artist), year(year), num_tracks(num_tracks), tracks(tracks) {}

    Album() {};


    Album InputAlbum() {
        std::string title, artist;
        int year, num_tracks;

        std::cout << "\nНазвание альбома: ";
        std::getline(std::cin, title);

        std::cout << "Имя исполнителя: ";
        std::getline(std::cin, artist);

        std::cout << "Год выхода альбома: ";
        std::cin >> year;

        std::cout << "Кол-во треков в альбоме: ";
        std::cin >> num_tracks;

        for (int i = 0; i < num_tracks; ++i) {
            std::cout << "Введите информацию о треке #" << (i + 1) << std::endl;
            Track track = Track::InputShortTrack();
            tracks.push_back(track);
        }
        return Album(title, artist, year, num_tracks,tracks);
    }

    void SetTracks(const std::vector<Track>& newTracks) {
        tracks = newTracks;
    }

    void OutputAlbum() const {
        std::cout << "Название: " << title << std::endl;
        std::cout << "Исполнитель: " << artist << std::endl;
        std::cout << "Год выхода: " << year << std::endl;
        std::cout << "Кол-во треков: " << num_tracks << std::endl;
        for (const Track& track : tracks) {
            track.OutputShortTrack();
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
        std::cout << "Введите номер альбома, который хотите удалить: " << std::endl;
        std::cin >> number;
        albums.erase(albums.begin() + number - 1);
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
        std::cout << "Введите номер трека, который хотите удалить:" << std::endl;
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
        std::cout << "Введите номер альбома, который хотите удалить: " << std::endl;
        std::cin >> number;
        albums.erase(albums.begin() + number - 1);
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

    Playlist myPlaylist("Любимые треки", 3, 2);
    std::vector<Track> tracks = {
    {"Кукушка", "Виктор Цой", 400, 1986, "рок"},
    {"Метель", "Би-2", 345, 1998, "рок"},
    {"Лето в городе", "Иван Дорн", 328, 2012, "поп"}
    };
    myPlaylist.SetTracks(tracks);
    myPlaylist.PrintTracks();
    //myPlaylist.DeleteTrack();
    //myPlaylist.PrintTracks();
    //Track newTrack;
    //newTrack = newTrack.InputTrack();
    //myPlaylist.AddTrack(newTrack);
    //myPlaylist.PrintTracks();


    Album album1("Несчастные люди", "ЛСП", 2023, 12, std::vector<Track>());
    std::vector<Track> tracks1 = {
        {"Карантин", "ЛСП", 180, 2023, "поп хип-хоп"},
        {"Троянский конь", "ЛСП", 200, 2023, "поп хип-хоп"},
        {"Монополия", "ЛСП", 198, 2023, "поп хип-хоп"},
        {"Золотой ключик", "ЛСП", 222, 2023, "поп хип-хоп"},
        {"Несчастные люди", "ЛСП", 210, 2023, "поп хип-хоп"},
        {"Вечная весна", "ЛСП", 195, 2023, "поп хип-хоп"},
        {"Ураганы", "ЛСП", 189, 2023, "поп хип-хоп"},
        {"Не убежал", "ЛСП", 240, 2023, "поп хип-хоп"},
        {"Боди", "ЛСП", 200, 2023, "поп хип-хоп"},
        {"Сектор Приз", "ЛСП", 192, 2023, "поп хип-хоп"},
        {"Сикрет Плейс", "ЛСП", 203, 2023, "поп хип-хоп"},
        {"Стоп Игра", "ЛСП", 240, 2023, "поп хип-хоп"}
    };
    album1.SetTracks(tracks1);

    Album album2("Дух мира", "Джизус", 2023, 13,std::vector<Track>());
    std::vector<Track> tracks2 = {
         {"Я голоден", "Джизус", 171, 2023, "альтернатива"},
        {"Едкий дым", "Джизус", 224, 2023, "альтернатива"},
        {"Маньяк", "Джизус", 161, 2023, "альтернатива"},
        {"Галактика", "Джизус", 330, 2023, "альтернатива"},
        {"Всё забрать", "Джизус", 239, 2023, "альтернатива"},
        {"Плавишься", "Джизус", 167, 2023, "альтернатива"},
        {"Ждал тебя", "Джизус", 225, 2023, "альтернатива"},
        {"Рай или Ад", "Джизус", 258, 2023, "альтернатива"},
        {"Spirit of the World", "Джизус", 217, 2023, "альтернатива"},
        {"Жвачка", "Джизус", 266, 2023, "альтернатива"},
        {"Заповедь", "Джизус", 100, 2023, "альтернатива"},
        {"Сигареты и творчество", "Джизус", 155, 2023, "альтернатива"},
        {"Каплей дождя", "Джизус", 238, 2023, "альтернатива"}
    };
    album2.SetTracks(tracks2);

    std::vector<Album> albums = { {album1},{album2} };

    myPlaylist.SetAlbums(albums);
    myPlaylist.PrintAlbums();
    //myPlaylist.DeleteAlbum();
    //myPlaylist.PrintAlbums();
    //Album newAlbum;
    //newAlbum = newAlbum.InputAlbum();
    //myPlaylist.AddAlbum(newAlbum);
    //myPlaylist.PrintAlbums();

    Album albumLsp1("Magic City", "ЛСП", 2015, 9, std::vector<Track>());
    std::vector<Track> tracksLsp1 =
    { {"Bullet", "ЛСП", 130, 2015, "рэп"},
    {"Что-то ещё", "ЛСП", 423, 2015, "рэп"},
    {"Шест", "ЛСП", 412, 2015, "рэп"},
    {"Безумие", "ЛСП", 258, 2015, "рэп"},
    {"Синее", "ЛСП", 258, 2015, "рэп"},
    {"Фокус", "ЛСП", 258, 2015, "рэп"},
    {"Бигги", "ЛСП", 258, 2015, "рэп"},
    {"ОК", "ЛСП", 258, 2015, "рэп"},
    {"Уровни", "ЛСП", 258, 2015, "рэп"} };
    Album albumLsp2("Tragic City", "ЛСП", 2017, 10, std::vector<Track>());
    std::vector<Track> tracksLsp2  =
    { {"Воскресение", "ЛСП", 130, 2015, "рэп"},
    {"Монетка", "ЛСП", 423, 2015, "рэп"},
    {"Тело", "ЛСП", 412, 2015, "рэп"},
    {"Лабиринт отражений", "ЛСП", 258, 2015, "рэп"},
    {"Конец света", "ЛСП", 258, 2015, "рэп"},
    {"Белый танец", "ЛСП", 258, 2015, "рэп"},
    {"Ещё один день", "ЛСП", 258, 2015, "рэп"},
    {"Канкан", "ЛСП", 258, 2015, "рэп"},
    {"Ползать", "ЛСП", 258, 2015, "рэп"},
    {"Деньги не проблема", "ЛСП", 258, 2015, "рэп"}};
    albumLsp1.SetTracks(tracksLsp1);
    albumLsp2.SetTracks(tracksLsp2);
    std::vector<Album> albumsLsp = { {albumLsp1},{albumLsp2} };
    Artist myArtist("ЛСП", 2);
    myArtist.SetAlbums(albums);
    myArtist.PrintAlbums();
    myArtist.DeleteAlbum();
    myArtist.PrintAlbums();

    return 0;
}
