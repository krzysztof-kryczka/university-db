#include "EndGame.hpp"

void EndProgram::run() {
    Command::quit = true;
}

std::string EndProgram::getName() {
    return "End Program";
}
