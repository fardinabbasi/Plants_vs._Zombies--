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
#define MIN_X 0
#define MIN_Y 0
//#define NUM_COLS 9
#define NUM_ROWS 5

const unsigned int NUM_COLS = 9;
const string IMAGES_PATH = "./assets/images/";
const string MUSIC_PATH = "./assets/musics/";
const string FONTS_PATH = "./assets/fonts/";
const vector<unsigned int> WIDTH_GRIDS = {
  295, 370, 453, 530, 620, 700, 780, 855, 940
};
const vector<unsigned int> HEIGHT_GRIDS ={
  125, 230, 320, 420, 520
};

#endif
