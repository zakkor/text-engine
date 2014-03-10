#ifndef PLAY_HPP_INCLUDED
#define PLAY_HPP_INCLUDED

void Game::play(std::string soundName)
{
    std::cout << "Loading sound...\n";
    if (!buffer.loadFromFile("Media/" + soundName));

    else
    {
        sound.setBuffer(buffer);
        sound.play();
        std::cout << "Playing \"" << soundName << "\"\n";
    }
}

#endif // PLAY_HPP_INCLUDED
