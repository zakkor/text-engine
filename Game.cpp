#include "Game.hpp"
#define WIDTH 1440
#define HEIGHT 900

/// //////////////////////////////////////////////////////////////////////
sf::RenderWindow mWindow(sf::VideoMode(WIDTH, HEIGHT), "Text Engine");
sf::Font font;
sf::Clock mClock, sClock; // starts the clock
sf::Time elapsedTime;
//Render queue
std::queue<sf::Text> rendQ;
//Duration queue
std::queue<int> busyQ, s_busyQ;
//Sound queue
std::queue<sf::Sound> soundQ;
/// ///////////////////////////////////////////////////////////////////////


#include "loadScript.hpp"

#include "parseScript.hpp"

#include "processEvents.hpp"

#include "display.hpp"

#include "run.hpp"

///Functions:
#include "Functions/print.hpp"

#include "Functions/wait.hpp"

#include "Functions/sound.hpp"

#include "Functions/image.hpp"

#include "Functions/setfont.hpp"
