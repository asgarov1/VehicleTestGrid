//
// Created by Javid Asgarov on 08.06.20.
//

#include <getopt.h>

#include <utility>
#include <iostream>
#include "RaceField.h"

void RaceField::initialiseRaceField(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "x:y:")) != -1) {
        switch (opt) {
            case 'x': {
                dimensionX = std::stoi(optarg);
                break;
            }
            case 'y': {
                dimensionY = std::stoi(optarg);
                break;
            }
            case '?': {
                fprintf(stderr, "unknown option: %c\n", optopt);
                break;
            }
            case ':': {
                fprintf(stderr, "missing argument.\n");
                break;
            }
        }
    }

    fields.reserve(dimensionY);
    for (int i = 0; i < dimensionY; ++i) {
        std::vector<std::string> field;
        field.reserve(dimensionX);
        for (int j = 0; j < dimensionX; ++j) {
            field.emplace_back(" ");
        }
        fields.emplace_back(field);
    }
}

RaceField::RaceField(int argc, char **argv) {
    initialiseRaceField(argc, argv);
}

const std::vector<std::vector<std::string>> &RaceField::getFields() const {
    return fields;
}

const std::string *RaceField::getCarNames() const {
    return carNames;
}

std::string RaceField::getCarName(int index) const {
    return carNames[index];
}

void RaceField::setCarName(int index, std::string name) {
    carNames[index] = std::move(name);
}

std::basic_string<char> RaceField::placeCar(int index, const std::string &carName) {
    setCarName(index, carName);

    int randomY = rand() % dimensionY;
    int randomX = rand() % dimensionX;

    int count = 0; // the logic of the program currently doesnt allow more people than amount of letters in alphabet to connect
                    //but just in case (maybe program changes) to avoid infinite loops
    while (fields.at(randomY).at(randomX) != " " && count++ < 1000) {
        randomY = rand() % dimensionY;
        randomX = rand() % dimensionX;
    }

    fields.at(randomY).at(randomX) = carName;
    std::string position = std::to_string(randomX) + "," + std::to_string(randomY);
    return position;
}

bool RaceField::letterIsTaken(const std::string& letter) {
    for (int i = 0; i < std::size(carNames); ++i) {
        if (carNames[i].compare(letter) == 0) {
            return true;
        }
    }
    return false;
}

bool RaceField::moveCar(int carIndex, const std::string &receivedLetter) {
    int x = -1, y = -1;
    for (int i = 0; i < dimensionY; ++i) {
        for (int j = 0; j < dimensionX; ++j) {
            if (fields.at(i).at(j) == carNames[carIndex]) {
                x = j;
                y = i;
                fields.at(i).at(j) = " ";
                goto outOfLoop;
            }
        }
    }
    outOfLoop:

    if(x == -1){ //meaning there is no such car on the field
        return false;
    }

    int newX = x, newY = y;
    if (receivedLetter == "T") {
        removeCarName(carIndex);
        return false;
    } else if (receivedLetter == "N") {
        newY--;
    } else if (receivedLetter == "S") {
        newY++;
    } else if (receivedLetter == "W") {
        newX--;
    } else if (receivedLetter == "E") {
        newX++;
    }

    if(newX <= -1 || newX >= dimensionX || newY <= -1 || newY >= dimensionY){
        removeCarName(carIndex); //de-registering the client
        return false;
    }

    if(fields.at(newY).at(newX) != " "){ //meaning there is a car clash
        std::string letter = fields.at(newY).at(newX);
        fields.at(newY).at(newX) = " ";
        removeCarName(carNames[carIndex]);
        removeCarName(letter);
        return false;
    }

    fields.at(newY).at(newX) = carNames[carIndex];
    return true;
}

void RaceField::removeCarName(const std::string &carName) {
    for (int i = 0; i < std::size(carNames); ++i) {
        if(carNames[i].compare(carName) != 0){
            carNames[i] = " ";
            break;
        }
    }
}

void RaceField::removeCarName(int carIndex) {
    carNames[carIndex]=" ";
}

bool RaceField::isFull() {
    for (int i = 0; i < dimensionY; ++i) {
        for (int j = 0; j < dimensionX; ++j) {
            if (fields.at(i).at(j) == " ") {
                return false;
            }
        }
    }
    return true;
}

