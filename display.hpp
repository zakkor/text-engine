#ifndef DISPLAY_HPP_INCLUDED
#define DISPLAY_HPP_INCLUDED

void Game::display()
{
    mWindow.clear();

    ///
    if (busyQ.empty() && s_busyQ.empty())
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
        elapsedTime = mClock.getElapsedTime();
        std::cout << elapsedTime.asSeconds() << "\n";
        if (elapsedTime.asSeconds() >= busyQ.front())
        {
            busyQ.pop();
            rendQ.pop();
        }
    }

    if (!soundQ.empty())
    {
        if (!s_busyQ.empty() && soundQ.front().getStatus() == sf::SoundSource::Status::Stopped)
        {
            soundQ.front().play();
        }
        elapsedTime = sClock.getElapsedTime();
        if (elapsedTime.asSeconds() >= s_busyQ.front())
        {
            s_busyQ.pop();
            soundQ.pop();
        }
    }

    mWindow.display();
}


#endif // DISPLAY_HPP_INCLUDED
