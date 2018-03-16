#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
// #include<math.h>

#define INFINITY 10000
#define match 1
#define mismatch -1
#define gap -2

// typedef struct Parent{      // 0 for left, 1 for digonal, 2 for top
//   int a[3];
//   int b[3];
// }Parent;

typedef struct Score{      // 0 for left, 1 for digonal, 2 for top
  int score;
  struct Score *parent[3];
}Score;

void global_alignment(char seq1[], char seq2[]);
int max(Score **s, int t, int l, int d, int i, int j);

void main(int argc, char** argv){
  if(argc!=3){
    printf("Usage: %s Sequence 1 Sequence 2\n",argv[0]);
    exit(0);
  }
  global_alignment(argv[1],argv[2]);
}

void global_alignment(char seq1[], char seq2[]){
  int x,y,i,j,t,l,d,k;
  int **ptr;
  x=strlen(seq1);
  y=strlen(seq2);

  // int **score=(int **)malloc((x+1)*sizeof(int *));
  // for(i=0;i<x+1;i++) score[i]=(int *)malloc((y+1)*sizeof(int *));

  // Parent **parent=(Parent **)malloc((x+1)*sizeof(Parent *));
  // for(i=0;i<x+1;i++) parent[i]=(Parent *)malloc((y+1)*sizeof(Parent *));

  Score **s=(Score **)malloc((x+1)*sizeof(Score *));
  for(i=0;i<x+1;i++) s[i]=(Score *)malloc((y+1)*sizeof(Score *));

  for(i=0;i<x+1;i++){
    for(j=0;j<y+1;j++){
      s[i][j].score=0;
      // for(k=0;k<3;k++) s[i][j].parent[i]=NULL;
    }
  }
  for(i=0;i<x+1;i++){
    if(i==0)
      s[i][0].score=0;
    else{
      s[i][0].score=s[i-1][0].score+gap;
      // s[i][0].parent[2]=&s[i-1][0];
    }
  }
  for(j=0;j<y+1;j++){
    if(j==0){
      s[0][j].score=0;
    }
    else{
      s[0][j].score=s[0][j-1].score+gap;
      // s[0][j].parent[0]=&s[0][j-1];
    }
  }
  for(i=1;i<x+1;i++){
    for(j=1;j<y+1;j++){
      l=s[i][j-1].score+gap;
      t=s[i-1][j].score+gap;
      if(seq1[i-1]==seq2[j-1])
        d=s[i-1][j-1].score+match;
      else
        d=s[i-1][j-1].score+mismatch;
      s[i][j].score=max(s,t,l,d,i,j);
    }
  }
  for(i=0;i<x+1;i++){
    for(j=0;j<y+1;j++){
      printf("%d\t",s[i][j].score);
    }
    printf("\n");
  }
  i=x+1;
  j=y+1;
  // ptr=&score[x][y];
  // while (ptr!=NULL) {
  //   if(parent)
  // }
  // for(i=0;i<x+1;i++) free(s[i]);
  free(s);
}


int max(Score **s, int t, int l, int d, int i, int j){
  int maximum=(int)(-INFINITY);
  if(l>maximum)
    maximum=l;
  if(t>maximum)
    maximum=t;
  if(d>maximum)
    maximum=d;

  // if(d==maximum){
  //   s[i][j].parent[1]=&s[i-1][j-1];
  // }
  // if(l==maximum){
  //   s[i][j].parent[0]=&s[i-1][j];
  // }
  // if(t==maximum){
  //   s[i][j].parent[2]=&s[i][j-1];
  // }

  return maximum;
}
