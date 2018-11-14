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

#define TESTCARD "steward"

int main() {
	//initilization variables from example
	int i, testResult, startCard, endCard;
	int seed = 1000;
	int numPlayer = 2;
	int handPos = 0, choice1 = 0, altChoice1 = 1, choice2 = 0, choice3 = 0, bonus = 0, kingdomChange = 0;
	struct gameState testGame, testGameDis, testGameStart;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	memset(&testGame, 23, sizeof(struct gameState));   // clear the game state
	memset(&testGameStart, 23, sizeof(struct gameState));   // clear the game state
	memset(&testGameDis, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &testGame);
	memcpy(&testGameStart, &testGame, sizeof(struct gameState)); //backup state for comparison
	memcpy(&testGameDis, &testGame, sizeof(struct gameState)); //backup state for comparison

	cardEffect(salvager, choice1, choice2, choice3, &testGame, handPos, &bonus);
	cardEffect(salvager, altChoice1, choice2, choice3, &testGameDis, handPos, &bonus);

	printf("TESTING salvager:\n");

	// Test that 1 buy was added
	if (testGameStart.numBuys + 1 == testGame.numBuys)
	{
		printf("TEST Player 0 Buys +1 PASSED:\n");
	}
	else
	{
		printf("TEST Player 0 Buys +1 FAILED:\n");
	}

	// Test that coins were added 
	if (testGameStart.coins + getCost(handCard(altChoice1, &testGameStart)) == testGameDis.coins)
	{
		printf("TEST Player 0 coins added PASSED:\n");
	}
	else
	{
		printf("TEST Player 0 coins added FAILED:\n");
	} 

	// Test that card was Played
	if (testGameStart.handCount[0] == testGameDis.handCount[0] + 2)
	{
		printf("TEST Player 0 Discard PASSED:\n");
	}
	else
	{
		printf("TEST Player 0 Discard FAILED:\n");
	}

	// Test that card was Played
	if (testGameStart.playedCardCount + 1 == testGame.playedCardCount)
	{
		printf("TEST Player 0 salvager Played PASSED:\n");
	}
	else
	{
		printf("TEST Player 0 salvager Played FAILED:\n");
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


