# Rock-Paper-Scissors
I wrote a simple program which implements the classic game of “Rock, Paper, Scissors.”  For those unfamiliar with the game: two players (yourself and the computer, in this case) choose at random from among three “weapons”: a piece of paper, a rock, and a pair of scissors.  Both players present their weapons, and depending on the weapons selected, one player is declared a winner, or else the game is declared a draw:

•	If both players select the same weapon, the game is a tie.

•	ROCK blunts SCISSORS, so the player who selects ROCK wins.

•	PAPER wraps ROCK, so the player who selects PAPER wins.

•	SCISSORS cuts PAPER, so the player who selects SCISSORS wins.

The version of this game should select one of the three weapons at random (this is the computer's weapon), and prompt the player to select his or her weapon by entering either “P”, “R”, or “S” at the console.  The game should then compare weapons, determine the winner (if any), and print the outcome to the screen.  The outcome should indicate which player is the winner, and should also explain why the winner was chosen (see the rules outlined above and the sample output for examples).

The output of the program is the following:

WELCOME TO PAPER-ROCK-SCISSORS!

This is a game for two players, which you will be playing
against the computer.  With each game, both players will
select one of the following weapons: PAPER, ROCK, or SCISSORS.
The winner is determined as follows:

* If both players select the same weapon, the game is a tie.
* ROCK blunts SCISSORS, so the player who selects ROCK wins.
* PAPER wraps ROCK, so the player who selects PAPER wins.
* SCISSORS cuts PAPER, so the player who selects SCISSORS wins.

With each turn, select 'R' for ROCK, 'P' for PAPER, or 'S' for
SCISSORS, and then press ENTER.  You may quit at any time.

Choose Weapon ('R', 'P', or 'S'): r

Player Picked: ROCK
Computer Picked: PAPER
COMPUTER WINS: PAPER WRAPS ROCK

PLAY AGAIN? ('Y' or 'N'): y
Choose Weapon ('R', 'P', or 'S'): p

Player Picked: PAPER
Computer Picked: ROCK
PLAYER WINS: PAPER WRAPS ROCK

PLAY AGAIN? ('Y' or 'N'): y
Choose Weapon ('R', 'P', or 'S'): s

Player Picked: SCISSORS
Computer Picked: PAPER
PLAYER WINS: SCISSORS CUTS PAPER

PLAY AGAIN? ('Y' or 'N'): y
Choose Weapon ('R', 'P', or 'S'): p

Player Picked: PAPER
Computer Picked: SCISSORS
COMPUTER WINS: SCISSORS CUTS PAPER

PLAY AGAIN? ('Y' or 'N'): y
Choose Weapon ('R', 'P', or 'S'): r

Player Picked: ROCK
Computer Picked: SCISSORS
PLAYER WINS: ROCK BLUNTS SCISSORS

PLAY AGAIN? ('Y' or 'N'): n

You won 3 out of 5 game(s)!
THANKS FOR PLAYING!
