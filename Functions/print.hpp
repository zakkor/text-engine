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
    **/

    unsigned int duration = 0;

    if (!std::get<1> (tuplePar).empty())
    {
        for (unsigned int i = 0; i < std::get<1> (tuplePar).size(); i++)
        {
            switch (std::get<1> (tuplePar)[i])
            {
            case 1:
            {
                //set font size
                text.setCharacterSize(std::get<1> (tuplePar)[i+1]);
                i++;
                break;
            }

            case 2:
            {
                // set the text style
                text.setStyle(sf::Text::Bold);
                break;
            }

            case 3:
            {
                //duration is immediately ahead of the position of duration's argument
                duration = std::get<1> (tuplePar)[i + 1];
                i++;
                break;
            }

            case 4:
            {
                //set position as i+1 and i+2
                text.setPosition(std::get<1> (tuplePar)[i + 1], std::get<1> (tuplePar)[i + 2]);
                i+=2;
                break;

            }

            case 5:
            {
                //set position to center
                text.setPosition(WIDTH /2, HEIGHT/2);
                sf::FloatRect textRect = text.getLocalBounds();
                text.setOrigin(textRect.left + textRect.width/2.0f,
                               textRect.top  + textRect.height/2.0f);
                break;
            }

            case 6:
            {
                switch (std::get<1> (tuplePar)[i+1])
                {
                case 1:
                {
                    text.setColor(sf::Color::Red);
                    break;
                }
                case 2:
                {
                    text.setColor(sf::Color::Green);
                    break;
                }
                case 3:
                {
                    text.setColor(sf::Color::Blue);
                    break;
                }
                }
                i++;
                break;
            }
            case 7:
            {
                text.setStyle(sf::Text::Italic);
            }
            case 8:
            {
                ///fade
                if (std::get<1> (tuplePar)[i + 1] == 1) //if the type of transition is 'fade'
                {
                    /** @args
                     * 0 -> fade
                     * 1 -> dir
                     * 2 -> dur
                     * 3 -> alpha
                     */
                    std::vector<int> transAuxStore;
                    transAuxStore.push_back(1); /// 1-> fade/move
                    ///in
                    if (std::get<1> (tuplePar)[i + 2] == 1)
                    {
                        transAuxStore.push_back(1); /// 1-> in
                        transAuxStore.push_back(std::get<1> (tuplePar)[i + 3]); //
                        transAuxStore.push_back(0); /// alpha

                    }
                    ///out
                    if (std::get<1> (tuplePar)[i + 2] == 2)
                    {
                        transAuxStore.push_back(2); /// 2-> out
                        transAuxStore.push_back(std::get<1> (tuplePar)[i + 3]); //
                        transAuxStore.push_back(255); ///alpha
                    }

                    transQ.push_back(transAuxStore);
                }
                i+=3;
                sf::Clock newTransClock;
                tClock.push_back(newTransClock);
                break;
            }
            }
        }
    }
    //Add text to render queue
    rendQ.push_back(text);
    //Push duration to busyQ.
    if (duration == 0)
    {
        paused = true;
    }
    busyQ.push(duration);
    //Restart clock.
    mClock.restart(); std::cout << "Printing \"" << std::get<0> (tuplePar) << "\"... ";
}


#endif // PRINT_HPP_INCLUDED
