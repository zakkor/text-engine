#ifndef DISPLAY_HPP_INCLUDED
#define DISPLAY_HPP_INCLUDED

void Game::display()
{
    mWindow.clear();
    ///
    if (busyQ.empty() && i_busyQ.empty())
    {
        processEvents(parseScript());
    }

    ///
    if (!rendQ.empty())
    {
        if (!busyQ.empty())
        {
            mWindow.draw(rendQ.front());
        }
        sf::Time elapsedTime = mClock.getElapsedTime();
        //std::cout << elapsedTime.asSeconds() << "\n";
        if (elapsedTime.asMilliseconds() >= busyQ.front())
        {
            if (paused == false)
            {
                busyQ.pop();
                rendQ.pop();
                std::cout << "done.\n";
            }
        }
    }

    if (!soundQ.empty())
    {
        if (s_busyQ.empty())
        {
            soundQ.front().play();
            s_busyQ.push(buffer.getDuration().asMilliseconds());
        }
        sf::Time elapsedTime = sClock.getElapsedTime();
        //std::cout << elapsedTime.asSeconds() << "\n";
        if (elapsedTime.asSeconds() >= s_busyQ.front() && soundQ.front().getStatus() == sf::SoundSource::Status::Stopped)
        {
            s_busyQ.pop();
            soundQ.pop();
        }
    }
    if (!imageQ.empty())
    {
        if (!i_busyQ.empty())
        {
            mWindow.draw(imageQ.front());
        }
        sf::Time elapsedTime = iClock.getElapsedTime();
        if (elapsedTime.asMilliseconds() >= i_busyQ.front())
        {
            if (paused == false)
            {
                i_busyQ.pop();
                imageQ.pop();
                std::cout << "done.\n";
            }
        }
    }

    mWindow.display();
}


#endif // DISPLAY_HPP_INCLUDED
