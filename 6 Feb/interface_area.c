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
  float sasa;
  float Q;
  int N;
  int atm_tp;
  int atm_gp;
  float surf;
}asa;

void main(){
  FILE *comp,*A,*B,*C,*D,*E,*F,*G,*H,*A_interacting,*B_interacting,*C_interacting,
  *D_interacting,*E_interacting,*F_interacting,*G_interacting,*H_interacting;
  asa comp_asa,chain;
  char line[100];
  int len,i;
  float area[8];
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

  for(i=0;i<8;i++) area[i]=0;

  i=0;

  while(fgets(line,100,comp)!=NULL){
    if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
        &comp_asa.atm_no,comp_asa.atm_nm,comp_asa.res_nm,&comp_asa.ch_id,&comp_asa.res_no,&comp_asa.sasa,&comp_asa.Q,&comp_asa.N,&comp_asa.atm_tp,&comp_asa.atm_gp,&comp_asa.surf) && (comp_asa.atm_no)){

            // printf("%d %f\n",comp_asa.atm_no,comp_asa.Q);
            i++;
      if(comp_asa.ch_id=='A'){
        while(fgets(line,100,A)){
          if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
            &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.sasa,&chain.Q,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_no)){
              // printf("%d %d %f %f %d\n",comp_asa.atm_no,chain.atm_no,comp_asa.Q,chain.Q ,i);

                          // printf("%d %f\n",comp_asa.atm_no,comp_asa.Q);
              if(comp_asa.atm_no==chain.atm_no && comp_asa.sasa!=chain.sasa){
                  fprintf(A_interacting,"%s",line);
                  area[0]+=chain.sasa-comp_asa.sasa;
              }
          }
        }
        fseek(A, 0, SEEK_SET );
      }
      else if(comp_asa.ch_id=='B'){
        while(fgets(line,100,B)){
          if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
            &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.sasa,&chain.Q,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_no)){
              if(comp_asa.atm_no==chain.atm_no && comp_asa.sasa!=chain.sasa){
                  fprintf(B_interacting,"%s",line);
                  area[1]+=chain.sasa-comp_asa.sasa;
              }
          }
        }
        fseek(B, 0, SEEK_SET );
      }

      else if(comp_asa.ch_id=='C'){
        while(fgets(line,100,C)){
          if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
            &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.sasa,&chain.Q,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_no)){
              if(comp_asa.atm_no==chain.atm_no && comp_asa.sasa!=chain.sasa){
                  fprintf(C_interacting,"%s",line);
                  area[2]+=chain.sasa-comp_asa.sasa;
              }
          }
        }
        fseek(C, 0, SEEK_SET );
      }
      else if(comp_asa.ch_id=='D'){
        while(fgets(line,100,D)){
          if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
            &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.sasa,&chain.Q,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_no)){
              if(comp_asa.atm_no==chain.atm_no && comp_asa.sasa!=chain.sasa){
                  fprintf(D_interacting,"%s",line);
                  area[3]+=chain.sasa-comp_asa.sasa;
              }
          }
        }
        fseek(D, 0, SEEK_SET );
      }
      else if(comp_asa.ch_id=='E'){
        while(fgets(line,100,E)){
          if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
            &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.sasa,&chain.Q,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_no)){
              if(comp_asa.atm_no==chain.atm_no && comp_asa.sasa!=chain.sasa){
                  fprintf(E_interacting,"%s",line);
                  area[4]+=chain.sasa-comp_asa.sasa;
              }
          }
        }
        fseek(E, 0, SEEK_SET );
      }
      else if(comp_asa.ch_id=='F'){
        while(fgets(line,100,F)){
          if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
            &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.sasa,&chain.Q,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_no)){
              if(comp_asa.atm_no==chain.atm_no && comp_asa.sasa!=chain.sasa){
                  fprintf(F_interacting,"%s",line);
                  area[5]+=chain.sasa-comp_asa.sasa;
              }
          }
        }
        fseek(F, 0, SEEK_SET );
      }
      else if(comp_asa.ch_id=='G'){
        while(fgets(line,100,G)){
          if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
            &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.sasa,&chain.Q,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_no)){
              if(comp_asa.atm_no==chain.atm_no && comp_asa.sasa!=chain.sasa){
                  fprintf(G_interacting,"%s",line);
                  area[6]+=chain.sasa-comp_asa.sasa;
              }
          }
        }
        fseek(G, 0, SEEK_SET );
      }
      else if(comp_asa.ch_id=='H'){
        while(fgets(line,100,H)){
          if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
            &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.sasa,&chain.Q,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_no)){
              if(comp_asa.atm_no==chain.atm_no && comp_asa.sasa!=chain.sasa){
                  fprintf(H_interacting,"%s",line);
                  area[7]+=chain.sasa-comp_asa.sasa;
              }
          }
        }
        fseek(H, 0, SEEK_SET );
      }

        // printf("%d %d %s %s %c %d %5.2f %6.4f %d %d %d %6.2f\n",
        //   i,comp_asa.atm_no,comp_asa.atm_nm,comp_asa.res_nm,comp_asa.ch_id,comp_asa.res_no,comp_asa.sasa,comp_asa.Q,comp_asa.N,comp_asa.atm_tp,comp_asa.atm_gp,comp_asa.surf);
        //   i++;
    }
  }

  printf("Interface area:\nChain A:\t%f\nChain B:\t%f\nChain C:\t%f\nChain D:\t%f\nChain E:\t%f\nChain F:\t%f\nChain G:\t%f\nChain H:\t%f\n",
    area[0],area[1],area[2],area[3],area[4],area[5],area[6],area[7]);

  fclose(comp);
  fclose(A);
  fclose(B);
  fclose(C);
  fclose(D);
  fclose(E);
  fclose(F);
  fclose(G);
  fclose(H);
  fclose(A_interacting);
  fclose(B_interacting);
  fclose(C_interacting);
  fclose(D_interacting);
  fclose(E_interacting);
  fclose(F_interacting);
  fclose(G_interacting);
  fclose(H_interacting);
}
