#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
// #include<math.h>

#define INFINITY 10000
#define match 1
#define mismatch -1
#define gap -2

// #define match 1
// #define mismatch -1
// #define gap -8

typedef struct Score{      // 0 for left, 1 for digonal, 2 for top
  int score;
  struct Score *parent[3];
}Score;

void global_alignment(char seq1[], char seq2[]);
int max(Score **s, int t, int l, int d, int i, int j);
void align(Score *s, char *seq1, char *seq2,char *s1, char*s2, int i, int j,int l, int len, int flag);
char *strrev(char *str);

char *out1, *out2;

void main(int argc, char** argv){
  if(argc!=3){
    printf("Usage: %s Sequence 1 Sequence 2\n",argv[0]);
    exit(0);
  }
  global_alignment(argv[1],argv[2]);
}

void global_alignment(char seq1[], char seq2[]){
  int x,y,i,j,t,l,d,k;
  Score *ptr;
  x=strlen(seq1);
  y=strlen(seq2);

  Score **s=(Score **)malloc((x+1)*sizeof(Score *));
  for(i=0;i<x+1;i++) s[i]=(Score *)malloc((y+1)*sizeof(Score ));

  for(i=0;i<x+1;i++){
    for(j=0;j<y+1;j++){
      s[i][j].score=0;
      for(k=0;k<3;k++) s[i][j].parent[k]=NULL;
    }
  }
  for(i=0;i<x+1;i++){
    if(i==0)
      s[i][0].score=0;
    else{
      s[i][0].score=s[i-1][0].score+gap;
      s[i][0].parent[2]=&s[i-1][0];
    }
  }
  for(j=0;j<y+1;j++){
    if(j==0){
      s[0][j].score=0;
    }
    else{
      s[0][j].score=s[0][j-1].score+gap;
      s[0][j].parent[0]=&s[0][j-1];
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
        // s[i][j].score=max(t,l,d);
        s[i][j].score=max(s,t,l,d,i,j);
    }
  }
  for(i=0;i<x+1;i++){
    for(j=0;j<y+1;j++){
      printf("%d\t",s[i][j].score);
    }
    printf("\n");
  }
  ptr=&s[x][y];
  l=x+y;
  char *s1=(char *)malloc((l+1)*sizeof(char));
  char *s2=(char *)malloc((l+1)*sizeof(char));
  out1=(char *)malloc((l+1)*sizeof(char));
  out2=(char *)malloc((l+1)*sizeof(char));
  align(ptr, seq1, seq2, s1, s2, x-1, y-1, 0,l,0);
  for(i=0;i<x+1;i++) free(s[i]);
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

  if(d==maximum){
    s[i][j].parent[1]=&s[i-1][j-1];
  }
  if(l==maximum){
    s[i][j].parent[0]=&s[i][j-1];
  }
  if(t==maximum){
    s[i][j].parent[2]=&s[i-1][j];
  }

  return maximum;
}


void align(Score *s, char *seq1, char *seq2,char *s1, char*s2, int i, int j,int l,int len,int flag){
  int k;
  // if(flag==1){
  //   s1[l]=seq1[i];
  //   s2[l]=seq2[j];
  // }
  // else if(flag==0){
  //   s1[l]='-';
  //   s2[l]=seq2[j];
  // }
  // else if(flag==2){
  //   s2[l]='-';
  //   s1[l]=seq1[j];
  // }
  for(k=0;k<3;k++){
    if(s->parent[k]!=NULL){
      if(k==1){
        s1[l]=seq1[i];
        s2[l]=seq2[j];
        align(s->parent[k],seq1,seq2,s1,s2,i-1,j-1,l+1,len,1);
      }
      else if(k==0){
        s1[l]='-';
        s2[l]=seq2[j];
        align(s->parent[k],seq1,seq2,s1,s2,i,j-1,l+1,len,0);
      }
      else if(k==2){
        s1[l]=seq1[i];
        s2[l]='-';
        align(s->parent[k],seq1,seq2,s1,s2,i-1,j,l+1,len,2);
      }
    }
  }
  if(i==0 && j==0){
    s1[l+1]='\0';
    s2[l+1]='\0';
    strcpy(out1,s1);
    strcpy(out2,s2);
    strrev(out1);
    strrev(out2);
    printf("Sequence 1:\t%s\nSequence 2:\t%s\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", out1, out2);
  }
}

char *strrev(char *str)
{
    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}
