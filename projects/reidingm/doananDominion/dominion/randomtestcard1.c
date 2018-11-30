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
#include <time.h>
#include <math.h>


int main() {
	//initilization variables from example
	int i, j, m, l, n, testResult, startCard, endCard;
	int randDeck, randDis, randHand, randPlayed;
	int startVal;

	int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, startTreasure = 0, endTreasure = 0, kingdomChange = 0;

	// fail counter variables
	int drawThreeFail = 0, threeOwnFail = 0, wasDiscardFail = 0, otherHandFail = 0, otherDeckFail = 0, otherDiscardFail = 0;
	int dutchyFail = 0, kingdomFail = 0, estateFail = 0, provinceFail = 0, noFails = 0;
	int handFlag = 0, deckFlag = 0, discardFlag = 0;

	SelectStream(2);
	PutSeed(3);

	int numOfPlayers = 2;

	struct gameState testGame, testGameStart;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	printf("TESTING random smithy:\n");

	// initilize a random testing array for testing the adventurer card
	for (j = 0; j < 8000; j++)
	{
		for (i = 0; i < sizeof(struct gameState); i++)
		{
			startVal = floor(Random() * 256);
			((char*)&testGame)[i] = startVal; // borrowed from betterTestDrawCard example
			((char*)&testGameStart)[i] = startVal;

		}
//				printf("TESTING int done:\n");

		//reset counting variables
		handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0, startTreasure = 0, endTreasure = 0, kingdomChange = 0;
		handFlag = 0, deckFlag = 0, discardFlag = 0;

		// chose a random number of players ensuring there is enough to play the game
		numOfPlayers = rand() % 5;
		if (numOfPlayers < 2)
		{
			numOfPlayers = 2;
		}

//				printf("TESTING players done:\n");

		//choose random values for all used play counts
		randDeck = floor(Random() * MAX_DECK); // modeled from betterTestDrawCard example
		if (randDeck < 10)
		{
			randDeck = 10;
		}
		randDis = floor(Random() * MAX_DECK);
		randHand = floor(Random() * MAX_HAND);
		randPlayed = floor(Random() * (MAX_DECK -1 ));
		// assign the random values to each player
		for (m = 0; m < numOfPlayers; m++)
		{
			testGame.deckCount[m] = randDeck;
			testGameStart.deckCount[m] = randDeck;
			testGame.discardCount[m] = randDis;
			testGameStart.discardCount[m] = randDis;
			testGame.handCount[m] = randHand;
			testGameStart.handCount[m] = randHand;
		}

		for (i = 0; i < numOfPlayers; i++)
		{
			for (n = 0; n < 3; n++)
			{
				testGame.deck[i][n] = copper;
				testGameStart.deck[i][n] = copper;
			}

			for (n = 3; n < randDeck; n++)
			{
				testGame.deck[i][n] = estate;
				testGameStart.deck[i][n] = estate;
			}
		}

		testGame.playedCardCount = randPlayed;
		testGameStart.playedCardCount = randPlayed;
		testGame.whoseTurn = 0;
		testGameStart.whoseTurn = 0;

//	printf("TESTING precard done:\n");

	cardEffect(smithy, choice1, choice2, choice3, &testGame, handPos, &bonus);


//	printf("TESTING postcard:\n");

	// Test that three cards were drawn
	if (testGameStart.handCount[0] + 2 != testGame.handCount[0])
	{
	//	printf("TEST Player 0 Draw Two Cards FAILED:\n");
		drawThreeFail++;
	}

	// Test that three cards drawn were from own deck
	if (testGameStart.deckCount[0] != testGame.deckCount[0] + 3)
	{
//		printf("TEST Player 0 Draw 3 From Own Deck FAILED:\n");
		threeOwnFail++;
	}

	// Test that card was discarded
	if (testGameStart.playedCardCount + 1 != testGame.playedCardCount)
	{
//		printf("TEST Player 0 Smithy Played FAILED:\n");
		wasDiscardFail++;
	}

	//check other players for improper changes
	for (l = 1; l <numOfPlayers; l++)
	{
		//Check Player 1 for change
		if (testGameStart.handCount[l] != testGame.handCount[l])
		{
			//	printf("TEST Player 1 Hand FAILED:\n");
			handFlag = 1;
		}

		if (testGameStart.deckCount[l] != testGame.deckCount[l])
		{
			//	printf("TEST Player 1 Deck FAILED:\n");
			deckFlag = 1;
		}

		if (testGameStart.discardCount[l] != testGame.discardCount[l])
		{
			//	printf("TEST Player 1 Discard FAILED:\n");
			discardFlag = 1;
		}
	}

	//add changes to failure totals
	otherHandFail = otherHandFail + handFlag;
	otherDeckFail = otherDeckFail + deckFlag;
	otherDiscardFail = otherDiscardFail + discardFlag;

	// Check Victory and Kingdom Piles
	if (testGameStart.supplyCount[estate] != testGame.supplyCount[estate])
	{
		//	printf("TEST Estate Unchanged FAILED:\n");
		estateFail++;
	}

	if (testGameStart.supplyCount[duchy] != testGame.supplyCount[duchy])
	{
		//	printf("TEST Duchy Unchanged FAILED:\n");
		dutchyFail++;
	}

	if (testGameStart.supplyCount[province] != testGame.supplyCount[province])
	{
		//	printf("TEST Province Unchanged FAILED:\n");
		provinceFail++;
	}

	for (i = 0; i < 10; i++)
	{
		if (testGameStart.supplyCount[k[i]] != testGame.supplyCount[k[i]])
		{
			kingdomChange++;
		}
	}

	if (kingdomChange != 0)
	{
		//	printf("TEST Kingdom Unchanged FAILED:\n");
		kingdomFail++;
	}

	}

	noFails = drawThreeFail + threeOwnFail + wasDiscardFail + otherHandFail + otherDeckFail + otherDiscardFail + dutchyFail + kingdomFail + estateFail + provinceFail;

	if (noFails == 0)
	{
		printf("All Tests Successful:\n");
	}

	else
	{
		printf("TEST Player 0 Draw Three Cards FAILED: %d\n", drawThreeFail);
		printf("TEST Player 0 Draw 3 From Own Deck FAILED: %d\n", threeOwnFail);
		printf("TEST Player 0 Smithy Played FAILED: %d\n", wasDiscardFail);
		printf("TEST Other Players Hand FAILED: %d\n", otherHandFail);
		printf("TEST Other Players Deck FAILED:\n", otherDeckFail);
		printf("TEST Other Players Discard FAILED:\n", otherDiscardFail);
		printf("TEST Estate Unchanged FAILED: %d\n", estateFail);
		printf("TEST Duchy Unchanged FAILED: %d\n", dutchyFail);
		printf("TEST Province Unchanged FAILED: %d\n", provinceFail);
		printf("TEST Kingdom Unchanged FAILED: %d\n\n", kingdomFail);
	}
	

	return 0;
}


