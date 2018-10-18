#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio2.h>
#include <ctype.h>


void criptografar(char matriz[][5], char criptografada[], char mensagem[]){
	int i, j, k, l;
	int wlinha_k, xcoluna_k, ylinha_l , zcoluna_l;
	int tammensagem;
	tammensagem = strlen(mensagem);
	for(k=0, l=1; l < tammensagem; k=k+2, l=l+2){	
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				if (mensagem[k] == matriz[i][j]){  
                  wlinha_k = i;
                  xcoluna_k = j;
            	} else if (mensagem[l] == matriz[i][j]){  
                  ylinha_l = i;
                  zcoluna_l = j;                  
            	}	  
			}
		}	
		if( wlinha_k == ylinha_l){
			criptografada[k] = matriz[wlinha_k][(xcoluna_k + 1) % 5];
			criptografada[l] = matriz[ylinha_l][(zcoluna_l + 1) % 5];
		}
		if( xcoluna_k == zcoluna_l){
			criptografada[k] = matriz[(wlinha_k + 1) % 5][xcoluna_k];
			criptografada[l] = matriz[(ylinha_l + 1) % 5][zcoluna_l];
		}
		else{
			criptografada[k] = matriz[wlinha_k][zcoluna_l];
			criptografada[l] = matriz[ylinha_l][xcoluna_k];
		}
	}
criptografada[k]='\0';	//para determinar o final da string 
printf("\n Palavra criptografada: %s \n", criptografada);
}

void descriptografar(char matriz[][5], char descriptografada[], char criptografada[]){
        int i, j, k, l;
        int wlinha_k, xcoluna_k, ylinha_l , zcoluna_l;
        int tammensagem;
        tammensagem = strlen(criptografada);
        for(k=0, l=1; l < tammensagem; k=k+2, l=l+2){   
                for(i=0;i<5;i++){
                        for(j=0;j<5;j++){
                                if (criptografada[k] == matriz[i][j]){  
                  wlinha_k = i;
                  xcoluna_k = j;
                } else if (criptografada[l] == matriz[i][j]){  
                  ylinha_l = i;
                  zcoluna_l = j;                  
                }         
                        }
                }       
                if( wlinha_k == ylinha_l){
                        descriptografada[k] = matriz[wlinha_k][(xcoluna_k + 4) % 5];
                        descriptografada[l] = matriz[ylinha_l][(zcoluna_l + 4) % 5];
                }
                if( xcoluna_k == zcoluna_l){
                        descriptografada[k] = matriz[(wlinha_k + 4) % 5][xcoluna_k];
                        descriptografada[l] = matriz[(ylinha_l + 4) % 5][zcoluna_l];
                }
                else{
                        descriptografada[k] = matriz[wlinha_k][zcoluna_l];
                        descriptografada[l] = matriz[ylinha_l][xcoluna_k];
                }
        }
descriptografada[k]='\0';       
printf("\n Palavra descriptografada: %s \n", descriptografada);
}


int main (){
	setlocale(LC_ALL, "portuguese");
	
	int op=0, i=0, j, l, k, tam, tamtexto;	
	char mensagem[40], chave[100], matriz[5][5], semchave[25], criptografada[26], descriptografada[26];
	char alfa[26]={'A','B','C','D','E','F','G','H','I','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(14,2);
	printf("Cifra Playfair");	
	textbackground(BLACK);
	textcolor(WHITE);
	printf("\n  ________________________________________\n");
	printf("\n Digite a sua opção: ");
	printf("\n 1 - Inserir uma palavra \n 2 - Inserir uma chave \n 3 - Criptografar a palavra inserida  \n 4 - Descriptografar a palavra inserida \n 5 - Limpar tudo \n 6 - Sair do programa");
	printf("\n");

	
	while(op != 6){	
	printf("\n Opção: ");
	scanf("%i", &op);
	switch(op){
		
            case 1:
            	
            	printf("\n Palavra: ");
				fflush(stdin);
				gets(mensagem);
				i=0;
				while(mensagem[i] != '\0'){
				mensagem[i] = toupper(mensagem[i]);
				i++;
				}
				
				tamtexto=strlen(mensagem);
   				for (i=0; i<tamtexto; i++){
				        if(mensagem[i] == ' '){
						   l=i;
				            while (l<tamtexto)
              				{
				               mensagem[l]=mensagem[l+1];
	    	           l++;
    	    	      }
            				  tamtexto--;
            				  i--;
       				 }
   				}
   				
				k = tamtexto;
   				for(i=0, j=1; j < tamtexto; i=i+2, j=j+2){
   					if(mensagem[i] == mensagem[j]){   						
   						for(; k >= j; k--){
   							mensagem[k+1]= mensagem[k];
							if(k==j){												
							mensagem[k]='X';
							break;
							}																				
						   }
						tamtexto++;   
					   }
				   }				
   				if(tamtexto % 2 != 0){
   					mensagem[tamtexto] ='X';
   					mensagem[tamtexto + 1] ='\0';
				}
				   
                break;
                
            
			case 2:
				
            	printf("\n Chave: ");
				fflush(stdin);
				gets(chave);
				i=0;
				
				while(chave[i] != '\0'){
				chave[i] = toupper(chave[i]);
				i++;
				}
				
				tam = strlen(chave);
   				for (i=0; i<tam; i++)
   				{
				        if(chave[i] == ' '){
						   l=i;
				            while (l<tam)
              				{
				               chave[l]=chave[l+1];
	    	           l++;
    	    	      }
            				  tam--;
            				  i--;
       				 }
   				}
				for (i=0;i<tam;i++){
      				for (j=i+1;j<tam;j++){
          				if(chave[i] == chave[j]){ 
		  					l=j;
           						while (l<tam){
            						chave[l]=chave[l+1];
               						l++;
               						}	    
      						tam--;
      						j--;
							}
						}
				}
				
				for(i=0;chave[i] != '\0'; i++){
					if(chave[i]=='J')
					chave[i]= 'I';
				}
				
				j = 0;  
    			for (i = 0; i < 25; i++) {
        			for (k = 0; k < tam; k++) {  
        			    if (chave[k] == alfa[i])
						break;  
			        }  
			        if (k == tam) {  
			            semchave[j] = alfa[i];  
			            j++;  
			        }  
			    }
			    semchave[j]='\0';

				
				for(i=0, k=0;i<5;i++){
					for(j=0;j<5;j++){
						if(chave[k] != '\0'){
						matriz[i][j] = chave[k];
						k++;
						}
						else if (chave[k] == '\0')
						break;
					}
					
					if(j != 5)
					break;
				}
				
				for(k=0;i<5;i++){
					for(;j<5;j++){
						matriz[i][j] = semchave[k];
						k++;
					}
				j=0;
				}
				
				textbackground(WHITE);
				textcolor(BLACK);
				printf("\n MATRIZ: \n");	
				textbackground(BLACK);
				textcolor(WHITE);				
				for(i=0;i<5;i++){
					for(j=0;j<5;j++){
						printf(" %c ",matriz[i][j]);
					}
				printf("\n");
				}
				
				break;
            
			case 3:
            criptografar(matriz, criptografada, mensagem);

			    break;
			
			case 4:
            descriptografar(matriz, descriptografada, criptografada);
			
                break;
			
			case 5:
				tam = 0, tamtexto = 0;	
				mensagem[0] = '\0', chave[0] = '\0', matriz[5][5], semchave[0] = '\0', criptografada[0] = '\0', descriptografada[0] = '\0';
				
                break;
			
			default:
				return 0;
	}
	}
	return 0;
}
