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
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState testGame;


	memset(&testGame, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &testGame); // initialize a new game

    printf ("TESTING shuffle():\n");
	
	//Test for shuffle on empty deck
	for (i = 0; i < 2; i++)
	{	
		testGame.deckCount[i] = 0;
		testResult = shuffle(i, &testGame);
		if (testResult == -1)
		{
			printf("TEST Player %d empty deck PASSED:\n", i);
		}
		else
		{
			printf("TEST Player %d empty deck Failed:\n", i);
		}
	}
	

	//Test for proper return after shuffle
	for (i = 0; i < 2; i++)
	{
		testGame.deckCount[i] = 8;
	}
	
	for (i = 0; i < 2; i++)
	{
		if (shuffle(i, &testGame) == 0)
		{
			printf("TEST Player %d full deck crash PASSED:\n", i);
		}
		else
		{
			printf("TEST Player %d full deck crash Failed:\n", i);
		}
	}
	  
	int deck1Start, deck2Start, deck1End, deck2End;
	deck1Start = testGame.deck[0][0];
	deck2Start = testGame.deck[1][0];
	deck1End = testGame.deck[0][7];
	deck2End = testGame.deck[1][7];
	shuffle(0, &testGame);

	//Test proper shuffle behavior on player 1
		if (deck1Start == testGame.deck[0][0] && deck1End == testGame.deck[0][7])
		{
			printf("TEST Player 0 Shuffle full FAILED:\n");
		}
		else
		{
			printf("TEST Player 0 Shuffle full PASSED:\n");
		}

	//Test if shuffle selected the proper player
	if (deck2Start == testGame.deck[1][0] && deck2End == testGame.deck[1][7])
	{
		printf("TEST Player 1 Accidental Shuffle PASSED:\n");
	}
	else
	{
		printf("TEST Player 1 Accidental Shuffle PASSED:\n");
	}
	
    return 0;
}
