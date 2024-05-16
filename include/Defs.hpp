#ifndef DEFS_HPP
#define DEFS_HPP

#include <vector>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


#define CONFIG_FILE_INDEX 1
#define FILE_FAILED_MESSAGE "Failed to open the file!"
#define WRONG_TYPE_MESSAGE "Not supported type!"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define FRAME_RATE 30
#define GARGANTUAR_RATIO 0.25
#define COOL_PENALTY 5

using namespace sf;
using namespace std;

const string IMAGES_PATH = "./assets/images/";
const string MUSIC_PATH = "./assets/musics/";
const string FONTS_PATH = "./assets/fonts/";


const vector<unsigned int> WIDTH_GRIDS = {
  255, 340, 410, 500, 570, 660, 740, 815, 895
};
const vector<unsigned int> HEIGHT_GRIDS ={
  80, 175, 275, 380, 470
};

const IntRect PEA_RECT(0, 150, 95, 96);
const IntRect SNOWPEA_RECT(0, 130, 120, 115);
const IntRect SUNFLOWER_RECT(0, 175, 125, 125);
const IntRect WALNUT_RECT(0, 0, 101, 115);
const IntRect BATTLE_FIELD(250, 70, 745, 515);
const IntRect SUN_RECT(0, 0, 350, 325);
const IntRect ZOMBIE_RECT(5, 5, 23, 36);
const IntRect MELONPULT_RECT(0, 0, 135, 120);

enum State {
  BATTLE,
  STARTING,
  VICTORY,
  GAMEOVER,
  EXIT
};


#endif
