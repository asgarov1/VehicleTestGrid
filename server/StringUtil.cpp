//
// Created by Javid Asgarov on 08.06.20.
//

#include <numeric>
#include "StringUtil.h"

#define ROUTE "#"

void StringUtil::addALineOfSymbols(std::vector<std::string> &message, int numberOfTimes, const std::string &symbol) {
    for (int j = 0; j < numberOfTimes; ++j) {
        message.emplace_back(symbol);
    }
    message.emplace_back("\n");
}

std::string StringUtil::flatMapVectorOfVectorsIntoMessage(std::vector<std::vector<std::string>> vector) {
    int x = vector.at(0).size();
    std::vector<std::string> message;
    addALineOfSymbols(message, x + 2, ROUTE);

    for (const std::vector<std::string> &line : vector) {
        message.emplace_back(ROUTE);
        for (const std::string &s : line) {
            message.emplace_back(s);
        }
        message.emplace_back(ROUTE);
        message.emplace_back("\n");
    }
    addALineOfSymbols(message, x + 2, ROUTE);

    return std::accumulate(message.begin(), message.end(), std::string{});
}

bool StringUtil::isSingleCapitalLetter(const std::string& input) {
    return input.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos && input.length() == 1;
}
