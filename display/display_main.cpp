#include <stdio.h>
#include <string>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdlib>
#include <csignal>
#include <iostream>

using namespace std;

//using pipe communication to display info from server
int main() {
    int fd1;
    bool keepReading = true;

    // FIFO file path
    char *myfifo = "/tmp/myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);

    int inputSizeInBytes = 4096;
    char input[inputSizeInBytes];
    std::cout << "Once clients register, grid will be displayed here" << std::endl;
    while (keepReading) {
        fd1 = open(myfifo, O_RDONLY);
        // First open in read only and read
        read(fd1, input, inputSizeInBytes);
        printf("%s", input);
        if(string(input).compare(std::to_string(SIGTERM)) == 0){
            keepReading = false;
        }
    }
    close(fd1);
    return EXIT_SUCCESS;
}