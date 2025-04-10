countRightGuesses(int guessArray[], int drawnArray[], int numOfDraws)
{
	// This functions counts the number of right guesses of the user
	// by comparing all the drawn numbers to each guessed number.
	int currentDraw;
	int numOfRightGuess = 0;
	for (int i = 0; i < numOfDraws; i++)
	{
		currentDraw = guessArray[i];
		for (int j = 0; j < numOfDraws; j++)
		{
			if (drawnArray[j] == currentDraw)
			{
				numOfRightGuess++;
				break;
			}
		}
	}
	return numOfRightGuess;
}