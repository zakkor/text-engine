#ifndef IMAGE_HPP_INCLUDED
#define IMAGE_HPP_INCLUDED

void Game::image(std::tuple<std::string, std::vector<int>> tuplePar)
{
    if (!texture.loadFromFile("Media/" + std::get<0> (tuplePar)));
    else
    {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        unsigned int duration;
        for (unsigned int i = 0; i < std::get<1> (tuplePar).size(); i++)
        {
            switch (std::get<1> (tuplePar)[i])
            {
            case 1:
            {
                //duration
                duration = std::get<1> (tuplePar)[i + 1];
                i++;
                break;
            }
            case 2:
            {
                //center
                sprite.setPosition(WIDTH /2, HEIGHT/2);
                sf::FloatRect textRect = sprite.getLocalBounds();
                sprite.setOrigin(textRect.left + textRect.width/2.0f,
                               textRect.top  + textRect.height/2.0f);
                break;
            }
            }
        }
        imageQ.push(sprite);
        i_busyQ.push(duration);
        iClock.restart();
        std::cout << "Loading \"" << std::get<0> (tuplePar) << "\"...";

    }

}

#endif // IMAGE_HPP_INCLUDED
