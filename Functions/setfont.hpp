#ifndef SETFONT_HPP_INCLUDED
#define SETFONT_HPP_INCLUDED

void Game::setfont(std::string fontName)
{
    std::string finalFontName = "Media/" + fontName;
    if (!font.loadFromFile(finalFontName))
    {
        std::cout << "No font found!\n";
    }
}

#endif // SETFONT_HPP_INCLUDED
