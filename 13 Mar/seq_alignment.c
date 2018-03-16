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

typedef struct Parent{      // 0 for left, 1 for digonal, 2 for top
  int *p[3];
}Parent;

void global_alignment(char seq1[], char seq2[]);
int max(Parent **parent,int **score, int t, int l, int d, int i, int j);

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

  int **score=(int **)malloc((x+1)*sizeof(int *));
  for(i=0;i<x+1;i++) score[i]=(int *)malloc((y+1)*sizeof(int *));

  Parent **parent=(Parent **)malloc((x+1)*sizeof(Parent *));
  for(i=0;i<x+1;i++) parent[i]=(Parent *)malloc((y+1)*sizeof(Parent *));

  for(i=0;i<x+1;i++){
    for(j=0;j<y+1;j++){
      score[i][j]=(int)INFINITY;
      // parent[i][j].a[0]=-1;
      // parent[i][j].b[0]=-1;
      // parent[i][j].a[1]=-1;
      // parent[i][j].b[1]=-1;
      // parent[i][j].a[2]=-1;
      // parent[i][j].b[2]=-1;
      for(k=0;k<3;k++) parent[i][j].p[i]=NULL;
    }
  }
  for(i=0;i<x+1;i++){
    if(i==0)
      score[i][0]=0;
    else
      score[i][0]=score[i-1][0]+gap;
      parent[0][j].p[2]=&score[i-1][0];
  }
  for(j=0;j<y+1;j++){
    if(j==0){
      score[0][j]=0;
    }
    else
      score[0][j]=score[0][j-1]+gap;
      parent[0][j].p[0]=&score[0][j-1];
  }
  for(i=1;i<x+1;i++){
    for(j=1;j<y+1;j++){
      t=score[i][j-1]+gap;
      l=score[i-1][j]+gap;
      if(seq1[i-1]==seq2[j-1])
        d=score[i-1][j-1]+match;
      else
        d=score[i-1][j-1]+mismatch;
      score[i][j]=max(parent,score,t,l,d,i,j);
    }
  }
  for(i=0;i<x+1;i++){
    for(j=0;j<y+1;j++){
      printf("%d\t",score[i][j]);
    }
    printf("\n");
  }
  i=x+1;
  j=y+1;
  // ptr=&score[x][y];
  // while (ptr!=NULL) {
  //   if(parent)
  // }
  free(score);
  free(parent);
}


int max(Parent **parent,int **score, int t, int l, int d, int i, int j){
  int maximum=(int)(-INFINITY);
  if(l>=maximum)
    maximum=l;
  if(t>=maximum)
   maximum=t;
  if(d>=maximum)
   maximum=d;

  if(d==maximum){
    // parent[i][j].a[1]=i-1;
    // parent[i][j].b[1]=j-1;
    parent[i][j].p[1]=&score[i-1][j-1];
  }
  if(l==maximum){
    // parent[i][j].a[0]=i-1;
    // parent[i][j].b[0]=j;
    parent[i][j].p[1]=&score[i-1][j];
  }
  if(t==maximum){
    // parent[i][j].a[1]=i;
    // parent[i][j].b[1]=j-1;
    parent[i][j].p[1]=&score[i][j-1];
  }
  return maximum;
}
