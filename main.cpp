#include <iostream>
#include <string>
#include <cmath>
#include <random>

/*
This program will help you profit at the Schedule I casino game,
Ride the Bus

It will calculate the odds for rounds 2 and 3 and tell you what to pick
As it is currently undetermined whether Schedule I emulates a single deck,
or if all cards are equally likely to be drawn, the latter is assumed
for simplicity's sake.

It's important to note that, theoretically, none of the rounds are profitable in the long run
(assuming the game deals entirely fair, which it very well might not be, as the game might
intentionally give the player hands with better probabilities for fun's sake.)
*/

bool isInputValid(int input);
bool askToContinue();
void inputValue();
double round2_percentage(int card1_value);
double round3_percentage(int card1_value, int card2_value);
int input;

int main() {
  bool playAgain = true;

  while (playAgain) {
    // J = 11, Q = 12, K = 13, A = 14
    // note, we are assuming that all card values are equally likely to be drawn next
    std::cout << "\n=== RIDE THE BUS HELPER ===\n";
    std::cout << "Pick either Red or Black; it doesn't matter (50%)\n";

    if (!askToContinue()) {
      continue;
    }

    inputValue();
    int card1_value = input;

    if (!askToContinue()) {
      continue;
    }

    // Round 2: will the next card be higher or lower than the first? (equal values are considered higher)
    double odds = round2_percentage(card1_value);
    std::cout << "Pick " << ((odds < 0) ? "lower; " : "higher; ") << "your odds are " << std::abs(odds * 100.0) << "%.\n";
    //note: ternary has lower precedence than insertion operator, so must group that in parentheses

    inputValue();
    int card2_value = input;

    if (!askToContinue()) {
      continue;
    }

    // Round 3: will the next card be inside (inclusive) or outside the first two?

    odds = round3_percentage(card1_value, card2_value);
    std::cout << "Pick " << ((odds < 0) ? "inside; " : "outside; ") << "your odds are " << std::abs(odds * 100.0) << "%.\n";

    if (!askToContinue()) {
      continue;
    }

    // Round 4: what is the suit of the last card?
    std::cout << "Time for the 'gambling' part of gambling, pick your own\nsuit, or let "
    << "the program roll the dice for you!\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 4);
    int random_suit = distrib(gen);
    std::string suit = "";
    switch(random_suit) {
      case 1:
        suit += "Hearts";
      break;
      case 2:
        suit += "Diamonds";
      break;
      case 3:
        suit += "Spades";
      break;
      case 4:
        suit += "Clubs";
      break;
    }
    std::cout << "God says you should pick " << suit << "!\n";
    std::cout << "\nDo you want to play another game? (y/n): ";
    char response;
    std::cin >> response;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    playAgain = (response == 'y' || response == 'Y');
  }
}

bool isInputValid(int input) {
      if (input > 0 && input < 15)
          return true;
      else
          return false;
}

bool askToContinue() {
  char response;
  std::cout << "Did you win this round? (y/n): ";
  std::cin >> response;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (response == 'n' || response == 'N') {
      std::cout << "Better luck next time! Starting a new game...\n";
      return false; // Don't continue with the current game
  }
  return true; // Continue with the current game
}

void inputValue() {
  std::cout << "Input the drawn card's value (or input 0 to restart)\n";
  std::cout << "Integer 1-10, 11 for J, 12 for Q, 13 for K, 14 for A\n";
  std::cin >> input;
  if (input == 0)
      return;
  while (!isInputValid(input)) {
      std::cout << "Invalid input; retry\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin >> input;
  }
}

double round2_percentage(int card1_value) {
  int numerator;
  if (card1_value >= 8) {
      numerator = card1_value - 1;
      numerator *= -1; // encoding that the user should pick lower
  }
  else {
      numerator = 15 - card1_value;
  }

  return ((double)numerator / 14.0);
}

double round3_percentage(int card1_value, int card2_value) {
  int higher_value;
  int lower_value;

  if (card1_value > card2_value) {
      higher_value = card1_value;
      lower_value = card2_value;
  }
  else if (card2_value > card1_value) {
      higher_value = card2_value;
      lower_value = card1_value;
  }
  else
      return .926; // 13/14, pick outside because card values are equal
  int range = higher_value - lower_value;
  if (range == 13)
      return -1; //special case for 1 and an ace
  if (range <= 6) {
      return (14.0 - (double)range)/14.0; //some whiteboard probability analysis
  }
  else
      return -1 * ((double)range + 1.0)/14.0; // encoding that the user should pick inside as negative
}

