#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include</home/arthik/TENACIOUS/PYTHON/GESTURE_KEYBOARD/ImplementationC/DigitsData.h>
#include</home/arthik/TENACIOUS/PYTHON/GESTURE_KEYBOARD/ImplementationC/IN.h>

void multiply(float *,int,int,float *,int,int,float *,int *,int *);
void add(float *,int,int,float *,int,int,float *,int *,int *);
void ReLU(float *,int,int);
void softmax(float *,int,int);
void printout(float *,int,int);

void main()
{
	int row1,col1,row2,col2,row3,col3,i,j;
	float result_mul[1000]; //2D array stored as a 1D array
	float result_add[1000]; //2D array stored as a 1D array
	float *p1, *p2, *p3;
	
	p1 = &IN[0][0];
	p2 = &d0kernal_0[0][0];
	p3 = result_mul;
	row1 = 1;
	col1 = 123;
	row2 = 123;
	col2 = 10;

	multiply(p1,row1,col1,p2,row2,col2,p3,&row3,&col3);

	p1 = p3;
	p2 = &d0bias_0[0][0];
	p3 = result_add;
	row1 = row3;
	col1 = col3;
	row2 = 1;
	col2 = 10;

	add(p1,row1,col1,p2,row2,col2,p3,&row3,&col3);
	ReLU(p3,row3,col3);

	p1 = result_add;
	p2 = &d1kernal_0[0][0];
	p3 = result_mul;
	row1 = row3;
	col1 = col3;
	row2 = 10;
	col2 = 10;

	multiply(p1,row1,col1,p2,row2,col2,p3,&row3,&col3);

	p1 = p3;
	p2 = &d1bias_0[0][0];
	p3 = result_add;
	row1 = row3;
	col1 = col3;
	row2 = 1;
	col2 = 10;

	add(p1,row1,col1,p2,row2,col2,p3,&row3,&col3);
	ReLU(p3,row3,col3);

	p1 = result_add;
	p2 = &d2kernal_0[0][0];
	p3 = result_mul;
	row1 = row3;
	col1 = col3;
	row2 = 10;
	col2 = 4;

	multiply(p1,row1,col1,p2,row2,col2,p3,&row3,&col3);

	p1 = p3;
	p2 = &d2bias_0[0][0];
	p3 = result_add;
	row1 = row3;
	col1 = col3;
	row2 = 1;
	col2 = 4;

	add(p1,row1,col1,p2,row2,col2,p3,&row3,&col3);

	printf("\nPrinting the Computed Raw Result : \n");
	for(i=0;i<row3;i++)
	{
		for(j=0;j<col3;j++)
		{
			printf("%f  ",*(p3 + i*col3 +j));
		}
		printf("\n");
	}

	softmax(p3,row3,col3);

	printf("\nPrinting the Computed Softmax Result : \n");
	for(i=0;i<row3;i++)
	{
		for(j=0;j<col3;j++)
		{
			printf("%f  ",*(p3 + i*col3 +j));
		}
		printf("\n");
	}

	printout(p3,row3,col3);
}

void multiply(float *p1, int row1, int col1, float *p2, int row2, int col2, float *p3, int *row3, int *col3)
{
  int i, j, k;

  for (i = 0; i < row1; i++)
  {
    for (j = 0; j < col2; j++)
    {
      *(p3 + i*col2 + j) = 0;
      for (k = 0; k < row2; k++)
      {
        *(p3 + i*col2 + j) += *(p1 + i*col1 + k) * *(p2 + k*col2 + j);
      }
    }
  }

  *row3 = row1;
  *col3 = col2;
}

void add(float *p1, int row1, int col1, float *p2, int row2, int col2, float *p3, int *row3, int *col3)
{
  int i, j;

  for (i = 0; i < row1; i++)
  {
    for (j = 0; j < col2; j++)
    {
      *(p3 + i*col2 + j) = *(p1 + i*col2 + j) + *(p2 + i*col2 + j);
    }
  }

  *row3 = row1;
  *col3 = col2;
}

void ReLU(float *p, int row, int col)
{
	int i,j;
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
    	if(*(p + i*col + j)<0)
    	{
    		*(p + i*col + j)=0;
    	}
    }
  }
}

void softmax(float *p, int row, int col)
{
	float max=*p,sum=0;
	int i,j;

	for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
    	if(*(p + i*col + j) > max)
    	{
    		max = *(p + i*col + j);
    	}
    }
  }

  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
    	sum += exp(*(p + i*col + j) - max);
    }
  }

  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
    	*(p + i*col + j) = (exp(*(p + i*col + j) - max))/sum;
    }
  }
}

void printout(float *p,int row,int col)
{
	int i,j,index=0;
	float max=*p;

	for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
    	if(*(p + i*col + j) > max)
    	{
    		max = *(p + i*col + j);
    		index = j;
    	}
    }
  }

  printf("\nThe predicted Integer is : %d\n", index);
  printf("Detected with %f%% confidence.\n", *(p + index)*100.0);
}