#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

int main(int argc, char* argv[]) {
    std::string log_name = argv[1];
    std::ifstream LogFile(log_name);
    // Read only
    if (!LogFile.is_open()) {
        std::cerr << "Failed to open " << log_name << std::endl;
        return 1;
    }
    std::vector<std::string> commands;
    std::unordered_map<std::string , int> command_count;
    std::string line;
    while (std::getline(LogFile, line)) {
        commands.push_back(line);
    }
    for (const auto& cmd : commands) {
        command_count[cmd]++;
    }
    for (const auto& [key , value] : command_count) {
        std::cout << key << ": " << value << std::endl;
    }
    return 0;
}