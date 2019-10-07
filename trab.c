#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AUXILIARES
void geraArquivo(
                    int *a, int *b, int *c, int *d, int *e, int *f, 
                    int *a2, int *b2, int *c2, int *d2, int *e2, int *f2,
                    int *a3, int *b3, int *c3, int *d3, int *e3, int *f3
                );
void catalogar();
void extrai(char file[20], int *a, int *b, int *c, int *d, int *e, int *f);

// FUNÇÕES 

// ARQUIVOS
#define SPIDER "albina.txt"
#define CICADA "cigarra.txt"
#define SCORPION "escorpiao.txt"

/*---------------- CLASSIFICADORES ------------------*/
//      FAMILIA                     
#define fam_aa "AACGTCT"  
#define fam_tc "TCGACGG"  
#define fam_cc "CCTTGAA"  

//      GENERO
#define gen_tt "TTAACGC"
#define gen_gg "GGATACC" 
#define gen_cg "CGCGTTA"


int main(){
    catalogar();
}

void catalogar(){
    // PARÂMETROS
    int alb_aa=0, alb_tc=0, alb_cc=0, alb_tt=0, alb_gg=0, alb_cg=0;
    int cic_aa=0, cic_tc=0, cic_cc=0, cic_tt=0, cic_gg=0, cic_cg=0;
    int sco_aa=0, sco_tc=0, sco_cc=0, sco_tt=0, sco_gg=0, sco_cg=0;

    extrai(SPIDER, &alb_aa, &alb_tc, &alb_cc, &alb_tt, &alb_gg, &alb_cg);
    extrai(CICADA, &cic_aa, &cic_tc, &cic_cc, &cic_tt, &cic_gg, &cic_cg);
    extrai(SCORPION, &sco_aa, &sco_tc, &sco_cc, &sco_tt, &sco_gg, &sco_cg);


    geraArquivo(
                &alb_aa, &alb_tc, &alb_cc, &alb_tt, &alb_gg, &alb_cg,
                &cic_aa, &cic_tc, &cic_cc, &cic_tt, &cic_gg, &cic_cg,
                &sco_aa, &sco_tc, &sco_cc, &sco_tt, &sco_gg, &sco_cg
            );
}

void extrai(char file[20], int *aa, int *tc, int *cc, int *tt, int *gg, int *cg){
    FILE *fp;
    int arq = 0;

    // Contadores FAMILIA
    int flag_aa = 0, cont_aa = 0;
    int flag_tc = 0, cont_tc = 0;
    int flag_cc = 0, cont_cc = 0;

    // Contadores Gênero
    int flag_tt = 0, cont_tt = 0;
    int flag_gg = 0, cont_gg = 0;
    int flag_cg = 0, cont_cg = 0;

    char txt;

    fp = fopen(file, "a+");
    if(fp == NULL){
        printf("\033[31m[ERRO] Falha ao ler a Base de Dados!\n");
    }else{
        printf("\033[35m[RUN] Extraindo dados de {%s}...\033[0;0m\n", file);
        // ALBINA 
        while (arq != EOF){
            arq = fscanf(fp, "%c", &txt);
            
            // AACGTCT
            if(txt == '\n'){
                continue;
            }else if(txt == fam_aa[cont_aa]){
                flag_aa++;
                cont_aa++;
            }else if (txt != fam_aa[cont_aa]){
                flag_aa = 0;
                cont_aa = 0;
            }

            // TCGACGG
            if(txt == '\n'){
                continue;
            }else if(txt == fam_tc[cont_tc]){
                flag_tc++;
                cont_tc++;
            }else if (txt != fam_tc[cont_tc]){
                flag_tc = 0;
                cont_tc = 0;
            }
            
            // CCTTGAA
            if(txt == '\n'){
                continue;
            }else if(txt == fam_cc[cont_cc]){
                flag_cc++;
                cont_cc++;
            }else if (txt != fam_cc[cont_cc]){
                flag_cc = 0;
                cont_cc = 0;
            }

            // TTAACGC
            if(txt == '\n'){
                continue;
            }else if(txt == gen_tt[cont_tt]){
                flag_tt++;
                cont_tt++;
            }else if (txt != gen_tt[cont_tt]){
                flag_tt = 0;
                cont_tt = 0;
            }

            // GGATACC
            if(txt == '\n'){
                continue;
            }else if(txt == gen_gg[cont_gg]){
                flag_gg++;
                cont_gg++;
            }else if (txt != gen_gg[cont_gg]){
                flag_gg = 0;
                cont_gg = 0;
            }
            
            // CGCGTTA
            if(txt == '\n'){
                continue;
            }else if(txt == gen_cg[cont_cg]){
                flag_cg++;
                cont_cg++;
            }else if (txt != gen_cg[cont_cg]){
                flag_cg = 0;
                cont_cg = 0;
            }

            // RESETS FAMILIA
            if(flag_aa == 7){
                (*aa)++;
                cont_aa = 0;
                flag_aa = 0;
            }
            if(flag_tc == 7){
                (*tc)++;
                cont_tc = 0;
                flag_tc = 0;
            }
            if(flag_cc == 7){
                (*cc)++;
                cont_cc = 0;
                flag_cc = 0;
            } 

             // RESETS GÊNERO
            if(flag_tt == 7){
                (*tt)++;
                cont_tt = 0;
                flag_tt = 0;
            }
            if(flag_gg == 7){
                (*gg)++;
                cont_gg = 0;
                flag_gg = 0;
            }
            if(flag_cg == 7){
                (*cg)++;
                cont_cg = 0;
                flag_cg = 0;
            } 
        }
    }
    printf("\033[36m[INFO] Extração Concluída!\n");
    fclose(fp);
}

void geraArquivo(
                    int *a, int *b, int *c, int *d, int *e, int *f, 
                    int *a2, int *b2, int *c2, int *d2, int *e2, int *f2,
                    int *a3, int *b3, int *c3, int *d3, int *e3, int *f3
                ){
    FILE *fp;

    fp = fopen("catalogo.txt", "w+");
    if(fp == NULL){
        printf("\033[31m[ERRO] Falha ao Salvar Informações!\n");
    }else{
        printf("\n\033[32m[FINISH] Salvando informações!\n");
          
        fputs("ARANHA ALBINA\n(Theridiidae / Phoneutria)\n\n", fp);
        fputs("Sequências - Familia\t\tSequências - Gênero\n", fp);
        fprintf(fp, "[AACGTCT]: %i vezes\t\t\t[TTAACGC]: %i vezes\n", *a, *d);
        fprintf(fp, "[TCGACGG]: %i vezes\t\t\t[GGATACC]: %i vezes\n", *b, *e);
        fprintf(fp, "[CCTTGAA]: %i vezes\t\t\t[CGCGTTA]: %i vezes\n", *c, *f);
        
        fputs("\n\nARANHA CIGARRA\n(Theridiidae /  Avicularia)\n\n", fp);
        fputs("Sequências - Familia\t\tSequências - Gênero\n", fp);
        fprintf(fp, "[AACGTCT]: %i vezes\t\t\t[TTAACGC]: %i vezes\n", *a2, *d2);
        fprintf(fp, "[TCGACGG]: %i vezes\t\t\t[GGATACC]: %i vezes\n", *b2, *e2);
        fprintf(fp, "[CCTTGAA]: %i vezes\t\t\t[CGCGTTA]: %i vezes\n", *c2, *f2);
        
        fputs("\n\nARANHA ESCORPIÃO\n(Theraphosidae  /  Latrodectus)\n\n", fp);
        fputs("Sequências - Familia\t\tSequências - Gênero\n", fp);
        fprintf(fp, "[AACGTCT]: %i vezes\t\t\t[TTAACGC]: %i vezes\n", *a3, *d3);
        fprintf(fp, "[TCGACGG]: %i vezes\t\t\t[GGATACC]: %i vezes\n", *b3, *e3);
        fprintf(fp, "[CCTTGAA]: %i vezes\t\t\t[CGCGTTA]: %i vezes\n", *c3, *f3);
    }
}