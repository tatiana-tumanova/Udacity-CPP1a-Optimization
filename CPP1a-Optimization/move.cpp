#include "stdafx.h"
#include "headers/move.h"
#include "headers/zeros.h"

using namespace std;

// OPTIMIZATION: Pass large variable by reference
vector< vector <float> > move(int dy, int dx, 	vector < vector <float> > &beliefs) 
{
	const int height = beliefs.size();
	const int width = beliefs[0].size();
	vector < vector <float> > new_beliefs(height, vector<float>(width, 0));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			new_beliefs[(i + height + dy) % height][(j + width + dx) % width] = beliefs[i][j];
		}
	}

	return new_beliefs;
}
