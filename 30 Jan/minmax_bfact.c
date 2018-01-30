#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

//Program to find most fluctuating residue in each chain

void main() {
  FILE *pdb;
  char line[100];
  int atm_no,res_no,i=0,j=0,a=0,b=0,c=0,d=0,len,count[300][4],n_res[4],max_pos[4],min_pos[4],prev_res_no[4];
  double x, y, z;
  float occ_fact,b_fact,bfact_tot[300][4],bfact_avg[300][4],max[4],min[4];
  char atm_nm[4],res_nm[4],res[300][4][4];
  char ch_id[2],atm[2];
  pdb=fopen("1oj6.pdb","r");  //open the pdb file
  for(i=0;i<300;i++){     //initialize sum and count variables to zero
	   for(j=0;j<4;j++){
		     bfact_tot[i][j]=0;
		     count[i][j]=0;
	    }
  }
  while(fgets(line,100,pdb)!=NULL){         //read one line
    if(sscanf(line, "ATOM  %5d  %4s %s %s  %d   %lf%lf%lf  %f  %f           %s\n",
        &atm_no, atm_nm,res_nm,ch_id,&res_no,&x,&y,&z,&occ_fact,&b_fact,atm)){    //scan the line for inormation
	         if(!strcmp(ch_id,"A") && !(!strcmp(atm_nm,"N") ||
              !strcmp(atm_nm,"CA") || !strcmp(atm_nm,"C") || !strcmp(atm_nm,"O"))){   //if side chain and chain id A
		           if(res_no==prev_res_no[0]){
			              bfact_tot[a][0]+=b_fact;     //calculate total B-factor
			              count[a][0]++;               //count the number of atoms
		           }
		           else{
			              prev_res_no[0]=res_no;
			              a++;                         //count the number of residues
                    strcpy(res[a][0],res_nm);
			              bfact_tot[a][0]+=b_fact;
			              count[a][0]++;
		           }
		           i++;
	         }
           if(!strcmp(ch_id,"B") && !(!strcmp(atm_nm,"N") ||
              !strcmp(atm_nm,"CA") || !strcmp(atm_nm,"C") || !strcmp(atm_nm,"O"))){  //if side chain and chain id B
		           if(res_no==prev_res_no[1]){
			              bfact_tot[b][1]+=b_fact;
			              count[b][1]++;
		           }
		           else{
			              prev_res_no[1]=res_no;
			              b++;
                    strcpy(res[b][1],res_nm);
			              bfact_tot[b][1]+=b_fact;
			              count[b][1]++;
		           }
		           i++;
	         }
           if(!strcmp(ch_id,"C") && !(!strcmp(atm_nm,"N") ||
              !strcmp(atm_nm,"CA") || !strcmp(atm_nm,"C") || !strcmp(atm_nm,"O"))){  //if side chain and chain id C
		           if(res_no==prev_res_no[2]){
			              bfact_tot[c][2]+=b_fact;
			              count[c][2]++;
		           }
		           else{
			              prev_res_no[2]=res_no;
			              c++;
                    strcpy(res[c][2],res_nm);
			              bfact_tot[c][2]+=b_fact;
			              count[c][2]++;
		           }
		           i++;
	         }
           if(!strcmp(ch_id,"D") && !(!strcmp(atm_nm,"N") ||
              !strcmp(atm_nm,"CA") || !strcmp(atm_nm,"C") || !strcmp(atm_nm,"O"))){  //if side chain and chain id D
		           if(res_no==prev_res_no[3]){
			              bfact_tot[d][3]+=b_fact;
			              count[d][3]++;
		           }
		           else{
			              prev_res_no[3]=res_no;
			              d++;
                    strcpy(res[d][3],res_nm);
			              bfact_tot[d][3]+=b_fact;
			              count[d][3]++;
		           }
		           i++;
	         }
    }
  }
  n_res[0]=a;
  n_res[1]=b;
  n_res[2]=c;
  n_res[3]=d;
  for(i=0;i<4;i++){
    max[i]=0;
    min[i]=INFINITY;
    for(j=0;j<n_res[i];j++){
	    bfact_avg[j][i]=bfact_tot[j][i]/count[j][i];
      if(bfact_avg[j][i]>max[i]){  //find max
          max[i]=bfact_avg[j][i];
          max_pos[i]=j;
      }
      if(bfact_avg[j][i]<min[i]){  //find min
        min[i]=bfact_avg[j][i];
        min_pos[i]=j;
     }
    }
  }
  //print the residues with lowest and highest side chain B-factor
  printf("Chain A:   Highest B-factor: %s %f\tLowest B-factor: %s %f\n",res[max_pos[0]][0],max[0],res[min_pos[0]][0],min[0]);
  printf("Chain B:   Highest B-factor: %s %f\tLowest B-factor: %s %f\n",res[max_pos[1]][1],max[1],res[min_pos[1]][1],min[1]);
  printf("Chain C:   Highest B-factor: %s %f\tLowest B-factor: %s %f\n",res[max_pos[2]][2],max[2],res[min_pos[2]][2],min[2]);
  printf("Chain D:   Highest B-factor: %s %f\tLowest B-factor: %s %f\n",res[max_pos[3]][3],max[3],res[min_pos[3]][3],min[3]);
  fclose(pdb);
}
