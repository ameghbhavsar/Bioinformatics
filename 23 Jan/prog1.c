#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

void main() {
  FILE *pdb,*out;
  char line[100];
  int atm_no[20000],res_no[20000],i=0,j=1;
  double x[20000], y[20000], z[20000],tot_x,tot_y,tot_z,cm_x,cm_y,cm_z;
  float occ_fact,temp_fact,tot_res_no,pos_comp,neg_comp,arm_comp,neutral_comp,hphobic_comp,pos=0,neg=0,arm=0,neutral=0,hphobic=0;
  char atm_nm[20000][4],res_nm[20000][4];
  char ch_id[20000][1],atm[20000][1];
  pdb=fopen("3fe0.pdb","r");
  //out=fopen("out_new.pdb","w");
  while(fgets(line,100,pdb)!=NULL){
    if(sscanf(line, "ATOM  %5d  %4s %s %s  %d   %lf%lf%lf  %f  %f           %s\n",
        &atm_no[i], atm_nm[i],res_nm[i],ch_id[i],&res_no[i],&x[i],&y[i],&z[i],&occ_fact,&temp_fact,atm[i])){
        //fprintf(out, "ATOM  %5d  %-4s %s %s  %d   %8.3f%8.3f%8.3f  %5.2f  %5.2f        %s\n",
          //  atm_no[i], atm_nm[i],res_nm[i],ch_id[i],res_no[i],x[i],y[i],z[i],occ_fact,temp_fact,atm[i]);
        // printf("ATOM  %5d  %-4s %s %s  %d   %lf %lf %lf  %4.2f  %4.2f        %s\n",
        //     atm_no[i], atm_nm[i],res_nm[i],ch_id[i],res_no[i],x[i],y[i],z[i],occ_fact,temp_fact,atm[i]);
	if(res_no[i]==j){
		j++;
		if(!(strcmp(res_nm[i],"ARG") && strcmp(res_nm[i],"LYS")))
			pos++;
                if(!(strcmp(res_nm[i],"ASP") && strcmp(res_nm[i],"GLU")))
                        neg++;
                if(!(strcmp(res_nm[i],"TYR") && strcmp(res_nm[i],"TRP") && strcmp(res_nm[i],"PHE")))
                        arm++;
                if(!(strcmp(res_nm[i],"SER") && strcmp(res_nm[i],"THR") && strcmp(res_nm[i],"HIS") && 
			strcmp(res_nm[i],"ASN") && strcmp(res_nm[i],"GLN") && strcmp(res_nm[i],"MET") && strcmp(res_nm[i],"CYS")))
                        neutral++;
                if(!(strcmp(res_nm[i],"ILE") && strcmp(res_nm[i],"LEU") && strcmp(res_nm[i],"VAL") && 
			strcmp(res_nm[i],"PRO") && strcmp(res_nm[i],"ALA") && strcmp(res_nm[i],"GLY")))
                        hphobic++;
	}
	i++;
      }
  }

  tot_res_no=pos+neg+arm+neutral+hphobic;
  pos_comp=(pos*100)/tot_res_no;
  neg_comp=(neg*100)/tot_res_no;
  arm_comp=(arm*100)/tot_res_no;
  neutral_comp=(neutral*100)/tot_res_no;
  hphobic_comp=(hphobic*100)/tot_res_no;	
  printf("\nPositively charged\t:\t%f%%\nNegatively charged\t:\t%f%%\nAromatic\t\t:\t%f%%\nNeutral pole\t\t:\t%f%%\nHydrophobic\t\t:\t%f%%\n", 
	pos_comp,neg_comp,arm_comp,neutral_comp,hphobic_comp);
  fclose(pdb);
}

