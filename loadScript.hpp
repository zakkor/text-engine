#ifndef LOADSCRIPT_HPP_INCLUDED
#define LOADSCRIPT_HPP_INCLUDED

bool Game::loadScript()
{
    Script s;
    unsigned int nmbrLines = 0;
    std::ifstream scrStream("script.txt");
    while (std::getline(scrStream, s.action))
    {
        Scr.push_back(s);
        nmbrLines++;
    }
    scriptSize = nmbrLines;
    Scr.resize(scriptSize);

    if (Scr.empty())
    {
        std::cout << "Script empty! Either missing file or other issue!\n";
        return 0;
    }
    else
    {
        std::cout << "Script loaded successfully. (" << scriptSize << " lines)\n";
        return 1;
    }
}


#endif // LOADSCRIPT_HPP_INCLUDED
