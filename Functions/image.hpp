#ifndef IMAGE_HPP_INCLUDED
#define IMAGE_HPP_INCLUDED

void Game::image(std::string imageName)
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

#endif // IMAGE_HPP_INCLUDED
