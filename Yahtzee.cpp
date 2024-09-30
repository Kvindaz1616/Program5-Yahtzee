/****************************
 * HEADER
 KEVIN DIAZ
 PROGRAM 5 - YAHTZEE
 MWF 1-1:50PM
 CSC-141
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
		bool ifDicehasRolled; //checks if dice has rolled or not
	public:

		void setTrue(); //sets to ifDicehasRolled to true
		void setFalse(); //sets to ifDicehasRolled to false
		bool isOpposite(); //returns opposite of ifDicehasRolled

		//Randomly assigns a value between from 1 to 6 to the dice.
		void roll();
		int reveal();
		//The autograder will set the values directly instead of calling roll() to avoid randomness!
		void setValue(int value);

};

int Dice::reveal(){
	return value;
}

void Dice::setValue(int value){
	this->value = value;
}
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
	if (ifDicehasRolled == true){	//if true, return false
		return false;
	}
	else{	//if false, return true
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
	Dice arr[HAND_SIZE];	//array of dice
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
	for (int i=0; i < selection.length(); i++){
		int num = selection[i] - '0';
		arr[num-1].setTrue();
	}
}

Hand::Hand(){		//default constructor
	for (int i =0; i < HAND_SIZE; i++){
		arr[i].setFalse();
	}
}
//######################################################################


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
		
		//Returns the score of the lower part of the board
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

		//setScore for arrayBoard
		void setScore(int row, int score);

		//getScore for arrayBoard
		int getScore(int row);

		Game(){
			for (int i=0; i < BOARD_SIZE; i++){
			arrayBoard[i]=-1;
			}
		}

	private:
	int arrayBoard[BOARD_SIZE]; //arrayBoard
	int calculateScore; //private int for the function calcScore()
	int upperScore;	//private int for getUpperScore()
	int lowerScore;	//private int for getLowerScore()
	int bonusScore;	//private int for getBonusScore()
	int totalScore;	//private int for getTotalScore()
	bool ifPlayed;	//private bool for isPlayed()
	bool ifFinished; //private bool for isFinished()
	string starting_Hyphen_Value; //private string for play()
};

int Game::calcScore(Hand* hand, int row){//returns a score of a hand (5 dice) for given row in the board. --stash in arrayBoard for every row and return arrayboard[row]

	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;
	int counter4 = 0;
	int counter5 = 0;
	int counter6 = 0;
	int calculateScore = 0;
	
	if (row == ONES){	//go through and check if the value is 1, if so add 1 to calculateScore
		 calculateScore = 0;	//initialize score to 0
		for (int i=0; i < HAND_SIZE; i++){
			if (hand->getDice(i)->reveal() == 1){
				calculateScore += 1;
			}
		}
		return arrayBoard[ONES] = calculateScore;	//return score
	}
	 else if (row == TWOS){	//if row is 1 then it will add up all the 2's in the hand
		calculateScore = 0;	//initialize score to 0
		for (int i=0; i<HAND_SIZE; i++){ //loops through hand
			if (hand->getDice(i)->reveal() == 2){	//if dice is 2 then add 2 to score
				calculateScore += 2;
			}
		}
		return arrayBoard[TWOS] = calculateScore;	//set arrayBoard[1] to score
	}
	 else if (row == THREES){	//if row is 2 then it will add up all the 3's in the hand
		calculateScore = 0;	//initialize score to 0
		for (int i=0; i<HAND_SIZE; i++){ //loops through hand
			if (hand->getDice(i)->reveal() == 3){	//if dice is 3 then add 3 to score
				calculateScore += 3;
			}
		}
		return arrayBoard[THREES] = calculateScore;	//set arrayBoard[2] to score
	}
	else if (row == FOURS){	//if row is 3 then it will add up all the 4's in the hand
		calculateScore = 0;	//initialize score to 0
		for (int i=0; i<HAND_SIZE; i++){ //loops through hand
			if (hand->getDice(i)->reveal() == 4){	//if dice is 4 then add 4 to score
				calculateScore += 4;
			}
		}
		return arrayBoard[FOURS] = calculateScore;	//set arrayBoard[3] to score
	}
	else if (row == FIVES){	//if row is 4 then it will add up all the 5's in the hand
		calculateScore = 0;	//initialize score to 0
		for (int i=0; i<HAND_SIZE; i++){ //loops through hand
			if (hand->getDice(i)->reveal() == 5){	//if dice is 5 then add 5 to score
				calculateScore += 5;
			}
		}
		return arrayBoard[FIVES] = calculateScore;	//set arrayBoard[4] to score
	}
	else if (row == SIXES){	//loop through hand and for all sixes found add six
	     calculateScore=0;
	     for (int i=0; i<HAND_SIZE; i++){ //loops through hand
		     if (hand->getDice(i)->reveal() == 6){	//if dice is 6 then add 6 to score
			 calculateScore += 6;
		    }
	   }
	  return arrayBoard[SIXES] = calculateScore; //set arrayBoard[5] to score
	}
	else if (row == THREE_OF_KIND){	//if row is 6 then it will add up all the dice in the hand --need help
		for (int i =0; i < HAND_SIZE; i++){ //loops through hand
			if (hand->getDice(i)->reveal() == 1){
				counter++;
			}
			else if (hand->getDice(i)->reveal() == 2){
				counter2++;
			}
			else if (hand->getDice(i)->reveal() == 3){
				counter3++;
			}
			else if (hand->getDice(i)->reveal() == 4){
				counter4++;
			}
			else if (hand->getDice(i)->reveal() == 5){
				counter5++;
			}
			else if (hand->getDice(i)->reveal() == 6){
				counter6++;
			}
		}
		if (counter>=3 || counter2>=3 || counter3>=3 || counter4>=3 || counter5>=3 || counter6>=3){ //if any of the counters are greater than 3 then return the sum of the hand
			for (int i = 0; i < HAND_SIZE; i++){
				calculateScore += hand->getDice(i)->reveal();
			}
		}
		return arrayBoard[THREE_OF_KIND] = calculateScore; //set arrayBoard[6] to score
	}
	 else if (row == FOUR_OF_KIND){	//if row is 7 then it will add up all the dice in the hand --need help
			//initialize score to 0
		//go through array of counters and if any values at any index is four, then it is four of a kind
		for (int i =0; i < HAND_SIZE; i++){ //loops through hand
			if (hand->getDice(i)->reveal() == 1){
				counter++;
			}
			else if (hand->getDice(i)->reveal() == 2){
				counter2++;
			}
			else if (hand->getDice(i)->reveal() == 3){
				counter3++;
			}
			else if (hand->getDice(i)->reveal() == 4){
				counter4++;
			}
			else if (hand->getDice(i)->reveal() == 5){
				counter5++;
			}
			else if (hand->getDice(i)->reveal() == 6){
				counter6++;
			}
		}
		if (counter>=4 || counter2>=4 || counter3>=4 || counter4>=4 || counter5>=4 || counter6>=4){ //if any of the counters are 4 or more
			for (int i = 0; i < HAND_SIZE; i++){ //loop through hand
				calculateScore += hand->getDice(i)->reveal();
			}
		}
		return arrayBoard[FOUR_OF_KIND] = calculateScore;
	}
	 else if (row == FULL_HOUSE){	//if row is 8 and a pair and three of a kind
		for (int i =0; i < HAND_SIZE; i++){ //loops through hand
			if (hand->getDice(i)->reveal() == 1){
				counter++;
			}
			else if (hand->getDice(i)->reveal() == 2){
				counter2++;
			}
			else if (hand->getDice(i)->reveal() == 3){
				counter3++;
			}
			else if (hand->getDice(i)->reveal() == 4){
				counter4++;
			}
			else if (hand->getDice(i)->reveal() == 5){
				counter5++;
			}
			else if (hand->getDice(i)->reveal() == 6){
				counter6++;
			}
		}
		if ((counter == 3 || counter3 == 3 || counter4 == 3 || counter5 == 3 || counter6 == 3) && (counter2 ==2)){ //if there is a three of a kind and a pair
			calculateScore += 25; //add 25 to score
		}
		else if ((counter2 == 3 || counter3 == 3 || counter4 == 3 || counter5 == 3 || counter6 == 3) && (counter == 2)){ //if there is a three of a kind and a pair
			calculateScore += 25; //add 25 to score
		}
		else if ((counter == 3 || counter2 == 3 || counter4 == 3 || counter5 == 3 || counter6 == 3) && (counter3 ==2)){ //if there is a three of a kind and a pair
			calculateScore += 25; //add 25 to score
		}
		else if ((counter == 3 || counter2 == 3 || counter3 == 3 || counter5 == 3 || counter6 == 3) && (counter4 ==2)){ //if there is a three of a kind and a pair
			calculateScore += 25; //add 25 to score
		}
		else if ((counter == 3 || counter2 == 3 || counter3 == 3 || counter4 == 3 || counter6 == 3) && (counter5 ==2)){ //if there is a three of a kind and a pair
			calculateScore += 25; //add 25 to score
		}
		else if ((counter == 3 || counter2 == 3 || counter3 == 3 || counter4 == 3 || counter5 == 3) && (counter6 ==2)){ //if there is a three of a kind and a pair
			calculateScore += 25; //add 25 to score
		}
		else if ((counter==5)|| (counter2==5) || (counter3==5) || (counter4==5) || (counter5==5) || (counter6==5)){ //if there is a five of a kind
			calculateScore += 25; //add 25 points
		}
		ifPlayed = true;
		return arrayBoard[FULL_HOUSE] = calculateScore; //if row is 8 then it will add 25 to score
	 }
	else if (row == SMALL_STRAIGHT){ // if row is 9 and there is a small straight
		for (int i =0; i < HAND_SIZE;i++){ //go through the hand and check if there is a small straight
			if(hand->getDice(i)->reveal() == 1){
				counter++;
			}
			else if(hand->getDice(i)->reveal() == 2){
				counter2++;
			}
			else if(hand->getDice(i)->reveal() == 3){
				counter3++;
			}
			else if(hand->getDice(i)->reveal() == 4){
				counter4++;
			}
			else if(hand->getDice(i)->reveal() == 5){
				counter5++;
			}
			else if(hand->getDice(i)->reveal() == 6){
				counter6++;
			}
		}
		if (counter >= 1 && counter2 >= 1 && counter3 >= 1 && counter4 >= 1){ // 1,2,3,4
			calculateScore += 30; // add 30 points
		}
		else if (counter2 >= 1 && counter3 >= 1 && counter4 >= 1 && counter5 >= 1){ // 2,3,4,5
			calculateScore += 30; //add 30 points
		}
		else if (counter3 >= 1 && counter4 >= 1 && counter5 >= 1 && counter6 >= 1){ // 3,4,5,6
			calculateScore += 30; //if there is a small straight then it will add 30 points
		}
		return arrayBoard[SMALL_STRAIGHT] = calculateScore; //return the score
	}
	else if (row == LARGE_STRAIGHT){ // if row is 10 and there is a large straight
		for (int i =0; i < HAND_SIZE; i++){ //go through array of counters and if any values at any index is 5, then it is a large straight
			if (hand->getDice(i)->reveal() == 1){
				counter++;
			}
			else if (hand->getDice(i)->reveal() == 2){
				counter2++;
			}
			else if (hand->getDice(i)->reveal() == 3){
				counter3++;
			}
			else if (hand->getDice(i)->reveal() == 4){
				counter4++;
			}
			else if (hand->getDice(i)->reveal() == 5){
				counter5++;
			}
			else if (hand->getDice(i)->reveal() == 6){
				counter6++;
			}
		}
		if ((counter == 1 && counter2 == 1 && counter3 == 1 && counter4 == 1 && counter5 == 1)){ //if there is a 1,2,3,4,5
			calculateScore += 40; //add 40 to the score
		}
		else if ((counter2 == 1 && counter3 == 1 && counter4 == 1 && counter5 == 1 && counter6 == 1)){ //if there is a 2,3,4,5,6
			calculateScore += 40; //add 40 to the score
		}
		
		return arrayBoard[LARGE_STRAIGHT] = calculateScore; //return the score
	}

	if (row == CHANCE){
		calculateScore=0;	//initialize score to 0
		//go through array of counters and Sum of all of the dice.
		for (int i=0; i<HAND_SIZE; i++){
			calculateScore += hand->getDice(i)->reveal();
		}
		return arrayBoard[CHANCE] = calculateScore;	//set arrayBoard[11] to score
	}
	else if (row == YAHTZEE){ // if row is 12 and there is a yahtzee
		for (int i =0; i < HAND_SIZE; i++){ // go through the hand
			if (hand->getDice(i)->reveal() == 1){
				counter++;
			}
			else if (hand->getDice(i)->reveal() == 2){
				counter2++;
			}
			else if (hand->getDice(i)->reveal() == 3){
				counter3++;
			}
			else if (hand->getDice(i)->reveal() == 4){
				counter4++;
			}
			else if (hand->getDice(i)->reveal() == 5){
				counter5++;
			}
			else if (hand->getDice(i)->reveal() == 6){
				counter6++;
			}
		}
		if ((counter==5)|| (counter2==5) || (counter3==5) || (counter4==5) || (counter5==5) || (counter6==5)){ // if there is a yahtzee
			calculateScore += 50; // add 50 points
		}
		return arrayBoard[YAHTZEE] = calculateScore; // set arrayBoard[12] to score
	}
}

void Game::show(){	//standard board display
starting_Hyphen_Value = "-";
Hand hand;
	cout << "1." << setw(7) << "Ones:" << setw(14) << starting_Hyphen_Value << endl;
	cout << "2." << setw(7) << "Twos:" << setw(14) << starting_Hyphen_Value << endl;
	cout << "3." << setw(9) << "Threes:" << setw(12) << starting_Hyphen_Value << endl;
	cout << "4." << setw(8) << "Fours:" << setw(13) << starting_Hyphen_Value << endl;
	cout << "5." << setw(8) << "Fives:" << setw(13) << starting_Hyphen_Value << endl;
	cout << "6." << setw(8) << "Sixes:" << setw(13) << starting_Hyphen_Value << endl;
	cout <<setw(8) << "Sum:" << setw(15) << "0" << endl;
	cout <<setw(10) << "Bonus:" << setw(13) << "0" << endl;
	cout << "7." << setw(18) << "Three of a kind:" << setw(3) << starting_Hyphen_Value << endl;
	cout << "8." << setw(17) << "Four of a kind:" << setw(4) << starting_Hyphen_Value << endl;
	cout << "9." << setw(13) << "Full house:" << setw(8) << starting_Hyphen_Value << endl;
	cout << "10." << setw(16) << "Small straight:" << setw(4) << starting_Hyphen_Value << endl;
	cout << "11." << setw(16) << "Large straight:" << setw(4) << starting_Hyphen_Value << endl;
	cout << "12." << setw(8) << "Chance:" << setw(12) << starting_Hyphen_Value << endl;
	cout << "13." << setw(9) << "Yahtzee:" << setw(11) << starting_Hyphen_Value << endl;
	cout <<"Total:" << setw(17) << "0" << endl;
	cout <<"Hand: ";
	hand.play();
	hand.show();
	cout <<"Keep Dice (s to stop rolling): ";
}

int Game::getUpperScore(){ //get total score from ONES to SIXES (inclusive)
	for (int i=0; i<6; i++){
		upperScore += arrayBoard[i];
	}
	return upperScore;
}

int Game::getLowerScore(){ //get total score from rows 6 to 12 from int calcScore() function and return its value
	for (int i=6; i<13; i++){
		lowerScore += arrayBoard[i];
	}
	return lowerScore;
}	

int Game::getBonusScore(){	//Check upper board and having bonus correctly and if so add 35 points to upperScore
	if (upperScore >= 63){	//if upperScore is greater than or equal to 63
		bonusScore = 35;	//set bonusScore to 35
	}
	else{
		bonusScore = 0;
	}
	return bonusScore;	//return bonusScore
}

int Game::getTotalScore(){	//get the total score by adding the upper score, lower score, and bonus score -- ?????
	upperScore = getUpperScore();	//get the upper score
	lowerScore = getLowerScore();	//get the lower score
	bonusScore = getBonusScore();	//get the bonus score
	totalScore = upperScore + lowerScore + bonusScore;	//add up the upper score, lower score, and bonus score
	return totalScore;	//return the total score
}

void Game::play(Hand* hand, int row){ //Play a hand based on the selected row and updates void Game::show() -- need help
int calcScoreValue; //local variable to hold score value and store in arrayBoard[row]
calcScoreValue = calcScore(hand, row);	//get the score from the calcScore() function
arrayBoard[row] = calcScoreValue;	//set the arrayBoard[row] to the score
}

bool Game:: isFinished(){	//check to see if the game is finished
	for(int i=0; i<13; i++){
		if(arrayBoard[i] == -1){	//if the arrayBoard[i] is equal to -1 then the game is not finished
			return false;
		}
	}
	return true;	//if the arrayBoard[i] is not equal to -1 then the game is finished
}

bool Game::isPlayed(int row){//Check to see if a row has been played or not (returns true if a row has been played)
	if(arrayBoard[row] != -1){	//if the arrayBoard[row] is not equal to -1 then the row has been played
		return true;
	}
	else{
		return false;	//if the arrayBoard[row] is equal to -1 then the row has not been played
	}
}

void Game::setScore(int row, int score){ //setScore for arrayBoard
	arrayBoard[row] = score;	//set the arrayBoard[row] to the score
}

int Game::getScore(int row){	//getScore for arrayBoard
	return arrayBoard[row];
}
//#######################################################################################

//The run function is the main loop of your program
void run() {
	Game game;
	game.show();
}


//For these types of programs there exists many combinations that you might have missed. 
//The best way to check them all is to write test cases for your program. 
//Here I give you an example of checking large straight. You can design your own test cases for different parts.

/*void test_case() {
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
		cout << "check 1 for LARGE STRAIGHT passed\n"; 
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
		cout << "check 2 for LARGE STRAIGHT passed\n"; 
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
		cout << "check 3 FOR LARGE STRAIGHT passed\n"; 
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
		cout << "check 4 FOR LARGE STRAIGHT passed\n"; 
	}

	hand->getDice(0)->setValue(1);
	hand->getDice(1)->setValue(2);
	hand->getDice(2)->setValue(3);
	hand->getDice(3)->setValue(4);
	hand->getDice(4)->setValue(5);
	
	bool check5 = true;
	if (game.calcScore(hand, ONES) != 1) {
		check5 = false;
	}
	if (check5) {
		cout << "check 1 for ONES passed\n"; 
	}

	hand->getDice(0)->setValue(1);
	hand->getDice(1)->setValue(2);
	hand->getDice(2)->setValue(3);
	hand->getDice(3)->setValue(4);
	hand->getDice(4)->setValue(5);
	
	bool check6 = true;
	if (game.calcScore(hand, TWOS) != 2) {
		check6 = false;
	}
	if (check6) {
		cout << "check 1 for TWOS passed\n"; 
	}

	hand->getDice(0)->setValue(1);
	hand->getDice(1)->setValue(2);
	hand->getDice(2)->setValue(3);
	hand->getDice(3)->setValue(4);
	hand->getDice(4)->setValue(5);
	
	bool check7 = true;
	if (game.calcScore(hand, THREES) != 3) {
		check7 = false;
	}
	if (check7) {
		cout << "check 1 for THREES passed\n"; 
	}

	hand->getDice(0)->setValue(1);
	hand->getDice(1)->setValue(2);
	hand->getDice(2)->setValue(3);
	hand->getDice(3)->setValue(4);
	hand->getDice(4)->setValue(5);
	
	bool check8 = true;
	if (game.calcScore(hand, FOURS) != 4) {
		check8 = false;
	}
	if (check8) {
		cout << "check 1 for FOURS passed\n"; 
	}

	hand->getDice(0)->setValue(1);
	hand->getDice(1)->setValue(2);
	hand->getDice(2)->setValue(3);
	hand->getDice(3)->setValue(4);
	hand->getDice(4)->setValue(5);
	
	bool check9 = true;
	if (game.calcScore(hand, FIVES) != 5) {
		check9 = false;
	}
	if (check9) {
		cout << "check 1 for FIVES passed\n"; 
	}

	hand->getDice(0)->setValue(4);
	hand->getDice(1)->setValue(3);
	hand->getDice(2)->setValue(6);
	hand->getDice(3)->setValue(4);
	hand->getDice(4)->setValue(5);
	
	bool check10 = true;
	if (game.calcScore(hand, SIXES) != 6) {
		check10 = false;
	}
	if (check10) {
		cout << "check 1 for SIXES passed\n"; 
	}

	hand->getDice(0)->setValue(4);
	hand->getDice(1)->setValue(3);
	hand->getDice(2)->setValue(6);
	hand->getDice(3)->setValue(4);
	hand->getDice(4)->setValue(5);
	
	bool check11 = true;
	if (game.calcScore(hand, SMALL_STRAIGHT) != 30) {
		check11 = false;
	}
	if (check11) {
		cout << "check 1 for SMALL STRAIGHT passed\n"; 
	}

	hand->getDice(0)->setValue(5);
	hand->getDice(1)->setValue(5);
	hand->getDice(2)->setValue(5);
	hand->getDice(3)->setValue(5);
	hand->getDice(4)->setValue(5);
	
	bool check12 = true;
	if (game.calcScore(hand, SMALL_STRAIGHT) != 0) {
		check12 = false;
	}
	if (check12){
		cout << "check 2 for SMALL STRAIGHT passed\n";
	}

	hand->getDice(0)->setValue(2);
	hand->getDice(0)->setValue(2);
	hand->getDice(0)->setValue(3);
	hand->getDice(0)->setValue(3);
	hand->getDice(0)->setValue(3);


	bool check13 = true;
	if (game.calcScore(hand, FULL_HOUSE) !=25){
		check13 = false;
	}
	if (check13){
		cout << "check 1 for FULL HOUSE passed\n";
	}

	hand->getDice(0)->setValue(3);
	hand->getDice(0)->setValue(3);
	hand->getDice(0)->setValue(3);
	hand->getDice(0)->setValue(1);
	hand->getDice(0)->setValue(6);

	bool check14 = true;
	if (game.calcScore(hand, THREE_OF_KIND)!=0){
		check14=false;
	}
	if (check14){
		cout << "check 1 for THREE OF A KIND passed\n";
	}

	hand->getDice(0)->setValue(2);
	hand->getDice(0)->setValue(2);
	hand->getDice(0)->setValue(2);
	hand->getDice(0)->setValue(3);
	hand->getDice(0)->setValue(2);


	bool check15 = true;
	if (game.calcScore(hand, FOUR_OF_KIND) !=0){
		check15=false;
	}
	if (check15){
		cout << "check 1 for FOUR OF A KIND passed\n";
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
