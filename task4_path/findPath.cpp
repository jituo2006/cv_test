#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include "bfs.hpp"



int main(int argc, char* argv[]) {
    // 读取地图数据
    std::ifstream infile("map.txt");
    if (!infile) {
        std::cerr << "failed to open file!" << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> grid(5, std::vector<int>(5, 0));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            infile >> grid[4-i][j];
        }
    }

    int sx = std::stoi(argv[1]);
    int sy = std::stoi(argv[2]);
    int tx = std::stoi(argv[3]);
    int ty = std::stoi(argv[4]);

    try {
        bfs(grid, sx, sy, tx, ty);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    for (int i = 4; i >= 0; i--) {
        for (int j = 0; j < 5; j++) {
            if (grid[i][j] == 1)
                std::cout << "1 ";
            else if (grid[i][j] == -1)
                std::cout << "* ";
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }

    return 0;
}