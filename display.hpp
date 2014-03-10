#ifndef DISPLAY_HPP_INCLUDED
#define DISPLAY_HPP_INCLUDED

void Game::display()
{
    mWindow.clear();

    processEvents(parseScript());

    mWindow.display();
}


#endif // DISPLAY_HPP_INCLUDED
