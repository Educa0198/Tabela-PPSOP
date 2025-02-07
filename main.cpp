#include <iostream>
#include <string>


using namespace std;

class jogador
{

    string nome;
    int pontos;
    int posicao;

    public:

    jogador()
    {
        setnome("Sem_Nome");
        setpontos(0);
        setposicao(0);

    }
    jogador(string nome1, int pontos1, int posicao1)
    {
        setnome(nome1);
        setpontos(pontos1);
        setposicao(posicao1);
    }

    void setnome(string nome1)
    {
        nome = nome1;
    }

    void setpontos( int pontos1)
    {
        pontos = pontos1;
    }

    void setposicao(int posicao1)
    {
        posicao = posicao1;
    }

    string getnome()
    {
        return nome;
    }

    int getpontos()
    {
        return pontos;
    }

    int getposicao()
    {
        return posicao; 
    }
};

class tabela
{
    jogador** player;
    int numjogadores;

    public:
    
    void setnumjogadores( int numjogadores1)
    {
        numjogadores = numjogadores1;
    }

};


int main()
{

}