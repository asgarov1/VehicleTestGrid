//
// Created by Javid Asgarov on 08.06.20.
//

#ifndef GRIDSERVER_STRINGUTIL_H
#define GRIDSERVER_STRINGUTIL_H


#include <string>
#include <vector>

class StringUtil {
    static void addALineOfSymbols(std::vector<std::string> &message, int numberOfTimes, const std::string &symbol);

public:
    static std::string flatMapVectorOfVectorsIntoMessage(std::vector<std::vector<std::string>> vector);
    static bool isSingleCapitalLetter(const std::string& input);


};


#endif //GRIDSERVER_STRINGUTIL_H
