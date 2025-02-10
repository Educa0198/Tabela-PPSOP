#include <iostream>
#include <string>

using namespace std;

class jogador {
    string nome;
    int pontos;

public:
    jogador() {
        setnome("Sem_Nome");
        setpontos(0);
   
    }

    jogador(string nome1, int pontos1) {
        setnome(nome1);
        setpontos(pontos1);
    
    }

    void setnome(string nome1) {
        nome = nome1;
    }

    void setpontos(int pontos1) {
        pontos = pontos1;
    }

   

    string getnome() {
        return nome;
    }

    int getpontos() {
        return pontos;
    }

};

class tabela {
    jogador** player;
    int numjogadores;
public:
    tabela(int numjogadores1) {
        numjogadores = numjogadores1;
        int posicao[numjogadores];
        player = new jogador*[numjogadores];  // Alocação dinâmica do array de jogadores
        for (int i = 0; i < numjogadores; i++) {
            player[i] = new jogador();  // Criando jogadores padrão
        }
    }

   

    ~tabela() {  
        // Destrutor para liberar a memória alocada dinamicamente
        for (int i = 0; i < numjogadores; i++) {
            delete player[i];
        }
        delete[] player;
    }

    void setnumjogadores(int numjogadores1) {
        numjogadores = numjogadores1;
    }

    int getnumjogadores() {
        return numjogadores;
    }


    void adicionarJogador(string nome, int pontos, int posicao) {
        // Criar um novo array com tamanho maior
        jogador** novoArray = new jogador*[numjogadores + 1];

        // Copiar os jogadores existentes
        for (int i = 0; i < numjogadores; i++) {
            novoArray[i] = player[i];
        }

        // Criar e adicionar o novo jogador na última posição
        novoArray[numjogadores] = new jogador(nome, pontos, posicao);

        // Liberar o array antigo
        delete[] player;

        // Atualizar o ponteiro e o número de jogadores
        player = novoArray;
        numjogadores++;
    }

    void exibe() {
        cout << "Lista de jogadores:\n";
        for (int i = 0; i < numjogadores; i++) {
            cout << "Nome: " << player[i]->getnome()
                 << " | Pontos: " << player[i]->getpontos()
                 << endl;
    }
};

int main() {
    tabela t(3);  // Criando uma tabela com 3 jogadores
    t.exibe();  // Exibindo os jogadores
    return 0;
}


