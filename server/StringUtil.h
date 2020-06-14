//
// Created by Javid Asgarov on 08.06.20.
//

#ifndef GRIDSERVER_STRINGUTIL_H
#define GRIDSERVER_STRINGUTIL_H


#include <string>
#include <vector>

class StringUtil {
    /**
     * Adds a line of symbols (necessary for drawing top and bottom borders)
     * @param message
     * @param numberOfTimes
     * @param symbol
     */
    static void addALineOfSymbols(std::vector<std::string> &message, int numberOfTimes, const std::string &symbol);

public:
    /**
     * Flattens the Vector of Vectors of Strings in one string message (used to send message from server to grid display service)
     * @param vector
     * @return
     */
    static std::string flatMapVectorOfVectorsIntoMessage(std::vector<std::vector<std::string>> vector);

    /**
     * Checks if provided letter with which client wants to register a single capital letter
     * @param input
     * @return
     */
    static bool isSingleCapitalLetter(const std::string& input);
};


#endif //GRIDSERVER_STRINGUTIL_H
