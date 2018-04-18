#include "stdafx.h"
#include "headers/sense.h"

using namespace std;

// OPTIMIZATION: Pass larger variables by reference
vector< vector <float> > sense(char color, vector< vector <char> > &grid, vector< vector <float> > &beliefs,  float p_hit, float p_miss) 
{
	int height = grid.size();
	int width = grid[0].size();
	if (height != beliefs.size() || width!= beliefs[0].size()) throw invalid_argument("world grid and believes are not the same size");
	


	float np = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			beliefs[i][j] = beliefs[i][j] * ((color == grid[i][j])*p_hit + (color != grid[i][j])*p_miss);
		}
	}


	return beliefs;
}
