#include <random>
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

HANDLE red = GetStdHandle(STD_OUTPUT_HANDLE);



// Array that can be shared among all functions innit
int USERINPUT[2]; // holds the row and column that user choose
int USERINPUT1[2]; // remembers the second position that the user has entered
int MEMORY[2][18][2];
int PAIRSCORRECT = 17;
string PlayerName;




// Creating UI board
char board[20][20] = {				{'*' , '*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' , '*' , '*' , '*' , '*'},
									{'*','  ','  ' ,'  ' ,'  ' ,'  ','  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' , '*'},
									{'*','   ' ,'   ' , '   ',  '1' , '  ',  '2' , '  ' , '3' , '   ', '4' , '  ', '5' , '  ' , '6','  ' , '  ','  ' , '*'},
									{'*',  '    ', '1' , '|' ,  '-' , '|', '-', '|','-', '|' , '-' , '|' ,  '-' ,'|'  , '-' , '|' , '  ' ,'  ' ,'*'},
									{'*','   ', '2', '|' ,  '-' , '|', '-', '|','-', '|' , '-' , '|' ,  '-' ,'|'  , '-' , '|'   , '  ' ,'  ', '*'},
									{'*','   ', '3', '|' ,  '-' , '|', '-', '|','-', '|' , '-' , '|' ,  '-' ,'|'  , '-' , '|'   , '  ','  ' , '*'},
									{'*','   ', '4', '|' ,  '-' , '|', '-', '|','-', '|' , '-' , '|' ,  '-' ,'|'  , '-' , '|'   ,'  ', '  '  , '*'},
									{'*','   ', '5', '|' ,  '-' , '|', '-', '|','-', '|' , '-' , '|' ,  '-' ,'|'  , '-' , '|'   ,'  ' ,'  ' , '*'},
									{'*','   ', '6', '|' ,  '-' , '|', '-', '|','-', '|' , '-' , '|' ,  '-' ,'|'  , '-' , '|'   ,'  ' ,'  ' , '*'},
									{'*','  ','  ' ,'  ' ,'  ' ,'  ','  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' , '*'},
									{'*','  ','  ' ,'  ' ,'  ' ,'  ','  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' ,'  ' , '*'},
									{'*' , '*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' ,'*' , '*' , '*' , '*', '*'},
					 };



int randomNumber(float smallest, float biggest) // function which gives a random number from minimum to max value
{

	return(int)(((float)rand() / (float)RAND_MAX) * (biggest - smallest) + smallest); // rand gives number between 0 to 1
																					  // dividing it by randmax gives us a number between 0 and 1
																					

}

void placeAlpha() //places alphabets at random positions and check whther the alphabet has appeared more than 2 times
{
	char storage[18]; 

	for (int i = 0; i < 18; i++) // first for loop generates a random alphabet
	{
		char Result = (char)randomNumber(97, 122); // generate letter
		storage[i] = Result; // store the alphabet in an array so that it "remember" what the alphabet was
		int check = 0; // to count how many times the integer/alphabet has appeared
	for (int j = 0; j < 18; j++) // second for loop check whether the alphabet has existed before
	{
		if (storage[j] == Result)
		{
			check++; // check will be flipped since bool can only be true to false
		}
	}
	if (check > 1)
	{

		i--; // repeats this run of the for loop if there is 2 or more of the same pairs
	}



	}

	for (int k = 0; k < 18; k++) // This for loop will put our random letters into the board defined at the start of the 
								 // program but not PRINTING onto the board just loading
	{

		for (int distribute = 0; distribute < 2; distribute++)
		{
			int row = randomNumber(0, 6);  // random coordinates
			int column = randomNumber(0, 6); // random coordinates
			if (board[row + 3][(column * 2) + 4] == '-') // checking whether the space is occupied or not
			{
				board[row + 3][(column * 2) + 4] = storage[k]; 
			}
			else
			{
				distribute--; // repeats the loop and will random another coordinate for the letter avoiding conflict
			}

		}

	}

}


void printboard() // loops through whole array
{
	for (char i = 0; i < 20; i++) // handles the rows
	{
		for (char j = 0; j < 20; j++) // handles the column
		{
			if (board[i][j] >= 97 && board[i][j] <= 122) 
			{
				if (((USERINPUT[0] - 1) + 3 == i && (USERINPUT[1] - 1) * 2 + 4 == j || (USERINPUT1[0] - 1) + 3 == i && (USERINPUT1[1] - 1) * 2 + 4 == j))
					// The first row is the third of row of the playable board, so since players 
											// want to start the board from 1 we minus 2 to get 1 from 3					
				{
					SetConsoleTextAttribute(red, 4); // changes color to red 
					cout << board[i][j] << "    ";
					SetConsoleTextAttribute(red, 15); // setting text color to white if not everything that
														// user will enter will be red 
				}
				else
				{
					for (int k = 0; k < 18; k++)
					{
						if (((MEMORY[0][k][0]-1)+3  == i && (MEMORY[0][k][1]-1) * 2 + 4 == j) || ((MEMORY[1][k][0] -1) + 3  == i && (MEMORY[1][k][1]-1)* 2 + 4 == j))
						{
							SetConsoleTextAttribute(red, 4);
							break;
						}
						else
						{
							SetConsoleTextAttribute(red, 0);
						}
					}
					cout << board[i][j] << "    ";
					SetConsoleTextAttribute(red, 15);
				}
			}
			else
			{
				SetConsoleTextAttribute(red, 4); // Makes the * UI red color
				cout << board[i][j] << "    ";
				SetConsoleTextAttribute(red, 15); // Then again, making it white so that text user has entered
													// will always be white
			}

		}
		cout << endl; // creates a new line for the row only so that the board will not be just one staight line
	}
}


void AskPlayer() // AskPlayer function serves to handle what user has inputted in the row and column question
{
	int Ask;
	int Ask1;
	cout << "Enter Row:" << endl;
	cin >> Ask;
	cout << "Enter Column:" << endl;
	cin >> Ask1;
	USERINPUT[0] = Ask;
	USERINPUT[1] = Ask1;
	printboard();  // have to print the board because if i dont the the user will be asked for the row and column 2 times without
					// the board printing
	cout << "Enter Row:" << endl;
	cin >> Ask;
	cout << "Enter Column:" << endl;
	cin >> Ask1;
	USERINPUT1[0] = Ask;
	USERINPUT1[1] = Ask1;

}

void MatchCorrectly()
{	
	// if statement to check whether the user is within playing grounds	so can compare matching 
	if (board[(USERINPUT[0] - 1) + 3][(USERINPUT[1] - 1) * 2 + 4] == board[(USERINPUT1[0] - 1) + 3][(USERINPUT1[1] - 1) * 2 + 4])
	{
		cout << "Match Found! " << endl;
		MEMORY[0][PAIRSCORRECT][0] = USERINPUT[0];
		MEMORY[0][PAIRSCORRECT][1] = USERINPUT[1];
		MEMORY[1][PAIRSCORRECT][0] = USERINPUT1[0];
		MEMORY[1][PAIRSCORRECT][1] = USERINPUT1[1];
		PAIRSCORRECT++;
		
	}
	else
	{
		cout << "Oops, you didn't match correctly! Try again!" << endl;
	}
	USERINPUT[0] = 0;
	USERINPUT[1] = 0;
	USERINPUT1[0] = 0;
	USERINPUT1[1] = 0;
}


bool PlayerWin()
{
	if (PAIRSCORRECT == 18)
	{
		cout <<
"	  ,..                      ,.................,,.     .,,,,,,,..........,,,,*/\n"<<
"        .                 .........,....,...........   .,,,.     .,,,,,,....... \n"<<
"                         .. ....,.,,.,,,,...,,.,........,....           ..,,,,,,\n"<<
"                      .....,.,,,,,,*,*,,*,,,,,*,,,,,.... ..,.......            ,\n"<<
"                     .....,,.,,,*,*,******,****,**,**,.,.       ..,.......    ,,\n"<<
"                    .,,,,,,********/////(//(////*//(//*,..             ..,,,....\n"<<
"                   .,/((((###########%########(((((((((/,,.                  ...\n"<<
"                   .*(((((#########%%%%%%%#####((((((((///*                     \n"<<
"                   ,/((((#######%%%%%%%%%%%%#####((((((///*                     \n"<<
"                   ,/((((#####%%%%%%%%%%%%%%%###((((((((////*.                  \n"<<
"                   ./(((######%%%%%%%%%%%%%%%%#####(((((////*                   \n"<<
"                   /(((#######%%%%%%%%%%%%%%%%##//*////((//(/                   \n"<<
"                    .((#####%%%%%%%%%%%%%%%#(//(#%%###(((/((/        ....       \n"<<
"                     */((//////((##%%%%%%##(#######(####((((,                   \n"<<
"                     *(((((#(/#%#####%%%####%&##%%######(((#,                   \n"<<
"                      (#####%%%%%%###%%%#########%%%%%##(/*.                    \n"<<
"...                   ,###%%%%%%%####%%%####%%%%&%%%%##((/.                     \n"<<
".....                ../(##%%%%%%####%%%%##(##%%%%%%##((//.                     \n"<<
".............,*///*///(/((###%%%%###%&&&%%%####%%%%%#(((///                     \n"<<
".........,*//(//////((((((((##%%##%%%%&&%%%%###%%%##((((///(*.                  \n"<<
".......,/////(((((((((((((/(((######(####%%#########((////(%(////,.             \n"<<
".......*//((##########((((((/(((##((//(#####(###(((((/////#%((##((((/**,        \n"<<
".....,*/((######%%%###(((((((/((((##((###((/(#####((/////(&#(##%%%###((//**.    \n"<<
".....,/((((######%##(((((((((((#((###%%%%%%%##(((((////(%%((###########((///**  \n"<<
".....,/(((############((((((((((#/(((((((/*/(((##(////##(#####(((////////////***\n"<<
".....,/(((((((###############(((((#((//((/////*((((%#((##((((///(((((((((((((///\n"<<
",....,,//(((((###################(((#/,,*,,,,,*#((((((((((((/(((################\n"<<
"...,,,***/((((########################((((((((((((((#####((//(((##%%%%%%%#######\n"<<
",,,,,****/(((##################%%%%####((((((############((((((###%%%%%%%%%%%%%%\n"<<
",..,,****/((###################%%%%%##(((###############((((########%%%%%%%%%%%%\n"<<
",,.,*****/(((####################%%##################################%%%%%%%%%%%\n"<<
",,,*/*////(((#######################(((#############################%%%%%###%%%%\n"<<
",,/////////(((#####################(((##############################%%%#########\n"<<
",*/((((///*/((##########%%########((((((#######################(((((##((//((/(((\n"<<
",/((((((((///((#######%%%%%%%######((((#######################(((//////(((((((((\n"<<
",/((((((((/////((#########%%%#####((((######################(((((/////((((((((((\n"<<
",*/((((((///*,,/(((##############(((###############((((((((((((/////*(((((((##(#\n"<<
",,*///////***,..,//((((((##((((#((((((#########(((((((((((//////*////(((((((####\n"<<
",,**////****,,,.,/////(((((((((#((/(((((#((((((((((((((//////*////(((((((((#####\n"<<
",,**//////*,.,,,*////((###%#####((//((((((((((((((((///////////(((((((((((######\n"<<
",,***////**,,,,,**////((##%%%%%%%%#(/((((((((//////////////((((((((((((((#######\n"<<
",,**///****,,,,,***/(((/((((##########((((((((/(///////////////////////((####%%%\n"<<
"****/////*,,,,,*///*/((((((((((((((#######((((((((((((((((///*****,,,,,((####%%%\n"<<
"****/(///*,,,*//*/////(((((((((((((((((((#####(((((((/(////////*,,,,,,,*(###%%%%\n"<<
"*****((//**,**#/,///((///(((((((((((###((((((//////(/////(///*,,,,,,,,,,(###%%%%\n"<<
"****/((//,*/**(%(/////(((((((((((((((########((((/(((((((//**,,,,,,,,,,,,(#%%%%&\n"<<
"****/(/****/*/*(%%#////((((((((((((((((((((((/////////////**,,,,,,,,,,,,,/##%%%&\n"<<
"***********///*//#%(//((((((((((((((((((((//(/(((((((/////**,,,,,,,,,,,,,,(#%%%%\n"<<
"************///*///##///((((((##(((((((((((((((((((((////**,,,,,,,,,,,,,,,,##%%%\n"<<
"************/////////(%////((###(((((((((((((((((((((///*/,,,,**,,,,,,,,,,,,#%%%\n";
		cout << "WOW  congrats  " << PlayerName <<  ", really, that's very cool. i just told everyone in my family about it, everybody thinks that's very impressive and asked me to congratulate you.they want to speak to you in person, if possible, to give you their regards.  " <<  endl;
		return true;
	}
	return false;
}

void AskPlayerName()
{

	cout << "Enter your name:  " << endl;
	getline(cin, PlayerName);


}


