//
// Created by extremer on 08.06.20.
//

#ifndef GRIDSERVER_RACEFIELD_H
#define GRIDSERVER_RACEFIELD_H


#include <vector>
#include <string>

class RaceField {

    std::vector<std::vector<std::string>> fields;
    std::string carNames[27];  //27 because sockets start from 1 and I keep track by using same index for car name as the socket number that it came from

    int dimensionX{};
    int dimensionY{};

    void initialiseRaceField(int argc, char *argv[]);
    void setCarName(int index, std::string name);

public:
    RaceField(int argc, char **argv);

    //Getters
    [[nodiscard]] const std::vector<std::vector<std::string>> &getFields() const;
    [[nodiscard]] const std::string *getCarNames() const;
    [[nodiscard]] std::string getCarName(int index) const;

    std::basic_string<char> placeCar(int index, const std::string& carName);

    bool letterIsTaken(const std::string& letter);

    bool moveCar(int carIndex, const std::string& string);

    void removeCarName(const std::string &carName);

    void removeCarName(int index);

    bool isFull();
};


#endif //GRIDSERVER_RACEFIELD_H
