#ifndef RUN_HPP_INCLUDED
#define RUN_HPP_INCLUDED

void Game::run()
{
    //This is the main game loop. It handles all the gameplay.
    //([receiving input, printing to screen] - according to a script, playing sounds,
    //printing to the screen unrelated events and visual effects, timers and time events)

    loadScript();

    //Declare scrpos to keep track of the parsing.
    scrpos = 0;

    while (mWindow.isOpen())
    {
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                mWindow.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (paused)
                {
                    if (event.key.code == sf::Keyboard::Space)
                    {
                        paused = false;
                        //std::cout << "a mers";
                    }

                }
            }
        }
        display();
    }
}


#endif // RUN_HPP_INCLUDED
