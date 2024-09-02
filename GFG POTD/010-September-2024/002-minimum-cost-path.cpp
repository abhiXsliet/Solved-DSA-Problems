// https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1




//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Cell {
public:
    int row, col, cost;
    
    // Constructor to initialize a cell with its position and cost
    Cell(int row, int col, int cost) : row(row), col(col), cost(cost) {}
};

class CellComparator {
public:
    // Comparator to prioritize cells with lower cost in the priority queue
    bool operator()(Cell& cell1, Cell& cell2) {
        return cell1.cost > cell2.cost;
    }
};

class Solution {
public:
    int minimumCostPath(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        // Priority queue (min-heap) to store cells by their cost, prioritizing lower costs
        priority_queue<Cell, vector<Cell>, CellComparator> minHeap;
        
        // 2D vector to store the minimum cost to reach each cell
        vector<vector<int>> minCost(rows, vector<int>(cols, INT_MAX));
        
        // Direction vectors for moving left, right, up, and down
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        
        // Start from the top-left cell (0,0) with its initial cost
        minHeap.push(Cell(0, 0, grid[0][0]));
        minCost[0][0] = grid[0][0];
        
        // Process the grid until all possible paths are explored
        while (!minHeap.empty()) {
            Cell currentCell = minHeap.top();
            minHeap.pop();
            
            // Traverse all four possible directions from the current cell
            for (auto& direction : directions) {
                int newRow = currentCell.row + direction[0];
                int newCol = currentCell.col + direction[1];
                
                // Skip invalid cell positions
                if (newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) {
                    continue;
                }
                
                // Calculate the new cost to reach the neighboring cell
                int newCost = grid[newRow][newCol] + currentCell.cost;
                
                // If a cheaper path to the neighboring cell is found, update the cost
                if (minCost[newRow][newCol] <= newCost) {
                    continue;
                }
                
                // If the bottom-right cell is reached, return the cost
                if (newRow == rows - 1 && newCol == cols - 1) {
                    return newCost;
                }
                
                // Update the minimum cost to reach the neighboring cell and push it to the heap
                minCost[newRow][newCol] = newCost;
                minHeap.push(Cell(newRow, newCol, newCost));
            }
        }
        
        // This line should never be reached, as the grid is always traversable
        return 0;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends