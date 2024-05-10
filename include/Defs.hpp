#ifndef DEFS_HPP
#define DEFS_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

#define CONFIG_FILE_INDEX 1
#define FILE_FAILED_MESSAGE "Failed to open the file!"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define FRAME_RATE 60
#define SEED 456
const string IMAGES_PATH = "./assets/images/";
const string MUSIC_PATH = "./assets/musics/";
const string FONTS_PATH = "./assets/fonts/";

enum State {
  BATTLE,
  STARTING,
  VICTORY,
  GAMEOVER,
  EXIT
};


#endif