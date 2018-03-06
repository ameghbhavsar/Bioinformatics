#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

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

int salt_bridge(char pdb1[], char pdb2[]);

void main(){
  int i,j,salt_bridge_count=0;
  char pdb_name[8][11];
  for(i=0;i<8;i++){
    snprintf(pdb_name[i],11,"pdb/%c.pdb",i+65);
  }
  for(i=0;i<8;i++){
    for(j=i+1;j<8;j++){
      salt_bridge_count=salt_bridge(pdb_name[i],pdb_name[j]);
      printf("Between chains %c and %c: %d \n",i+65,j+65,salt_bridge_count);
    }
  }
}



int salt_bridge(char pdb1_name[], char pdb2_name[]){
  FILE *F1,*F2;
  F1=fopen(pdb1_name,"r");
  F2=fopen(pdb2_name,"r");
  pdb pdb1,pdb2;
  char line[100];
  int count=0;
  float dist;
  while(fgets(line,100,F1)){
    if(sscanf(line, "ATOM  %5d  %4s %s %c  %d   %lf%lf%lf  %f  %f           %c\n",
        &pdb1.atm_no, pdb1.atm_nm,pdb1.res_nm,&pdb1.ch_id,&pdb1.res_no,&pdb1.x,&pdb1.y,&pdb1.z,&pdb1.occ_fact,&pdb1.temp_fact,&pdb1.atom)){
          if(!strcmp(pdb1.res_nm,"ARG") || !strcmp(pdb1.res_nm,"GLU") || !strcmp(pdb1.res_nm,"ASP") || !strcmp(pdb1.res_nm,"LYS")){
            while(fgets(line,100,F2)){
              if(sscanf(line, "ATOM  %5d  %4s %s %c  %d   %lf%lf%lf  %f  %f           %c\n",
                &pdb2.atm_no, pdb2.atm_nm,pdb2.res_nm,&pdb2.ch_id,&pdb2.res_no,&pdb2.x,&pdb2.y,&pdb2.z,&pdb2.occ_fact,&pdb2.temp_fact,&pdb2.atom)){
      					// printf( "ATOM  %5d  %4s %s %c  %d   %lf%lf%lf  %f  %f           %c\n",
                //       pdb2.atm_no, pdb2.atm_nm,pdb2.res_nm,pdb2.ch_id,pdb2.res_no,pdb2.x,pdb2.y,pdb2.z,pdb2.occ_fact,pdb2.temp_fact,pdb2.atom);
                // printf("%s\n",pdb1.res_nm);
                  if(!strcmp(pdb1.res_nm,"ARG")){
                    if(!strcmp(pdb1.atm_nm,"NH1") || !strcmp(pdb1.atm_nm,"NH2") || !strcmp(pdb1.atm_nm,"NE")){
                      if(!strcmp(pdb2.res_nm,"ASP")){
                        if(!strcmp(pdb2.atm_nm,"OD1") || !strcmp(pdb2.atm_nm,"OD2")){
                          dist=sqrt(pow(pdb1.x-pdb2.x,2)+pow(pdb1.y-pdb2.y,2)+pow(pdb1.z-pdb2.z,2));
                          if(dist<4) count++;
                        }
                        if(!strcmp(pdb2.res_nm,"GLU")){
                          if(!strcmp(pdb2.atm_nm,"OE1") || !strcmp(pdb2.atm_nm,"OE2")){
                            dist=sqrt(pow(pdb1.x-pdb2.x,2)+pow(pdb1.y-pdb2.y,2)+pow(pdb1.z-pdb2.z,2));
                            if(dist<4) count++;
                          }
                        }
                      }
                    }
                  }

                  if(!strcmp(pdb1.res_nm,"LYS")){
                    if(!strcmp(pdb1.atm_nm,"NZ")){
                      if(!strcmp(pdb2.res_nm,"ASP")){
                        if(!strcmp(pdb2.atm_nm,"OD1") || !strcmp(pdb2.atm_nm,"OD2")){
                          dist=sqrt(pow(pdb1.x-pdb2.x,2)+pow(pdb1.y-pdb2.y,2)+pow(pdb1.z-pdb2.z,2));
                          if(dist<4) count++;
                        }
                      }
                      if(!strcmp(pdb2.res_nm,"GLU")){
                        if(!strcmp(pdb2.atm_nm,"OE1") || !strcmp(pdb2.atm_nm,"OE2")){
                          dist=sqrt(pow(pdb1.x-pdb2.x,2)+pow(pdb1.y-pdb2.y,2)+pow(pdb1.z-pdb2.z,2));
                          if(dist<4) count++;
                        }
                      }
                    }
                  }

                  if(!strcmp(pdb2.res_nm,"ARG")){
                    if(!strcmp(pdb2.atm_nm,"NH1") || !strcmp(pdb2.atm_nm,"NH2") || !strcmp(pdb2.atm_nm,"NE")){
                      if(!strcmp(pdb1.res_nm,"ASP")){
                        if(!strcmp(pdb1.atm_nm,"OD1") || !strcmp(pdb1.atm_nm,"OD2")){
                          dist=sqrt(pow(pdb1.x-pdb2.x,2)+pow(pdb1.y-pdb2.y,2)+pow(pdb1.z-pdb2.z,2));
                          if(dist<4) count++;
                        }
                        if(!strcmp(pdb1.res_nm,"GLU")){
                          if(!strcmp(pdb1.atm_nm,"OE1") || !strcmp(pdb1.atm_nm,"OE2")){
                            dist=sqrt(pow(pdb1.x-pdb2.x,2)+pow(pdb1.y-pdb2.y,2)+pow(pdb1.z-pdb2.z,2));
                            if(dist<4) count++;
                          }
                        }
                      }
                    }
                  }

                  if(!strcmp(pdb2.res_nm,"LYS")){
                    if(!strcmp(pdb2.atm_nm,"NZ")){
                      if(!strcmp(pdb1.res_nm,"ASP")){
                        if(!strcmp(pdb1.atm_nm,"OD1") || !strcmp(pdb1.atm_nm,"OD2")){
                          dist=sqrt(pow(pdb1.x-pdb2.x,2)+pow(pdb1.y-pdb2.y,2)+pow(pdb1.z-pdb2.z,2));
                          if(dist<4) count++;
                        }
                      }
                      if(!strcmp(pdb1.res_nm,"GLU")){
                        if(!strcmp(pdb1.atm_nm,"OE1") || !strcmp(pdb1.atm_nm,"OE2")){
                          dist=sqrt(pow(pdb1.x-pdb2.x,2)+pow(pdb1.y-pdb2.y,2)+pow(pdb1.z-pdb2.z,2));
                          if(dist<4) count++;
                        }
                      }
                    }
                  }
              }
            }
            fseek(F2, 0, SEEK_SET );
          }
    }
  }
  fclose(F1);
  fclose(F2);
  return count;
}
