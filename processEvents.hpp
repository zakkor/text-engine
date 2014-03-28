#ifndef PROCESSEVENTS_HPP_INCLUDED
#define PROCESSEVENTS_HPP_INCLUDED

sf::SoundBuffer buffer; //this might be bad
sf::Sound soundObj;

void Game::processEvents(std::string lineText)
{
    //Parse the line until we find a space

    //Position of the first space +1 (so it doesnt print the space)


    std::string action;

    //Get command in string format
    for (int i = 0; i < (int)lineText.find_first_of(" "); i++)
    {
        action.push_back(lineText[i]);
    }

    //Check which command it is

    //Print

    if (action == "print")
    {
        // Argument list vector that will get tied to the tuple later
        std::vector<int> argList;
        //storeArguments.resize(4);

        std::string argumentFinder;

        // set auxLen as position of last bracket - first bracket (and - 1, to get the length right)
        unsigned int auxLen = lineText.find_last_of(")") - lineText.find_first_of("(") - 1;

        // declare an auxiliary c string in which we will hold the text between the brackets
        char auxText[100];
        // copy the text starting at the position of the first bracket, with length auxLen
        lineText.copy(auxText, auxLen, lineText.find_first_of("(") + 1);

        // declare a c++ string in which we copy auxText[]
        std::string argText(auxText);

        if (argText.find("center") != std::string::npos)
        {
            argList.push_back(1); /// <- 1 = center.
        }
        if (argText.find("bold") != std::string::npos)
        {
            argList.push_back(2); /// <- 2 = bold.
        }
        if (argText.find("duration") != std::string::npos)
        {
            argList.push_back(3); /// <- 3 = duration.
            //declare and find the length of what's inside duration's brackets
            unsigned int durAuxLen;
            durAuxLen = argText.find_first_of(")", argText.find("duration")) -
            argText.find_first_of("(", argText.find("duration")) - 1;

            unsigned int duration;
            char durAux[100];

            argText.copy(durAux, durAuxLen, argText.find_first_of("(", argText.find("duration")) + 1);
            // DONT mess with these values, if you remove +-1, it wont work.
            duration = atoi(durAux);

            //push back duration.
            argList.push_back(duration);
        }
        if (argText.find("position") != std::string::npos)
        {
            argList.push_back(4); /// <- 4 = position.

            unsigned int print_height, print_width;

            unsigned int posAuxLen = argText.find_first_of(")", argText.find("position")) -
            argText.find_first_of("(", argText.find("position")) - 1;

            char posAux[100];

            argText.copy(posAux, posAuxLen, argText.find_first_of("(", argText.find("position")) + 1);

            std::string auxH, auxW;
            bool spaceFound = false;
            for (int findPos = 0; findPos <= strlen(posAux); findPos++)
            {
                if (posAux[findPos] == ' ')
                {
                    spaceFound = true;
                }
                else if (spaceFound)
                {
                    auxH = auxH + posAux[findPos];
                }
                else
                {
                    auxW = auxW + posAux[findPos];
                }
            }
            print_height = atoi(auxH.c_str());
            print_width = atoi(auxW.c_str());

            argList.push_back(print_width);
            argList.push_back(print_height);
        }

        std::string toPrint;

        //If arguments are found, copy the letters starting at the end of the parenthesis
        //or else if no arguments are found, copy the letters starting at the first space.
        for (unsigned int i = (!argList.empty() ? (int)lineText.find_last_of(")") + 2 :
                               (int)lineText.find_first_of(" ") + 1); i < lineText.length(); i++)
        {
            toPrint.push_back(lineText[i]);
        }


        // Create tuple with syntax: toPrint, argList.

        std::tuple<std::string, std::vector<int>> tuplePar (toPrint, argList);

        // Call print with tuplePar as a parameter.

        print(tuplePar);
    }

    //Pause

    if (action == "wait")
    {
        int waitTime = 0;
        std::string aux;
        for (unsigned int i = (int)lineText.find_first_of(" "); i < lineText.length(); i++)
        {
            aux = lineText[i];
            waitTime = waitTime * 10;
            waitTime += atoi(aux.c_str());
        }
        wait(waitTime);
    }

    //Play

    if (action == "sound")
    {
        char soundName[100];
        lineText.copy(soundName, lineText.size() - 6, 6);
        sound(soundName);
    }

    //Show

    if (action == "image")
    {
        //char imageName[100];
        //lineText.copy(imageName, lineText.size() - 6, 6);
        // Argument list vector that will get tied to the tuple later
        std::vector<int> argList;
        //storeArguments.resize(4);

        std::string argumentFinder;

        // set auxLen as position of last bracket - first bracket (and - 1, to get the length right)
        unsigned int auxLen = lineText.find_last_of(")") - lineText.find_first_of("(") - 1;

        // declare an auxiliary c string in which we will hold the text between the brackets
        char auxText[100];
        // copy the text starting at the position of the first bracket, with length auxLen
        lineText.copy(auxText, auxLen, lineText.find_first_of("(") + 1);

        // declare a c++ string in which we copy auxText[]
        std::string argText(auxText);
        if (argText.find("duration") != std::string::npos)
        {
            argList.push_back(1); /// <- 1 = duration.
            //declare and find the length of what's inside duration's brackets
            unsigned int durAuxLen;
            durAuxLen = argText.find_first_of(")", argText.find("duration")) -
            argText.find_first_of("(", argText.find("duration")) - 1;

            unsigned int duration;
            char durAux[100];

            argText.copy(durAux, durAuxLen, argText.find_first_of("(", argText.find("duration")) + 1);
            // DONT mess with these values, if you remove +-1, it wont work.
            duration = atoi(durAux);

            //push back duration.
            argList.push_back(duration);
        }

        std::string imageName;
        for (unsigned int i = (!argList.empty() ? (int)lineText.find_last_of(")") + 2 :
                               (int)lineText.find_first_of(" ") + 1); i < lineText.length(); i++)
        {
            imageName.push_back(lineText[i]);
        }

        std::tuple<std::string, std::vector<int>> tuplePar (imageName, argList);
        image(tuplePar);
    }

    //Set font

    if (action == "setfont")
    {
        char fontName[100];
        lineText.copy(fontName, lineText.size() - 8, 8);
        setfont(fontName);
    }

}

#endif // PROCESSEVENTS_HPP_INCLUDED
