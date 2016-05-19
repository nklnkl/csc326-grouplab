#ifndef _SORT
#define _SORT

class Sort {
  public:
    Sort ();
    ~Sort ();
    void insertion (int * arr, int length, int & steps) const;
    void selection (int * arr, int length, int & steps) const;
    void bubble (int * arr, int length, int & steps) const;
    void merge (int * arr, int length, int & steps);
    void quick (int * arr, int start, int length, int & steps);
    void mergeStep (int * arr, int n1, int n2, int & steps);
    int partitionStep (int * arr, int start, int length, int & steps);
    void swap (int* val1, int* val2);
  private:
};

#endif
