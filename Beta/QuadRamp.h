#ifndef QuadRamp
#define QuadRamp
class QuadRamp{
  public:
    float eval(float input);
  private:
    float a, b, c;
    QuadRamp(float dist, float begin, float max, float end)
};
#endif
