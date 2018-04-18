#include "stdafx.h"
#include "headers/blur.h"

using namespace std;

// OPTIMIZATION: Pass large variable by reference
vector < vector <float> > blur(vector < vector < float> > &grid, float blurring) {

	// OPTIMIZATION: window, DX and  DY variables have the 
    // same value each time the function is run.
  	// It's very inefficient to recalculate the vectors
    // every time the function runs. 
    // 
    // The const and/or static operator could be useful.
  	// Define and declare window, DX, and DY using the
    // bracket syntax: vector<int> foo = {1, 2, 3, 4} 
    // instead of calculating these vectors with for loops 
    // and push back
	int height = grid.size();
	int width = grid[0].size();
	vector < vector <float> > blurred_grid(height, vector<float>(width, 0));
	float sum_of_4_corners, sum_of_4_adjucents, center;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			sum_of_4_corners = grid[(i + height - 1) % height][(j + width - 1) % width]
				+ grid[(i + 1) % height][(j + width - 1) % width]
				+ grid[(i + height - 1) % height][(j + 1) % width]
				+ grid[(i + 1) % height][(j + 1) % width];
			sum_of_4_adjucents = grid[i][(j + width - 1) % width]
				+ grid[i][(j + 1) % width]
				+ grid[(i + height - 1) % height][j]
				+ grid[(i + 1) % height][j];
			center = grid[i][j];
			blurred_grid[i][j] = center * (1 - blurring)
				+ sum_of_4_corners * blurring / 12
				+ sum_of_4_adjucents * blurring / 6;
		}
	}

	//cout << "[helpers.blur] blurred_grid before normalization:" << endl;
	//show_grid(blurred_grid);

	return blurred_grid;
}
