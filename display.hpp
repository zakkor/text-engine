#ifndef DISPLAY_HPP_INCLUDED
#define DISPLAY_HPP_INCLUDED

void Game::display()
{
    mWindow.clear();
    if (busyQ.empty())
    {
        processEvents(parseScript());
    }
    if (!rendQ.empty())
    {
        if (!busyQ.empty())
        {
            mWindow.draw(rendQ.front());
        }
        std::cout << busyQ.front() << " " << elapsedTime.asSeconds() << "\n";
        if (elapsedTime.asMilliseconds() >= busyQ.front())
        {
            busyQ.pop();
            rendQ.pop();
        }
    }
    mWindow.display();
}


#endif // DISPLAY_HPP_INCLUDED
