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
#define FRAME_RATE 60
#define GARGANTUAR_RATIO 0.25
#define COOL_TIME 5

const string IMAGES_PATH = "./assets/images/";
const string MUSIC_PATH = "./assets/musics/";
const string FONTS_PATH = "./assets/fonts/";

const vector<unsigned int> WIDTH_GRIDS = {
  295, 370, 453, 530, 620, 700, 780, 855, 940
};
const vector<unsigned int> HEIGHT_GRIDS ={
  125, 230, 320, 420, 520
};

const IntRect peaRect(0, 150, 95, 96);
const IntRect snowyRect(0, 130, 120, 115);
const IntRect sunflowerRect(0, 170, 130, 130);
const IntRect peanutRect(0, 0, 101, 115);

enum State {
  BATTLE,
  STARTING,
  VICTORY,
  GAMEOVER,
  EXIT
};


#endif
