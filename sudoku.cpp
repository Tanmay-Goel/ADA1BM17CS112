#include<iostream>
#define UNASSIGNED 0
#define N 4
#define SQN 2
using namespace std;
using namespace std::chrono;


bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{

for (int row = 0; row < SQN; row++)

  for (int col = 0; col < SQN; col++)

    if (grid[row+boxStartRow][col+boxStartCol] == num)

      return true;

return false;
}


bool UsedInRow(int grid[N][N], int row, int num)
{

for (int col = 0; col < N; col++)

  if (grid[row][col] == num)

    return true;

return false; }


bool UsedInCol(int grid[N][N], int col, int num)
{

for (int row = 0; row < N; row++)

  if (grid[row][col] == num)

    return true;

return false; }


bool isSafe(int grid[N][N], int row, int col, int num)
{

return !UsedInRow(grid, row, num) &&

       !UsedInCol(grid, col, num) &&

       !UsedInBox(grid, row - row%SQN , col - col%SQN, num);

}

bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
for (row = 0; row < N; row++)

  for (col = 0; col < N; col++)

    if (grid[row][col] == UNASSIGNED)

      return true;

return false;
}


bool SolveSudoku(int grid[N][N])

{ int row, col;

if (!FindUnassignedLocation(grid, row, col))

  return true; 

for (int num = 1; num <= N; num++)

{

  if (isSafe(grid, row, col, num)) 

    {

      grid[row][col] = num; 
      if (SolveSudoku(grid))

	return true;

      grid[row][col] = UNASSIGNED;  
    }

} 
return false; 
}


int main()
{
int g[N][N], i, j;
cout<<"Enter incomplete 4x4 sudoku grid:\n";
for(i=0;i<N;i++)
  for(j=0;j<N;j++)
    cin>>g[i][j];

auto start = high_resolution_clock::now();
bool result=SolveSudoku(g);
auto stop = high_resolution_clock::now();

if(result)
{
cout<<"\nSolution: \n";
for(i=0;i<N;i++)
  {
   for(j=0;j<N;j++)
     cout<<g[i][j]<<" ";
   cout<<endl;
  }
}

else
cout<<"\nInvalid Grid: ";

std::chrono::duration<double, std::milli> fp_ms = stop - start;
	
cout<<"\ntime in milliseconds: "<<fp_ms.count()<<endl;

return 0;
}