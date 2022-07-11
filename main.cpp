#include <iostream>
#include <string>
#include "functions.h"
using namespace std;



int main()
{
	srand(1); // Making the seed number 1 makes the letters in the board the same each time
	cout << "*****************" << "Welcome to the 6x6 matching game!" << "*******************" << endl; 
	placeAlpha();
	AskPlayerName();
	while (!PlayerWin()) 
	{
			
			printboard();
			AskPlayer();
			MatchCorrectly();

	}
}




	




