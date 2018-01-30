#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

void main() {
  FILE *pdb,*out,*interact;
  char line[100];
  int atm_no[20000],res_no[20000],i=0,j=0,len,interacting[20000];
  double x[20000], y[20000], z[20000];
  float occ_fact[20000],temp_fact[20000],dist;
  char atm_nm[20000][4],res_nm[20000][4];
  char ch_id[20000][2],atm[20000][2];
  pdb=fopen("1asy.pdb","r");
  out=fopen("out.pdb","w");
  interact=fopen("interacting.pdb","w");
  while(fgets(line,100,pdb)!=NULL){
    if(sscanf(line, "ATOM  %5d  %4s %s %s  %d   %lf%lf%lf  %f  %f           %s\n",
        &atm_no[i], atm_nm[i],res_nm[i],ch_id[i],&res_no[i],&x[i],&y[i],&z[i],&occ_fact[i],&temp_fact[i],atm[i])){
	      if(!strcmp(ch_id[i],"A") || !strcmp(ch_id[i],"R")){    //store only if it is R chain or A chain
		        i++;
	      }
    }
  }
  int match=0;
  len=i;
  for(i=0;i<len;i++){
    interacting[i]=0;
  }
  for(i=0;i<len;i++){
	 if(!strcmp(ch_id[i],"R")){
		  for(j=0;j<len;j++){
			  if(!strcmp(ch_id[j],"A")){
				  dist=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)+pow(z[i]-z[j],2));
				  if(dist<=4.5){
					interacting[i]=1;                 //flag the interacting atoms
					interacting[j]=1;
					fprintf(out,"%s,\t%d,\t%s,\t%d\t-\t%s,\t%d,\t%s,\t%d\n",     //saving the atoms in pdb file
						atm_nm[j],atm_no[j],res_nm[j],res_no[j],atm_nm[i],atm_no[i],res_nm[i],res_no[i]);
				  }
			 }
		 }
	 }
  }
/*  for(i=0;i<len;i++){				//Saving the interacting atoms in pdb format
    if(interacting[i]){
      if(!strcmp(ch_id[i],"R")){
        match++;
        fprintf(interact, "ATOM  %5d  %-4s  %s %s %d    %8.3f%8.3f%8.3f %5.2f %5.2f           %s\n",
         atm_no[i], atm_nm[i],res_nm[i],ch_id[i],res_no[i],x[i],y[i],z[i],occ_fact[i],temp_fact[i],atm[i]);
       }
      else if(!strcmp(ch_id[i],"A")){
        match++;
        fprintf(interact, "ATOM  %5d  %-4s%s %s %d    %8.3f%8.3f%8.3f %5.2f %5.2f           %s\n",
          atm_no[i], atm_nm[i],res_nm[i],ch_id[i],res_no[i],x[i],y[i],z[i],occ_fact[i],temp_fact[i],atm[i]);
       }
    }
  }*/
  fclose(pdb);
  fclose(interact);
  fclose(out);
}
