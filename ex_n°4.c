#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct nbrw{
    int nbr;//nombre d'apparence de mot;
    char wrd[100];//mot;
};typedef struct nbrw nbrw;
int find_wrd(nbrw *tab,int taille,char *ch)//fonction pour chercher un mot dans le tableux des mots;
{
    int i=0;
    while(i<=taille && strcmp(ch,tab[i].wrd)!=0){i++;};
    if(i<=taille){return i;}
    else {return -1;}
}
void add_word(nbrw *tab,char *wrd,int taille)
//fonction pour ajouter un mot au tableu des mots ou incrementer le nombre d apparence par 1
{
    int cond=find_wrd(tab,taille,wrd);
    if(cond==-1){
        taille++;
        tab[taille].nbr=1;
        strcpy(tab[taille].wrd,wrd);
    }else{
        tab[cond].nbr++;
    }
}
void tab_share(nbrw* tab, int taille){//afficher les element du tableaux;
    for(int i=0;i<taille;i++){
        printf("le mots est %s de nombre d'occurence %d \n",tab[i].wrd,&tab[i].nbr);
    }
}
int main(){
    nbrw tab[100];
    int taille=0;
    FILE *file=fopen("test_file.txt","r");
    if(file!=NULL){
        char ch[100];
        while(fgets(ch,100,file)!=NULL){
            char wrd[100];
            for(int i=0;i<strlen(ch);i++)//decomposer la phrase en mots;
            {if(ch[i+1]==' ' || ch[i+1]=='\0'){
                    add_word(tab,wrd,taille);
                }
                if(ch[i]==' '){strcpy(wrd,"");continue;}
                wrd[i]=ch[i];
            }
        }
        fclose(file);
    }else{printf("error!!!");}
    tab_share(tab,taille);
}
