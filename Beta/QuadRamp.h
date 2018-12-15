#ifndef QuadRamp
#define QuadRamp
class QuadRamp{
  public:
    double eval(double input);
  private:
    double a, b, c;
    QuadRamp(double dist, double begin, double max, double end)
};
#endif
