#include "point_t.h"
#include "circle_t.h"

#pragma once

double randomDouble(double min, double max);
point_t randomPoint(point_t minPoint, point_t maxPoint);
circle_t randomCircle(circle_t minCircle, circle_t maxCircle);
void generateRandomPoints(point_t pointArray[], int numOfElems, point_t minPoint, point_t maxPoint);
void generateRandomCircles(circle_t circleArray[], int numOfElems, circle_t minCircle, circle_t maxCircle);
void printPoints(point_t pointArray[], int numOfElems);
void printCircles(circle_t circleArray[], int numOfElems);
int isPointInCircle(point_t point, circle_t circle);