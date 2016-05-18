#include "sort.cpp"
#include "sequence.cpp"
#include <iostream>
#include <time.h>

using namespace std;

void printArray (int * a, int n);
void setSequence (Sequence & mySequence);
void setPreorder (Sequence & mySequence);
void sort (Sequence & mySequence);

int main () {

  // Initialize data set object.
  Sequence mySequence;
  mySequence.initialize(100);

  int input = 1;

  // Loop for user input.
  while ( input != 0) {
    cout << endl << endl;
    cout << "CSC 326 - Group Lab" << endl;
    cout << "0) Exit." << endl;
    cout << "1) Set Sequence." << endl;
    cout << "2) Pre order sequence." << endl;
    cout << "3) Sort." << endl;
    cout << "$: ";
    cin >> input;
    switch (input) {
      case 0:
        break;
      case 1:
        setSequence(mySequence);
        break;
      case 2:
        setPreorder(mySequence);
        break;
      case 3:
        sort(mySequence);
        break;
    }
  }

  return 0;
}

void sort (Sequence & mySequence) {
  Sort mySort;
  int method, repeat;

  clock_t time1, time2, timeD;
  float time = 0;
  int steps = 0;

  cout << endl << endl;
  cout << "Amount of repitions." << endl;
  cout << "$: ";
  cin >> repeat;

  cout << endl << endl;
  cout << "Method." << endl;
  cout << "1) Insertion." << endl;
  cout << "2) Selection." << endl;
  cout << "3) Bubble." << endl;
  cout << "4) Merge." << endl;
  cout << "5) Quick." << endl;
  cout << "$: ";
  cin >> method;

  for(int i = 0; i < repeat; i++) {
    // If we're going to repeat this more than one time, for a random set. (For Task 2)
    if (repeat > 1) {
      // Randomize the set.
      mySequence.random();
    }
    switch(method) {
      case 1:
        time1 = clock();
        mySort.insertion(mySequence.getArray(), mySequence.getLength(), repeat, steps);
        time2 = clock();
        break;
      case 2:
        time1 = clock();
        mySort.selection(mySequence.getArray(), mySequence.getLength(), repeat, steps);
        time2 = clock();
        break;
      case 3:
        time1 = clock();
        mySort.bubble(mySequence.getArray(), mySequence.getLength(), repeat, steps);
        time2 = clock();
        break;
      case 4:
        time1 = clock();
        mySort.merge(mySequence.getArray(), mySequence.getLength(), repeat, steps);
        time2 = clock();
        break;
      case 5:
        time1 = clock();
        mySort.quick(mySequence.getArray(), 0, mySequence.getLength()-1, repeat, steps);
        time2 = clock();
        break;
    }
    timeD = time2 - time1;
    time += (float) timeD / CLOCKS_PER_SEC;
  }
  cout << "Repitions: " << repeat << endl;
  cout << "Total Time: " << fixed << time << " seconds." << endl;
  cout << "Total Steps: " << steps << endl;
  cout << "Average Time: " << fixed << time/repeat << " seconds." << endl;
  cout << "Average Steps: " << steps/repeat << endl;
}

void printArray (int * a, int n) {
  cout << "Array: ";
  for (int i = 0; i < n; i++) {
    cout << * (a + i) << " ";
  }
  cout << endl;
}

void setSequence (Sequence & mySequence) {
  cout << endl << endl;
  int input;
  cout << "Number of elements to be used." << endl;
  cout << "$: ";
  cin >> input;
  mySequence.initialize(input);
  return;
}

void setPreorder (Sequence & mySequence) {
  cout << endl << endl;
  cout << "Pre order of array." << endl;
  int input;
  cout << "1) Sorted." << endl;
  cout << "2) Reverse." << endl;
  cout << "3) Random." << endl;
  cout << "$: ";
  cin >> input;
  switch(input) {
    case 1:
      mySequence.ascend();
      break;
    case 2:
      mySequence.descend();
      break;
    case 3:
      mySequence.random();
      break;
    default:
      mySequence.random();
      break;
  }
  return;
}
