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
            if (!transQ.empty())
            {
                for (int transObj = 0; transObj < transQ.size(); transObj++)
                {
                    sf::Color color(255, 255, 255, transQ[transObj][3]);

                    rendQ[transObj].setColor(color);

                    sf::Time elapsedTime = tClock[transObj].getElapsedTime();

                    if (elapsedTime.asMilliseconds() >= transQ[transObj][2])
                    {
                        if (transQ[transObj][1] == 1)
                        {
                            ///in
                            if (transQ[transObj][3] >= 255)
                            {

                            }
                            else
                            {
                                ///deincrement alpha
                                transQ[transObj][3]++;
                            }
                        }
                        else if (transQ[transObj][1] == 2)
                        {
                            ///out
                            /// check alpha
                            if (transQ[transObj][3] <= 0)
                            {

                            }
                            else
                            {
                                ///increment alpha
                                transQ[transObj][3]--;
                            }
                        }
                        tClock[transObj].restart();
                    }
                }
            }

            for (int drawObj = 0; drawObj < rendQ.size(); drawObj++)
            {
                mWindow.draw(rendQ[drawObj]);
            }
        }
        sf::Time elapsedTime = mClock.getElapsedTime();

        if (elapsedTime.asMilliseconds() >= busyQ.front())
        {
            if (paused == false)
            {
                busyQ.pop();
                rendQ.pop_back();
                if (!transQ.empty())
                {
                    transQ.pop_back();
                    tClock.pop_back();
                    std::cout << " cleaned transitions, ";
                }
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
