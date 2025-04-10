void bubbleSort(int array[], int numOfElems, int order)
{
	// This function sorts the elements of any array according to give order
	int memory;
	int isAscendingSwap;
	int isDescendingSwap;
	for (int i = numOfElems - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			isAscendingSwap = (order > 0) && (array[j + 1] < array[j]);
			isDescendingSwap = (order < 0) && (array[j + 1] > array[j]);
			if (isAscendingSwap || isDescendingSwap)
			{
				memory = array[j];
				array[j] = array[j + 1];
				array[j + 1] = memory;
			}
		}
	}
}