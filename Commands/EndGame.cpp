#include "EndGame.hpp"

EndProgram::EndProgram(bool& end): end_(end) {}

void EndProgram::run() {
    end_ = true;
}

std::string EndProgram::getName() const {
    return "End Program";
}
