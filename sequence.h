#ifndef _SEQUENCE
#define _SEQUENCE

class Sequence {
  public:
    Sequence ();
    ~Sequence ();
    void initialize (int length = 100);
    void ascend ();
    void descend ();
    void random ();
    int * getArray ();
    int getLength () const;
  private:
    int * arr;
    int length;
    bool initialized;
};

#endif
