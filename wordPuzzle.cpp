//Hamza Ilyas
//hi3zk
//3.11.18
//wordPuzzle.cpp

/* Parameter 1: Word2 File
   Parameter 2: 300x300 grid File
   time taken: 6.14785 seconds
*/

/* Big-Theta Run-time: (row * column) * 23 * direction = n^2
 */


#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<vector>
#include "timer.h"
#include "hashTable.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
timer t;

bool readInGrid(string filename, int &rows, int &cols);
char *getWordInGrid (int startRow, int startCol, int dir, int len,
		     int numRows, int numCols);

int main (int argc, char *argv[]) {
  string dictFile = argv[1];
  string gridFile = argv[2];
  string line;
  int rows, cols;
  int numLines = 0;
  int numWords = 0;

  ifstream newStream (dictFile.c_str());
  readInGrid(gridFile, rows, cols);

  while (getline(newStream, line)) {
    if (line.size() > 2) {
      numLines++;
    }
  }

  newStream.close();
  hashTable newHash(numLines);

  ifstream newStream1 (dictFile.c_str());

  while (getline(newStream1, line)) {
    if (line.size() > 2) {
      newHash.insert(line);
    }
  }

  newStream1.close();

  ifstream newStream2 (gridFile.c_str());
  newStream2.open(gridFile.c_str());

  t.start();
  
  string direction;
  for (int column = 0; column < cols; column++) {
    for (int row = 0; row < rows; row++) {
      for (int dir = 0; dir < 8; dir++) {
	for (int length = 3; length < 23; length++) {
	  string word = getWordInGrid (row, column, dir, length, rows, cols);
	  if (word.length() == length) {
	    if (newHash.contains(word)) {
	      numWords++;

	      switch (dir) {
	      case 0:
		direction = "N";
		cout << direction << "(" << row << "," << column << "): " << word << endl;
		break;
	      case 1:
		direction = "NE";
		cout << direction << "(" << row << "," << column << "): " << word << endl;
		break;
	      case 2:
		direction = "S";
		cout << direction << "(" << row << "," << column << "): " << word << endl;
		break;
	      case 3:
		direction = "SE";
		cout << direction << "(" << row << "," << column << "): " << word << endl;
		break;
	      case 4:
		direction = "SW";
		cout << direction << "(" << row << "," << column << "): " << word << endl;
		break;
	      case 5:
		direction = "W";
		cout << direction << "(" << row << "," << column << "): " << word << endl;
		break;
	      case 6:
		direction = "E";
		cout << direction << "(" << row << "," << column << "): " << word << endl;
		break;
	      case 7:
		direction = "NW";
		cout << direction << "(" << row << "," << column << "): " << word << endl;
		break;
	      }
	    }
	  }
	}
      }
    }
  }

  t.stop();
  double time = t.getTime();
  cout << "Found " << numWords << " words" << endl;
  cout << "Words found in " << time << " seconds" << endl;
  return 0;
}

  

bool readInGrid (string filename, int &rows, int &cols) {
  string line;
  ifstream file (filename.c_str());

  if (!file.is_open()) {
    return false;
  }

  file >> rows;
  cout << "There are " << rows << " rows." << endl;
  getline (file, line);
  file >> cols;
  cout << "There are " << cols << " cols." << endl;
  getline (file, line);
  getline (file, line);
  file.close();

  int pos = 0;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      grid[r][c] = line[pos++];
      cout << grid [r][c];
    }
    cout << endl;
  }
  return true;
}

char* getWordInGrid (int startRow, int startCol, int dir, int len,
		     int numRows, int numCols) {
  static char output[256];

  if (len >= 255) {
    len = 255;
  }

  int pos = 0, r = startRow, c = startCol;

  for (int i = 0; i < len; i++) {
    if ((c >= numCols) || (r >= numRows) || (r < 0) || (c < 0)) {
      break;
    }
    output[pos++] = grid[r][c];

    switch (dir) {
    case 0:
      r--;
      break;
    case 1:
      r--;
      c++;
      break;
    case 2:
      c++;
      break;
    case 3:
      r++;
      c++;
      break;
    case 4:
      r++;
      break;
    case 5:
      r++;
      c--;
      break;
    case 6:
      c--;
      break;
    case 7:
      r--;
      c--;
      break;
    }
  }
  output[pos] = 0;
  return output;
}
  

