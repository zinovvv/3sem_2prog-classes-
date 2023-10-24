#include "MusicLibrary.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>

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
    Album* album1 = new Album("Несчастные люди", "ЛСП", 2023, 12, {});
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
    album1->SetTracks(tracks1);
    Album* album2 = new Album("Дух мира", "Джизус", 2023, 13, {});
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
    album2->SetTracks(tracks2);
    std::vector<Album> albums = { *album1, *album2 };
    myPlaylist.SetAlbums(albums);
    Album albumLsp1("Magic City", "ЛСП", 2015, 9, {});
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
    Album albumLsp2("Tragic City", "ЛСП", 2017, 10, {});
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
    std::vector<Album> albumsLsp = { albumLsp1,albumLsp2 };
    Artist* myArtist = new Artist("ЛСП", 2);
    myArtist->SetAlbums(albumsLsp);
    myMusicLibrary.AddPlaylist(myPlaylist);

    myPlaylist = myMusicLibrary.GetPlaylist(0);
    std::cout << "Вывод треков из плейлиста\n" << std::endl;
    myPlaylist.PrintTracks();
    myPlaylist.DeleteTrack();
    myPlaylist.PrintTracks();
    //std::cout << "Добавление трека в плейлист" << std::endl;
    //Track newTrack;
    //newTrack = newTrack.InputTrack();
    //myPlaylist.AddTrack(newTrack);
    //myPlaylist.PrintTracks();
    std::cout << "\nВывод альбомов из плейлиста\n" << std::endl;
    myPlaylist.PrintAlbums();
    std::cout << "\nУдаление альбома из плейлиста\n" << std::endl;
    myPlaylist.DeleteAlbum();
    std::cout << "\nВывод альбомов из плейлиста\n" << std::endl;
    myPlaylist.PrintAlbums();
 /*   Album newAlbum;
    newAlbum = newAlbum.InputAlbum();
    myPlaylist.AddAlbum(newAlbum);
    myPlaylist.PrintAlbums();*/

    myMusicLibrary.AddArtist(*myArtist);
    myArtist = myMusicLibrary.GetArtist(0);
    std::cout << "\nВывод альбомов артиста\n" << std::endl;
    myArtist->PrintAlbums();
    std::cout << "\nУдаление альбома артиста\n" << std::endl;
    myArtist->DeleteAlbum();
    std::cout << "\nВывод альбомов артиста\n" << std::endl;
    myArtist->PrintAlbums();

    delete album1;
    delete album2;

    return 0;
}