#include <stdio.h>
struct client {
    int code ;       //code du cliets
    char nom[30];    //nom de client
    int solde;       //solde pour client
};typedef struct client client;
//fonction pour inserer un client:
void get_client(client *cl){
    printf("donner le code du client\n");
    scanf("%d",&cl->code);
    printf("donner le nom du client\n");
    scanf("%s",cl->nom);
    printf("donner le solde du client\n");
    scanf("%d",&cl->solde);
}
//fonction de tri pour les clients :
void tri_clients(client *tab,int taille){
    int i=taille,aux;
    while(i>1){
        for(int j=0;j<i;j++){
            if(tab[j].code>tab[j+1].code){
                aux=tab[j].code;
                tab[j].code=tab[j+1].code;
                tab[j+1].code=aux;
            }
        }i--;
    }
}
//recherche du client donner par clavier
void return_client(client *tab, int taille, int code) {
    int deb = 0, fin = taille - 1, moy;
    while (deb <= fin) {
        moy = (deb + fin) / 2;
        if (code == tab[moy].code) {
            printf("Le client est %s, de code %d et de solde %d", tab[moy].nom, tab[moy].code, tab[moy].solde);
            return;
        } else if (code < tab[moy].code) {
            fin = moy - 1;
        } else {
            deb = moy + 1;
        }
    }
    printf("Client non trouvé pour le code %d", code);
}
void main(){
    client tab[20];
    int taille,code;
    printf("donner la taille du tab de clients");
    scanf("%d",&taille);
    for(int i=0;i<taille;i++){
        get_client(&tab[i]);
    }
    tri_clients(tab,taille);
    printf("donner le code du client a chercher ");
    scanf("%d",&code);
    return_client(tab,taille,code);
}
