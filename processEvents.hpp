#ifndef PROCESSEVENTS_HPP_INCLUDED
#define PROCESSEVENTS_HPP_INCLUDED

sf::SoundBuffer buffer; //this might be bad
sf::Sound sound;

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
        int argNumber = 0;

        // Checks if there are any arguments that have been found
        bool noArguments = true;

        //checks if arguments are present, if not just skip
        if (lineText.find_first_of("(") != std::string::npos)
        {
            for (int i = (int)lineText.find_first_of("(") + 1; lineText[i - 1] != ')';)
            {
                //Starts at the letter after open bracket '('
                if (argumentFinder == "bold")
                {
                    noArguments = false;
                    argNumber++;
                    //reset argument finder to make way for next argument
                    argList.push_back(2); // 2 = bold

                    //set i as the first space encountered

                    /// if (storeArguments[0] == 0) /// needs revamp to work for multiple arguments
                    {
                        int pos = (int)lineText.find_first_of("(");
                        if ((int)lineText.find_first_of(")") > (int)lineText.find_first_of(" ", pos))
                        {
                            i = (int)lineText.find_first_of(" ", pos) + 1;
                        }
                    }

                    argumentFinder = "";
                }
                if (argumentFinder == "center")
                {
                    noArguments = false;
                    argNumber++;
                    argList.push_back(1); // 1 = center

                    //If the other arguments haven't been found
                    //set i to the first space after the first '(' found

                    /// if (storeArguments[1] == 0) /// needs revamp
                    {
                        int pos = (int)lineText.find_first_of("(");
                        if ((int)lineText.find_first_of(")") > (int)lineText.find_first_of(" ", pos))
                        {
                            i = (int)lineText.find_first_of(" ", pos) + 1;
                        }
                    }
                    argumentFinder = "";
                }
                if (argumentFinder == "duration")
                {
                    noArguments = false;
                    argNumber++;
                    argList.push_back(3); // duration exists

                    int pos = (int)lineText.find_first_of("(") + 1;
                    int secpos = (int)lineText.find_first_of("(", pos); //finds the second open brace

                    //checks if the last 3 letters before the second open brace match what we need (duration)
                    if (lineText[secpos - 1] == 'n' && lineText[secpos - 2] == 'o' && lineText[secpos - 3] == 'i')
                    {
                        unsigned int duration = 0;
                        //set duration as what's inside the second paranthesis (only ints)
                        //note: incorrect input will not break it, it simply will not read.
                        duration = atoi(&lineText[secpos + 1]);
                    }

                    //If the other arguments haven't been found
                    //set i to the first space after the first '(' found
                    /// if (storeArguments[1] == 0) /// needs revamp
                    {
                        int pos = (int)lineText.find_first_of("(");

                        if ((int)lineText.find_first_of(")") > (int)lineText.find_first_of(" ", pos))
                        {
                            i = (int)lineText.find_first_of(" ", pos) + 1;
                        }
                    }
                    argumentFinder = "";

                }
                else
                {
                    argumentFinder.push_back(lineText[i]);
                    i++; //manually increment to prevent loss of letters
                    //when a match is found
                }
            }
        }


        std::string toPrint;





        //If arguments are found, copy the letters starting at the end of the parenthesis
        //or else if no arguments are found, copy the letters starting at the first space.
        for (unsigned int i = (noArguments == false ? (int)lineText.find_last_of(")") + 1 :
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

    if (action == "play")
    {
        std::string soundName = "";
        for (int i = (int) lineText.find_first_of(" ") + 1; i < lineText.length(); i++)
        {
            soundName.push_back(lineText[i]);
        }
        play(soundName);
    }

    //Show

    if (action == "show")
    {
        std::string imageName = "";
        for (int i = (int) lineText.find_first_of(" ") + 1; i < lineText.length(); i++)
        {
            imageName.push_back(lineText[i]);
        }
        show(imageName);
    }

}

#endif // PROCESSEVENTS_HPP_INCLUDED
