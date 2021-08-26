#include <iostream>
#include <cstdlib> // for NULL
#include <stdlib.h> // for srand, and rand
#include <time.h> // for time
#include <iomanip>
using namespace std;

const int MAXCOL = 3;
const int MAXROW = 3;
typedef char board[MAXROW][MAXCOL];

//prototypes
void initializeBoard(board game);
void printBoard(board game);
int getStatus(board game);
void makeMove(board, int& turn,string name);



int main(){

    board game;
    string player1, player2;
    int x,flip;
    srand(time(NULL));
    flip = rand()%2+1;

    
    cout << "Player one, Enter your name: \n";
    cin >> player1;
    cout << "Player two, Enter your name: \n";
    cin >> player2;
    
    if(flip == 2){
        string temp;
        temp = player1;
        player1=player2;
        player2=temp;
    }
   // cout << endl;
   // cout << flip << endl;
   // cout << player1 << endl;
   // cout << player2 << endl;

    initializeBoard(game);
    /*
    game[0][0] = 'X';
    game[1][1] = 'X';
    game[2][2] = 'O';
    game[0][1]= 'X';
    game[0][2] = 'O';
    game[1][0]='O';
    game[1][2] = 'X';
    game[2][0] = 'X';
    game[2][1] = 'X';
    */
    makeMove(game,flip,player1);
    printBoard(game);
    makeMove(game,flip,player2);
    printBoard(game);
    makeMove(game,flip,player1);
    printBoard(game);

    //makeMove(game,flip,player1);

    cout << endl;
    x = getStatus(game);
    cout << x << endl;

    return 0;
}

void initializeBoard(board game){
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3; j++){
            game[i][j] = ' ';
        }
    }
}

void printBoard(board game){
    
    cout << endl;
    cout <<setw(1)<< game[0][0]<< setw(1)<<" | " <<setw(1)<< game[0][1] <<setw(1)<< " | " <<setw(1)<< game[0][2] << endl;
    cout <<setw(1)<< "----------\n";
    cout <<setw(1)<< game[1][0] <<setw(1)<< " | " <<setw(1)<< game[1][1] <<setw(1)<< " | " <<setw(1)<< game[1][2] << endl;
    cout <<setw(1)<< "----------\n";
    cout <<setw(1)<< game[2][0] <<setw(1)<< " | " <<setw(1)<< game[2][1] <<setw(1)<< " | " <<setw(1)<< game[2][2] << endl;
    
}

int getStatus(board game){
    int num; // return 0 for tie, 1 player1 win, 2 player2 win, 3 no result yet

    
    if(game[0][0] == 'X' && game[0][1]== 'X' && game[0][2] == 'X'){
        num = 1;
    }
    else if(game[0][0] == 'O' && game[0][1]== 'O' && game[0][2] == 'O'){
        num = 2;
    }
    else if(game[1][0] == 'X' && game[1][1]== 'X' && game[1][2] == 'X'){
        num = 1;
    }
    else if(game[1][0] == 'O' && game[1][1]== 'O' && game[1][2] == 'O'){
        num = 2;
    }
    else if(game[2][0] == 'X' && game[2][1]== 'X' && game[2][2] == 'X'){
        num = 1;
    }
    else if(game[2][0] == 'O' && game[2][1]== 'O' && game[2][2] == 'O'){
        num = 2;
    }
    else if(game[0][0] == 'X' && game[1][1]== 'X' && game[2][2] == 'X'){
        num = 1;
    }
    else if(game[0][0] == 'O' && game[1][1]== 'O' && game[2][2] == 'O'){
        num = 2;
    }
    else if(game[0][2] == 'X' && game[1][1]== 'X' && game[2][0] == 'X'){
        num = 1;
    }
    else if(game[0][2] == 'O' && game[1][1]== 'O' && game[2][0] == 'O'){
        num = 2;
    }
    else if(game[0][0] == 'X' && game[0][1] == 'X' && game[0][2] == 'X'){
        num =1;
    }
    else if(game[0][0] == 'O' && game[0][1] == 'O' && game[0][2] == 'O'){
        num=2;
    }
    else if(game[0][1] == 'X' && game[1][1] == 'X' && game[2][1] == 'X'){
        num =1;
    }
    else if(game[0][1] == 'O' && game[1][1] == 'O' && game[2][1] == 'O'){
        num =2;
    }
    else if(game[0][2] == 'X' && game[1][2] == 'X' && game[2][2] == 'X'){
        num =1;
    }
    else if(game[0][2] == 'O' && game[1][2] == 'O' && game[2][2] == 'O'){
        num =2;
    }
    else if(game [0][0] == ' ' || game [0][1] == ' ' || game[0][2] == ' '
            || game[1][0] == ' ' || game[1][1]==' ' || game[1][2] == ' '
            || game[2][0] == ' ' || game[2][1]== ' ' || game[2][2] == ' '){
                num = 3;
            }
    else{
        num = 0;
    }

    return num;
}

void makeMove(board game, int& turn,string name){

    int row, col;

    cout << endl << "Enter the row(1-3): \n";
    cin >> row;
    cout << endl << "Enter the col(1-3): \n";
    cin >> col;
    if(turn == 1){
        game[row-1][col-1] = 'X';
        turn =2;
    }
    else{
        game[row-1][col-1] = 'O';
        turn =1;
    }

}