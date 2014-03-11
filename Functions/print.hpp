#ifndef PRINT_HPP_INCLUDED
#define PRINT_HPP_INCLUDED

void Game::print(std::tuple<std::string, std::vector<int>> tuplePar)
{
    //va_list args;
    //va_start(args, toPrint);
    unsigned int displayDuration = 0;

    sf::Font font;
    if (!font.loadFromFile("Media/arial.ttf"))
    {
        std::cout << "No font found!\n";
    }
    sf::Text text;

    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString(std::get<0> (tuplePar)); //(toPrint) string

    // set the character size
    text.setCharacterSize(55); // in pixels, not points!

    // set the color
    text.setColor(sf::Color::White);

    /*
    1 = center
    2 = bold
    3 = duration
    */
    if (!std::get<1> (tuplePar).empty())
    {
        for (int i = 0; i < std::get<1> (tuplePar).size(); i++)
        {
            switch (std::get<1> (tuplePar)[i])
            {
            case 0:
            {
                //set position to center
                text.setPosition(WIDTH /2, HEIGHT/2);
                sf::FloatRect textRect = text.getLocalBounds();
                text.setOrigin(textRect.left + textRect.width/2.0f,
                               textRect.top  + textRect.height/2.0f);
                std::cout << "center \n";
                break;
            }
            case 1:
            {
                // set the text style
                text.setStyle(sf::Text::Bold);
                std::cout << "bold \n";
                break;
            }
            case 2:
            {
                //sets displayDuration's value to the argument recieved
                //displayDuration =
                std::cout << "at least it WORKED\n";
            }
            }
        }
    }

    ///mClock.restart();

    // inside the main loop, between window.clear() and window.display()
    ///while (elapsedTime.asSeconds() <= 5)
    {
        ///elapsedTime = mClock.getElapsedTime();
        mWindow.draw(text);
    }

}


#endif // PRINT_HPP_INCLUDED
