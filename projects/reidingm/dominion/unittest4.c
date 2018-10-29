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
	int i, testResult, tempProvince;
	int seed = 1000;
	int numPlayer = 2;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState testGame;

	memset(&testGame, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &testGame); // initialize a new game

	printf("TESTING isGameOver():\n");
	testResult = isGameOver(&testGame);
	
	if (testResult == 0)
	{
		printf("TEST New Game PASSED:\n");
	}
	else
	{
		printf("TEST New Game FAILED:\n");
	}

	tempProvince = testGame.supplyCount[province];

	testGame.supplyCount[province] = 0;
	testResult = isGameOver(&testGame);

	if (testResult == 1)
	{
		printf("TEST Province Depleated PASSED:\n");
	}
	else
	{
		printf("TEST Province Depleated FAILED:\n");
	}

	testGame.supplyCount[province] = tempProvince;

	testGame.supplyCount[copper] = 0;
	testResult = isGameOver(&testGame);

	if (testResult == 0)
	{
		printf("TEST One Depleated Pile PASSED:\n");
	}
	else
	{
		printf("TEST One Depleated Pile FAILED:\n");
	}

	testGame.supplyCount[silver] = 0;
	testResult = isGameOver(&testGame);

	if (testResult == 0)
	{
		printf("TEST Two Depleated Piles PASSED:\n");
	}
	else
	{
		printf("TEST Two Depleated Piles FAILED:\n");
	}

	testGame.supplyCount[gold] = 0;
	testResult = isGameOver(&testGame);

	if (testResult == 1)
	{
		printf("TEST Three Depleated Piles PASSED:\n");
	}
	else
	{
		printf("TEST Three Depleated Piles FAILED:\n");
	}

    return 0;
}
