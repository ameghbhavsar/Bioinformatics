#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct asa{
  int atm_no;
  char atm_nm[4];
  char res_nm[4];
  char ch_id;
  int res_no;
  float icode;
  float sasa;
  int N;
  int atm_tp;
  int atm_gp;
  float surf;
}asa;

void check_interacting(FILE *input_asa,FILE *interacting_asa,asa comp_asa[20000]);

void main(){
  FILE *comp,*A,*B,*C,*D,*E,*F,*G,*H,*A_interacting,*B_interacting,*C_interacting,
  *D_interacting,*E_interacting,*F_interacting,*G_interacting,*H_interacting;
  asa comp_asa[20000],chain;
  char line[100];
  int len,i;
  comp=fopen("asa/5un8.asa","r");
  A=fopen("asa/A.asa","r");
  B=fopen("asa/B.asa","r");
  C=fopen("asa/C.asa","r");
  D=fopen("asa/D.asa","r");
  E=fopen("asa/E.asa","r");
  F=fopen("asa/F.asa","r");
  G=fopen("asa/G.asa","r");
  H=fopen("asa/H.asa","r");
  A_interacting=fopen("asa/A_interacting.asa","w");
  B_interacting=fopen("asa/B_interacting.asa","w");
  C_interacting=fopen("asa/C_interacting.asa","w");
  D_interacting=fopen("asa/D_interacting.asa","w");
  E_interacting=fopen("asa/E_interacting.asa","w");
  F_interacting=fopen("asa/F_interacting.asa","w");
  G_interacting=fopen("asa/G_interacting.asa","w");
  H_interacting=fopen("asa/H_interacting.asa","w");

  // interacting(comp,A,A_interacting);
  // fseek(comp, 0, SEEK_SET );
  i=0;
  while(fgets(line,100,comp)!=NULL){
    if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
        &comp_asa[i].atm_no,comp_asa[i].atm_nm,comp_asa[i].res_nm,&comp_asa[i].ch_id,&comp_asa[i].res_no,&comp_asa[i].icode,&comp_asa[i].sasa,&comp_asa[i].N,&comp_asa[i].atm_tp,&comp_asa[i].atm_gp,&comp_asa[i].surf)){
      if (comp_asa[i].atm_no) {
        printf("%d %s %s %c %d %5.2f %6.4f %d %d %d %6.2f\n",
          comp_asa[i].atm_no,comp_asa[i].atm_nm,comp_asa[i].res_nm,comp_asa[i].ch_id,comp_asa[i].res_no,comp_asa[i].icode,comp_asa[i].sasa,comp_asa[i].N,comp_asa[i].atm_tp,comp_asa[i].atm_gp,comp_asa[i].surf);
          i++;
      }
    }
  }

  //CHECK INTERACTING

  while(fgets(line,100,A)!=NULL){
    if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
    &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.icode,&chain.sasa,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_nm)){
      if(comp_asa[chain.atm_no].sasa!=chain.sasa){
        //printf("%d %s %s %c %d %5.2f %6.4f %d %d %d %6.2f\n",
        //  chain.atm_no,chain.atm_nm,chain.res_nm,chain.ch_id,chain.res_no,chain.icode,chain.sasa,chain.N,chain.atm_tp,chain.atm_gp,chain.surf);
        	fprintf(A_interacting,"%s",line);
      }
    }
  }

  while(fgets(line,100,B)!=NULL){
    if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
    &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.icode,&chain.sasa,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_nm)){
      if(comp_asa[chain.atm_no].sasa!=chain.sasa){
        //printf("%d %s %s %c %d %5.2f %6.4f %d %d %d %6.2f\n",
        //  chain.atm_no,chain.atm_nm,chain.res_nm,chain.ch_id,chain.res_no,chain.icode,chain.sasa,chain.N,chain.atm_tp,chain.atm_gp,chain.surf);
        	fprintf(B_interacting,"%s",line);
      }
    }
  }

  while(fgets(line,100,C)!=NULL){
    if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
    &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.icode,&chain.sasa,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_nm)){
      if(comp_asa[chain.atm_no].sasa!=chain.sasa){
        //printf("%d %s %s %c %d %5.2f %6.4f %d %d %d %6.2f\n",
        //  chain.atm_no,chain.atm_nm,chain.res_nm,chain.ch_id,chain.res_no,chain.icode,chain.sasa,chain.N,chain.atm_tp,chain.atm_gp,chain.surf);
          fprintf(C_interacting,"%s",line);
      }
    }
  }

  while(fgets(line,100,D)!=NULL){
    if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
    &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.icode,&chain.sasa,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_nm)){
      if(comp_asa[chain.atm_no].sasa!=chain.sasa){
        //printf("%d %s %s %c %d %5.2f %6.4f %d %d %d %6.2f\n",
        //  chain.atm_no,chain.atm_nm,chain.res_nm,chain.ch_id,chain.res_no,chain.icode,chain.sasa,chain.N,chain.atm_tp,chain.atm_gp,chain.surf);
        	fprintf(D_interacting,"%s",line);
      }
    }
  }

  while(fgets(line,100,E)!=NULL){
    if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
    &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.icode,&chain.sasa,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_nm)){
      if(comp_asa[chain.atm_no].sasa!=chain.sasa){
        //printf("%d %s %s %c %d %5.2f %6.4f %d %d %d %6.2f\n",
        //  chain.atm_no,chain.atm_nm,chain.res_nm,chain.ch_id,chain.res_no,chain.icode,chain.sasa,chain.N,chain.atm_tp,chain.atm_gp,chain.surf);
        	fprintf(E_interacting,"%s",line);
      }
    }
  }

  while(fgets(line,100,F)!=NULL){
    if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
    &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.icode,&chain.sasa,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_nm)){
      if(comp_asa[chain.atm_no].sasa!=chain.sasa){
        //printf("%d %s %s %c %d %5.2f %6.4f %d %d %d %6.2f\n",
        //  chain.atm_no,chain.atm_nm,chain.res_nm,chain.ch_id,chain.res_no,chain.icode,chain.sasa,chain.N,chain.atm_tp,chain.atm_gp,chain.surf);
        	fprintf(F_interacting,"%s",line);
      }
    }
  }

  while(fgets(line,100,G)!=NULL){
    if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
    &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.icode,&chain.sasa,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_nm)){
      if(comp_asa[chain.atm_no].sasa!=chain.sasa){
        //printf("%d %s %s %c %d %5.2f %6.4f %d %d %d %6.2f\n",
        //  chain.atm_no,chain.atm_nm,chain.res_nm,chain.ch_id,chain.res_no,chain.icode,chain.sasa,chain.N,chain.atm_tp,chain.atm_gp,chain.surf);
        	fprintf(G_interacting,"%s",line);
      }
    }
  }

  while(fgets(line,100,H)!=NULL){
    if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
    &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.icode,&chain.sasa,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_nm)){
      if(comp_asa[chain.atm_no].sasa!=chain.sasa){
        //printf("%d %s %s %c %d %5.2f %6.4f %d %d %d %6.2f\n",
        //  chain.atm_no,chain.atm_nm,chain.res_nm,chain.ch_id,chain.res_no,chain.icode,chain.sasa,chain.N,chain.atm_tp,chain.atm_gp,chain.surf);
        	fprintf(H_interacting,"%s",line);
      }
    }
  }


  // check_interacting(A,A_interacting,comp_asa);

  fclose(comp);
  fclose(A);
  fclose(A_interacting);
}

void check_interacting(FILE *input_asa,FILE *interacting_asa,asa comp_asa[20000]){
  char line[100];
  asa chain;
  while(fgets(line,100,input_asa)!=NULL){
    if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
    &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.icode,&chain.sasa,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_no)){
      if(comp_asa[chain.atm_no].sasa!=chain.sasa){
        //printf("%d %s %s %c %d %5.2f %6.4f %d %d %d %6.2f\n",
        //  chain.atm_no,chain.atm_nm,chain.res_nm,chain.ch_id,chain.res_no,chain.icode,chain.sasa,chain.N,chain.atm_tp,chain.atm_gp,chain.surf);
          fprintf(interacting_asa,"%s",line);
      }
    }
  }
}
