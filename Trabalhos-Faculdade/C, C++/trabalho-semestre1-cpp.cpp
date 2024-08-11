#include <iostream>
using namespace std;

int main()
{
    bool eleicao = false;
    
    string nomes[100];
    int idades[100];
    int identificadores[100];
    int numeros[100];
    
    int total_eleitores=0;
    int total_candidatos=0;
    
    do{
        int opcao;
        
        cout<<"Escolha uma opção\n\n(1)Adicionar eleitor\n(2)Adicionar candidato\n(3)Iniciar eleição\n\n";
        cin>>opcao;
        switch(opcao){
            case(1):
                {
                string nome;
                int idade;
                int identificador;
                
                cout<<"Adicione o nome do eleitor\n";
                cin>>nome;
                cout<<"Adicione a idade do eleitor\n";
                cin>>idade;
                cout<<"Adicione o identificador do eleitor\n";
                cin>>identificador;
                
                for(int i=0; i<=99; i++){
                    if(identificadores[i]==identificador || identificador<0 || identificador>=100000){
                        cout<<"Erro ao incluir eleitor.\nReiniciando o cadastro\n\n";
                        break;
                    }
                }
                
                nomes[total_eleitores] = nome;
                idades[total_eleitores] = idade;
                identificadores[total_eleitores] = identificador;
                
                total_eleitores++;
                break;
            }
            case(2):
            {
                string nome;
                int idade;
                int identificador;
                int numero;
                
                cout<<"Adicione o nome do candidato\n";
                cin>>nome;
                cout<<"Adicione a idade do candidato\n";
                cin>>idade;
                cout<<"Adicione o identificador do candidato\n";
                cin>>identificador;
                cout<<"Adicione o numero do candidato\n";
                cin>>numero;
                
                for(int i=0; i<=99; i++){
                    if(identificadores[i]==identificador || identificador<0 || identificador>=100000){
                        cout<<"Erro ao incluir candidato.\nReiniciando o cadastro\n\n";
                        break;
                    }
                    
                    if(numeros[i]==numero || numero<0 || numero>=100000){
                        cout<<"Erro ao incluir candidato.\nReiniciando o cadastro\n\n";
                        break;
                    }
                }
                
                nomes[total_eleitores] = nome;
                idades[total_eleitores] = idade;
                identificadores[total_eleitores] = identificador;
                numeros[total_candidatos] = numero;
                
                total_eleitores++;
                total_candidatos++;
                break;
            }
            
            case(3):
                {
                eleicao=true;
            break;
            }
            
            default:
            {
            cout<<"Opção inválida"<<endl;
            break;
            }
            
        }
    }while(eleicao==false);
    
    int nums[total_candidatos];
    int votos[total_candidatos];
    
    for(int i=0; i<=total_candidatos-1; i++){
        nums[i] = numeros[i];
    }
    
    int contador1=total_eleitores;
    int contador2=0;
    do{
        int voto;
        
        cout<<"\nEm quem deseja votar, "<<nomes[contador2]<<"?"<<endl;
        cin>>voto;
        for(int i=0; i<=total_candidatos-1; i++){
            if(voto==nums[i]){
                cout<<"Candidato encontrado.\nVoto válido.\n\n";
                votos[i]++;
                contador1--;
                contador2++;
                break;
                
            }else if(i==-1){
                cout<<"Candidato não encontrado.\nTente novamente\n\n";
                break;
            }
        }
        
    }while(contador1!=0);
    
    int eleito;
    int total_votos=0;
        for(int i=0; i<=total_candidatos-1; i++){
            if(total_votos<votos[i]){
                total_votos=votos[i];
                eleito=nums[i];
            }
        }
    cout<<"O número do candidato eleito foi "<<eleito<<" com "<<total_votos<<endl;
    
}
