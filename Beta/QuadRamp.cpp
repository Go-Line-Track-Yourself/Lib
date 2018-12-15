#ifndef QuadRamp_cpp
#define QuadRamp_cpp
class QuadRamp {
  public:
    QuadRamp() {
      a = 0;
      b = 0;
      c = 0;
    }

    double eval(double input) {
      return a*input*input + b*input + c;
    }

    void newRamp(double dist, double begin, double max, double end) {
      a = ((end + begin - 2*max) - 2*sqrt((end-max) * (begin-max))) / (dist * dist);
      b = ((end-begin)/dist - a*dist) * SGN(dist);
      c = begin;
    }

  private:
    double a;
    double b;
    double c;
};
#endif
