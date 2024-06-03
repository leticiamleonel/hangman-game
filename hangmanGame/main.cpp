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
    string palavras[3] = {"caju", "morango", "manga"};
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

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasArriscadas){
    cout << "A palavra �: " << palavraComMascara << "(Tamanho: " << tamanhoDaPalavra << ")" << endl;
    cout << "Tentativas Restantes: " << tentativasRestantes << endl;

    int cont;
    //exibe as letras arriscadas
    cout << "Letras j� arriscadas: " << endl;
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
    char letra; //letra de entrada do usu�rio
    int opcao;
    int cont; //auxiliar para la�os de repeti��o
    string letrasArriscadas; //acumula as tentativas do jogador
    bool letraJaDigitada = false;

    while(palavra != palavraComMascara && maximoTentativas - tentativas > 0){
        limpaTela();
        //exibe o status atual do jogo
        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoTentativas - tentativas, letrasArriscadas);
        //palpite
        cout << "\nDigite uma letra: ";
        cin >> letra;

        //percorre as letras j� arriscadas
        for(cont = 0; cont < tentativas; cont++){
            if(letrasArriscadas[cont] == letra){
                cout << "Essa letra j� foi digitada!" << endl;
                letraJaDigitada = true;
            }
        }

        if(letraJaDigitada == false){
            //incrementa as letras j� arriscadas
            letrasArriscadas += tolower(letra);
            //percorre a letra real
            for(cont=0; cont<tamanhoDaPalavra; cont++){
            //se a letra existir na palavra com m�scara
                if (palavra[cont]== tolower(letra)){

                //fa�o aquela letra aparecer naquela palavra com m�scara
                    palavraComMascara[cont] = palavra[cont];
                }
            }
            tentativas++;
        }
        letraJaDigitada = false;

    }
    if(palavra == palavraComMascara){
        limpaTela();
        cout << "Parab�ns, Voc� venceu. A palavra era: " << palavra << "!"<< endl;
        cout << "Deseja reiniciar?" << endl;
        cout << "Digite: Sim = 1 ou N�o = 2" << endl;
        cin >> opcao;
        return opcao;
    }else{
        limpaTela();
        cout << "Sem tentativas! Game Over!" << endl;
        cout << "Deseja reiniciar?" << endl;
        cout << "Digite: Sim = 1 ou N�o = 2" << endl;
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
        cout << "Escolha uma op��o abaixo e aperte ENTER:" << endl;
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair" << endl;
        cin >> opcao;
        cout << endl;

        switch(opcao){
        case 1:
            cout << "__ In�cio do jogo __" <<endl;
            if(jogarSozinho() == 1){
                menuInicial();
            }
            break;
        case 2:
            cout << "__ Informa��es do jogo __" <<endl;
            limpaTela();
            cout << "Jogo desenvolvido por Let�cia Leonel, em 2024.";
            cout << "\n1 - Voltar";
            cout << "\n2 - Sair" << endl;
            cin >> opcao;
            if(opcao==1){
                menuInicial();
            }
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
