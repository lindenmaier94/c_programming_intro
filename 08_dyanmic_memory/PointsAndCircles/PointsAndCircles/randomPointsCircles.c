#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "point_t.h"
#include "circle_t.h"

double randomDouble(double min, double max)
{
	double random = (double)rand() / RAND_MAX * (max - min) + min;
	return random;
}

point_t randomPoint(point_t minPoint, point_t maxPoint)
{
	point_t randomPoint;
	randomPoint.xCoord = randomDouble(minPoint.xCoord, maxPoint.xCoord);
	randomPoint.yCoord = randomDouble(minPoint.yCoord, maxPoint.yCoord);
	return randomPoint;
}

circle_t randomCircle(circle_t minCircle, circle_t maxCircle)
{
	circle_t randomCircle;
	randomCircle.center = randomPoint(minCircle.center, maxCircle.center);
	randomCircle.radius = randomDouble(minCircle.radius, maxCircle.radius);
	return	randomCircle;
}

void generateRandomPoints(point_t pointArray[], int numOfElems, point_t minPoint, point_t maxPoint)
{
	for (int i = 0; i < numOfElems; i++)
	{
		pointArray[i] = randomPoint(minPoint, maxPoint);
	}
}

void generateRandomCircles(circle_t circleArray[], int numOfElems, circle_t minCircle, circle_t maxCircle)
{
	circle_t currentCircle;
	for (int i = 0; i < numOfElems; i++)
	{
		circleArray[i] = randomCircle(minCircle, maxCircle);
	}
}

void printPoints(point_t pointArray[], int numOfElems)
{
	printf("----------------------------------------\n");
	for (int i = 0; i < numOfElems; i++)
	{
		printf("%d. point: x: %6.2f  y: %6.2f\n", i + 1, pointArray[i].xCoord, pointArray[i].yCoord);
	}
}

void printCircles(circle_t circleArray[], int numOfElems)
{
	printf("----------------------------------------\n");
	for (int i = 0; i < numOfElems; i++)
	{
		printf("%d. circle: r: %6.2f  u: %6.2f  v: %6.2f\n", i + 1, circleArray[i].radius, circleArray[i].center.xCoord, circleArray[i].center.yCoord);
	}
}

int isPointInCircle(point_t point, circle_t circle)
{
	int isInCircle;
	double distance;
	distance = sqrt(pow(point.xCoord - circle.center.xCoord, 2) + pow(point.yCoord - circle.center.yCoord, 2));

	if (distance < circle.radius)
	{
		isInCircle = 1;
	}
	else
	{
		isInCircle = 0;
	}
	return isInCircle;
}