#ifndef IMAGE_HPP_INCLUDED
#define IMAGE_HPP_INCLUDED

void Game::image(std::tuple<std::string, std::vector<int>> tuplePar)
{
    if (!texture.loadFromFile("Media/" + std::get<0> (tuplePar)));
    else
    {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        unsigned int duration = 0;
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
                sf::FloatRect imgRect = sprite.getLocalBounds();
                sprite.setOrigin(imgRect.left + imgRect.width/2.0f,
                               imgRect.top  + imgRect.height/2.0f);
                break;
            }
            case 3:
            {
                //fit
                sf::FloatRect imgRect = sprite.getLocalBounds();
                float scaleFactorX = WIDTH / imgRect.width;
                float scaleFactorY = HEIGHT / imgRect.height;
                sprite.setScale(scaleFactorX, scaleFactorY);
            }
            }
        }

        if (duration == 0)
        {
            paused = true;
        }

        imageQ.push(sprite);
        i_busyQ.push(duration);
        iClock.restart();
        std::cout << "Loading \"" << std::get<0> (tuplePar) << "\"...";

    }

}

#endif // IMAGE_HPP_INCLUDED
