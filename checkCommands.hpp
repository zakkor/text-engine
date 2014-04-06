#ifndef CHECKCOMMANDS_HPP_INCLUDED
#define CHECKCOMMANDS_HPP_INCLUDED

void Game::checkCommands(std::string lineText)
{
    //Parse the line until we find a space

    //Position of the first space +1 (so it doesnt print the space)


    std::string action;

    //Get command in string format
    for (int i = 0; i < (int)lineText.find_first_of(" "); i++)
    {
        action.push_back(lineText[i]);
    }

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
        // copy the text starting at the position of the first bracket, with length auxLen
        std::string auxText =
        lineText.substr(lineText.find_first_of("(") + 1, auxLen);

        // declare a c++ string in which we copy auxText[]
        std::string argText(auxText);

        if (argText.find("fontsize") != std::string::npos)
        {
            argList.push_back(1); /// <- 1 = fontsize.

            unsigned int fsAuxLen = argText.find_first_of(")", argText.find("fontsize")) -
                                    argText.find_first_of("(", argText.find("fontsize")) - 1;

            std::string fsAux =
            argText.substr(argText.find_first_of("(", argText.find("fontsize")) + 1, fsAuxLen);

            argList.push_back(atoi(fsAux.c_str()));
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
            std::string durAux =
            argText.substr(argText.find_first_of("(", argText.find("duration")) + 1, durAuxLen);
            // DONT mess with these values, if you remove +-1, it wont work.
            duration = atoi(durAux.c_str());

            //push back duration.
            argList.push_back(duration);
        }
        if (argText.find("position") != std::string::npos)
        {
            argList.push_back(4); /// <- 4 = position.

            unsigned int print_height, print_width;

            unsigned int posAuxLen = argText.find_first_of(")", argText.find("position")) -
                                     argText.find_first_of("(", argText.find("position")) - 1;

            std::string posAux =
            argText.substr(argText.find_first_of("(", argText.find("position")) + 1, posAuxLen);

            std::string auxH, auxW;
            bool spaceFound = false;
            for (int findPos = 0; findPos <= strlen(posAux.c_str()); findPos++)
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
        if (argText.find("center") != std::string::npos)
        {
            argList.push_back(5); /// <- 5 = center.
        }
        if (argText.find("colour") != std::string::npos)
        {
            argList.push_back(6); /// <- 6 = colour;

            unsigned int coAuxLen = argText.find_first_of(")", argText.find("colour")) -
                                    argText.find_first_of("(", argText.find("colour")) - 1;

            std::string coAux =
            argText.substr(argText.find_first_of("(", argText.find("colour")) + 1, coAuxLen);

            std::string str_coAux(coAux);

            if (str_coAux == "red")
            {
                argList.push_back(1);
                /// 1 = red
            }
            else if (str_coAux == "green")
            {
                argList.push_back(2);
                /// 2 = green
            }
            else if (str_coAux == "blue")
            {
                argList.push_back(3);
                /// 3 = blue;
            }
        }
        if (argText.find("italic") != std::string::npos)
        {
            argList.push_back(7);
        }
        if (argText.find("transition") != std::string::npos)
        {
            argList.push_back(8);

            //Extracts all 3 parts: type, direction, duration;
            unsigned int transAuxLen = argText.find_first_of(")", argText.find("transition")) -
                                     argText.find_first_of("(", argText.find("transition")) - 1;
            std::string transAux =
            argText.substr(argText.find_first_of("(", argText.find("transition")) + 1, transAuxLen);

            std::string transType =
            transAux.substr(0, transAux.find_first_of(" "));

            std::string transDir =
            transAux.substr(transAux.find_first_of(" ") + 1, transAux.find_last_of(" ") - transAux.find_first_of(" ") - 1);

            std::string transDur =
            transAux.substr(transAux.find_last_of(" ") + 1, transAux.length() - transAux.find_last_of(" ") - 1);

            //

            if (transType == "fade")
            {
                argList.push_back(1); /// fade = 1.
                if (transDir == "in")
                {
                    argList.push_back(1); /// in = 1.
                }
                if (transDir == "out")
                {
                    argList.push_back(2); /// out = 2;
                }
                argList.push_back(atoi(transDur.c_str()));
            }

            /*
            if (transType == "move")
            {
                argList.push_back(2) /// move = 2.
            }
            */
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
        std::string soundName =
        lineText.substr(lineText.find_first_of(" ") + 1, lineText.size() - lineText.find_first_of(" "));
        sound(soundName);
    }

    //Show

    if (action == "image")
    {
        // Argument list vector that will get tied to the tuple later
        std::vector<int> argList;
        //storeArguments.resize(4);

        std::string argumentFinder;

        // set auxLen as position of last bracket - first bracket (and - 1, to get the length right)
        unsigned int auxLen = lineText.find_last_of(")") - lineText.find_first_of("(") - 1;

        std::string auxText =
        // copy the text starting at the position of the first bracket, with length auxLen
        lineText.substr(lineText.find_first_of("(") + 1, auxLen);

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
            std::string durAux =
            argText.substr(argText.find_first_of("(", argText.find("duration")) + 1, durAuxLen);

            // DONT mess with these values, if you remove +-1, it wont work.
            duration = atoi(durAux.c_str());

            //push back duration.
            argList.push_back(duration);
        }
        if (argText.find("center") != std::string::npos)
        {
            argList.push_back(2); /// <- 2 = center.
        }
        if (argText.find("fit") != std::string::npos)
        {
            argList.push_back(3); /// <- 3 = fit to screen.
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
        std::string fontName =
        lineText.substr(lineText.find_first_of(" ") + 1, lineText.size() - lineText.find_first_of(" "));
        setfont(fontName);
    }

}

#endif // CHECKCOMMANDS_HPP_INCLUDED
