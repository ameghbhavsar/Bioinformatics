#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Program to find most fluctuating residue in each chain

void main() {
  FILE *pdb;
  char line[100];
  int atm_no[20000],res_no[20000],i=0,j=0,len,count[300][4],n_res=1;
  double x[20000], y[20000], z[20000];
  float occ_fact[20000],b_fact[20000],bfact_tot[300][4],bfact_avg[300][4];
  char atm_nm[20000][4],res_nm[20000][4];
  char ch_id[20000][2],atm[20000][2];
  pdb=fopen("1oj6.pdb","r");
  for(i=0;i<300;i++){
	for(j=0;j<4;j++){
		bfact_tot[i][j]=0;
		count[i][j]=0;
	}			
  }
  i=0;
  j=0;
  while(fgets(line,100,pdb)!=NULL){
    if(sscanf(line, "ATOM  %5d  %4s %s %s  %d   %lf%lf%lf  %f  %f           %s\n",
        &atm_no[i], atm_nm[i],res_nm[i],ch_id[i],&res_no[i],&x[i],&y[i],&z[i],&occ_fact[i],&b_fact[i],atm[i])){
	if(!strcmp(ch_id[i],"A"){
		if(i==0)
			prev_res_no=res_no[i];
		if(res_no[i]==prev_res_no){
			bfact_tot[j][0]+=bfact[i];
			count[j][0]++;
		}
		else{
			prev_res_no=res_no[i];
			j++;
			bfact_tot[j][0]+=bfact[i];
			count[j][0]++;
		}
		i++;
	}
    }
  }
  n_res=j;
  max=0;
  for(j=0;j<n_res;j++){
	bfact_avg[j][0]=bfact_tot[j][0]/count[j][0];
  }	
  fclose(pdb);
}
