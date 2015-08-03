#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using std::vector;

class Grid {
  private:
    int **grid;
    int rows;
    int cols;
    
    int patternMatch(int prows, int pcols, int grow, int gcol, int **pattern) {
        for (int i = 0; i < prows; i++) {
            for (int j = 0; j < pcols; j++) {
                if (pattern[i][j] != grid[grow+i][gcol+j])
                    return 0;
            }
        }
        return 1;
    }
    
  public:
    Grid() {
        
    }
    
    Grid(int R, int C) {
        string row;
        
        rows = R;
        cols = C;
        grid = new int*[R];
        for (int i = 0; i < R; i++) {
            grid[i] = new int[C];
            cin >> row;
            for (int j = 0; j < C; j++) {
                grid[i][j] = row[j] - '0';
            }
        }
    }
    
    void to_string() {
        cout << rows << " " << cols << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    
    int getRows() {return rows;}
    
    int getCols() {return cols;}
    
    int** getGrid() {return grid;}
    
    /**
     * Checks if the calling Grid G contains the pattern represented by P's grid.
     * Returns 1 if found, 0 if not found.
     */
    int Contains(Grid *P) {
        int prows, pcols;
        int searchrows, searchcols; //less than rows and cols because the search grid is large
        int **pgrid;
        
        prows = P->getRows();
        pcols = P->getCols();
        
        searchrows = rows - prows;
        searchcols = cols - pcols;
        pgrid = P->getGrid();
        
        for (int i = 0; i <= searchrows; i++) {
            for (int j = 0; j <= searchcols; j++) {
                if (pgrid[0][0] == grid[i][j])
                    //Check if it contains the pattern
                    //if it doesn't, continue searching
                    if (patternMatch(prows,pcols,i,j,pgrid))
                        return 1;
            }
        }
        return 0;
    }
};

int main() {
    int T;
    int R;
    int C;
    Grid *G;
    int r;
    int c;
    Grid *P;
    
    cin >> T;
    
    for (int trial = 0; trial < T; trial++) {
        
        //Make the G grid
        cin >> R >> C;
        G = new Grid(R,C);
        
        //Make the P grid
        cin >> r >> c;
        P = new Grid(r,c);
        
        if (G->Contains(P))
            cout << "YES";
        else
            cout << "NO";
        
        cout << endl;
        delete G;
        delete P;
    }
     
    return 0;
}
