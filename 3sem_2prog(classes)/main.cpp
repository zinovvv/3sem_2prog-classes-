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
 /*   Album newAlbum;
    newAlbum = newAlbum.InputAlbum();
    myPlaylist.AddAlbum(newAlbum);
    myPlaylist.PrintAlbums();*/

    myMusicLibrary.AddArtist(myArtist);
    myArtist = myMusicLibrary.GetArtist(0);
    myArtist.PrintAlbums();
    myArtist.DeleteAlbum();
    myArtist.PrintAlbums();


    return 0;
}