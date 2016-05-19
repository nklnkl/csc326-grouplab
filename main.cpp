#include "sort.cpp"
#include "sequence.cpp"
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

/*
  void test()
  sequence: the data set to be worked on.
  repeat: how many times this test will run.
  order: {
    0: Sorted
    1: Reverse
    2: Random
  }
  average: if the test will be printing average values as well.
*/
void test (Sequence & sequence, int repeat, int order, bool average);

// Returns amount of elements to be worked on based on table row.
int getN (int row);

// Prints a fixed table.
void printTableInt (int table [][5], int repeat);
void printTableFloat (float table [][5], int repeat);

// Print width for table display.
int printW = 12;


int main () {
  Sequence sequence;

  // Single Instance - Sorted
  cout << "Single Instance - Sorted" << endl;
  test (sequence, 1, 0, false);
  // Single Instance - Reverse
  cout << "Single Instance - Reverse" << endl;
  test (sequence, 1, 1, false);
  // Single Instance - Random
  cout << "Single Instance - Random" << endl;
  test (sequence, 1, 2, false);

  cout << "Multiple Instance - Random" << endl;
  // Multiple instance - Random
  test (sequence, 50, 2, true);

  return 0;
}

void test (Sequence & sequence, int repeat, int order, bool average) {

  // The object to sort the sequence.
  Sort sort;

  // Data to keep track of steps and time.
  clock_t time1, time2, timeD;
  float time;
  int steps;

  // Arrays to hold values for printing.
  int stepsTable [8][5];
  float timeTable [8][5];

  // Loop through rows.
  for (int i = 0; i < 8; i++) {

    // Determine amount of elements.
    int n = getN (i);
    sequence.initialize (n);

    // Loop through columns
    for (int j = 0; j < 5; j++) {

      // Initialize time and steps for this column.
      steps = 0;
      time = 0;

      // Iterate based on how many repitions.
      for (int r = 0; r < repeat; r++) {

        // Pre-order sequence.
        switch (order) {
          case 0:
            sequence.ascend();
            break;
          case 1:
            sequence.descend();
            break;
          case 2:
            sequence.random();
            break;
          default:
            sequence.random();
            break;
        }

        // Get start time.
        time1 = clock();

        // Run a test based on column.
        switch (j) {
          case 0:
            sort.insertion(sequence.getArray(), sequence.getLength(), steps);
            break;
          case 1:
            sort.selection(sequence.getArray(), sequence.getLength(), steps);
            break;
          case 2:
            sort.bubble(sequence.getArray(), sequence.getLength(), steps);
            break;
          case 3:
            sort.merge(sequence.getArray(), sequence.getLength(), steps);
            break;
          case 4:
            sort.quick(sequence.getArray(), 0, sequence.getLength() - 1, steps);
            break;
          default:
            break;
        }

        // Get end time.
        time2 = clock();

        // Calculate time elapsed.
        timeD = time2 - time1;
        time += (float) timeD / CLOCKS_PER_SEC;

      }

      // Add value to table.
      stepsTable [i][j] = steps;
      timeTable [i][j] = time;

    }
  }

  // Print step table. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  cout << "Steps (Assignments, swaps, and comparions)" << endl;
  printTableInt (stepsTable, 1);

  // Print time table. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  cout << "Time in seconds." << endl;
  printTableFloat (timeTable, 1);

  // If the average was to be printed. Usuallly for multiple repeated instances.
  if (average) {
    cout << "AVERAGES" << endl;
    // Print step table. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    cout << "Steps (Assignments, swaps, and comparions)" << endl;
    printTableInt (stepsTable, repeat);

    // Print time table. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    cout << "Time in seconds." << endl;
    printTableFloat (timeTable, repeat);
  }
}

int getN (int row) {
  switch (row) {
    case 0:
      return 100;
      break;
    case 1:
      return 200;
      break;
    case 2:
      return 300;
      break;
    case 3:
      return 400;
      break;
    case 4:
      return 500;
      break;
    case 5:
      return 1000;
      break;
    case 6:
      return 2000;
      break;
    case 7:
      return 4000;
      break;
  }
}

void printTableInt (int table [][5], int repeat) {
  cout << left << setw(printW) << "." << "\t";
  for (int i = 0; i < 5; i++) {
    switch (i) {
      case 0:
        cout << left << setw(printW) << "insertion" << "\t";
        break;
      case 1:
        cout << left << setw(printW) << "selection" << "\t";
        break;
      case 2:
        cout << left << setw(printW) << "bubble" << "\t";
        break;
      case 3:
        cout << left << setw(printW) << "merge" << "\t";
        break;
      case 4:
        cout << left << setw(printW) << "quick" << "\t";
        break;
    }
  }
  cout << endl;

  // Print time table values. Loop through rows.
  for (int i = 0; i < 8; i++) {
    // Get row info.
    int n = getN (i);
    // Print row info.
    cout << left << setw(printW) << n << "\t";
    // Loop through columns.
    for (int j = 0; j < 5; j++) {
      cout << left << setw(printW) << fixed << table [i][j] / repeat << "\t";
    }
    // End of row.
    cout << endl;
  }

  // End of step table.
  cout << endl << endl;
}

void printTableFloat (float table [][5], int repeat) {
  cout << left << setw(printW) << "." << "\t";
  for (int i = 0; i < 5; i++) {
    switch (i) {
      case 0:
        cout << left << setw(printW) << "insertion" << "\t";
        break;
      case 1:
        cout << left << setw(printW) << "selection" << "\t";
        break;
      case 2:
        cout << left << setw(printW) << "bubble" << "\t";
        break;
      case 3:
        cout << left << setw(printW) << "merge" << "\t";
        break;
      case 4:
        cout << left << setw(printW) << "quick" << "\t";
        break;
    }
  }
  cout << endl;

  // Print time table values. Loop through rows.
  for (int i = 0; i < 8; i++) {
    // Get row info.
    int n = getN (i);
    // Print row info.
    cout << left << setw(printW) << n << "\t";
    // Loop through columns.
    for (int j = 0; j < 5; j++) {
      cout << left << setw(printW) << fixed << table [i][j] / repeat << "\t";
    }
    // End of row.
    cout << endl;
  }

  // End of step table.
  cout << endl << endl;
}
