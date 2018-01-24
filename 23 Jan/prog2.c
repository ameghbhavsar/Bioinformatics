#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

void main() {
  FILE *pdb,*out;
  char line[100];
  int atm_no[20000],res_no[20000],i=0,j=0,len,interacting[20000];
  double x[20000], y[20000], z[20000];
  float occ_fact[20000],temp_fact[20000],dist;
  char atm_nm[20000][4],res_nm[20000][4];
  char ch_id[20000][2],atm[20000][2];
  pdb=fopen("1asy.pdb","r");
  out=fopen("out.pdb","w");
  while(fgets(line,100,pdb)!=NULL){
    if(sscanf(line, "ATOM  %5d  %4s %s %s  %d   %lf%lf%lf  %f  %f           %s\n",
        &atm_no[i], atm_nm[i],res_nm[i],ch_id[i],&res_no[i],&x[i],&y[i],&z[i],&occ_fact[i],&temp_fact[i],atm[i])){
        //fprintf(out, "ATOM  %5d  %-4s %s %s  %d   %8.3f%8.3f%8.3f  %5.2f  %5.2f        %s\n",
          //  atm_no[i], atm_nm[i],res_nm[i],ch_id[i],res_no[i],x[i],y[i],z[i],occ_fact,temp_fact,atm[i]);
//         printf("ATOM  %5d  %-4s %s %s  %d   %lf %lf %lf  %4.2f  %4.2f        %s\n",
  //           atm_no[i], atm_nm[i],res_nm[i],ch_id[i],res_no[i],x[i],y[i],z[i],occ_fact[i],temp_fact[i],atm[i]);
	      if(!strcmp(ch_id[i],"A") || !strcmp(ch_id[i],"R")){
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
	//printf("In for loop 1\n");
	 if(!strcmp(ch_id[i],"R")){
	//	printf("In if R\n");
		  for(j=0;j<len;j++){
	//		printf("In for loop 2\n");
			  if(!strcmp(ch_id[j],"A")){
				  dist=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)+pow(z[i]-z[j],2));
	//			printf("In if A %f\n",dist);
				  if(dist<4.5){
              interacting[i]=1;
              interacting[j]=1;
				  }
			 }
		 }
	 }
  }
  for(i=0;i<len;i++){
    if(interacting[i]){
      if(!strcmp(ch_id[i],"R")){
        match++;
        fprintf(out, "ATOM  %5d  %-4s  %s %s %d    %8.3f%8.3f%8.3f %5.2f %5.2f           %s\n",
         atm_no[i], atm_nm[i],res_nm[i],ch_id[i],res_no[i],x[i],y[i],z[i],occ_fact[i],temp_fact[i],atm[i]);
       }
      else if(!strcmp(ch_id[i],"A")){
        match++;
        fprintf(out, "ATOM  %5d  %-4s%s %s %d    %8.3f%8.3f%8.3f %5.2f %5.2f           %s\n",
          atm_no[i], atm_nm[i],res_nm[i],ch_id[i],res_no[i],x[i],y[i],z[i],occ_fact[i],temp_fact[i],atm[i]);
       }
    }
  }
  printf("%d\n",match );
  fclose(pdb);
  fclose(out);
}
