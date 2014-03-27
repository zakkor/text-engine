#ifndef SOUND_HPP_INCLUDED
#define SOUND_HPP_INCLUDED

void Game::sound(std::string soundName)
{
    std::cout << "Loading sound...\n";
    if (!buffer.loadFromFile("Media/" + soundName));

    else
    {
        soundObj.setBuffer(buffer);
        soundQ.push(soundObj);
        sClock.restart();
        std::cout << "Playing \"" << soundName << "\"\n";
    }
}


#endif // SOUND_HPP_INCLUDED
