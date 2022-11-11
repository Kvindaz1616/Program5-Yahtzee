/****************************
 * HEADER
 KEVIN DIAZ
 PROGRAM 5 - YAHTZEE
 MWF 1-1:50PM
 CSC-141 - UIC - FALL 2022
 * Starter code provided by: Dr. Sara Riazi
 * ***************************/


#include <string>
#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
#include <iomanip>	//setw
#include <cstdlib> // for rand() and srand()
#include <ctime> // for randomization

using namespace std;



//#################################################################################################



class Dice{
	private:
		int value;
		bool ifDicehasRolled;
	public:

		void setTrue(); //sets to ifDicehasRolled to true
		void setFalse(); //sets to ifDicehasRolled to false
		bool isOpposite(); //returns opposite of ifDicehasRolled

		//Randomly assigns a value between from 1 to 6 to the dice.
		void roll();
		int reveal() {
            return value;
            }
		//The autograder will set the values directly instead of calling roll() to avoid randomness!
		void setValue(int value) {
            this->value = value;
            }

};

void Dice::roll(){          //rolls a random value between 1-6 & assigns it
    value = (rand()% 6) + 1;  
}
void Dice::setTrue(){		//sets to ifDicehasRolled to true
	ifDicehasRolled = true;
}
void Dice::setFalse(){		//sets to ifDicehasRolled to false
	ifDicehasRolled = false;
}
bool Dice::isOpposite(){	//returns opposite of ifDicehasRolled
	if (ifDicehasRolled == true){
		return false;
	}
	else{
		return true;
	}
}
//#################################################################################################

const int HAND_SIZE = 5;

class Hand {
	public:

		//Display the value of the five dice
		void show();	//shows five dice
		void play();	//roll dice
		Dice* getDice(int diceNum); //sets size of array & return array
		
		//selection is the string of dice numbers that the player wants to keep.
		//For example, "125" means that player wants to keep the first, second, and fifth dice, and roll the rest.
		void setSelection(string selection);	//loop thrugh string and set each number to integer 

		Hand();	//default constructor - setting all values to false by looping through arr[]
	
	private:
	Dice arr[HAND_SIZE];
};

void Hand::show(){	//shows five dice
	for (int i=0; i<HAND_SIZE; i++){
		cout << arr[i].reveal() << " ";
	}
	cout << endl;
}

void Hand::play() { //loop through arr and check to see if bool return True & roll dice/ if False set position to arr to false - No if/else
for (int i=0; i < HAND_SIZE; i++){
	if (arr[i].isOpposite() == true){
		arr[i].roll();
	}
}
}

Dice* Hand::getDice(int diceNum){	//sets size of array & return array using diceNum
	return &arr[diceNum];
}

void Hand::setSelection(string selection){	//loop thrugh string and set each number to integer
	for (int i=0; i<selection.size(); i++){
		int num;
		num = selection[i] - '0';
	}
}

Hand::Hand(){		//default constructor
	for (int i =0; i < HAND_SIZE; i++){
		arr[i].setFalse();
	}
}
//######################################################################

/*
//List of rows in the board
const int ONES = 0;
const int TWOS = 1;
const int THREES = 2;
const int FOURS = 3;
const int FIVES = 4;
const int SIXES = 5;
const int THREE_OF_KIND = 6;
const int FOUR_OF_KIND = 7;
const int FULL_HOUSE = 8;
const int SMALL_STRAIGHT = 9;
const int LARGE_STRAIGHT = 10;
const int CHANCE = 11;
const int YAHTZEE = 12;

const int BOARD_SIZE=13; 

class Game {

	public:
		//calcScore returns a score of a hand (5 dice) for given row in the board. 
		//Note the rows are indexed from zero. 
		//For example if the hand is 2 1 1 5 1 then calcScore(hand, ONES) returns 3 and  calcScore(hand, TWOS) returns 2.
		int calcScore(Hand* hand, int row); 
		
		
		//Display the board
		void show();
		

		//Returns the score of the upper part of the board
		int getUpperScore();
		
		//Returns the score of the upper part of the board
		int getLowerScore();
	

		//Returns the bonus points
		int getBonusScore();

		//Returns the total score
		int getTotalScore();

		//Play a hand based on the selected row --update board
		void play(Hand* hand, int row);

		
		//Check to see if a row has been played or not (returns true if a row has been played)
		bool isPlayed(int row);
		
		//Check to see if all rows haven been played or not (returns true if all rows have been played)
		bool isFinished();


	private:
	int calcScore;
	int upperScore;
	int lowerScore;
	int bonusScore;
	int totalScore;
	bool isPlayed;
	bool isFinished;
};

int Game::calcScore(Hand* hand, int row){
}


void Game::show(){
	cout << "1." << setw(4) << "Ones:" << setw(14) << "-" << endl;
	cout << "2." << setw(4) << "Twos:" << setw(14) << "-" << endl;
	cout << "3." << setw(4) << "Threes:" << setw(12) << "-" << endl;
	cout << "4." << setw(4) << "Fours:" << setw(13) << "-" << endl;
	cout << "5." << setw(4) << "Fives:" << setw(13) << "-" << endl;
	cout << "6." << setw(4) << "Sixes:" << setw(13) << "-" << endl;
	cout <<setw(5) << "Sum:" << setw(15) << "0" << endl;
	cout <<setw(5) << "Bonus:" << setw(13) << "0" << endl;
	cout << "7." << setw(5) << "Three of a kind:" << setw(8) << "-" << endl;
	cout << "8." << setw(5) << "Four of a kind:" << setw(9) << "-" << endl;
	cout << "9." << setw(5) << "Full house:" << setw(11) << "-" << endl;
	cout << "10." << setw(4) << "Small straight:" << setw(9) << "-" << endl;
	cout << "11." << setw(4) << "Large straight:" << setw(9) << "-" << endl;
	cout << "12." << setw(4) << "Chance:" << setw(12) << "-" << endl;
	cout << "13." << setw(4) << "Yahtzee:" << setw(12) << "-" << endl;
	cout <<"Total:" << setw(13) << "0" << endl;
	cout <<"Hand: ";
}
*/


//#######################################################################################

//The run function is the main loop of your program
void run() {
Hand test;
test.play();
test.play();
test.play();
test.show();
}


//For these types of programs there exists many combinations that you might have missed. 
//The best way to check them all is to write test cases for your program. 
//Here I give you an example of checking large straight. You can design your own test cases for different parts.
/*
void test_case() {
	Game game;
	Hand* hand = new Hand();
	hand->getDice(0)->setValue(1);
	hand->getDice(1)->setValue(2);
	hand->getDice(2)->setValue(3);
	hand->getDice(3)->setValue(4);
	hand->getDice(4)->setValue(5);
	
	bool check1 = true;
	if (game.calcScore(hand, LARGE_STRAIGHT) != 40) {
		check1 = false;
	}
	if (check1) {
		cout << "check 1 passed\n"; 
	}

	hand->getDice(0)->setValue(2);
	hand->getDice(1)->setValue(6);
	hand->getDice(2)->setValue(4);
	hand->getDice(3)->setValue(3);
	hand->getDice(4)->setValue(5);
	
	bool check2 = true;
	if (game.calcScore(hand, LARGE_STRAIGHT) != 40) {
		check2 = false;
	}

	if (check2) {
		cout << "check 2 passed\n"; 
	}

	hand->getDice(0)->setValue(3);
	hand->getDice(1)->setValue(2);
	hand->getDice(2)->setValue(5);
	hand->getDice(3)->setValue(6);
	hand->getDice(4)->setValue(3);

	bool check3 = true;
	if (game.calcScore(hand, LARGE_STRAIGHT) != 0) {
		check3 = false;
	}

	if (check3) {
		cout << "check 3 passed\n"; 
	}

	hand->getDice(0)->setValue(1);
	hand->getDice(1)->setValue(2);
	hand->getDice(2)->setValue(3);
	hand->getDice(3)->setValue(4);
	hand->getDice(4)->setValue(6);

	bool check4 = true;
	if (game.calcScore(hand, LARGE_STRAIGHT) != 0) {
		check4 = false;
	}

	if (check4) {
		cout << "check 4 passed\n"; 
	}


}
*/
// THE AUTOGRADER WILL REPLACE THE MAIN FUNCTION. 
// DO NOT ADD ANY LOGIC OF YOUR PROGRAM HERE.
int main() {
	
	run();
	//test_case();
	return 0;
}