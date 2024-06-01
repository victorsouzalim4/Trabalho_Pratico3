#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct{
    char day[100];
    char month[100];
    char year[100];

} DateTime;

typedef struct{
    char apelidos[18][1000];
} ListaDeApelidos;

typedef struct{

    char id[100];
    char name[100];
    ListaDeApelidos alternate_names;
    char house[100];
    char ancestry[100];
    char species[100];
    char patronus[100];
    bool hogwartsStaff;
    bool hogwartsStudent;
    char actorName[100];
    bool alive;
    DateTime dateOfBirth;
    int yearOfBirth;
    char  eyeColour[100];
    char  gender[100];
    char  hairColour[100];
    bool wizard;

}Personagem;






typedef struct Celula{
    Personagem personagem;
    struct Celula* prox;

}Celula;

Celula* construtorCelulaCabeca(){
    Celula* tmp = (Celula*) malloc(sizeof(Celula));
    tmp->prox = NULL;

    return tmp;
}

Celula* construtorCelula(Personagem personagem){
    Celula* tmp = (Celula*) malloc(sizeof(Celula));
    tmp->personagem = personagem;
    tmp->prox = NULL;

    return tmp;
}

typedef struct Pilha{
    Celula* cabeca;
    Celula* ultimo;
    int tamanho;

}Pilha;

Pilha* construtorPilha(){
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));

    pilha->cabeca = construtorCelulaCabeca();
    pilha->ultimo = pilha->cabeca;
    pilha->tamanho = 0;

    return pilha;
}

Personagem remover(Pilha* pilha){
    Personagem personagem;
    if(pilha->tamanho <= 0){
        printf("Pilha Vazia\n");
    }else{
        Celula* tmp;
        for(tmp = pilha->cabeca; tmp->prox != pilha->ultimo; tmp = tmp->prox);

        personagem = pilha->ultimo->personagem;
        pilha->ultimo = tmp;

        tmp->prox = NULL;
        tmp = NULL;
        free(tmp);

        pilha->tamanho--;
    }

    return personagem;
}

void inserir(Pilha* pilha, Personagem personagem){

        pilha->ultimo->prox = construtorCelula(personagem);
        pilha->ultimo = pilha->ultimo->prox;
        pilha->tamanho++;
}

void imprime(Personagem personagem){
    printf("%s ## ", personagem.id);
       printf("%s ## ", personagem.name);

        printf("{");
       for(int i = 0; i < 10; i++){
            int cont = 0;
            if(personagem.alternate_names.apelidos[i][0] > 'A' && personagem.alternate_names.apelidos[i][0] < 'z'){
                cont++;
            }
            if(cont != 0){
                if(i != 0){
                    printf(", %s", personagem.alternate_names.apelidos[i]);
                }else{
                    printf("%s", personagem.alternate_names.apelidos[i]);
                }
                 
            }
        }
         printf("} ## ");
    
       printf("%s ## ", personagem.house);
       printf("%s ## ", personagem.ancestry);
       printf("%s ## ", personagem.species);
       printf("%s ## ", personagem.patronus);
        if(personagem.hogwartsStaff == true){
          printf("true ## ");
       }
       else{
          printf("false ## ");
       }
       if(personagem.hogwartsStudent == true){
          printf("true ## ");
       }
       else{
          printf("false ## ");
       }
       printf("%s ## ", personagem.actorName);
       if(personagem.alive == true){
          printf("true ## ");
       }
       else{
          printf("false ## ");
       }
       printf("%s-", personagem.dateOfBirth.day);
       printf("%s-", personagem.dateOfBirth.month);
       printf("%s ## ", personagem.dateOfBirth.year);
       printf("%d ## ", personagem.yearOfBirth);
       printf("%s ## ", personagem.eyeColour);
       printf("%s ## ", personagem.gender);
       printf("%s ## ", personagem.hairColour);

       if(personagem.wizard == true){
          printf("true]\n");
       }
       else{
          printf("false]\n");
       }
       
}

void mostra(Pilha* pilha){
    int contador = 0;

    printf("[ Top ]\n");
    for(int j = pilha->tamanho; j > 0; j--){
        Celula* i = pilha->cabeca;
        for(int k = 0; k < j && i != NULL; i = i->prox, k++);
        if(i->personagem.name != ""){
            printf("[%d ## ", contador++);
            imprime(i->personagem);
        }

    }
    printf("[ Bottom ]\n");
}





void imprimePersonagem(Personagem personagens[], int indice){
       printf("%s ## ", personagens[indice].id);
       printf("%s ## ", personagens[indice].name);

        printf("{");
       for(int i = 0; i < 10; i++){
            int cont = 0;
            if(personagens[indice].alternate_names.apelidos[i][0] > 'A' && personagens[indice].alternate_names.apelidos[i][0] < 'z'){
                cont++;
            }
            if(cont != 0){
                if(i != 0){
                    printf(", %s", personagens[indice].alternate_names.apelidos[i]);
                }else{
                    printf("%s", personagens[indice].alternate_names.apelidos[i]);
                }
                 
            }
        }
         printf("} ## ");
    
       printf("%s ## ", personagens[indice].house);
       printf("%s ## ", personagens[indice].ancestry);
       printf("%s ## ", personagens[indice].species);
       printf("%s ## ", personagens[indice].patronus);
        if(personagens[indice].hogwartsStaff == true){
          printf("true ## ");
       }
       else{
          printf("false ## ");
       }
       if(personagens[indice].hogwartsStudent == true){
          printf("true ## ");
       }
       else{
          printf("false ## ");
       }
       printf("%s ## ", personagens[indice].actorName);
       if(personagens[indice].alive == true){
          printf("true ## ");
       }
       else{
          printf("false ## ");
       }
       printf("%s-", personagens[indice].dateOfBirth.day);
       printf("%s-", personagens[indice].dateOfBirth.month);
       printf("%s ## ", personagens[indice].dateOfBirth.year);
       printf("%d ## ", personagens[indice].yearOfBirth);
       printf("%s ## ", personagens[indice].eyeColour);
       printf("%s ## ", personagens[indice].gender);
       printf("%s ## ", personagens[indice].hairColour);

       if(personagens[indice].wizard == true){
          printf("true");
       }
       else{
          printf("false");
       }
       
}

void recebeAtributos(char atributos[18][1000], char* linha){
        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 1000; j++) {
            atributos[i][j] = '\0';
        }
    }
    int pos = 0;
    for(int i = 0; i < 18; i++){
        for(int j = pos, k = 0; j < 1000; j++, k++){
            if(linha[j] != ';' && linha[j] != '\0' && linha[j] != '\n'){
                atributos[i][k] = linha[j];
            }
            else{
                pos = j+1;
                j = 1000;
            }
            //printf("%c", atributos[i][k]);
        }  
        //printf("\n");  
    }
}

void separaApelidos(char apelidos[10][150], char atributos[18][1000]){
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 150; j++){
            apelidos[i][j] = '\0';
        }
    }
    int  pos = 0;
    for(int i = 0; i < 10; i++){
        int cont = 0;
        for(int j = pos, k = 0; j < 150; j++, k++){
            if(atributos[2][j] == '\''){
                cont++;
                j++;
            }
            if(cont == 1){
                apelidos[i][k] = atributos[2][j];
            }
            else if(cont == 2){
                pos = j+1;
                j = 150; 
            }
               //printf("%c", apelidos[i][k]);  
        }
        //printf("\n");
    }

}

bool StringToBoolean(char atributos[18][1000], int indice){
    char str[1000];
    bool valorLogico = false;

    for(int i = 0; i < 1000; i++){
        str[i] = '\0';
    }
    for(int i = 0; atributos[indice][i] != '\0'; i++){
        str[i] = atributos[indice][i];
    }

    //printf("%s\n", str);

    if(strcmp(str, "VERDADEIRO") == 0){
        valorLogico = true;
    }

    //printf("%d", valorLogico);

    return valorLogico;
}

void separaData(Personagem personagem[405], char atributos[18][1000], int indice, int num){
    char day[4]; 
    char month[4];
    char year[5]; 

    int pos = 0;
    int i = 0;


    while (atributos[indice][pos] != '-') {
        day[i++] = atributos[indice][pos++];
    }
    day[i] = '\0';
    pos++; 

  
    i = 0;
    while (atributos[indice][pos] != '-') {
        month[i++] = atributos[indice][pos++];
    }
    month[i] = '\0'; 
    pos++; 

  
    i = 0;
    while (atributos[indice][pos] != '\0') {
        year[i++] = atributos[indice][pos++];
    }
    year[i] = '\0';

    strcpy(personagem[num].dateOfBirth.day, day);
    strcpy(personagem[num].dateOfBirth.month, month);
    strcpy(personagem[num].dateOfBirth.year, year);

}

int StringToInt(char atributos[18][1000], int indice){
    char str[5]; 
    for(int i = 0; i < 5; i++){
        str[i] = atributos[indice][i];
    }
    char *endptr; 
    int valor = strtol(str, &endptr, 10); 

    if (*endptr != '\0') {
        //printf("Erro: A string não é um número válido.\n");
    } else {
        //printf("Valor convertido: %d\n", valor);
    }

    return valor;

}

void ConstroiPersonagem(char atributos[18][1000], char apelidos[10][150], Personagem* personagem, int posicao){
    
    char str[1000];
    
    for(int i = 0; i < 1000; i++){
        str[i] = '\0';
    }

    for(int i = 0; atributos[0][i] != '\0'; i++){
        str[i] = atributos[0][i];
    }
    strcpy(personagem[posicao].id, str);
 




    for(int i = 0; i < 1000; i++){
        str[i] = '\0';
    }

    for(int i = 0; atributos[1][i] != '\0'; i++){
        str[i] = atributos[1][i];
    }
    strcpy(personagem[posicao].name, str);
   




        for(int i = 0; i < 10; i++){
            char str1[150];
            for(int k = 0; k < 150; k++){
                str1[i] = '\0';
            }
            int cont = 0;
            for(int j = 0; j < 150 ; j++){
                if(apelidos[i][j] > 'a' && apelidos[i][j] < 'z'){
                    cont++;
                }
                    //printf("entrei");
                    str1[j] = apelidos[i][j+1];
                    //printf("%c", str1[j]);
                    //printf("%d\n", j);
                    
                 

            }
            strcpy(personagem[posicao].alternate_names.apelidos[i], str1);
            
            
            if(cont != 0){
                //printf("\n%s", str1);
                //printf("\n %d %s,",i, personagem[posicao].alternate_names.apelidos[i]);
            }   
        }

    








    for(int i = 0; i < 1000; i++){
        str[i] = '\0';
    }

    for(int i = 0; atributos[3][i] != '\0'; i++){
        str[i] = atributos[3][i];
    }
    strcpy(personagem[posicao].house, str);
    





    for(int i = 0; i < 1000; i++){
        str[i] = '\0';
    }

    for(int i = 0; atributos[4][i] != '\0'; i++){
        str[i] = atributos[4][i];
    }
    strcpy(personagem[posicao].ancestry, str);
    






    for(int i = 0; i < 1000; i++){
        str[i] = '\0';
    }

    for(int i = 0; atributos[5][i] != '\0'; i++){
        str[i] = atributos[5][i];
    }
    strcpy(personagem[posicao].species, str);
    







    for(int i = 0; i < 1000; i++){
        str[i] = '\0';
    }

    for(int i = 0; atributos[6][i] != '\0'; i++){
        str[i] = atributos[6][i];
    }
    strcpy(personagem[posicao].patronus, str);
    






    bool valor = StringToBoolean(atributos, 7);
    if(valor == true){
        personagem[posicao].hogwartsStaff = true;
    }
    else{
        personagem[posicao].hogwartsStaff = false;
    }
    






    valor = StringToBoolean(atributos, 8);
    if(valor == true){
        personagem[posicao].hogwartsStudent = true;
    }
    else{
        personagem[posicao].hogwartsStudent = false;
    }
    





    for(int i = 0; i < 1000; i++){
        str[i] = '\0';
    }

    for(int i = 0; atributos[9][i] != '\0'; i++){
        str[i] = atributos[9][i];
    }
    strcpy(personagem[posicao].actorName, str);
    







    valor = StringToBoolean(atributos, 10);
    if(valor == true){
        personagem[posicao].alive = true;
    }
    else{
        personagem[posicao].alive = false;
    }
    







    separaData(personagem,atributos, 12, posicao);







    int ano = StringToInt(atributos, 13);
    personagem[posicao].yearOfBirth = ano;
    






    for(int i = 0; i < 1000; i++){
        str[i] = '\0';
    }

    for(int i = 0; atributos[14][i] != '\0'; i++){
        str[i] = atributos[14][i];
    }
    strcpy(personagem[posicao].eyeColour, str);
    







    for(int i = 0; i < 1000; i++){
        str[i] = '\0';
    }

    for(int i = 0; atributos[15][i] != '\0'; i++){
        str[i] = atributos[15][i];
    }
    strcpy(personagem[posicao].gender, str);
    





    for(int i = 0; i < 1000; i++){
        str[i] = '\0';
    }

    for(int i = 0; atributos[16][i] != '\0'; i++){
        str[i] = atributos[16][i];
    }
    strcpy(personagem[posicao].hairColour, str);
    


    valor = StringToBoolean(atributos, 17);
    if(valor == true){
        personagem[posicao].wizard = true;
    }
    else{
        personagem[posicao].wizard = false;
    }
    
}   

bool isIgual(char str[], char id[]){
    bool test = true;
    int tam = strlen(id) -1 ;
    for(int i = 0; i < tam; i++){
        if(str[i] != id[i]){
            test = false;
            i = tam;
        }
    }

    return test;
}

Personagem getPersonagem(Personagem personagens[], char* id){
    Personagem personagemAtual;
    for(int i = 0; i < 405; i++){
        if(isIgual(personagens[i].id, id)){
            personagemAtual = personagens[i];
            i = 405;
        }
    }

    return personagemAtual;
}

bool isFim(char str[]){
    bool test = true;

    if(str[0] == 'F' && str[1] == 'I' && str[2] == 'M'){
        test = false;
    }

    return test;
}

int getOperacao(char* entrada){
    int resp;

    if(entrada[0] == 'I'){
        resp = 0;
    }else{
        resp = 1;
    }

    return resp;
}
 
char* subString(int posInit, int posFinal, char* entrada) {

    char* novaString = (char*) malloc((posFinal - posInit + 1) * sizeof(char));
    
    for (int i = 0; i < (posFinal - posInit); i++) {
        novaString[i] = entrada[posInit + i];
    }

    novaString[posFinal - posInit] = '\0';
    
    return novaString;
}

int toInt(char* entrada){
    int indicadorFim = 0;
    int i = 0;

    while(entrada[i] != '\0'){
        indicadorFim++;
        i++;
    }

    char novaString[indicadorFim];

    for(int j = 0; j < indicadorFim; j++){
        novaString[j] = entrada[indicadorFim-j-1];
    }

    int soma = 0;

    for(int i = 0; i < indicadorFim; i++){
        int asccivalue = novaString[i];
        asccivalue -= 48;

        soma+= asccivalue*(pow(10, i));
    }

    return soma;

}

int getEndOfNumber(char* entrada){
    int i;

    for(i = 3; i < strlen(entrada) && entrada[i] != ' '; i++);

    return i;
}

int main(){

    FILE *arq = fopen("C:/Users/Victor/Documents/FACULDADE/2 semestre/Aeds 2/TP_3/Trabalho_Pratico3/characters.csv", "r");
    char linha[1000];
    char atributos[18][1000];
    char apelidos[10][150];
    Personagem* personagens = (Personagem*) malloc (sizeof(Personagem)*404);




    if(arq == NULL){
        printf("Erro na abertura do arquivo");
        return 1;
    }

    fgets(linha, 1000, arq);
    int i = 0;
    while(fgets(linha, 300, arq) != NULL ){
        recebeAtributos(atributos, linha);
        separaApelidos(apelidos, atributos);
        ConstroiPersonagem(atributos, apelidos, personagens, i);
        i++;
    } 

  
    char id[100];
    Pilha* pilha = construtorPilha();

    
    scanf("%99[^\n]%*c", id);
    id[strcspn(id, "\r")] = '\0';
    

    while(isFim(id)){
        Personagem personagemAtual = getPersonagem(personagens, id);
        if(personagemAtual.yearOfBirth !=  0){
            inserir(pilha, personagemAtual);
        }
        scanf("%99[^\n]%*c", id);
        id[strcspn(id, "\r")] = '\0';
    }

    int numEntradas;
    scanf("%d", &numEntradas);

    for(int i = 0; i < numEntradas; i++){
        char entrada[100];

        scanf(" %99[^\n]%*c", entrada);
        entrada[strcspn(entrada, "\r")] = '\0';

        switch(getOperacao(entrada)){
            case 0:
                inserir(pilha, getPersonagem(personagens, subString(2, strlen(entrada), entrada)));
                break;
            case 1:
                printf("(R) %s\n", remover(pilha).name);
                break;
            default:
                printf("entrada invalida");
        }
    }

    mostra(pilha);

}

//C:/Users/Victor/Documents/FACULDADE/2 semestre/Aeds 2/TP_3/Trabalho_Pratico3/characters.csv