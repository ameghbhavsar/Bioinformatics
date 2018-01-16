#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main(){
	FILE *f1, *f2;
	int i,c1=0,c2=0,store_slno[20000],store_res_no[20000],store_atm_no[20000];
	char line[100],word[5],res_nm[4],ch_id[20000],x[9],y[9],z[9],res_no[5],slno[6],atm_nm[4],store_atm_nm[20000][4],store_res_nm[20000][4];
	float store_x[20000],store_y[20000],store_z[20000],tot_x,tot_y,tot_z,cm_x,cm_y,cm_z;
	f1=fopen("3fe0.pdb","r");
	f2=fopen("out.pdb","w");

	while(fgets(line,100,f1)!=NULL){
		for(i=0; i<4;i++) word[i]=line[i];
		word[4]='\0';
		if(strcmp(word,"ATOM")==0){
			for(i=0;i<5;i++) slno[i]=line[i+6];
			slno[5]='\0';
			store_slno[c1]=atoi(slno);

			for(i=0;i<3;i++) atm_nm[i]=line[13+i];
			atm_nm[3]='\0';
			strcpy(store_atm_nm[c1],atm_nm);

			for(i=0;i<3;i++) res_nm[i]=line[i+17];
			res_nm[3]='\0';
			strcpy(store_res_nm[c1],res_nm);

			ch_id[c1]=line[21];

			for(i=0;i<4;i++) res_no[i]=line[i+22];
			res_no[4]='\0';
			store_res_no[c1]=atoi(res_no);

			for(i=0;i<8;i++) x[i]=line[30+i];
			x[8]='\0';
			store_x[c1]=atof(x);

      for(i=0;i<8;i++) y[i]=line[30+i];
      y[8]='\0';
      store_y[c1]=atof(y);

      for(i=0;i<8;i++) z[i]=line[30+i];
      z[8]='\0';
      store_z[c1]=atof(z);

			c1++;
		}
	}

	for(i=0;i<c1;i++){
		fprintf(f2,"ATOM   %5d  %s %s %c%4d %8.3f%8.3f%8.3f\n",store_slno[i],store_atm_nm[i],store_res_nm[i],ch_id[i],store_res_no[i],
			store_x[i],store_y[i],store_z[i]);
	}
	tot_x=tot_y=tot_z=0;

	for(i=0;i<c1;i++){
		tot_x=tot_x+store_x[i];
		tot_y=tot_y+store_y[i];
		tot_z=tot_z+store_z[i];
	}

	cm_x=tot_x/c1;
	cm_y=tot_y/c1;
	cm_z=tot_z/c1;

	fprintf(f2,"ATOMCM     -   -   -  - 999 %8.3f%8.3f%8.3f\n",cm_x,cm_y,cm_z);

	fclose(f1);
	fclose(f2);
}
