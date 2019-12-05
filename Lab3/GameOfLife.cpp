// Daniel Polak
// C00228290
#include <iostream>
#include <ctime>

using namespace std;
void drawMaze(char mz[10][10], int numRows, int numCols )
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			if (mz[row][col] == 'X') {
				mz[row][col] = '2';
			}
			std::cout <<  mz[row][col];
		}
		std::cout << endl;
	}

}

void populateWalkers(char mz[10][10]) {

	for (int i = 0; i < 10; i++) {
		int row = rand() % 10;
		int col = rand() % 10;

		if (mz[row][col] == ' ') {
			mz[row][col] = '2';
		}
		else {
			i--;
		}
	}
}

void drawPlants(char mz[10][10]) {
	
	for (int i = 0; i < 5; i++) {
		int row = rand() % 10;
		int col = rand() % 10;

		if (mz[row][col] == ' ') {
			mz[row][col] = 'y';
		}
		else {
			i--;
		}
	}
}
void changePlants(char mz[10][10], int numRows, int numCols) {
	int up;
	int down;
	int left;
	int right;
	int check = 0;
	int cUp = 0;
	int cDown = 0;
	int cLeft = 0;
	int cRight = 0;

	for (int row = 1; row < numRows - 1; row++) {
		for (int col = 1; col < numCols - 1; col++) {
			/*if (mz[row][col] >= 'a' && mz[row][col] <= 'y') {
				up = row - 1;
				down = row + 1;
				left = col - 1;
				right = col + 1;

				while (cUp != 1) {
					if (mz[up][col] == '2') {
						break;
					}
					else if (mz[up][col] == 219) {
						cUp = 1;
						break;
					}
					up--;
				}

				while (cDown != 1) {
					if (mz[down][col] == '2') {
						break;
					}
					else if (mz[down][col] == 219) {
						cDown = 1;
						break;
					}
					down++;
				}

				while (cLeft != 1) {
					if (mz[row][left] == '2') {
						break;
					}
					else if (mz[row][left] == 219) {
						cLeft = 1;
						break;
					}
					left--;
				}

				while (cRight != 1) {
					if (mz[row][right] == '2') {
						break;
					}
					else if (mz[row][right] == 219) {
						cRight = 1;
						break;
					}
					right++;
				}

				if (cUp == 1 && cDown == 1 && cRight == 1 && cLeft == 1) {
					check = 1;
				}
				else {
					check = 0;
				}*/
				 //if (check == 1) {
					if (mz[row][col] >= 'a' && mz[row][col] <= 'y') {
						if (mz[row][col] == 'y') {
							mz[row][col] = 'a';
						}
						else if (mz[row][col] >= 'a' && mz[row][col] <= 'x') {
							mz[row][col]++;
						}
					}
				//}
			//}
		}
	}
}

int canMove(char mz[10][10], int row, int col) {
	//int check = 0;
	char empty = ' ';

	for (int i = 0; i < 8; i++) {
		switch (i) {
		case 0:
			if (mz[row - 1][col] == empty || mz[row - 1][col] >= 'a' && mz[row - 1][col] <= 'y') {
				return 1;
			}
		case 1:
			if (mz[row + 1][col] == empty || mz[row + 1][col] >= 'a' && mz[row + 1][col] <= 'y') {
				return 1;
			}
		case 2:
			if (mz[row][col - 1] == empty || mz[row][col - 1] >= 'a' && mz[row][col - 1] <= 'y') {
				return 1;
			}
		case 3:
			if (mz[row][col + 1] == empty || mz[row][col + 1] >= 'a' && mz[row][col + 1] <= 'y') {
				return 1;
			}
		case 4:
			if (mz[row - 1][col - 1] == empty || mz[row - 1][col - 1] >= 'a' && mz[row - 1][col - 1] <= 'y') {
				return 1;
			}
		case 5:
			if (mz[row + 1][col + 1] == empty || mz[row + 1][col + 1] >= 'a' && mz[row + 1][col + 1] <= 'y') {
				return 1;
			}
		case 6:
			if (mz[row + 1][col - 1] == empty || mz[row + 1][col - 1] >= 'a' && mz[row + 1][col - 1] <= 'y') {
				return 1;
			}
		case 7:
			if (mz[row - 1][col + 1] == empty || mz[row - 1][col + 1] >= 'a' && mz[row - 1][col + 1] <= 'y') {
				return 1;
			}
			return 0;
		}
	}
}
void moveWalkers(char mz[10][10], int numRows, int numCols) {
	int check = 0;
	int count = 0;

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			if (mz[i][j] == '2') {
				if (canMove(mz, i, j) == 1) {
					int row = rand() % 3 - 1;
					int col = rand() % 3 - 1;
					int check = 0;

					while (check == 0) {
						if (mz[i+row][j+col] == ' '||mz[i+row][j+col] >= 'a' && mz[i + row][j + col] <= 'y') {
							mz[i+row][j+col] = 'X';
							mz[i][j] = ' ';
							check++;
						}
						row = rand() % 3 - 1;
						col = rand() % 3 - 1;
					}
				}
			}
		}
	}
}

int main()
{
	char wall = 219;
	char path = ' ';
	srand(time(NULL));
	const int numRows = 10;
	const int numCols = 10;
	int countChar = 0;
	char  maze[numRows][numCols] = {
			{wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
			{wall,path,path,path,path,path,path,path,path,wall},
			{wall,path,wall,path,path,wall,path,wall,path,wall},
			{wall,path,wall,wall,wall,wall,path,wall,path,wall},
			{wall,path,wall,path,path,path,path,wall,path,wall},
			{wall,path,wall,wall,wall,path,wall,wall,path,wall},
			{wall,path,wall,path,wall,path,path,path,path,wall},
			{wall,path,wall,path,wall,wall,wall,wall,wall,wall},
			{wall,path,path,path,path,path,path,path,path,wall},
			{wall,wall,wall,wall,wall,wall,wall,wall,wall,wall} };

	char c = 'a';
	populateWalkers(maze);
	drawPlants(maze);
	while (c != 'x')
	{
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				if (maze[i][j] <= 'y' && maze[i][j] >= 'a') {
					countChar++;
				}
			}
		}

		drawMaze(maze, numRows, numCols);
		changePlants(maze, numRows, numCols);
		moveWalkers(maze, numRows, numCols);
		std::cout << "Number of Walkers: 10" << endl;
		std::cout << "Number of Plants: " << countChar << endl;
		std::cin >> c;
		if (countChar == 0) {
			std::cout << "Game won!" << endl;
			c = 'x';
		}
		countChar = 0;
	}

}