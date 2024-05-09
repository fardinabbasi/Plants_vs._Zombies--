#include <map>
#include <string>
#include <iostream>
#include "Defs.hpp"
#include "utils.hpp"
#include "PVZ.hpp"

int main(int argc, char* argv[]){
    const string config_file_path = argv[CONFIG_FILE_INDEX];
    map<string, map<string, int>> config = read_config(config_file_path);
    PVZ game = PVZ(config);
    game.run();
    return 0;
}