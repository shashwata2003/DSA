#include<iostream>
#include <bits/stdc++.h>
#include <array>
using namespace std;
/*
The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard such that no two queens 
attack each other.

Given an integer ‘N’, print all distinct solutions to the ‘N’ queen puzzle.

Two queens on the same chessboard can attack each other if any of the below condition satisfies:  
1. They share a row. 
2. They share a column. 
3. They share a diagonal.

Sample Input 1:
1
4   
Sample Output 1:
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
Explanation for Sample Input 1:
The 4 queens can be placed in two ways in a 4*4 chessboard. Both the configurations are shown in the below 
figure. 

Sol:
Apporach:
using back tracking
Here we are going to place the queen in each col and traverse each row after that 
While we are tracking back we will start removing the queens from the old places to make it open for other paths

So first we will place Q1 at 0,0 and then travers all the rows in 0 col
and then we will do the same for 0,1 and traverse all the row in 1 col.

we need to use a function called issafe which will tell us weather it is safe the place a queen there or not:
1. check there should not be any other queen in the same row , col or diagonal
-> now as we are traversing left to right hence dont have to check the right side of the current queen, hence
check only the left side
-> also we are backtracking when we are moving to the next col so we dont have to check the col
2. Hence we need to checK:
 i. left row (row = row , col = col -1)
 ii. diagonals only the left side (top cornor: row-1,col-1 ; down cornor: row+1 , col -1 )

See the node book for the tree

See the video once again

TS: N!
SP: N*N

Optimization:
The issafe function will take o(n) TS for each checks, which can be reduced to O(1) using maps
1. For Left row check: we can create a map b/w row and bool which will store which row has the queen
so consider if row 1 has a queen hence while placing the queen we will mark the bool to true. hence O(1)

2. down cornor diagonal: Here the entire diagonal will be equal of row + col , hence condider Queen is place 
at 4,3 hence in the map<col+row,bool> mark 7 -> true 
hence next when we are at any other box check of row + col , if it == 7 hence there is already a queen eg of
2,5 : we cannot place a queen there.

3. Upper cornor diagonal: Here we will apply the same logic but we will map it with (n-1) + col - row

Ts: O(N!)
SP: O(N*N)
*/

// this function adds the final board config to the ans in a 1d formate which need to be returned.
void addSoltion(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
        
    }

    ans.push_back(temp);
    
}

// this returns weather the given position is safe to place a new queen there. according to the provide 
// conditions.
bool issafe(int row, int col, vector<vector<int>> &board, int n){
    int x = row;
    int y = col;
    
    // case 1: check the left side of row: we dont need to check the right side as we are placing queens 
    // form left to right.
    while (y>=0)
    {
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }
    
    // case 2: check cols: we dont have to check the col as we are backtracking when we move to the next col 
    // hence no two queens will be placed in the same col:

    x = row;
    y = col;
    // case 3: check the diagonals: the left side only for the same reason as before:
        // case i: for the bottom cornor: row = row-1 col = col-1
    while (x>=0 && y>=0)
    {
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    
    x = row;
    y = col;
        //case ii: for the up corror : row+1 , col -1
    while (x<n && y>=0)
    {
        if(board[x][y] == 1){
            return false;
        }
        x++;
        y--;
    }
    
    return true;
}

void solve(vector<vector<int>> &board, vector<vector<int>> &ans, int col, int n){
    // base case: we have traversed all the cols possible hence add the final broad in the ans.
    if(col == n){
        addSoltion(board,ans,n);
        return;
    }

    // now we have to traverse each row for the given col using recursion.
    for (int row = 0; row < n; row++)
    {
        if(issafe(row,col,board,n)){
            board[row][col] = 1;
            solve(board,ans,col+1,n);
            // backtrack:
            board[row][col] = 0;
        }
    }
    
}


vector<vector<int>> nqueens( int n){
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;

    int col = 0;
    solve(board,ans,col,n);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> ans = nqueens(n);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
            if ((j + 1) % n == 0)
                cout << endl;
        }
        cout << endl;
    }
    return 0;
}