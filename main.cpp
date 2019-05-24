
/**
 * Implementação de de operações com Matriz nxm manipulada através um menu de opções.
 * A matriz utilizada é alocada dinamicamente.
 */

//Declaração de bibliotecas
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * Aloca uma matriz dinamicamente.
 * 
 * @param n Número de linhas da matriz.
 * @param m Número de colunas da matriz.
 * @return A matriz de double alocadas dinamicamente.
 */
double** alocaMatriz(int n, int m) {
    //Declara a matriz
    double **matriz;
    //Aloca um vetor de n posições
    matriz = new double *[n];
    //Cada elemento do vetoré um outro vetor de m posições
    for (int i = 0; i < m; i++) {
        matriz[i] = new double[n];
    }
    return matriz;
}

/**
 * Desaloca a matriz que foi alocada dinamicamente.
 * 
 * @param n Número de linhas da matriz.
 * @param m Número de colunas da matriz.
 * @return A matriz de double alocadas dinamicamente.
 */
void desalocaMatriz(double** &M, int &n, int &m){
   //Desaloca as colunas
   for(int i = 0; i < m; i++){ 
      delete[] M[i]; 
   }
   //Desaloca a linhas
   delete[] M;
   
   //Zera a quantidade de linhas e colunas
   n = 0;
   m = 0;
   cout << "\nMatriz desalocada!" << endl;
}

/**
 * Converte um double para string segundo uma precisão.
 * @param num número a ser convertido
 * @param precisao número de casas decimais
 * @return string com o número convertido e as casas decimais.
 */
string to_string_precision(double numero, int precisao) {
    ostringstream saida;
    saida.precision(precisao);
    saida << fixed << numero;    
    return saida.str();
}

/**
 * Cria uma cópia da Matriz.
 *
 * @param M Matriz com os dados a serem copiados.
 * @param linhas Quantidade de linhas da matriz.
 * @param colunas Quantidade colunas da matriz.
 * @return Uma matriz com uma cópia dos dados da matriz de M para C.
 */
double** criarCopia(double** M, int linhas, int colunas) {
    double** C = alocaMatriz(linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            C[i][j] = M[i][j];
        }
    }
    return C;
}

/**
 * Gera uma string formatada com os dados Matriz M.
 *
 * @param M Matriz com os dados a serem exibidos.
 * @param linhas Quantidade de linhas da matriz.
 * @param colunas Quantidade colunas da matriz.
 * @return Uma String formatada com os dados da matriz.
 */
string imprimirMatriz(double** M, int linhas, int colunas) {
    if (linhas != 0 || colunas != 0) {
        string saida = "";
        for (int j = 0; j < colunas; j++) {
            saida = saida + "\t" + to_string(j);
        }
        saida = "n/m" + saida + "\n";
        for (int i = 0; i < linhas; i++) {
            string dados = "";
            for (int j = 0; j < colunas; j++) {
                dados = dados + "\t" + to_string_precision(M[i][j], 1);
            }
            saida = saida + to_string(i) + dados + "\n";
        }
        return saida;
    } else {
        return "Matriz vazia!";
    }
}

/**
 * Carrega uma Matriz padrão de 3x3 com valores.
 *
 */
void carregarMatrizPadrao3x3(double** &M, int &n, int &m) {
    //Desaloca a matriz anterior
    desalocaMatriz(M,n,m);
    cout << "\ndesalocando3:" << M << " n="<< n << " m="<< m <<endl;
    
    //Número de linhas da Matriz.
    n = 3;
    //Número de colunas da Matriz.
    m = 3;
    //Declara uma matriz a com valores.
    double **a = alocaMatriz(n, m);
    
    //Inicializa os valores da matriz a
    a[0][0] = 2;
    a[0][1] = -1;
    a[0][2] = 3;
    a[1][0] = 5;
    a[1][1] = 2;
    a[1][2] = 1;
    a[2][0] = 3;
    a[2][1] = 1;
    a[2][2] = 4;
    //Deteterminante 28.
    
    //Atribui a matriz "a" para A.
    M = a;
    cout << "\nMatriz A(3x3) carregada!" << endl;
}

/**
 * Realiza a leitura dos dados da Matriz A.
 */
void leituraMatriz(double** &M, int &n, int &m) {
    //Desaloca a matriz anterior
    desalocaMatriz(M,n,m);
    
    //Preenche a quantidade linhas da matriz.
    cout << "\nDigite a quantidade de linhas da matriz(n):";
    cin >> n;
    //Preenche a quantidade colunas da matriz.
    cout << "\nDigite a quantidade de colunas da matriz(m):";
    cin >> m;
    //Instância a matriz com o novo tamanho.
    M = alocaMatriz(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "\nDigite o valor A[" << i << "," << j << "]:";
            cin >> M[i][j];
        }
    }
}

/**
 * Recupera os dados da Diagonal Principal.
 *
 * @param M Matriz com os dados a serem exibidos.
 * @param linhas Quantidade de linhas da matriz.
 * @param colunas Quantidade colunas da matriz.
 * @return Uma String com os dados da diagonal principal.
 */
string mostraDiagonalPrincipal(double** M, int linhas, int colunas) {
    string saida = "";
    //Somente para Matriz quadrada
    if (linhas == colunas) {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (i == j) {
                    saida = saida + "A[" + to_string(i) + "][" + to_string(j) + "] = " + to_string_precision(M[i][j],1) + " ";
                }
            }
        }
    } else {
        saida = "Matriz não é quadrada!";
    }
    return saida;
}

/**
 * Recupera os dados da Diagonal Secundária.
 *
 * @param M Matriz com os dados a serem exibidos.
 * @param linhas Quantidade de linhas da matriz.
 * @param colunas Quantidade colunas da matriz.
 * @return Uma String com os dados da diagonal secundária.
 */
string mostraDiagonalSecundaria(double** M, int linhas, int colunas) {
    string saida = "";
    //Somente para Matriz quadrada
    if (linhas == colunas) {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (i + j == linhas - 1) {
                    saida = saida + "A[" + to_string(i) + "][" + to_string(j) + "] = " + to_string_precision(M[i][j],1) + " ";
                }
            }
        }
    } else {
        saida = "Matriz não é quadrada!";
    }
    return saida;
}

/**
 * Recupera os dados do Triângulo Superior.
 *
 * @param M Matriz com os dados a serem verificados.
 * @param linhas Quantidade de linhas da matriz.
 * @param colunas Quantidade colunas da matriz.
 * @return Uma String com os dados da matriz acima da diagonal principal.
 */
string mostraTrianguloSuperiorPrincipal(double** M, int linhas, int colunas) {
    string saida = "";
    //Somente para Matriz quadrada.
    if (linhas == colunas) {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (i < j) {
                    saida = saida + "A[" + to_string(i) + "][" + to_string(j) + "] = " + to_string_precision(M[i][j],1) + " ";
                }
            }
        }
    } else {
        saida = "Matriz não é quadrada!";
    }
    return saida;
}

/**
 * Recupera os dados do Triângulo Inferior.
 *
 * @param M Matriz com os dados a serem verificados.
 * @param linhas Quantidade de linhas da matriz.
 * @param colunas Quantidade colunas da matriz.
 * @return Uma String com os dados da matriz abaixo da diagonal principal.
 */
string mostraTrianguloInferiorPrincipal(double** M, int linhas, int colunas) {
    string saida = "";
    //Somente para Matriz quadrada
    if (linhas == colunas) {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (i > j) {
                    saida = saida + "A[" + to_string(i) + "][" + to_string(j) + "] = " + to_string_precision(M[i][j],1) + " ";
                }
            }
        }
    } else {
        saida = "Matriz não é quadrada!";
    }
    return saida;
}

/**
 * Recupera os dados do Triângulo Inferior.
 *
 * @param M Matriz com os dados a serem verificados.
 * @param linhas Quantidade de linhas da matriz.
 * @param colunas Quantidade colunas da matriz.
 * @return Uma String com os dados da matriz abaixo da diagonal secundária.
 */
string mostraTrianguloInfeior(double** M, int linhas, int colunas) {
    string saida = "";
    //Somente para Matriz quadrada.
    if (linhas == colunas) {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (i > j) {
                    saida = saida + "A[" + to_string(i) + "][" + to_string(j) + "] = " + to_string_precision(M[i][j],1) + " ";
                }
            }
        }
    } else {
        saida = "Matriz não é quadrada!";
    }
    return saida;
}

/**
 * Recupera os dado do maior elemento da matriz.
 *
 * @param M Matriz com os dados a serem verificados.
 * @param linhas Quantidade de linhas da matriz.
 * @param colunas Quantidade colunas da matriz.
 * @return Uma String com o dado do maior elemento da matriz.
 */
string mostraMaiorElemento(double** M, int linhas, int colunas) {
    int linhaMaior = 0;
    int colunaMaior = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (M[i][j] > M[linhaMaior][colunaMaior]) {
                linhaMaior = i;
                colunaMaior = j;
            }
        }
    }
    string saida = "A[" + to_string(linhaMaior) + "][" + to_string(colunaMaior) + "] = " + to_string_precision(M[linhaMaior][colunaMaior],1);
    return saida;
}

/**
 * Retorna a Matriz Transposta.
 *
 * Matriz Mnxm gera Tmxn.
 *
 * @param M Matriz com os dados a serem gerados a transposta.
 * @param linhas Quantidade de linhas da matriz.
 * @param colunas Quantidade colunas da matriz.
 * @return Uma String com os dados da Matriz Transposta.
 */
double** transposta(double** M, int linhas, int colunas) {
    //Matriz para armazenar a transposta
    double** T = alocaMatriz(colunas, linhas);
    //Gera a transposta
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            T[j][i] = M[i][j];
        }
    }
    return T;
}

/**
 * Verificar se uma dada matriz quadrada é quadrado mágico
 *
 * A soma das linhas, soma das colunas e diagonais tem de ser igual.
 *
 * @param M Matriz com os dados a serem verificados.
 * @param linhas Quantidade de linhas da matriz.
 * @param colunas Quantidade colunas da matriz.
 * @return Verdadeiro ou falso se a matriz forma um quadrado mágico.
 */
bool eQuadradoMagico(double** M, int linhas, int colunas) {
    //Quadrado mágico somente para matriz quadrada.
    if (linhas == colunas) {
        double soma = (linhas * linhas * linhas + linhas) / 2;
        double somaLinha = 0;
        double somaColuna = 0;
        double somaDiagonalPrincipal = 0;
        double somaDiagonalSecundaria = 0;

        //Percorre as linhas.
        for (int i = 0; i < linhas; i++) {
            // diagonal principal i=j
            somaDiagonalPrincipal = somaDiagonalPrincipal + M[i][i];
            // diagonal secundária i + j == n - 1
            somaDiagonalSecundaria = somaDiagonalSecundaria + M[i][linhas - 1 - i];
            somaLinha = 0;
            somaColuna = 0;
            //Percorre as colunas
            for (int j = 0; j < linhas; j++) {
                // soma linha i
                somaLinha = somaLinha + M[i][j];
                // soma coluna i
                somaColuna = somaColuna + M[j][i];
            }
            if ((somaLinha != soma) || (somaColuna != soma)) {
                return false;
            }
        }
        if ((somaDiagonalPrincipal != soma) || (somaDiagonalSecundaria != soma)) {
            return false;
        } else {
            return true;
        }
    } else {
        cout << "Matriz não é quadrada." << endl;
        return false;
    }
}

/**
 * Retorna a matriz rotacionada 90 graus.
 *
 * @param M Matriz com os dados a serem rotacionados.
 * @param linhas Quantidade de linhas da matriz.
 * @param colunas Quantidade colunas da matriz.
 * @return A matriz rotacao gerada pela rotação de 90 graus da matriz.
 */
double** rotacao90(double** M, int linhas, int colunas) {
    //Somente para matriz quadrada
    if (linhas == colunas) {
        //Meio da matriz
        int meio = linhas / 2;
        //Copia a matriz A para matriz rotacao realizar a rotação
        double** rotacao = criarCopia(M, linhas, colunas);
        for (int i = 0; i < meio; i++) {
            for (int j = i; j < colunas - 1 - i; j++) {
                double temp = rotacao[linhas - 1 - j][i];
                // linha ; varia coluna
                rotacao[linhas - 1 - j][i] = rotacao[linhas - 1 - i][linhas - 1 - j];
                // linha n-1-i; varia coluna
                rotacao[linhas - 1 - i][linhas - 1 - j] = rotacao[j][linhas - 1 - i];
                // coluna n-1-i; varia linha
                rotacao[j][linhas - 1 - i] = rotacao[i][j];
                // linha i; varia coluna
                rotacao[i][j] = temp;
            }
        }
        return rotacao;
    } else {
        cout << "A matriz não é quadrada." << endl;
        return M;
    }
}

/**
 * Retorna uma matriz multiplicada por um valor.
 *
 * @param M Matriz com os dados a serem rotacionados.
 * @param linhas Quantidade de linhas da matriz.
 * @param colunas Quantidade colunas da matriz.
 * @param valor Valor a ser multiplicado por cada elemento da matriz.
 * @return A matriz rotacao gerada pela rotação de 90 graus da matriz.
 */
double** multiplicar(double** M, int linhas, int colunas, double valor) {
    //Copia a matriz para matriz produto da multiplicação
    double** produto = criarCopia(M, linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            produto[i][j] = M[i][j] * valor;
        }
    }
    return produto;
}

/**
 * Retorna o determinante da Matriz.
 *
 * @param M Matriz com os dados a serem gerados a transposta.
 * @param linhas Quantidade de linhas da matriz.
 * @param colunas Quantidade colunas da matriz.
 * @return O valor do determinante da matriz.
 */
double determinante(double** M, int linhas, int colunas) {
    //Determinante somente para matriz quadrada
    if (linhas == colunas) {
        //Cria uma cópia da matriz A para calcular o determinante em D
        double** D = criarCopia(M, linhas, colunas);
        //Armazena o valor do determinante 
        double det = 1.0;
        //Matriz com 1 linha e coluna
        if (linhas == 1) {
            det = D[0][0];
        } else {
            //Matriz com 2 linhas e colunas
            if (linhas == 2) {
                det = (D[0][0] * D[1][1]) - (D[1][0] * D[0][1]);
            } else {
                //Matriz com 3 ou mais linhas e colunas
                //fator de ajuste do sinal
                double p = 1;
                // faz a transformação em um triângulo.
                //Percorre todas as linhas
                for (int i = 0; i < linhas - 1; i++) {
                    if (D[i][i] == 0) {
                        for (int k = i; k < colunas; k++) {
                            //Somente para valores diferentes de 0
                            if (D[k][i] != 0) {
                                //Troca a linha j e k
                                for (int j = 0; j < colunas; j++) {
                                    double temp = D[i][j];
                                    D[i][j] = D[k][j];
                                    D[k][j] = temp;
                                }
                                p = p * (-1);
                                //Interrompe o laço
                                k = colunas;
                            }
                        }
                    }
                    //A é uma matriz singular
                    if (D[i][i] == 0) {
                        det = 0;
                    } else {
                        for (int k = i + 1; k < colunas; k++) {
                            double fator = -1.0 * D[k][i] / D[i][i];
                            for (int j = i; j < colunas; j++) {
                                D[k][j] = D[k][j] + (fator * D[i][j]);
                            }
                        }
                    }
                }
                if (det != 0) {
                    det = 1.0;
                    // Calcula o determinante
                    for (int i = 0; i < linhas; i++) {
                        det = det * D[i][i];
                    }
                }
            }
        }
        return det;
    } else {
        return 0;
    }
}

/**
 * Programa principal.
 *
 * @param argc
 * @param argv
 */
int main(int argc, char** argv) {

    //Número de linhas da Matriz.
    int n = 0;
    //Número de colunas da Matriz.
    int m = 0;

    //Matriz M de n por m.
    double** A = alocaMatriz(n, m);

    //Armazena opção lida
    int opcao = -1;

    //Laço do menu de opções
    while (opcao != 99) {
        //Realiza a leitura da opção
        cout << "\n\t### Menu de Opções - Matriz nxm ###\n"
                << " 1- Impressão da Matriz\n"
                << " 2- Carregamento da Matriz (3x3)\n"
                << " 3- Leitura de uma Matriz(nxm)\n"
                << " 4- Mostra a Diagonal Principal\n"
                << " 5- Mostra a Diagonal Secundária\n"
                << " 6- Mostra o Triângulo Superior Principal\n"
                << " 7- Mostra o Triângulo Inferior Principal\n"
                << " 8- Mostra o Maior Elemento\n"
                << " 9- Mostra a transposta\n"
                << "10- É quadrado mágico\n"
                << "11- Rotação 90 graus\n"
                << "12- Multiplicação\n"
                << "13- Determinante\n"

                //Outras opções vão aqui                    

                << "99- Sair\n"
                << "Digite a opção desejada:";
        cin >> opcao;
        //Verifica a opção
        switch (opcao) {
            case 1:
            {
                //Recupera os dados da matriz
                cout << "\nMatriz:" << "\n" << imprimirMatriz(A, n, m);
                break;
            }
            case 2:
            {
                carregarMatrizPadrao3x3(A,n,m);
                break;
            }
            case 3:
            {
                leituraMatriz(A,n,m);
                break;
            }
            case 4:
            {
                //Recupera os dados da diagonal principal da matriz
                cout << "\nDiagonal Principal:" << "\n" << mostraDiagonalPrincipal(A, n, m) << endl;
                break;
            }
            case 5:
            {
                //Recupera os dados da diagonal secundária da matriz
                cout << "\nDiagonal Secundária:\n" << mostraDiagonalSecundaria(A, n, m) << endl;
                break;
            }
            case 6:
            {
                //Recupera os dados da diagonal secundária da matriz
                cout << "\nTriângulo Superior Principal:\n" << mostraTrianguloSuperiorPrincipal(A, n, m) << endl;
                break;
            }
            case 7:
            {
                //Recupera os dados da diagonal secundária da matriz
                cout << "\nTriângulo Inferior Principal:\n" << mostraTrianguloInferiorPrincipal(A, n, m) << endl;
                break;
            }
            case 8:
            {
                //Recupera os dados da diagonal secundária da matriz
                cout << "\nMaior elemento da Matriz:\n" << mostraMaiorElemento(A, n, m) << endl;
                break;
            }
            case 9:
            {
                //Recupera os dados da matriz
                double** t = transposta(A, n, m);
                cout << "\nMatriz Transposta:\n" << imprimirMatriz(t, m, n) << endl;
                break;
            }
            case 10:
            {
                //Verifica se a matriz é um quadrado mágico
                if (eQuadradoMagico(A, n, m) == true) {
                    cout << "\nA Matriz forma um Quadrado Mágico." << endl;
                } else {
                    cout << "\nA Matriz não forma um Quadrado Mágico." << endl;
                }
                break;
            }
            case 11:
            {
                //Recupera os dados da matriz
                double** rotacao = rotacao90(A, n, m);
                cout << "\nMatriz Rotacionada 90 graus:\n" << imprimirMatriz(rotacao, m, n) << endl;
                break;
            }
            case 12:
            {
                //Realiza a leitura do valor a ser multiplicado
                cout << "\nDigite um valor para multiplicar pela matriz:";
                double valor;
                cin >> valor;
                //Recupera os dados da matriz                    
                double** produto = multiplicar(A, n, m, valor);
                cout << "\nMatriz multipicada por" << valor << " :\n" << imprimirMatriz(produto, m, n) << endl;
                break;
            }
            case 13:
            {
                //Recupera os dados da matriz
                cout << "\nDeterminante:\n" << determinante(A, n, m) << endl;
                break;
            }

            //Outras opções vão aqui

            //Opção de saída do programa
            case 99:
            {
                cout << "Saindo do programa!";
                break;
            }
            //Opção inválida do menu
            default:
            {
                cout << "Opção inválida!";
                break;
            }
        }//Fim switch
    }//Fim while
    return 0;
}//Fim main