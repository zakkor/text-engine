#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>
#include <string>
#include <cstdarg>
#include <tuple>
#include <algorithm>
#include <queue>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

struct Script
{
    std::string action;
};

class Game
{

public:

    void run();

private:

    void processEvents(std::string lineText);

    void display();

    bool loadScript();

    std::string parseScript();

    /// Functions

    void print(std::tuple<std::string, std::vector<int>> tuplePar);

    void wait(int msTime);

    void play(std::string soundName);

    void show(std::string imageName);

    void setfont(std::string fontName);


    /// Variables/Objects
    unsigned int scriptSize, scrpos;

    std::vector<Script> Scr;
};
#endif // GAME_HPP_INCLUDED
