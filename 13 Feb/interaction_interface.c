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

typedef struct atm{
  int atm_no;
  char atm_nm[4];
  int res_no;
  char res_nm[4];
  float x;
  float y;
  float z;
}atm;

typedef struct pdb{
  int atm_no;
  int res_no;
  double x;
  double y;
  double z;
  float occ_fact;
  float temp_fact;
  char atm_nm[4];
  char res_nm[4];
  char ch_id;
  char atom;
}pdb;

void find(char asa_name[], char pdb_name[],atm *atm_list);

void main(){
  char line[100];
  asa chain;
  atm A[5000],B[5000],C[5000],D[5000],E[5000],F[5000],G[5000],H[5000];
  find("asa/A_interacting.asa","pdb/A.pdb",A);
  find("asa/B_interacting.asa","pdb/B.pdb",B);
  find("asa/C_interacting.asa","pdb/C.pdb",C);
  find("asa/D_interacting.asa","pdb/D.pdb",D);
  find("asa/E_interacting.asa","pdb/E.pdb",E);
  find("asa/F_interacting.asa","pdb/F.pdb",F);
  find("asa/G_interacting.asa","pdb/G.pdb",G);
  find("asa/H_interacting.asa","pdb/H.pdb",H);
}

void find(char asa_name[], char pdb_name[],atm *atm_list){
  FILE *chain_asa,*pdb_asa;
  asa chain;
  pdb pdb_list;

  char line[100];

  chain_asa=fopen(asa_name,"r");
  pdb_asa=fopen(pdb_name,"r");
  while(fgets(line,100,chain_asa)){
    if(sscanf(line,"%d %s %s %c %d %f %f %d %d %d %f\n",
      &chain.atm_no,chain.atm_nm,chain.res_nm,&chain.ch_id,&chain.res_no,&chain.sasa,&chain.Q,&chain.N,&chain.atm_tp,&chain.atm_gp,&chain.surf) && (chain.atm_no)){
        while(fgets(line,100,pdb)){
          if(sscanf(line, "ATOM  %5d  %4s %s %c  %d   %lf%lf%lf  %f  %f           %c\n",
              &pdb_list.atm_no, pdb_list.atm_nm,pdb_list.res_nm,&pdb_list.ch_id,&pdb_list.res_no,&pdb_list.x,&pdb_list.y,&pdb_list.z,&pdb_list.occ_fact,&pdb_list.temp_fact,&pdb_list.atom) && chain.atm_no==pdb_list.atm_no){
              atm_list.atm_no=pdb_list.atm_no;
              strcpy(atm_list.atm_nm,pdb_list.atm_nm);
              atm_list.res_no=pdb_list.res_no;
              strcpy(atm_list.res_nm,pdb_list.res_nm);
              atm_list.x=pdb_list.x;
              atm_list.y=pdb_list.y;
              atm_list.z=pdb_list.z;
              break;
          }
        }
    }
  }
}
