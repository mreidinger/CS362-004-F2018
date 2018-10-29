/*
 * cardtest4.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main() {
	//initilization variables from example
	int i, testResult, startCard, endCard;
	int seed = 1000;
	int numPlayer = 2;
	int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, kingdomChange = 0;
	struct gameState testGame, testGameStart;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	memset(&testGame, 23, sizeof(struct gameState));   // clear the game state
	memset(&testGameStart, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &testGame);
	memcpy(&testGameStart, &testGame, sizeof(struct gameState)); //backup state for comparison

	cardEffect(great_hall, choice1, choice2, choice3, &testGame, handPos, &bonus);

	printf("TESTING great_hall:\n");

	// Test that one card was drawn
	if (testGameStart.handCount[0] == testGame.handCount[0])
	{
		printf("TEST Player 0 Draw One Cards PASSED:\n");
	}
	else
	{
		printf("TEST Player 0 Draw One Cards FAILED:\n");
	}

	// Test that one action was added
	if (testGameStart.numActions + 1 == testGame.numActions)
	{
		printf("TEST Player 0 +1 Action PASSED:\n");
	}
	else
	{
		printf("TEST Player 0 +1 Action FAILED:\n");
	}

	// Test that card was discarded
	if (testGameStart.playedCardCount + 1 == testGame.playedCardCount)
	{
		printf("TEST Player 0 great_hall Played PASSED:\n");
	}
	else
	{
		printf("TEST Player 0 great_hall Played FAILED:\n");
	}

	//Check Player 1 for change
	if (testGameStart.handCount[1] == testGame.handCount[1])
	{
		printf("TEST Player 1 Hand PASSED:\n");
	}
	else
	{
		printf("TEST Player 1 Hand FAILED:\n");
	}

	if (testGameStart.deckCount[1] == testGame.deckCount[1])
	{
		printf("TEST Player 1 Deck PASSED:\n");
	}
	else
	{
		printf("TEST Player 1 Deck FAILED:\n");
	}

	if (testGameStart.discardCount[1] == testGame.discardCount[1])
	{
		printf("TEST Player 1 Discard PASSED:\n");
	}
	else
	{
		printf("TEST Player 1 Discard FAILED:\n");
	}

	// Check Victory and Kingdom Piles
	if (testGameStart.supplyCount[estate] == testGame.supplyCount[estate])
	{
		printf("TEST Estate Unchanged PASSED:\n");
	}
	else
	{
		printf("TEST Estate Unchanged FAILED:\n");
	}

	if (testGameStart.supplyCount[duchy] == testGame.supplyCount[duchy])
	{
		printf("TEST Duchy Unchanged PASSED:\n");
	}
	else
	{
		printf("TEST Duchy Unchanged FAILED:\n");
	}

	if (testGameStart.supplyCount[province] == testGame.supplyCount[province])
	{
		printf("TEST Province Unchanged PASSED:\n");
	}
	else
	{
		printf("TEST Province Unchanged FAILED:\n");
	}

	for (i = 0; i < 10; i++)
	{
		if (testGameStart.supplyCount[k[i]] != testGame.supplyCount[k[i]])
		{
			kingdomChange++;
		}
	}

	if (kingdomChange == 0)
	{
		printf("TEST Kingdom Unchanged PASSED:\n");
	}
	else
	{
		printf("TEST Kingdom Unchanged FAILED:\n");
	}

	return 0;
}


