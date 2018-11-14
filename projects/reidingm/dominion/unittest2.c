/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main() {

	//initilization variables from example
	int i, testResult;
	int seed = 1000;
	int numPlayer = 2;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState testGame;

	memset(&testGame, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &testGame); // initialize a new game

	int p0Disc, p1Disc, p0Hand, p1Hand, p0Deck, p1Deck, tempSupply, emptySupply;

	p0Disc = testGame.discardCount[0];
	p1Disc = testGame.discardCount[1];
	p0Hand = testGame.handCount[0];
	p1Hand = testGame.handCount[1];
	p0Deck = testGame.deckCount[0];
	p1Deck = testGame.deckCount[1];
	testGame.supplyCount[copper] = 25;
	tempSupply = testGame.supplyCount[copper];

    printf ("TESTING gainCard():\n");
	
	//Test gain card to discard pile
	gainCard(copper, &testGame, 0, 0);

	if (p0Disc == testGame.discardCount[0] - 1)
	{
		printf("TEST Player 0 Discard PASSED:\n");
	}
	
	else
	{
		printf("TEST Player 0 Discard FAILED:\n");
	}

	//Test to ensure the proper pile was impacted
	if (p1Disc == testGame.discardCount[1])
	{
		printf("TEST Correct Discard PASSED:\n");
	}

	else
	{
		printf("TEST Correct Discard FAILED:\n");
	}

	//Test to check supply reduced correctly
	if (tempSupply == testGame.supplyCount[copper] + 1)
	{
		printf("TEST Correct Supply Reduced PASSED:\n");
	}

	else
	{
		printf("TEST Correct Supply Reduced FAILED:\n");
	}

	//Test gain card to deck pile
	gainCard(copper, &testGame, 1, 0);

	if (p0Deck == testGame.deckCount[0] - 1)
	{
		printf("TEST Player 0 Deck PASSED:\n");
	}

	else
	{
		printf("TEST Player 0 Deck FAILED:\n");
	}

	//Test to ensure the proper pile was impacted
	if (p1Deck == testGame.deckCount[1])
	{
		printf("TEST Correct Deck PASSED:\n");
	}

	else
	{
		printf("TEST Correct Deck FAILED:\n");
	}

	// Test gain card to hand
	gainCard(copper, &testGame, 2, 0);
	if (p0Hand == testGame.handCount[0] - 1)
	{
		printf("TEST Player 0 Hand PASSED:\n");
	}

	else
	{
		printf("TEST Player 0 Hand FAILED:\n");
	}

	//Test to ensure the proper pile was impacted
	if (p1Hand == testGame.handCount[1])
	{
		printf("TEST Correct Hand PASSED:\n");
	}

	else
	{
		printf("TEST Correct Hand FAILED:\n");
	}

	//Test depleted supply 
	testGame.supplyCount[copper] = 0;
	emptySupply = gainCard(copper, &testGame, 2, 0);

	if (emptySupply == -1)
	{
		printf("TEST Empty Supply PASSED:\n");
	}

	else
	{
		printf("TEST Empty Supply FAILED:\n");
	}

    return 0;
}
