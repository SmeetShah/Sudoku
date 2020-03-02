#include<stdio.h>
#include<stdlib.h>

int solve(int** mat,int size);
int isvalid(int**mat,int row,int col,int n);
void print(int** mat);


int main(int argc, char** argv){

  FILE* fp=fopen(argv[1],"r");

  int **matrix;
  matrix = (int**)malloc(9*sizeof(int*));

  for(int i=0;i<9;i++){

      matrix[i]=(int*)malloc(9*sizeof(int));

  }

  char n;

  //reading the sudoku from the textfile
  for(int i =0;i<9;i++){

      for(int j=0;j<9;j++){

          fscanf(fp,"%c ", &n);

          if(n=='-'){

              matrix[i][j]= 0;

          }else{

              matrix[i][j]= n -'0';

          }

      }

      fscanf(fp,"\n");
  }

  if(solve(matrix,9)==1){

    print(matrix);

  }else{

    printf("no-solution");

  }


  return 0;
}

int solve(int** mat,int size){
  //Looking for the empty cell
  int empty=1;
  int row =-1;
  int col =-1;

  for(int i=0;i<size;i++){

      for(int j=0;j<size;j++){

          //if finds an empty cell change value of row and column
          if(mat[i][j]==0){

              row =i;
              col=j;
              empty=0;
              break;

          }else continue;

      }

      if(empty==0){
          break;

      }

  }

  if(empty==1){

      return 1;

  }

  //itarate from 1 to 9 number for that cell
  for(int i=1;i<size+1;i++){

      //cheacking if it's possible
      if(isvalid(mat,row,col,i) == 1){

          mat[row][col]= i;
          if(solve(mat,size)){

              return 1;

          }else{

              mat[row][col]=0;

          }

    }

  }

  return 0;
}

//search through column, row and sub grid.
int isvalid(int** mat,int row, int col,int n){

  int result=1;
  //1)search through row

    for(int j=0;j<9;j++){

        if(mat[row][j]==n){

            result =0;
            return result;

        }else continue;

    }

  //2)search through columns

    for(int i=0;i<9;i++){

        if(mat[i][col]==n){

            result =0;
            return result;

        }else continue;

    }

  //3)search throuch subgrid 3x3
    row = row /3;
    col = col/3;

    int startr = row + (2*row);
    int startc = col + (2*col);

    for(int i = startr; i<(startr+3);i++){

        for(int j = startc; j<(startc+3);j++){

            if(mat[i][j]==n){

                result =0;
                return result;

            }else continue;

        }

    }

    //return result if not returned already
    return result;
}

//helping method for printing the sudoku
void print(int** mat){

  for(int i=0;i<9;i++){

    for(int j=0;j<9;j++)printf("%d\t",mat[i][j]);

    printf("\n");

  }

}
