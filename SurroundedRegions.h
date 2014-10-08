/*
Problem: Surrounded Regions
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/08/2014
Difficulty: **^
Review: ***^
Solution:
    想出了广度优先的思路，但由于设置访问标记的时机不对，导致TLE。
    BFS from edge nodes which equal to 'O'. Mark all visited nodes as 'o'. These 'o' 
    should be kept as 'O'.
    *Note*: BFS: The time to update visited node is when the node is push in the queue,
           not the node is pop from the queue.
*/
class Solution {
    // mark all nodes that are connected with node[i][j]
    // with 'o'. These 'o' should be kept as 'O'.
    void bfs(vector<vector<char>> &board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        board[i][j] = 'o';
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            int x = pos.first;
            int y = pos.second;
            
            if (x > 0 && board[x-1][y] == 'O') {
                board[x-1][y] = 'o';
                q.push(make_pair(x-1, y));
            }
            if (x < m-1 && board[x+1][y] == 'O') {
                board[x+1][y] = 'o';
                q.push(make_pair(x+1, y));
            }
            if (y > 0 && board[x][y-1] == 'O') {
                board[x][y-1] = 'o';
                q.push(make_pair(x, y-1));
            }
            if (y < n-1 && board[x][y+1] == 'O') {
                board[x][y+1] = 'o';
                q.push(make_pair(x, y+1));
            }
        }
    }
    
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        if (!m) return;
        int n = board[0].size();
        if (!n) return;

        // top and bottom
        for (int i = 0, j = 0; j < n; ++j) {
            if (board[i][j] == 'O')
                bfs(board, i, j);
            if (board[m-i-1][j] == 'O')
                bfs(board, m-i-1, j);
        }
        
        // left and right
        for (int i = 1, j = 0; i < m; ++i) {
            if (board[i][j] == 'O')
                bfs(board, i, j);
            if (board[i][n-j-1] == 'O')
                bfs(board, i, n-j-1);
        }
        
        // fill all with 'X' except 'o'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'o')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};