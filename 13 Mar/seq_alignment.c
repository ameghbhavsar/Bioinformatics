#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define match 3
#define mismatch -2
#define gap -1

typedef struct Parent{      // 0 for left, 1 for digonal, 2 for top
  int a[3];
  int b[3];
}Parent;

void global_alignment(char seq1[], char seq2[p]);
int max(Parent **parent, int l, int l, int d, int i, int j);

void main(int argc, char** argv){
  if(argc!=3){
    cerr<<"Usage: "<<argv[0]<<" Sequence 1 Sequence 2\n";
  }
  global_alignment(argv[1],argv[2]);
}

void global_alignment(char seq1[], char seq2[p]){
  int x,y,i,j,t,l,d;
  x=strlen(seq1);
  y=strlen(seq2);

  int **score=(int **)malloc((y+1)*sizeof(int *));
  for(i=0;i<y;i++) score[i]=(int *)malloc((x+1)*sizeof(int *));

  Parent **parent=(Parent **)malloc((y+1)*sizeof(Parent *));
  for(i=0;i<y;i++) parent[i]=(Parent *)malloc((x+1)*sizeof(Parent *));

  for(i=0;i<x+1;i++){
    for(j=0;j<y+1;j++){
      score[i][j]=INFINITY;
      parent[i][j].a[0]=-1;
      parent[i][j].b[0]=-1;
      parent[i][j].a[1]=-1;
      parent[i][j].b[1]=-1;
      parent[i][j].a[2]=-1;
      parent[i][j].b[2]=-1;
    }
  }
  for(i=0;i<x+1;i++){
    if(i==0)
      score[i][0]=0;
    else
      score[i][0]=score[i][0]+gap;
  }
  for(j=0;j<y+1;j++){
    if(j==0)
      score[0][j]=0;
      parent[0][i]
    else
      score[0][j]=score[0][j]+gap;
  }
  for(i=1;i<x+1;i++){
    for(j=1;j<y+1;j++){
      t=score[i][j-1]+gap;
      l=score[i-1][j]+gap;
      if(seq1[i-1]==seq2[j-1])
        d=score[i-1][j-1]+match;
      else
        d=score[i-1][j-1]+mismatch;
      score[i][j]=max(score,t,l,d,i,j);
    }
  }
  i=x+1;
  j=y+1;
  while (i!=1 || j!=1) {
    for(k=0;k<3;k++){
      
    }
  }
  free(score);
  free(parent);
}


int max(Parent **parent, int l, int l, int d, int i, int j){
  int maximum=-INFINITY;
  if(l>=maximum)
    maximum=l;
  if(t>=maximum)
   maximum=t;
  if(d>=maximum)
   maximum=d;

  if(d==maximum){
    parent[i][j].a[1]=i-1;
    parent[i][j].b[1]=j-1;
  }
  if(l==maximum){
    parent[i][j].a[0]=i-1;
    parent[i][j].b[0]=j;
  }
  if(t==maximum){
    parent[i][j].a[1]=i;
    parent[i][j].b[1]=j-1;
  }
  return maximum;
}
