# Schedule I: Ride the Bus Helper

## Overview
This program is designed to help players optimize their chances in the "Ride the Bus" card casino game found in [Schedule I](https://store.steampowered.com/app/3164500/Schedule_I/). It calculates odds for each round of the game and provides recommendations to maximize your profits.

## Game Rules
In the Ride the Bus game:

1. **Round 1**: Guess if the next card will be Red or Black (50% chance)
2. **Round 2**: Guess if the next card will be Higher or Lower than the first (equal values count as higher)
3. **Round 3**: Guess if the next card will be Inside or Outside the range of the first two cards (inclusive)
4. **Round 4**: Guess the suit of the next card

Winning each round provides (all is lost if you keep going and lose:
- Round 1: 2x multiplier
- Round 2: 3x multiplier
- Round 3: 4x multiplier
- Round 4: 20x multiplier

## Features
- Calculates exact probabilities for each round
- Recommends the best choice for each round
- Tracks your progress through the game
- Option to start over if you lose a round
- Random suit recommendation for the final round
- Handles special cases (equal cards, consecutive cards, etc.)

## How to Use
1. Run the program
2. After each card is drawn in the game, input its value
3. Follow the recommendation provided
4. Indicate whether you won or lost the round
5. Continue until you've completed all rounds or lost

## Input Guide
- Card values: 2-10 use those numbers, J=11, Q=12, K=13, A=14
- Winning rounds: Enter 'y' when asked if you won
- Losing rounds: Enter 'n' to restart the game

## Important Notes
- The program assumes all cards are equally likely to be drawn (as if using an infinite deck)
- This approach was chosen for simplicity, though the actual game may use a single deck simulation
- Theoretically, no round is profitable in the long run if the game deals fairly
- The game might intentionally give players hands with better probabilities for entertainment value

## Mathematical Approach
- Round 1: Always 50/50 odds
- Round 2: Calculates favorable outcomes based on your first card's value
- Round 3: Determines whether more cards fall inside or outside your first two cards
- Round 4: Pure chance (25% for each suit)

## Disclaimer
This tool is meant for entertainment purposes within the Schedule I game environment. It does not encourage or promote real-world gambling or drug dealing.

## Credits
Milam Garrett, Grand Oaks High School
