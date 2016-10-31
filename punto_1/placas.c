#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
  int i;
  int j;
  int k;
  float L = 0.05;
  float l = 0.02;
  float d = 0.01;
  float h = 0.0002;
  float V_0 = 100;
  float pot = V_0/2.0;
  float der;
  int N = (int)(2*(powf(L/h,2)));
  float *grid;
  float *future;
  int size = (int)(L/h);
  int gridsize = size*size;
  int relposd = (int)(d/(2.0*h));
  int relposl = (int)(l/(2.0*h));
  grid = malloc(gridsize*sizeof(float));
  future = malloc(gridsize*sizeof(float));

  for(i=1;i<size-1;i++)
    {
      for(j=1;j<size-1;j++)
	{
	  if(i==((size/2)-1)-relposd)
	    {
	      if(j>=((size/2)-1)-relposl && j<=((size)/2-1)+relposl)
		{
		  grid[size*i+j] = pot;
		}
	      else
		{
		  grid[size*i+j] = 25.0;
		}
	    }
	  else if(i==((size/2)-1)+relposd)
	    {
	      if(j>=((size/2)-1)-relposl && j<=((size)/2-1)+relposl)
		{
		  grid[size*i+j] = -pot;
		}
	      else
		{
		  grid[size*i+j] = 25.0;
		}
	    }
	  else
	    {
	      grid[size*i+j] = 25.0;
	    }
	}
    }
  
  for(i=0;i<size;i++)
    {
      grid[i] = 0.0;
      grid[size*i] = 0.0;
    }

  for(k=0;k<N;k++)
    {
      for(i=1;i<size-1;i++)
	{
	  for(j=1;j<size-1;j++)
	    {
	      if(i!=((size/2)-1)-relposd && i!=((size/2)-1)+relposd)
		{
		  future[size*i+j] = 0.25*(grid[size*i+j+1]+grid[size*(i+1)+j]+grid[size*i+j-1]+grid[size*(i-1)+j]-powf(h,2)*grid[size*i+j]);
		}
	      else
		{
		  if(j<((size/2)-1)-relposl || j>((size/2)-1)+relposl)
		    {
		      future[size*i+j] = 0.25*(grid[size*i+j+1]+grid[size*(i+1)+j]+grid[size*i+j-1]+grid[size*(i-1)+j]-powf(h,2)*grid[size*i+j]);
		    }
		  else
		    {
		      future[size*i+j] = grid[size*i+j];
		    }
		}
	    }
	}
      for(i=1;i<size-1;i++)
	{
	  for(j=1;j<size;j++)
	    {
	      grid[size*i+j] = future[size*i+j];
	    }
	}
    }

  FILE *f = fopen("potential.dat","w");
  for(i=0;i<size;i++)
    {
      for(j=0;j<size;j++)
	{
	  fprintf(f,"%f ",grid[size*i+j]);
	}
      fprintf(f,"\n");
    }
  fclose(f);

  FILE *fieldx = fopen("fieldx.dat","w");
  for(i=0;i<size;i++)
    {
      for(j=0;j<size;j++)
	{
	  if(j==0)
	    {
	      der = -(grid[size*i+j+1]-grid[size*i+j])/h;
	      fprintf(fieldx,"%f ",der);
	    }
	  else if(j==size-1)
	    {
	      der = -(grid[size*i+j]-grid[size*i+j-1])/h;
	      fprintf(fieldx,"%f ",der);
	    }
	  else
	    {
	      der = -(grid[size*i+j+1]-grid[size*i+j-1])/(2.0*h);
	      fprintf(fieldx,"%f ",der);
	    }
	}
      fprintf(fieldx,"\n");
    }
  fclose(fieldx);

  FILE *fieldy = fopen("fieldy.dat","w");
  for(i=0;i<size;i++)
    {
      for(j=0;j<size;j++)
	{
	  if(i==0)
	    {
	      der = (grid[size*(i+1)+j]-grid[size*i+j])/h;
	      fprintf(fieldy,"%f ",der);
	    }
	  else if(i==size-1)
	    {
	      der = (grid[size*i+j]-grid[size*(i-1)+j])/h;
	      fprintf(fieldy,"%f ",der);
	    }
	  else
	    {
	      der = (grid[size*(i+1)+j]-grid[size*(i-1)+j])/(2.0*h);
	      fprintf(fieldy,"%f ",der);
	    }
	}
      fprintf(fieldy,"\n");
    }
  fclose(fieldy);

  return 0;
}
