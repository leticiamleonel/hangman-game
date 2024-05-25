#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalavraAleatoria(){
    //vetor com palavras dispon�veis
    string palavras[3] = {"Ma�a", "Morango", "Manga"};
    //indice gerado no intervalo 0,1,2
    int indiceAleatorio = rand() % 3;

    return palavras[indiceAleatorio];
}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){
    int cont = 0;
    string palavraComMascara;

    //coloca m�scara na palavra que foi gerada aleatoriamente
    while(cont < tamanhoDaPalavra){
        palavraComMascara += "_";
        cont ++;
    }
    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes ){
    cout << "A palavra �: " << palavraComMascara << "(Tamanho: " << tamanhoDaPalavra << ")" << endl;
    cout << "Tentativas Restantes: " << tentativasRestantes << endl;

}

void jogarSozinho(){
    //palavra a ser advinhada
    string palavra = retornaPalavraAleatoria();
    //pega o tamanho da palavra | Ex: Morango = 7 letras
    int tamanhoDaPalavra = palavra.size();
    //palavra mascarada
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);

    int tentativas = 0, maximoTentativas = 10; //numero de tentativas e erros
    char letra; //letra de entrada do usu�rio
    int cont; //auxiliar para la�os de repeti��o

    while(maximoTentativas - tentativas >0){
        limpaTela();
        //exibe o status atual do jogo
        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoTentativas - tentativas);
        //palpite
        cout << "Digite uma letra: ";
        cin >> letra;
        tentativas++;
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
        cout << "Escolha uma op��o abaixo e aperte ENTER:" << endl;
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair" << endl;
        cin >> opcao;
        cout << endl;

        switch(opcao){
        case 1:
            cout << "__ In�cio do jogo __" <<endl;
            jogarSozinho();
            break;
        case 2:
            cout << "__ Informa��es do jogo __" <<endl;
            break;
        case 3:
            cout << "__ Fim. At� logo! __" <<endl;
            break;
        }
    }
}

int main()
{
    //gerar n�meros aleat�rios a partir da biblioteca time.h
    srand((unsigned)time(NULL));
    menuInicial();
    return 0;
}
