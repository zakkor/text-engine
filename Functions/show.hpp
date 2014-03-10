#ifndef SHOW_HPP_INCLUDED
#define SHOW_HPP_INCLUDED

void Game::show(std::string imageName)
{
        std::cout << "Loading image...\n";
    sf::Texture texture;
    if (!texture.loadFromFile("Media/" + imageName));
    else
    {
        sf::Sprite sprite;
        sprite.setTexture(texture);

        mWindow.draw(sprite);
    }

}

#endif // SHOW_HPP_INCLUDED
