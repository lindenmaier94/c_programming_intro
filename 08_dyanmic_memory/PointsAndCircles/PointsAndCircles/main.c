#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "point_t.h"
#include "circle_t.h"
#include "randomPointsCircles.h"


#define R_MIN 1
#define R_MAX 50
#define X_MIN -50
#define X_MAX +50
#define Y_MIN -50
#define Y_MAX +50

int main(int argc, char* argv[])
{
	srand(time(0));
	point_t minPoint = { .xCoord = X_MIN, .yCoord = Y_MIN };
	point_t maxPoint = { .xCoord = X_MAX, .yCoord = Y_MAX };
	int numOfPoints;
	printf("Please, enter the desired number of points: ");
	scanf_s("%d", &numOfPoints);
    point_t* pointArray = calloc(numOfPoints, sizeof(point_t));
	if (pointArray == NULL)
	{
		printf("The memory allocation was unsuccesful. Exit..\n");
		return -1;
	}
	generateRandomPoints(pointArray, numOfPoints, minPoint, maxPoint);
	printPoints(pointArray, numOfPoints);

	circle_t minCircle = { .center = minPoint, .radius = R_MIN };
	circle_t maxCircle = { .center = maxPoint, .radius = R_MAX };
	int numOfCircles;
	printf("Please, enter the desired number of circles: ");
	scanf_s("%d", &numOfCircles);
	circle_t* circleArray = calloc(numOfCircles, sizeof(circle_t));
	if (circleArray == NULL)
	{
		printf("The memory allocation was unsuccesful. Exit..\n");
		return -1;
	}
	generateRandomCircles(circleArray, numOfCircles, minCircle, maxCircle);
	printCircles(circleArray, numOfCircles);

	printf("----------------------------------------------\n");
	int* isInCircleMatrix = calloc(numOfPoints * numOfCircles, sizeof(int));
	if (isInCircleMatrix == NULL)
	{
		printf("The memory allocation was unsuccesful. Exit..\n");
		return -1;
	}
	printf("Circles: ");
	for (int j = 0; j < numOfCircles; j++)
	{
		printf("%d.   ", j + 1);
	}
	printf("\nPoints\n");
	printf("----------------------------------------------\n");

	for (int i = 0; i < numOfPoints; i++)
	{
		printf("  %d.     ", i + 1);
		for (int j = 0; j < numOfCircles; j++)
		{
			*(isInCircleMatrix + j * numOfPoints + i) = isPointInCircle(pointArray[i], circleArray[j]);
			printf("%d    ", *(isInCircleMatrix + j * numOfPoints + i));			
		}
		printf("\n");
	}

	free(isInCircleMatrix);
	free(circleArray);
	free(pointArray);

	return 0;
}