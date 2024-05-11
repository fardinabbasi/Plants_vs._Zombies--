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
#define NUM_COLS 9
#define NUM_ROWS 5

const string IMAGES_PATH = "./assets/images/";
const string MUSIC_PATH = "./assets/musics/";
const string FONTS_PATH = "./assets/fonts/";
const Vector2f GRID_TOP_LEFT = {256.0f, 80.0f};     
const Vector2f GRID_BOTTOM_RIGHT = {1000.0f, 575.0f};

#endif
