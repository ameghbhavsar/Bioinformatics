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
    FILE *A,*B,*C,*D,*E,*F,*G,*H;
    char line[100],prev[4];
    float tot_res_no,pos_comp,neg_comp,arm_comp,neutral_comp,hphobic_comp,pos=0,neg=0,arm=0,neutral=0,hphobic=0;
    asa chain;
    strcpy(prev," ")
    A=fopen("asa/A_interacting.asa","r");
    while(fgets(line,100,B)){
      if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
        &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.sasa,&chain.Q,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_no)){
          if(strcmp(chain.res_nm,prev)){
            strcpy(prev,chain);

          }
      }
    }
}
