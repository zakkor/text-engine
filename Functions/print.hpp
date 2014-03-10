#ifndef PRINT_HPP_INCLUDED
#define PRINT_HPP_INCLUDED

void Game::print(std::string toPrint, bool noArguments, int argNumber, ...)
{
    va_list args;
    va_start(args, toPrint);
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
    text.setString(toPrint);

    // set the character size
    text.setCharacterSize(55); // in pixels, not points!

    // set the color
    text.setColor(sf::Color::White);


    std::vector<int> arguments(argNumber);
    for (int i = 0; i < argNumber; i++)
    {
        arguments[i] = va_arg(args, int);
    }
    for (int i = 0; i < argNumber; i++)
    {
        std::cout << arguments[i] << " ";
    }
    /*
    1 = center
    2 = bold
    3 = duration
    */
    if (!noArguments)
    {
        for (int i = 0; i < argNumber; i++)
        {
            switch (arguments[i])
            {
            case 1:
            {
                //set position to center
                text.setPosition(WIDTH /2, HEIGHT/2);
                sf::FloatRect textRect = text.getLocalBounds();
                text.setOrigin(textRect.left + textRect.width/2.0f,
                               textRect.top  + textRect.height/2.0f);
                std::cout << "center \n";
                break;
            }
            case 2:
            {
                // set the text style
                text.setStyle(sf::Text::Bold);
                std::cout << "bold \n";
                break;
            }
            case 3:
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
