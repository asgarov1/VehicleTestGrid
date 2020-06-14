//
// Created by Javid Asgarov on 08.06.20.
//

#ifndef GRIDSERVER_RACEFIELD_H
#define GRIDSERVER_RACEFIELD_H


#include <vector>
#include <string>

class RaceField {

    /**
     * Racefield
     */
    std::vector<std::vector<std::string>> fields;
    std::string carNames[27];  //27 because sockets in main start from 1 and I keep track by using same index for car name as the socket number that it came from

    /**
     * to keep track of the X dimension size
     */
    int dimensionX{};

    /**
     * to keep track of the Y dimension size
     */
    int dimensionY{};

    /**
     * keeps track if the last movement resulted in crash
     */
    bool wasClash;

    /**
     * keeps track of the last crashes victim car index
     */
    int lastVictimCarIndex;

    /**
     * Used to initialise the race field based on the parameters passed in argv
     * @param argc
     * @param argv
     */
    void initialiseRaceField(int argc, char *argv[]);
    void setCarName(int index, std::string name);

public:
    RaceField(int argc, char **argv);

    /**
     * Method that places car on a random position and returns position X,Y as a string (for the return message)
     * @param index
     * @param carName
     * @return
     */
    std::basic_string<char> placeCar(int index, const std::string& carName);

    /**
     * Used when new client wants to register under a letter - checks if the letter is already taken
     * @param letter
     * @return
     */
    bool letterIsTaken(const std::string& letter);

    /**
     * Method that moves car and check for the consequences of the move
     * @param carIndex
     * @param string
     * @return boolean, true in case movement was uneventful, false if the car crashed
     */
    bool moveCar(int carIndex, const std::string& string);

    /**
     * Helper method that removes the car name from the registered cars array of names
     * @param carName
     * @return
     */
    int removeCarName(const std::string &carName);

    /**
     * An overloaded variation of the previous method
     * @param index
     */
    void removeCarName(int index);

    /**
     * Returns boolean to answer the question whether racefield is full or still has space for new clients
     * @return
     */
    bool isFull();

    /**
     * Returns if the client is registered
     * @param socketNumber
     * @return
     */
    bool clientIsRegistered(int socketNumber);

    //Getters
    [[nodiscard]] const std::vector<std::vector<std::string>> &getFields() const;
    [[nodiscard]] const std::string *getCarNames() const;
    [[nodiscard]] std::string getCarName(int index) const;
    [[nodiscard]] bool isWasClash() const;
    [[nodiscard]] int getLastVictimCarIndex() const;

    //Setters
    void setWasClash(bool wasClash);
    void setVictimCarIndex(int victimCarIndex);
};


#endif //GRIDSERVER_RACEFIELD_H
