#include "QuadRamp.h"

QuadRamp::QuadRamp(int dist, int begin, int max, int end) {
   a = ((end + begin - 2*max) - 2*sqrt((end-max) * (initial-max))) / (dist * dist);
   b = ((end-initial)/dist - a*dist) * SGN(dist);
   c = start;
}

float QuadRamp::eval(int input) {
  return a*input*input + b*input + c;
}
