#include "Game.hpp"
#define WIDTH 1280
#define HEIGHT 720

/// //////////////////////////////////////////////////////////////////////
sf::RenderWindow mWindow(sf::VideoMode(WIDTH, HEIGHT), "Text Engine");
sf::Font font;
sf::Texture texture;
sf::SoundBuffer buffer; //this might be bad
sf::Sound soundObj;
sf::Clock mClock, sClock, iClock; // starts the clock
//sf::Time elapsedTime;
//Render queue
std::queue<sf::Text> rendQ;
//Duration queue
std::queue<int> busyQ, s_busyQ, i_busyQ;
//Sound queue
std::queue<sf::Sound> soundQ;
//Image queue
std::queue<sf::Sprite> imageQ;
//Var queue, no pop tho
std::vector<std::tuple<std::string, int>> varArray;
/// ///////////////////////////////////////////////////////////////////////


#include "loadScript.hpp"

#include "parseScript.hpp"

#include "processEvents.hpp"

#include "checkCommands.hpp"

#include "display.hpp"

#include "run.hpp"

///Functions:
#include "Functions/print.hpp"

#include "Functions/wait.hpp"

#include "Functions/sound.hpp"

#include "Functions/image.hpp"

#include "Functions/setfont.hpp"
