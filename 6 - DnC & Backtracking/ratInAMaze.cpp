#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int srcx, int srcy, int newx, int newy, int row, int col, int maze[][4], vector<vector<bool>> &visited);

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool>> &visited) {
    if (srcx == row - 1 && srcy == col - 1) {
        cout << output << endl;
        return;
    }

    if (maze[srcx][srcy] == 0) {
        //src position is closed, that means RAT can't move
        cout << "No Path Exists" << endl;
    } else {
        visited[srcx][srcy] = true;
    }

    // Up
    if (isSafe(srcx, srcy, srcx - 1, srcy, row, col, maze, visited)) {
        int newx = srcx - 1;
        int newy = srcy;

        // Recursive call
        output.push_back('U');
        printAllPath(maze, row, col, newx, newy, output , visited);
        // Backtrack
        output.pop_back();
        visited[newx][newy] = false;
    }

    // Down
    if (isSafe(srcx, srcy, srcx + 1, srcy, row, col, maze, visited)) {
        int newx = srcx + 1;
        int newy = srcy;

        // Recursive call
        output.push_back('D');
        printAllPath(maze, row, col, newx, newy, output , visited);
        // Backtrack
        output.pop_back();
        visited[newx][newy] = false;
    }

    // Right
    if (isSafe(srcx, srcy, srcx, srcy + 1, row, col, maze, visited)) {
        int newx = srcx;
        int newy = srcy + 1;

        // Recursive call
        output.push_back('R');
        printAllPath(maze, row, col, newx, newy, output , visited);
        // Backtrack
        output.pop_back();
        visited[newx][newy] = false;
    }

    // Left
    if (isSafe(srcx, srcy, srcx, srcy - 1, row, col, maze, visited)) {
        int newx = srcx;
        int newy = srcy - 1;

        // Recursive call
        output.push_back('L');
        printAllPath(maze, row, col, newx, newy,output, visited);
        // Backtrack
        output.pop_back();
        visited[newx][newy] = false;
    }
}

bool isSafe(int srcx, int srcy, int newx, int newy, int row, int col, int maze[][4], vector<vector<bool>> &visited) {
    if ((newx >= 0 && newx < row) &&
        (newy >= 0 && newy < col) &&
        maze[newx][newy] == 1 &&
        !visited[newx][newy]) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int maze[][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1}};

    int row = 4;
    int col = 4;

    int srcx = 0;
    int srcy = 0;
    string output = "";

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    printAllPath(maze, row, col, srcx, srcy, output, visited);
    return 0;
}
