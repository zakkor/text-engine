#ifndef PARSESCRIPT_HPP_INCLUDED
#define PARSESCRIPT_HPP_INCLUDED

std::string Game::parseScript()
{
    if (scrpos < scriptSize)
    {
        unsigned int aux = scrpos; //remember scrpos so we can increment it
        scrpos++;
        //std::cout << Scr[aux].action << std::endl;
        return Scr[aux].action;
    }
    return "";
}


#endif // PARSESCRIPT_HPP_INCLUDED
