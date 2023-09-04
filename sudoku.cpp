#include<iostream>
using namespace std;

bool isSafe(int board[9][9],int value,int row,int col){
    int n =9;
    for(int i=0;i<n;i++){
    
    // row check
    
        if(board[row][i]==value)
        return false;
    
    

    // col chheck
    
    if(board[i][col]==value)
    return false;
    
    // 3*3 box
    
    if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==value)
    return false;
    }
    return true;

}


bool solve(int board[9][9],int n) {

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            // for empty cell
            if(board[row][col]==0){
                for(int value=1;value<=9;value++){
                    // check for safe
                    if(isSafe(board,value,row,col)){
                        // insert
                        board[row][col]=value;
                        // baaki recursion sambhal lega
                        bool remainingboardsoltion = solve(board,n);
                        if(remainingboardsoltion == true){
                            return true;
                        }
                        else{
                            // backtrack
                            board[row][col]=0;
                        }
                    }
                    
                }
                // if 1 se 9 tk koi bhi value ka soltion
                    // nhi nikla current cell pr that means
                    // piche khi pr glti h,
                    // go back by returning false
                    return false;
            }
            
        }
    }
    // filled all cell
    return true;
}

int main(){

    int board[9][9]= {
        {4,5,0,0,0,0,0,0,0},
        {0,0,2,0,7,0,6,3,0},
        {0,0,0,0,0,0,0,2,8},
        {0,0,0,9,5,0,0,0,0},
        {0,8,6,0,0,0,2,0,0},
        {0,2,0,6,0,0,7,5,0},
        {0,0,0,0,0,0,4,7,6},
        {0,7,0,0,4,5,0,0,0},
        {0,0,8,0,0,9,0,0,0}};

    

    int n =9;
    solve(board,n);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}