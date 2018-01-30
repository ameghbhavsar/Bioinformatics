#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Program to find average B-factor for side chain and main chain

void main() {
  FILE *pdb;
  char line[100];
  int atm_no[20000],res_no[20000],i=0,j=0,len,main_count[4],side_count[4];
  double x[20000], y[20000], z[20000];
  float occ_fact[20000],b_fact[20000],main_tot[4],side_tot[4],main_avg[4],side_avg[4];
  char atm_nm[20000][4],res_nm[20000][4];
  char ch_id[20000][2],atm[20000][2];
  pdb=fopen("1oj6.pdb","r");
  for(i=0;i<4;i++){
	main_tot[i]=0;
	side_tot[i]=0;
	main_avg[i]=0;
	side_avg[i]=0;
	main_count[i]=0;
	side_count[i]=0;
  }
  i=0;
  while(fgets(line,100,pdb)!=NULL){
    if(sscanf(line, "ATOM  %5d  %4s %s %s  %d   %lf%lf%lf  %f  %f           %s\n",
        &atm_no[i], atm_nm[i],res_nm[i],ch_id[i],&res_no[i],&x[i],&y[i],&z[i],&occ_fact[i],&b_fact[i],atm[i])){
		if(!strcmp(ch_id[i],"A")){
			if(!strcmp(atm_nm[i],"N") || !strcmp(atm_nm[i],"CA") || !strcmp(atm_nm[i],"C") || !strcmp(atm_nm[i],"O")){
				main_tot[0]+=b_fact[i];
				main_count[0]++;
			}
			else{
				side_tot[0]+=b_fact[i];
				side_count[0]++;
			}
		}
		else if(!strcmp(ch_id[i],"B")){
			if(!strcmp(atm_nm[i],"N") || !strcmp(atm_nm[i],"CA") || !strcmp(atm_nm[i],"C") || !strcmp(atm_nm[i],"O")){
				main_tot[1]+=b_fact[i];
				main_count[1]++;
			}
			else{
				side_tot[1]+=b_fact[i];
				side_count[1]++;
			}
		}
		else if(!strcmp(ch_id[i],"C")){
			if(!strcmp(atm_nm[i],"N") || !strcmp(atm_nm[i],"CA") || !strcmp(atm_nm[i],"C") || !strcmp(atm_nm[i],"O")){
				main_tot[2]+=b_fact[i];
				main_count[2]++;
			}
			else{
				side_tot[2]+=b_fact[i];
				side_count[2]++;
			}
		}
		else if(!strcmp(ch_id[i],"D")){
			if(!strcmp(atm_nm[i],"N") || !strcmp(atm_nm[i],"CA") || !strcmp(atm_nm[i],"C") || !strcmp(atm_nm[i],"O")){
				main_tot[3]+=b_fact[i];
				main_count[3]++;
			}
			else{
				side_tot[3]+=b_fact[i];
				side_count[3]++;
			}
		}
	       i++;
    }
  }
  for(i=0;i<4;i++){
	main_avg[i]=main_tot[i]/main_count[i];
	side_avg[i]=side_tot[i]/side_count[i];
  }
  printf("Average B-factor\nFor chain A:\tMain chain:\t%f\tSide Chain:\t%f\n",main_avg[0],side_avg[0]);
  printf("For chain B:\tMain chain:\t%f\tSide Chain:\t%f\n",main_avg[1],side_avg[1]);
  printf("For chain C:\tMain chain:\t%f\tSide Chain:\t%f\n",main_avg[2],side_avg[2]);
  printf("For chain D:\tMain chain:\t%f\tSide Chain:\t%f\n",main_avg[3],side_avg[3]);
  fclose(pdb);
}
