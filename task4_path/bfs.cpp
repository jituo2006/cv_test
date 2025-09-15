#include <stdexcept>
#include <iostream>
#include <vector>
#include <queue>

// 定义节点结构体，表示网格中的一个点以及从起点到该点的距离
struct Node {
    int x, y, dist;  
};

// 判断位置是否合法
bool isValid(int x, int y, std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited) {
    int n = grid.size(), m = grid[0].size();
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0 && !visited[x][y];
}

// 广度优先搜索函数，标记路径并输出地图
void bfs(std::vector<std::vector<int>> &grid, int sx, int sy, int tx, int ty) {
    int n = grid.size();
    int m = grid[0].size();

    if (grid[sx][sy] == 1 || grid[tx][ty] == 1) return;

    std::vector<int> dx = {1, -1, 0, 0};  
    std::vector<int> dy = {0, 0, 1, -1};  

    std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
    std::vector<std::vector<std::pair<int,int>>> parent(n, std::vector<std::pair<int,int>>(m, {-1,-1}));

    std::queue<std::pair<int,int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    bool found = false;
    while (!q.empty()) {
        auto [x, y] = q.front(); 
        q.pop();

        if (x == tx && y == ty) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m 
                && grid[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        throw std::runtime_error("I can't go to the position (" + std::to_string(tx) + "," + std::to_string(ty) + ").");
    }

    // 标记路径
    int px = tx, py = ty;
    while (!(px == sx && py == sy)) {
        grid[px][py] = -1; // 用 -1 临时标记路径
        auto p = parent[px][py];
        px = p.first;
        py = p.second;
    }
    grid[sx][sy] = -1;

   
    
}