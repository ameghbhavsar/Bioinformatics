#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

void split_chain(FILE*,FILE*,char);

void main() {
  FILE *pdb,*A,*B,*C,*D,*E,*F,*G,*H;
  pdb=fopen("pdb/5un8.pdb","r");
  A=fopen("pdb/A.pdb","w");
  B=fopen("pdb/B.pdb","w");
  C=fopen("pdb/C.pdb","w");
  D=fopen("pdb/D.pdb","w");
  E=fopen("pdb/E.pdb","w");
  F=fopen("pdb/F.pdb","w");
  G=fopen("pdb/G.pdb","w");
  H=fopen("pdb/H.pdb","w");
  split_chain(pdb,A,'A');
  fseek(pdb, 0, SEEK_SET );
  split_chain(pdb,B,'B');
  fseek(pdb, 0, SEEK_SET );
  split_chain(pdb,C,'C');
  fseek(pdb, 0, SEEK_SET );
  split_chain(pdb,D,'D');
  fseek(pdb, 0, SEEK_SET );
  split_chain(pdb,E,'E');
  fseek(pdb, 0, SEEK_SET );
  split_chain(pdb,F,'F');
  fseek(pdb, 0, SEEK_SET );
  split_chain(pdb,G,'G');
  fseek(pdb, 0, SEEK_SET );
  split_chain(pdb,H,'H');
}

void split_chain(FILE *pdb,FILE *out,char chain){
  int atm_no[6000],res_no[6000],i=0;
  double x[6000], y[6000], z[6000];
  float occ_fact,temp_fact;
  char atm_nm[6000][4],res_nm[6000][4],line[100];
  char ch_id[6000],atm[6000][1];
  while(fgets(line,100,pdb)!=NULL){
    if(sscanf(line, "ATOM  %5d  %4s%s %c  %d    %lf%lf%lf  %f  %f           %s\n",
        &atm_no[i], atm_nm[i],res_nm[i],&ch_id[i],&res_no[i],&x[i],&y[i],&z[i],&occ_fact,&temp_fact,atm[i]) &(ch_id[i]==chain) ){
  //      fprintf(out, "ATOM  %5d  %-4s%s %c %d    %8.3f%8.3f%8.3f %5.2f %5.2f           %s\n",
    //        atm_no[i], atm_nm[i],res_nm[i],ch_id[i],res_no[i],x[i],y[i],z[i],occ_fact,temp_fact,atm[i]);
	fprintf(out,"%s",line);
        // printf("ATOM  %5d  %-4s %s %s  %d   %lf %lf %lf  %4.2f  %4.2f        %s\n",
        //     atm_no[i], atm_nm[i],res_nm[i],ch_id[i],res_no[i],x[i],y[i],z[i],occ_fact,temp_fact,atm[i]);
        i++;
      }
  }
}
