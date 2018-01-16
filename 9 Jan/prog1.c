#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

void main() {
  FILE *pdb,*out;
  char line[100];
  int atm_no[20000],res_no[20000],i=0;
  double x[20000], y[20000], z[20000],tot_x,tot_y,tot_z,cm_x,cm_y,cm_z;
  float occ_fact,temp_fact;
  char atm_nm[20000][4],res_nm[20000][4];
  char ch_id[20000][1],atm[20000][1];
  pdb=fopen("3fe0.pdb","r");
  out=fopen("out_new.pdb","w");
  while(fgets(line,100,pdb)!=NULL){
    if(sscanf(line, "ATOM  %5d  %4s %s %s  %d   %lf%lf%lf  %f  %f           %s\n",
        &atm_no[i], atm_nm[i],res_nm[i],ch_id[i],&res_no[i],&x[i],&y[i],&z[i],&occ_fact,&temp_fact,atm[i])){
        fprintf(out, "ATOM  %5d  %-4s %s %s  %d   %8.3f%8.3f%8.3f  %5.2f  %5.2f        %s\n",
            atm_no[i], atm_nm[i],res_nm[i],ch_id[i],res_no[i],x[i],y[i],z[i],occ_fact,temp_fact,atm[i]);
        // printf("ATOM  %5d  %-4s %s %s  %d   %lf %lf %lf  %4.2f  %4.2f        %s\n",
        //     atm_no[i], atm_nm[i],res_nm[i],ch_id[i],res_no[i],x[i],y[i],z[i],occ_fact,temp_fact,atm[i]);
        i++;
      }
  }

  tot_x=tot_y=tot_z=0;
  int c1=i;
	for(i=0;i<c1;i++){
		tot_x=tot_x+x[i];
		tot_y=tot_y+y[i];
		tot_z=tot_z+z[i];
	}

	cm_x=tot_x/c1;
	cm_y=tot_y/c1;
	cm_z=tot_z/c1;
 // fprintf(out,"ATOMCM    -   -    -  -  999   %8.3f%8.3f%8.3f\n",cm_x,cm_y,cm_z);
  fprintf(out,"ATOM  99999  Zn   Zn  Z  999   %8.3f%8.3f%8.3f\n",cm_x,cm_y,cm_z);
}
