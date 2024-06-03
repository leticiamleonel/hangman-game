#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalavraAleatoria(){
    //vetor com palavras disponíveis
    string palavras[3] = {"caju", "morango", "manga"};
    //indice gerado no intervalo 0,1,2
    int indiceAleatorio = rand() % 3;

    return palavras[indiceAleatorio];
}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){
    int cont = 0;
    string palavraComMascara;

    //coloca máscara na palavra que foi gerada aleatoriamente
    while(cont < tamanhoDaPalavra){
        palavraComMascara += "_";
        cont ++;
    }
    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasArriscadas){
    cout << "A palavra é: " << palavraComMascara << "(Tamanho: " << tamanhoDaPalavra << ")" << endl;
    cout << "Tentativas Restantes: " << tentativasRestantes << endl;

    int cont;
    //exibe as letras arriscadas
    cout << "Letras já arriscadas: " << endl;
    for(cont = 0; cont < letrasArriscadas.size(); cont ++){
        cout << letrasArriscadas[cont] << ", ";
    }


}

int jogarSozinho(){
    //palavra a ser advinhada
    string palavra = retornaPalavraAleatoria();
    //pega o tamanho da palavra | Ex: Morango = 7 letras
    int tamanhoDaPalavra = palavra.size();
    //palavra mascarada
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);

    int tentativas = 0, maximoTentativas = 10; //numero de tentativas e erros
    char letra; //letra de entrada do usuário
    int opcao;
    int cont; //auxiliar para laços de repetição
    string letrasArriscadas; //acumula as tentativas do jogador
    bool letraJaDigitada = false;

    while(palavra != palavraComMascara && maximoTentativas - tentativas > 0){
        limpaTela();
        //exibe o status atual do jogo
        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoTentativas - tentativas, letrasArriscadas);
        //palpite
        cout << "\nDigite uma letra: ";
        cin >> letra;

        //percorre as letras já arriscadas
        for(cont = 0; cont < tentativas; cont++){
            if(letrasArriscadas[cont] == letra){
                cout << "Essa letra já foi digitada!" << endl;
                letraJaDigitada = true;
            }
        }

        if(letraJaDigitada == false){
            //incrementa as letras já arriscadas
            letrasArriscadas += tolower(letra);
            //percorre a letra real
            for(cont=0; cont<tamanhoDaPalavra; cont++){
            //se a letra existir na palavra com máscara
                if (palavra[cont]== tolower(letra)){

                //faço aquela letra aparecer naquela palavra com máscara
                    palavraComMascara[cont] = palavra[cont];
                }
            }
            tentativas++;
        }
        letraJaDigitada = false;

    }
    if(palavra == palavraComMascara){
        limpaTela();
        cout << "Parabéns, Você venceu. A palavra era: " << palavra << "!"<< endl;
        cout << "Deseja reiniciar?" << endl;
        cout << "Digite: Sim = 1 ou Não = 2" << endl;
        cin >> opcao;
        return opcao;
    }else{
        limpaTela();
        cout << "Sem tentativas! Game Over!" << endl;
        cout << "Deseja reiniciar?" << endl;
        cout << "Digite: Sim = 1 ou Não = 2" << endl;
        cin >> opcao;
        return opcao;
    }


}

void menuInicial(){
    setlocale(LC_ALL, "portuguese");
    int opcao;

    while(opcao < 1 || opcao > 3){
        limpaTela();
        cout << "___________________________________" << endl;
        cout << "___ Bem-vindo ao jogo da Forca! ___" << endl;
        cout << "___________________________________" << endl;
        cout << "Escolha uma opção abaixo e aperte ENTER:" << endl;
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair" << endl;
        cin >> opcao;
        cout << endl;

        switch(opcao){
        case 1:
            cout << "__ Início do jogo __" <<endl;
            if(jogarSozinho() == 1){
                menuInicial();
            }
            break;
        case 2:
            cout << "__ Informações do jogo __" <<endl;
            limpaTela();
            cout << "Jogo desenvolvido por Letícia Leonel, em 2024.";
            cout << "\n1 - Voltar";
            cout << "\n2 - Sair" << endl;
            cin >> opcao;
            if(opcao==1){
                menuInicial();
            }
            break;
        case 3:
            cout << "__ Fim. Até logo! __" <<endl;
            break;
        }
    }
}

int main()
{
    //gerar números aleatórios a partir da biblioteca time.h
    srand((unsigned)time(NULL));
    menuInicial();
    return 0;
}
