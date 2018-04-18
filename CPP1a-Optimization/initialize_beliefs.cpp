#include "stdafx.h"
#include "headers/initialize_beliefs.h"
#include "headers/initialize_beliefs.h"

using namespace std;

// OPTIMIZATION: pass large variables by reference
vector< vector <float> > initialize_beliefs(vector< vector <char> > &grid) {

	// OPTIMIZATION: Which of these variables are necessary?
	// OPTIMIZATION: Reserve space in memory for vectors
	
	int height, width;
	float prob_per_cell;

	height = grid.size();
	width = grid[0].size();
 
	

  	prob_per_cell = 1.0 / ( (float) (height * width) ) ;

	vector< vector <float> > newGrid(height, vector<float>(width, prob_per_cell));


  	
	return newGrid;
}