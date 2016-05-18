#include "sequence.h"
#include <cstdlib>
#include <ctime>

Sequence::Sequence () {}

Sequence::~Sequence () {
  // If the arr was initialized.
  if (initialized) {
    delete [] arr;
  }
}

void Sequence::initialize (int n) {

  // If arr wasn't already initialized before.
  if (!initialized) {
    // Set initialize to true;
    initialized = true;
  // If it was already initialized.
  } else {
    // Delete the previous one.
    delete [] arr;
  }

  // Create new array.
  length = n;
  arr = new int [length];
  for (int i = 0; i < length; i++) {
    * (arr + i) = i;
  }

}

// Uses insertion sort.
void Sequence::ascend () {
  int j, temp;

  // Loop through the array until length is reached.
  for (int i = 0; i < length; i++) {

    // Set the current to be checked element.
    j = i;

    // Swap the element backwards until it is greater than the element before it.
    while (j > 0 && * (arr + j) < * (arr + j - 1)) {
      temp = * (arr + j);
      * (arr + j) = * (arr + j - 1);
      * (arr + j - 1) = temp;
      j -= 1;
    }
  }
}

// Uses insertion sort.
void Sequence::descend () {
  int j, temp;

  // Loop through the array until length is reached.
  for (int i = 0; i < length; i++) {

    // Set the current to be checked element.
    j = i;

    // Swap the element backwards until it is less than the element before it.
    while (j > 0 && * (arr + j) > * (arr + j - 1)) {
      temp = * (arr + j);
      * (arr + j) = * (arr + j - 1);
      * (arr + j - 1) = temp;
      j -= 1;
    }
  }
}

void Sequence::random () {
  // Initialize seed based on current time.
  srand(time(0));
  int r, temp;
  for (int i = 0; i < length; i++) {
    // Get random position.
    r = rand() % length;
    // Temp current element.
    temp = *(arr + i);
    // Give current element the value from random position.
    *(arr + i) = *(arr + r);
    // Give the random element the current value.
    *(arr + r) = temp;
  }
}

int* Sequence::getArray () {
  return arr;
}

int Sequence::getLength () const {
  return length;
}
