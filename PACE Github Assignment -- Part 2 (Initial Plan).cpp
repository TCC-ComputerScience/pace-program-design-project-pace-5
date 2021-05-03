//Pace Group 5, functions done by Azarius Deberry
//CSC201
// 5/3/2021
// Board game of battleship
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



const int MAX_GAMEBOARD = 10;


//pre takes array to generate the board
//Places symbols to fill the array
//post sends out map
void GenerateMap(/* OUT */char gamemap[][MAX_GAMEBOARD]);
//void InitArray(/* OUT */ int twoDArray[][NUM_COLS], /* IN */ int rowSize);
// pre take numbers from the user
// checks the numbers in the array to see if it hit
// post nothing
void CheckHit(char gamemap[][MAX_GAMEBOARD], int x, int y);



int main()
{

    char gamemap[MAX_GAMEBOARD][MAX_GAMEBOARD];
    char userchoice = 'a';
    int x;
    int y;

    GenerateMap(gamemap); // call the generate map function to initialize the array



    do  // loop until user quits the program.
    {
        cout << endl << "Enter x coordinate: ";
        cin >> x;
        cout << endl << "Enter y coordinate: ";
        cin >> y;

        CheckHit(gamemap, x, y);

        for(int row = 0; row < MAX_GAMEBOARD; row++)  // loop until end of array
        {
            cout << endl;
            for(int col =0; col < MAX_GAMEBOARD; col++)
            {
                cout << gamemap[row][col]; // outputting to demonstrate code function

            }
        }
//prompt user to enter a choice to play or quit
        cout << endl << "Enter Q to quit playing or anything else to keep going: ";
        cin >> userchoice;
        cout << endl;

    }
    while (userchoice != 'Q');

    return 0;
}


void CheckHit(char gamemap[][MAX_GAMEBOARD], int x, int y)
{

    char shipsunk = 'S';

    if (gamemap[x][y] == '@')  // If the guessed num is a ship symbol, let the user know they sunk a ship
    {
        cout << "You sunk a warship!" << endl;
        gamemap[x][y] = shipsunk; // change the symbol at x,y to a sunken ship symbol
    }
    else if(gamemap[x][y] == 'S')   // If the guessed num is a sunken ship symbol, let the user know they already sunk that ship
    {

        cout << "You already sunk this ship!" << endl;

    }
    else
    {
        cout << "You missed!" << endl; // otherwise let the user know they missed.
    }
}


void GenerateMap(/* OUT */char gamemap[][MAX_GAMEBOARD])
{

    int randnum = 0;

    char water = '~';
    char warship = '@';

// loop through each row of the array.
    for(int row = 0; row < MAX_GAMEBOARD; row++)
    {


        // loop through each col of the array and assign a char to the space, randomly generated.
        for(int col =0; col < MAX_GAMEBOARD; col++)
        {

            randnum = rand() % 100 + 1;

            if(randnum % 2 == 0)  // if the random number is even, assign a water space to the array
            {
                gamemap[row][col] = water;

            }
            else
            {
                gamemap[row][col] = warship; // if the random number is odd, assign a warship space to the array
            }

        }

    }


}

