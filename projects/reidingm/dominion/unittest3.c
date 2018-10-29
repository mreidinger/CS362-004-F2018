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
	int i, testResult, p0ExTotal;
	int seed = 1000;
	int numPlayer = 2;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState testGame;

	memset(&testGame, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &testGame); // initialize a new game

	testGame.deckCount[0] = 6;
	testGame.deckCount[1] = 6;
	testGame.handCount[0] = 5;
	testGame.handCount[1] = 5;
	testGame.discardCount[0] = 5;
	testGame.discardCount[1] = 5;

	p0ExTotal = testGame.deckCount[0] + testGame.handCount[0] + testGame.discardCount[0];

	for (i = 0; i < testGame.deckCount[0]; i++)
	{
		testGame.deck[0][i] = copper;
	}

	for (i = 0; i < testGame.deckCount[1]; i++)
	{
		testGame.deck[1][i] = silver;
	}

	for (i = 0; i < testGame.handCount[0]; i++)
	{
		testGame.hand[0][i] = copper;
	}

	for (i = 0; i < testGame.handCount[1]; i++)
	{
		testGame.hand[1][i] = silver;
	}

	for (i = 0; i < testGame.discardCount[0]; i++)
	{
		testGame.discard[0][i] = copper;
	}

	for (i = 0; i < testGame.discardCount[1]; i++)
	{
		testGame.discard[1][i] = silver;
	}

	printf("TESTING fullDeckCount():\n");

	testResult = fullDeckCount(0, copper, &testGame);

	if (testResult == p0ExTotal)
	{
		printf("TEST Player 0 Full Pile Count PASSED :\n");
	}

	else
	{
		printf("TEST Player 0 Full Pile Count FAILED:\n");
	}

	testResult = fullDeckCount(0, silver, &testGame);
	
	if (testResult == 0)
	{
		printf("TEST Player 1 Empty Pile Count PASSED :\n");
	}

	else
	{
		printf("TEST Player 1 Empty Pile Count FAILED:\n");
	}

	for (i = 0; i < testGame.handCount[0]; i++)
	{
		testGame.hand[0][i] = silver;
	}

	for (i = 0; i < testGame.discardCount[0]; i++)
	{
		testGame.discard[0][i] = silver;
	}

	testResult = fullDeckCount(0, copper, &testGame);

	if (testResult == testGame.deckCount[0])
	{
		printf("TEST Player 0 Deck Only Count PASSED :\n");
	}

	else
	{
		printf("TEST Player 0 Deck Only Count FAILED:\n");
	}

	for (i = 0; i < testGame.handCount[0]; i++)
	{
		testGame.hand[0][i] = copper;
	}

	for (i = 0; i < testGame.deckCount[0]; i++)
	{
		testGame.deck[0][i] = silver;
	}

	testResult = fullDeckCount(0, copper, &testGame);

	if (testResult == testGame.handCount[0])
	{
		printf("TEST Player 0 Hand Only Count PASSED :\n");
	}

	else
	{
		printf("TEST Player 0 Hand Only Count FAILED:\n");
	}

	for (i = 0; i < testGame.handCount[0]; i++)
	{
		testGame.hand[0][i] = silver;
	}

	for (i = 0; i < testGame.discardCount[0]; i++)
	{
		testGame.discard[0][i] = copper;
	}

	testResult = fullDeckCount(0, copper, &testGame);

	if (testResult == testGame.discardCount[0])
	{
		printf("TEST Player 0 Discard Only Count PASSED :\n");
	}

	else
	{
		printf("TEST Player 0 Discard Only Count FAILED:\n");
	}

    return 0;
}
