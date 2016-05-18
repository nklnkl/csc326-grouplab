#include "sort.h"

Sort::Sort () {}
Sort::~Sort () {}

void Sort::insertion (int * arr, int length, int repeat, int & steps) const {

  int j, temp;

  // Loop through the array until length is reached.
  for (int i = 0; i < length; i++) {

    // Increment steps for i < length. +1
    steps += 1;

    // Set the current to be checked element.
    j = i;

    // Swap the element backwards until it is greater than the element before it.
    // Increment steps for first while comparison.
    steps += 1;
    while (j > 0 && * (arr + j) < * (arr + j - 1)) {
      temp = * (arr + j);
      * (arr + j) = * (arr + j - 1);
      * (arr + j - 1) = temp;
      j -= 1;
      // Increment steps for the swap. +1
      steps += 1;
      // Increment steps for the next while loop comparison. +2
      steps += 2;
    }
  }
  return;
}

void Sort::selection (int * arr, int length, int repeat, int & steps) const {

  int highest, temp;

  for (int i = 0; i < length; i++) {

    // Increment steps for i < length comparison. +1
    steps += 1;

    highest = 0;

    for (int j = 0; j < length - i; j++) {

      // Increment steps for j < length - i. +1
      steps += 1;

      // Increment steps for if comparision.
      steps += 1;
      if ( *(arr + j) > *(arr + highest) ) {
        highest = j;
      }

    }

    // Temporarily store the highest value.
    temp = *(arr + highest);
    // Swap.
    *(arr + highest) = *(arr + length - 1 - i);
    *(arr + length - 1 - i) = temp;
    // Increment steps for the swap. +1
    steps += 1;

  }
}

void Sort::bubble (int * arr, int length, int repeat, int & steps) const {
  int temp;

  // Make n amount of passes.
  for (int i = 0; i < length; i++ ) {

    // Increment steps for i < length comparisons.
    steps += 1;

    // Loop through the current sequence minus the amount of passes made.
    for (int j = 0; j < length - i - 1; j++) {

      // Increment steps for j < length comparisons.
      steps += 1;

      // Increment steps for if comparisons.
      steps += 1;
      if ( *(arr + j) > * (arr + j + 1)) {
        // Cache the current element value.
        temp = * (arr + j);
        // Assign the current element the value of the next element.
        * (arr + j) = * (arr + j + 1);
        // Assign the next element's value the value of the cached value.
        * (arr + j + 1) = temp;
        // Increment steps for swap.
        steps += 1;
      }
    }
  }
}

void Sort::merge (int * arr, int length, int repeat, int & steps) {
  // Increment steps for if comparison.
  steps += 1;
  if (length == 1) return;
  int size1 = length/2, size2 = length-size1;

  merge(arr, size1, repeat, steps);
  merge(arr+size1, size2, repeat, steps);
  mergeStep(arr, size1, size2, steps);
  return;
}

void Sort::mergeStep (int * arr, int n1, int n2, int & steps) {
  int temp[ n1 + n2 ];
  int p1=0, p2=0;

  // Increment steps for first while comparison.
  steps += 1;

  while ( p1+p2 < n1+n2 ) {

    // Increment steps for if comparions.
    steps += 1;
    if (p1 < n1 && arr[p1] <= arr[n1+p2] || p1 < n1 && p2 >= n2) {
      temp[p1+p2] = arr[p1++];
    }

    // Increment steps for if comparions.
    steps += 1;
    if (p2 < n2 && arr[n1+p2] < arr[p1] || p2 < n2 && p1 >= n1) {
      temp[p1+p2] = arr[n1+p2++];
    }

    // Increment steps for next while comparison.
    steps += 1;
  }

  for (int i=0; i < n1+n2; i++)
      arr[i] = temp[i];
  return;
}

void Sort::quick (int * arr, int start, int length, int repeat, int & steps) {
  int part;
  // Increment steps for if comparion. +1
  steps += 1;
	if(start < length) {
		part = partitionStep(arr, 0, length, steps);
		quick(arr, start, part-1, repeat, steps);
		quick(arr, part+1, length, repeat, steps);
	}
}

int Sort::partitionStep (int * arr, int start, int length, int & steps) {
  int i = start-1, j = start;
  int key = arr[length];

  // Increment steps for first while comparison.
  steps += 1;

  while(j < length) {

    // Increment steps for if comparison.
    steps += 1;
    if(arr[j] <= key) {
      i++;

      // Increment steps for if comparison.
      steps += 1;

      if(i!=j) {

        swap(&arr[i], &arr[j]);

        // Increment steps for swap.
        steps += 1;

      }
    }
    j++;

    // Increment steps for next while comparison.
    steps +=1;
  }

  swap(&arr[i+1], &arr[length]);
  // Increment steps for swap.
  steps += 1;

  return i+1;
}

void Sort::swap(int* val1, int* val2) {
	int temp;
	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}
