#ifndef PRINT_HPP_INCLUDED
#define PRINT_HPP_INCLUDED

void Game::print(std::tuple<std::string, std::vector<int>> tuplePar)
{
    sf::Text text;

    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString(std::get<0> (tuplePar)); //(toPrint) string

    // set the character size
    text.setCharacterSize(55); // in pixels, not points!

    // set the color
    text.setColor(sf::Color::White);

    /**
    * 1 = center
    * 2 = bold
    * 3 = duration
    */

    int duration = 0;

    if (!std::get<1> (tuplePar).empty())
    {
        for (unsigned int i = 0; i < std::get<1> (tuplePar).size(); i++)
        {
            switch (std::get<1> (tuplePar)[i])
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
                //duration is immediately ahead of the position of duration's argument
                duration = std::get<1> (tuplePar)[i + 1];
            }
            }
        }
    }
    //Add text to render queue
    rendQ.push(text);
    //Push duration to busyQ.
    busyQ.push(duration);
    //Restart clock.
    mClock.restart(); std::cout<< "Started timer!\n";
}


#endif // PRINT_HPP_INCLUDED
