#include <stdio.h>
#include <math.h>

int main()
{
  int n_points = 1000;
  float x[n_points];
  x[0] = 0;
  int i;
  float u_initial[n_points];
  for(i=0;i<n_points;i++)
    {
      x[i] = (float)(i)/(float)(n_points-1);
      u_initial[i] = exp(-pow((x[i]-(float)0.3),2)/(float)0.01);
    }
  float delta_x = x[1]-x[0];
  float delta_t = 0.0005;
  float c = 1.0;
  float r = c*delta_t/delta_x;
  u_initial[0] = 0.0;
  u_initial[n_points-1] = 0.0;
  for(i=0;i<n_points;i++)
    {
      printf("%g\n",r);
    }
  return 0;
}
