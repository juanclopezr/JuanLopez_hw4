#include <stdio.h>
#include <math.h>

int main()
{
  int n_points = 10000;
  float x[n_points];
  x[0] = 0.0;
  int i;
  int j;
  int number;
  float u_initial[n_points];
  float u_future[n_points];
  float u_past[n_points];
  float u_present[n_points];
  for(i=0;i<n_points;i++)
    {
      x[i] = (float)(i)*100/(float)(n_points-1);
      if(x[i]<=80.0)
	{
	  u_initial[i] = 1.25*x[i]/100.0;
	}
      else
	{
	  u_initial[i] = 5.0-5.0*x[i]/100.0;
	}
    }
  float delta_x = x[1]-x[0];
  float delta_t = 0.005;
  float c = 2.0;
  float r = c*delta_t/delta_x;
  int n_time = 40000;
  u_initial[0] = 0.0;
  u_initial[n_points-1] = 0.0;
  u_future[0] = 0.0;
  u_future[n_points-1] = 0.0;

  for(i=1;i<n_points-1;i++)
    {
      u_future[i] = u_initial[i] + ((r*r)/2.0) * (u_initial[i+1]-2.0*u_initial[i]+u_initial[i-1]);
    }
  char text0[256] = "cuerda00000.dat";
  FILE *f0 = fopen(text0,"w");
  for(i=0;i<n_points;i++)
    {
      fprintf(f0,"%f %f\n",x[i],u_initial[i]);
    }
  fclose(f0);
  for(i=0;i<n_points;i++)
    {
      u_past[i] = u_initial[i];
      u_present[i] = u_future[i];
    }

  for(i=0;i<n_time;i++)
    {
      for(j=1;j<n_points-1;j++)
	{
	  u_future[j] = (2.0*(1.0-r*r))*u_present[j] - u_past[j] + (r*r)*(u_present[j+1] +  u_present[j-1]);
	}
      if(i%100==0)
	{
	  char text[256];
	  number = (i+2)/100;
	  sprintf(text,"cuerda%05d.dat",number);
	  FILE *f = fopen(text,"w");
	  for(j=0;j<n_points;j++)
	    {
	      u_past[j] = u_present[j];
	      u_present[j] = u_future[j];
	      fprintf(f,"%f %f\n",x[j],u_present[j]);
	    }
	  fclose(f);
	}
      else
	{
	  for(j=0;j<n_points;j++)
	    {
	      u_past[j] = u_present[j];
	      u_present[j] = u_future[j];
	    }
	}
    }  
  return 0;
}
