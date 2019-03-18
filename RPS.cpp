#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ENUMERATIONS

enum Weapon { ROCK, PAPER, SCISSORS, BAD_WEAPON };



// FUNCTION DECLARATIONS

void print_instructions();
Weapon get_player_weapon();
Weapon get_computer_weapon();
string get_weapon_name(Weapon);
string get_winning_message(Weapon);
string get_losing_message(Weapon);
Weapon get_winning_weapon(Weapon);
int randint(int);



// FUNCTION DEFINITIONS

int main() {

	/* Seed pseudorandom number generator */

	srand( time(NULL) );

	/* Define state variables */

	Weapon computer_weapon;
	Weapon player_weapon;

	bool game_over = false;

	char play_again = 'N';

	int game_count = 0;
	int win_count = 0;

	/* Print Instructions */

	print_instructions();

	/* Main Game Loop */

	while ( !game_over ) {

		/* Increment Game Counter (once per turn) */

		++game_count;

		/* Get Player/Computer Weapon Choices */

		computer_weapon = get_computer_weapon();
		player_weapon = get_player_weapon();

		/* Print Weapon Choices */

		cout << "\nPlayer Picked: " << get_weapon_name(player_weapon) << '\n';
		cout << "Computer Picked: " << get_weapon_name(computer_weapon) << '\n';

		/* Check Draw, Win, or Lose */

		if ( player_weapon == computer_weapon ) {

			/* Draw */

			cout << "IT'S A DRAW!\n\n";

		}

		else if ( player_weapon == get_winning_weapon(computer_weapon) ) {

			/* Player Wins (increment win counter) */

			cout << "PLAYER WINS: " << get_winning_message(player_weapon) << "\n\n";
			++win_count;

		}

		else {

			/* Player Loses */

			cout << "COMPUTER WINS: " << get_losing_message(player_weapon) << "\n\n";

		}

		/* Prompt User to Play Again */

		cout << "PLAY AGAIN? ('Y' or 'N'): ";
		cin >> play_again;

		play_again = toupper(play_again);

		if ( play_again == 'N' ) {

			/* If No, Flip "Game Over" Flag */

			game_over = true;

		}

	}

	/* Game is Over: Output Game/Win Counters */

	cout << "\nYou won " << win_count << " out of " << game_count << " game(s)!\n";
	cout << "THANKS FOR PLAYING!\n\n";

	return 0;

} // End main()



// GET PLAYER WEAPON

Weapon get_player_weapon() {

	Weapon player_weapon;
	char player_choice;

	bool weapon_selected = false;

	/* Loop until valid weapon selected */

	while ( !weapon_selected ) {

		cout << "Choose Weapon ('R', 'P', or 'S'): ";

		cin >> player_choice;

		player_choice = toupper( player_choice );

		switch ( player_choice ) {

			case 'R': /* ROCK */
				player_weapon = ROCK;
				weapon_selected = true;
				break;
			case 'P': /* PAPER */
				player_weapon = PAPER;
				weapon_selected = true;
				break;
			case 'S': /* SCISSORS */
				player_weapon = SCISSORS;
				weapon_selected = true;
				break;
			default:
				cout << "I'm sorry, but I don't recognize that choice!  Please try again!\n";
				break;

		}

	}

	return player_weapon;

} // End get_player_weapon()



// GET COMPUTER WEAPON

Weapon get_computer_weapon() {

	Weapon computer_weapon;

	/* Choose random number between 0 and 2 */

	int computer_choice = randint(3);

	/* Select corresponding Weapon value */

	switch ( computer_choice ) {

		case 0: /* ROCK */
			computer_weapon = ROCK;
			break;
		case 1: /* PAPER */
			computer_weapon = PAPER;
			break;
		case 2: /* SCISSORS */
			computer_weapon = SCISSORS;
			break;
		default: /* In case something goes wrong with randint() */
			computer_weapon = BAD_WEAPON;
	}

	/* Return weapon choice */

	return computer_weapon;

} // End get_computer_weapon()



// GET WEAPON NAME

string get_weapon_name(Weapon weapon) {

	/* Returns name of Weapon object as a string */

	string name;

	switch ( weapon ) {

		case ROCK: /* ROCK */
			name = "ROCK";
			break;
		case PAPER: /* PAPER */
			name = "PAPER";
			break;
		case SCISSORS: /* SCISSORS */
			name = "SCISSORS";
			break;
		default:
			name = "UNKNOWN";

	}

	return name;

} // End get_weapon_name()



// GET WINNING MESSAGE

string get_winning_message(Weapon weapon) {

	/* For any Weapon object, returns the corresponding message if player wins */

	string message;

	switch ( weapon ) {

		case ROCK: /* ROCK */
			message = "ROCK BLUNTS SCISSORS";
			break;
		case PAPER: /* PAPER */
			message = "PAPER WRAPS ROCK";
			break;
		case SCISSORS: /* SCISSORS */
			message = "SCISSORS CUTS PAPER";
			break;
		default:
			message = "*** ERROR: UNKNOWN WEAPON! ***";

	}

	return message;

} // End get_winning_message()



// GET LOSING MESSAGE

string get_losing_message(Weapon weapon) {

	/* For any Weapon object, returns the corresponding message if player loses */

	string message;

	switch ( weapon ) {

		case ROCK: /* ROCK */
			message = "PAPER WRAPS ROCK";
			break;
		case PAPER: /* PAPER */
			message = "SCISSORS CUTS PAPER";
			break;
		case SCISSORS: /* SCISSORS */
			message = "ROCK BLUNTS SCISSORS";
			break;
		default:
			message = "*** ERROR: UNKNOWN WEAPON! ***";

	}

	return message;

} // End get_losing_message()



// GET WINNING WEAPON

Weapon get_winning_weapon(Weapon weapon) {

	/* For every possible weapon choice by the computer, return the weapon
       that would be needed by the player to defeat it */

	Weapon winning_weapon;

	switch ( weapon ) {

		case ROCK: /* ROCK */
			winning_weapon = PAPER;
			break;
		case PAPER: /* PAPER */
			winning_weapon = SCISSORS;
			break;
		case SCISSORS: /* SCISSORS */
			winning_weapon = ROCK;
			break;
		default: /* In case something went wrong with get_computer_weapon() */
			winning_weapon = BAD_WEAPON;

	}

	return winning_weapon;

} // End get_winning_weapon()



// PRINT INSTRUCTIONS

void print_instructions() {

	/* Prints the game instructions */

	cout << "\nWELCOME TO PAPER-ROCK-SCISSORS!\n\n";

	cout << "This is a game for two players, which you will be playing\n";

	cout << "against the computer.  With each game, both players will\n";

	cout << "select one of the following weapons: PAPER, ROCK, or SCISSORS.\n";

	cout << "The winner is determined as follows:\n\n";

	cout << "* If both players select the same weapon, the game is a tie.\n";

	cout << "* ROCK blunts SCISSORS, so the player who selects ROCK wins.\n";

	cout << "* PAPER wraps ROCK, so the player who selects PAPER wins.\n";

	cout << "* SCISSORS cuts PAPER, so the player who selects SCISSORS wins.\n\n";

	cout << "With each turn, select 'R' for ROCK, 'P' for PAPER, or 'S' for\n";

	cout << "SCISSORS, and then press ENTER.  You may quit at any time.\n\n";

} // End print_instructions()



// RANDOM NUMBER GENERATOR

int randint(int max) {

	return ( rand() % max );

} // End randint()
