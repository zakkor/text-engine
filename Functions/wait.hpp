#ifndef WAIT_HPP_INCLUDED
#define WAIT_HPP_INCLUDED

void Game::wait(int msTime)
{
    sf::Time t = sf::milliseconds(msTime);

    sf::sleep(t);

}

#endif // WAIT_HPP_INCLUDED
