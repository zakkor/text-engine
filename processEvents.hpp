#ifndef PROCESSEVENTS_HPP_INCLUDED
#define PROCESSEVENTS_HPP_INCLUDED

void Game::processEvents(std::string lineText)
{
    int sepNumb = 0;
    for (std::string lineTextAux = lineText; lineTextAux.find("|") != std::string::npos;)
    {
        lineTextAux = lineTextAux.substr(lineTextAux.find_first_of("|") + 1, lineTextAux.length() - lineTextAux.find_first_of("|"));
        sepNumb++;
    }

    //Check which command it is
    do
    {
        std::string action;
        std::string lineTextPush;

        //
        action = lineText.substr(0, lineText.find_first_of(" "));
        //

        //Get command in string format
        if (sepNumb > 0)
        {
            lineTextPush = lineText.substr(0, lineText.find_first_of("|") - 1);


            lineText = lineText.substr(lineText.find_first_of("|") + 2, lineText.length() - lineText.find_first_of("|") - 1);
        }
        else
        {
            lineTextPush = lineText;
        }

        /// <-----COMMANDS----> ///
        checkCommands(lineTextPush);

        /// <----VARIABLES, IF, LOOPS-----> ///

        if (action == "int")
        {
            //Copies the name of the variable into varName
            std::string varName =
                lineText.substr(lineText.find_first_of(" ") + 1, lineText.find_first_of("=") - lineText.find_first_of(" ") - 2);

            //Copies the value of the variable into varNumber
            std::string varNumber =
                lineText.substr(lineText.find_first_of("=") + 2, lineText.size() - lineText.find_first_of("="));

            std::tuple<std::string, int> tupleVar (varName, atoi(varNumber.c_str()));

            varArray.push_back(tupleVar);
        }

        if (action == "if")
        {
            //same as up
            std::string varName =
                lineText.substr(lineText.find_first_of(" ") + 1, lineText.find_first_of("=") - lineText.find_first_of(" ") - 2);

            std::string varNumber =
                lineText.substr(lineText.find_first_of("=") + 2, lineText.find_first_of("-") - lineText.find_first_of("=") - 3);

            for (int i = 0; i < varArray.size(); i++)
            {
                if (varName == std::get<0> (varArray.at(i)))
                {
                    if (atoi(varNumber.c_str()) == std::get<1> (varArray.at(i)))
                    {
                        std::string lineCond =
                            lineText.substr(lineText.find_last_of(">") + 2, lineText.size() - lineText.find_last_of(">"));

                        checkCommands(lineCond);
                    }
                }
            }
        }
        sepNumb--;
    }
    while (sepNumb >= 0);
}

#endif // PROCESSEVENTS_HPP_INCLUDED
