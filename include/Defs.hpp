#ifndef DEFS_HPP
#define DEFS_HPP

#include <vector>
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
#define FRAME_RATE 30
#define GARGANTUAR_RATIO 0.25
#define COOL_PENALTY 5

const string IMAGES_PATH = "./assets/images/";
const string MUSIC_PATH = "./assets/musics/";
const string FONTS_PATH = "./assets/fonts/";

const vector<unsigned int> WIDTH_GRIDS = {
  255, 340, 410, 500, 570, 660, 740, 815, 895
};
const vector<unsigned int> HEIGHT_GRIDS ={
  80, 175, 275, 380, 470
};

const IntRect BATTLE_FIELD(250, 70, 745, 515);
const IntRect SUN_RECT(0, 0, 350, 325);
const IntRect ZOMBIE_RECT(5, 5, 23, 36);

enum State {
  BATTLE,
  STARTING,
  VICTORY,
  GAMEOVER,
  EXIT
};


#endif