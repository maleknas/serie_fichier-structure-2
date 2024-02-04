#include<stdio.h>
#include <string.h>
#include <stdlib.h>
struct adresse {
    char nr[100];  //nom rue
    char vil[100]; //ville
    int cp;        //code postal
};typedef struct adresse adresse ;
struct ddn {   //date de naissance
    int jour;  //jour
    int mois;  //mois
    int annee; //annee
};typedef struct ddn ddn;
struct fiche {
    char nom[100]; //nom
    char prenom[100];//prenom
    adresse ad ;  //adresse
    int phone ;   //telephone
    ddn dn    ;   // date de naissance
};typedef struct fiche fiche ;
void lireFiche(fiche *fch){ //****** fonction pour lire une fichier :
    printf("donner votre nom\n");//nom
    scanf("%s",fch->nom);
    printf("donner votre prenom\n");//prenom
    scanf("%s",fch->prenom);
    printf("donner votre adresse\n"); //adresse
    printf("inserer la rue\n");
    scanf("%s",fch->ad.nr);
    printf("inserer le code postal\n");
    scanf("%d",&fch->ad.cp);
    printf("inserer la ville\n");
    scanf("%s",fch->ad.vil);
    printf("donner votre telephone\n");//telephone
    scanf("%d",&fch->phone);
    printf("donner votre date de naissance\n");//date de naissance
    printf("inserer le jour\n");
    scanf("%d",&fch->dn.jour);
    printf("inserer le mois\n");
    scanf("%d",&fch->dn.mois);
    printf("inserer l'annee\n");
    scanf("%d",&fch->dn.annee);
}
void remplirTab (fiche tf[100],int n){ //****** remmplir un tableaux de fiche
    for(int i=0 ;i<n;i++){
        lireFiche(&tf[i]);
    }
}
int rechNom(fiche tf[100],char nom,int n){  //******rechercher par nom
    int i=0;
    while(i<=n && strcmp(tf[i].nom,nom)==0){i++;}
    if (i<=n){return  i;}
    else {return -1;};
}
int rechTel(fiche tf[100],int ph,int n){  //******rechercher par teliphone
    int i=0;
    while(i<=n && tf[i].phone!=ph){i++;}
    if (i<=n){return i;}
    else {return -1;}
}
void affichePers(fiche fch){       //******afficher une fiche
    printf("le nom est : %s\n",fch.nom);
    printf("le prenom est : %s\n",fch.prenom);
    printf("le nom rue est : %s\n",fch.ad.nr);
    printf("le code postal est : %d\n",fch.ad.cp);
    printf("la ville est : %s\n",fch.ad.vil);
    printf("le telephone est : %d\n",fch.phone);
    printf("le jour de naissance est : %d\n",fch.dn.jour);
    printf("le mois de naissance est : %d\n",fch.dn.mois);
    printf("l'annee de naissance est : %d\n",fch.dn.annee);
}
void main(){
    fiche fch;
    lireFiche(&fch);
    affichePers(fch);
}
