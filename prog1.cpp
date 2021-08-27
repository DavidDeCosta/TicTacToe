//Name: David DeCosta
//File Name: prog1.cpp
//Date: 26 August, 2021
//Program Description: This is a 2 player game called TicTacToe

#include <iostream>
#include <stdlib.h> // for srand, and rand
#include <time.h> // for time
#include <iomanip> //for setw
using namespace std;

const int MAXCOL = 3;
const int MAXROW = 3;
typedef char board[MAXROW][MAXCOL]; //a 2D array representing out TicTacToe board

//prototypes
void initializeBoard(board game);
void printBoard(board game);
int getStatus(board game);
void makeMove(board, int& turn,string name);


int main(){

    board game;
    string player1, player2;
    int flip;
    srand(time(NULL)); //seeds the random number generator
    flip = rand()%2+1; //generates a random number 1 or 2
    int turn = 1;
    
    cout << "Player one, Enter your name: \n";
    cin >> player1;
    cout << "Player two, Enter your name: \n";  
    cin >> player2;
    cout << endl <<endl;

    if(flip == 1){
        cout << player1 << " Won the toss\n";
    }
    else{
        cout << player2 << " Won the toss \n";
    }
    
    if(flip == 2){ //This will swap player1 and player2 depending on the random number generated
        string temp;
        temp = player1;
        player1=player2;
        player2=temp;
    }

    initializeBoard(game);

    /* This While loop will continuously execute until either player wins or it's declared a tie */
   while(getStatus(game) == 3){
       printBoard(game);
       makeMove(game,turn,player1);
       getStatus(game);
    if(getStatus(game)==3){
       printBoard(game);
       makeMove(game,turn,player2);
       getStatus(game);
       }
   }

   printBoard(game);
   cout << endl << endl;

   if(getStatus(game) == 1){
       cout << player1 << " WINS!! \n";
   }
   else if(getStatus(game) == 2){
       cout << player2 << " WINS!! \n";
   }
   else{
       cout << "It was a Tie.... \n";
   }

    return 0;
}

            /* This Function initializes the board with a black space */
void initializeBoard(board game){
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3; j++){
            game[i][j] = ' ';
        }
    }
}

            /* This function prints the board to the terminal */
void printBoard(board game){
    
    cout << endl;
    cout <<setw(1)<< game[0][0]<< setw(1)<<" | " <<setw(1)<< game[0][1] <<setw(1)<< " | " <<setw(1)<< game[0][2] << endl;
    cout <<setw(1)<< "----------\n";
    cout <<setw(1)<< game[1][0] <<setw(1)<< " | " <<setw(1)<< game[1][1] <<setw(1)<< " | " <<setw(1)<< game[1][2] << endl;
    cout <<setw(1)<< "----------\n";
    cout <<setw(1)<< game[2][0] <<setw(1)<< " | " <<setw(1)<< game[2][1] <<setw(1)<< " | " <<setw(1)<< game[2][2] << endl;
    
}

            /* This function checks for a Win, a Tie, or if no result yet */
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

            /* This function is responsible for making the moves according to what players turn it is */
void makeMove(board game, int& turn,string name){

    int row, col;
    bool turnMade = false;

    while(turnMade == false){
        cout << endl << name << ": Enter the row(1-3): \n";
        cin >> row;
        while(row<1 || row > 3){
            cout << "To large or to small.. TRY AGAIN \n";
            cout << endl << name << ": Enter the row(1-3): \n"; 
            cin >> row;
        }
        cout << endl << name << ": Enter the col(1-3): \n";
        cin >> col;
        while(col < 1 || col > 3){
            cout << "To large or to small.. TRY AGAIN \n";
            cout << endl << name << ": Enter the col(1-3): \n";
            cin >> col;
        }
        if(game[row-1][col-1] != ' '){
            cout << "Already filled TRY AGAIN \n";
        }
        else if(turn == 1){
            game[row-1][col-1] = 'X';
            turn =2;
            turnMade = true;
        }
        else{
            game[row-1][col-1] = 'O';
            turn =1;
            turnMade = true;
        }
    }
}
