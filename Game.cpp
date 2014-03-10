#include "Game.hpp"
#define WIDTH 1440
#define HEIGHT 900

sf::RenderWindow mWindow(sf::VideoMode(WIDTH, HEIGHT), "Text Engine");
sf::Clock mClock; // starts the clock
sf::Time elapsedTime;

#include "loadScript.hpp"

#include "parseScript.hpp"

#include "processEvents.hpp"

#include "display.hpp"

#include "run.hpp"

///Functions:
#include "Functions/print.hpp"

#include "Functions/wait.hpp"

#include "Functions/play.hpp"

#include "Functions/show.hpp"
