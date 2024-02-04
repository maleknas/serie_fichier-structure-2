#include<stdio.h>
#include <string.h>
#include <stdlib.h>
struct nbr{
    char car;     //caractere
    int nb ;      //nombre de repetition
};typedef struct nbr nbr;
int find(char c , nbr *tab,int n){ //rechercher la pos de c dans tab
    int i=0;
    while(i<=n && tab[i].car!=c){i++;}
    if(i<=n){return i;}
    else{return -1;}
}
void insere_caractere(nbr *tab,int *n,char c){//la fonction inser_caractere
    if (find(c,tab,*n)==-1){
        *n=*n+1;
        tab[*n].car=c;
        tab[*n].nb=1;
    }else {tab[find(c,tab,*n)].nb++;}
}
void view_occurence(nbr*tab,int n){ //la fonction view occurence
    for(int i=0;i<n;i++){
        printf(" le nombre d'apparence de %c est %d \n",tab[i].car,tab[i].nb);
    }
}
void main(){
    nbr tab[100];
    int taille=0;
    FILE * texte=fopen("texte.txt","r");
    if(texte!=NULL){
        char ch[100];
        while(fgets(ch,100,texte)!=NULL){
            for(int i=0;i<strlen(ch);i++){
                insere_caractere(tab,&taille,ch[i]);
            }
        }
        fclose(texte);
    }
    else{printf("error!!!");}
        view_occurence(tab,taille);

}

