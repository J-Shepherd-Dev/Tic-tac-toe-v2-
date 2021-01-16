#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <cstdlib>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <time.h>       /* time */
#include <string>
using namespace std;


char square[10] = {'o','1','2','3','4','5','6','7','8','9'}; // Array variables 

int checkwin(); // funation to check win 
void board(); // draw and update board for playervsplayer
void board_2(); // draw and update board for playervsai

int main();


int gameVsHuman()
{

  

  
	  int player = 1,i,choice; // i records last player to take the turn so if we use this                    check if they have won then we can print out last player to win since 
                            // also way of asking of player's choice whlist playng the game 
    char mark;              // replaces the square number with player's chars like X and O 
    do
    {
        board(); // loads the board 
        player=(player%2)?1:2; // switches between player after while 

        cout << "Player's " << player <<  " Turn" << ", enter a input:  "; // player input
        cin >> choice; // takes player choice

        mark=(player == 1) ? 'X' : 'O'; // switches player's char with turns 

        if (choice == 1 && square[1] == '1')

            square[1] = mark;
        else if (choice == 2 && square[2] == '2')

            square[2] = mark;
        else if (choice == 3 && square[3] == '3')

            square[3] = mark;
        else if (choice == 4 && square[4] == '4')

            square[4] = mark;
        else if (choice == 5 && square[5] == '5')

            square[5] = mark;
        else if (choice == 6 && square[6] == '6')

            square[6] = mark;
        else if (choice == 7 && square[7] == '7')

            square[7] = mark;
        else if (choice == 8 && square[8] == '8')

            square[8] = mark;
        else if (choice == 9 && square[9] == '9')

            square[9] = mark;
        else
        {
            cout<<"Invalid move "; // Exception handling just case player try place their symbol already placed or not right input such as letter 

            player--; // otherwise it would switch to next turn 
            cin.ignore(); // ignore input 
            cin.get(); // gets another input 
        }
        i=checkwin(); // checks if player win before switching turns 

        player++; // switches players turns
    }while(i==-1); // I is -1 the game keeps on running 
    board(); // updates the board
    if(i==1) // winstate 

        cout<<"==>\aPlayer "<<--player<<" win ";
    else // otherwise is draw 
        cout<<"==>\aGame draw";

    cin.ignore(); 
    cin.get();
    return 0; // game ends in draw
  
}



int checkwin() // Check winner
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0; // game is over as draw 
    else
        return -1; // otherwise contiune 
}

 
int gameVsRobot() {
    int turncounter = 0; //The number of turns taken in the game
    int i; //The winstate of the game
    int selected_sqaure;
    int result = 0;
 
    char mark; //Keeps track of the current mark to add to the board
 
    do
    {
        turncounter++;
 
        board_2(); //Draws the board
 
        if(turncounter % 2 == 1){
            //Players turn
            mark = 'X';
 
            cout << "Please choose a square:"; // player input
            cin >> selected_sqaure; // takes player choice
        }
        else{
            //Computer's turn
            mark = 'O';
  
            //Pick a square from remaining squares (you can work this out)
            selected_sqaure = 0;//Get remaining squares and pick random one here
            // char remaining_squares[10]
            int total_squares_remaining = 0;
            int remaining_squares[10] = {};
            if(square[1] == '1'){
    remaining_squares[total_squares_remaining] = 1;
    total_squares_remaining++;
}
            if(square[2] == '2'){
    remaining_squares[total_squares_remaining] = 2;
    total_squares_remaining++;
}
            if(square[3] == '3'){
    remaining_squares[total_squares_remaining] = 3;
    total_squares_remaining++;
}
            if(square[4] == '4'){
    remaining_squares[total_squares_remaining] = 4;
    total_squares_remaining++;
}
            if(square[5] == '5'){
    remaining_squares[total_squares_remaining] = 5;
    total_squares_remaining++;
}
            if(square[6] == '6'){
    remaining_squares[total_squares_remaining] = 6;
    total_squares_remaining++;
}
            if(square[7] == '7'){
    remaining_squares[total_squares_remaining] = 7;
    total_squares_remaining++;
}
            if(square[8] == '8'){
    remaining_squares[total_squares_remaining] = 8;
    total_squares_remaining++;
}
            if(square[9] == '9'){
    remaining_squares[total_squares_remaining] = 9;
    total_squares_remaining++;
}
srand(time(0)); 
int r = rand() % total_squares_remaining; // total_squares_remaining get lesser each time square is taken. mod limt of number to something we want for computer input
  selected_sqaure = remaining_squares[r]; // random item from remaining array 
           cout << "Computer has picked..." << selected_sqaure << endl;
           //selected saure = math.rand(0,total_squares_remaining)
        }
 
        result = 1;
        if (selected_sqaure == 1 && square[1] == '1')
            square[1] = mark;
        else if (selected_sqaure == 2 && square[2] == '2')
            square[2] = mark;
        else if (selected_sqaure == 3 && square[3] == '3')
            square[3] = mark;
        else if (selected_sqaure == 4 && square[4] == '4')
            square[4] = mark;
        else if (selected_sqaure == 5 && square[5] == '5')
            square[5] = mark;
        else if (selected_sqaure == 6 && square[6] == '6')
            square[6] = mark;
        else if (selected_sqaure == 7 && square[7] == '7')
            square[7] = mark;
        else if (selected_sqaure == 8 && square[8] == '8')
            square[8] = mark;
        else if (selected_sqaure == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            cout << "Invalid move, "<<selected_sqaure<<"please pick an empty square";
 
            turncounter--; // otherwise it would switch to next turn
        }
 
        i = checkwin(); // checks if player win before switching turns
    } while (i == -1); // I is -1 the game keeps on running
 
    board_2(); //Display the final board state
 
    if (i == 1) // last player who taken the turn got all 3 in row is winner
        if(turncounter % 2 == 1) {
            cout << "==>\aPlayer win!";
        }else{
            cout << "==>\aAI win!";
        }
    else // otherwise is draw
        cout << "==>\aGame draw";
 
    cin.ignore();
    cin.get();
    return 0; // game ends in draw
}




void board() // draws the board player vs player
{
    


    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}

void board_2() // draws the board for computer vs player
{
    


    cout << "Player 1 (X)  -  Computer (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}

int main(){ // menu 

  int userInput; 
  char rerun;
    do{
    cout << "Hello" << endl;
    cout << "Which gamemode would you like to play?" << endl; 
    cout << "One player mode is 1 : Two player mode is 2" << endl;
    cin >> userInput;
    if (userInput == 1){
      gameVsRobot();
    }
    if(userInput == 2){
      
      gameVsHuman();
    }
    else{
      cout << "Invalid command" << endl;
      cout << "Do you want to rerun the program? input Y or y" << endl;
      cin >> rerun;
    }
    
    
  }  
   while(rerun == 'y' || rerun == 'Y');
   cout << "Bye Bye";
}