// =============================================================
// Curso Prático de Computação Científica em C++
// Gustavo Valdiviesso (2020)
// =============================================================

// =============================================================
// Uma função fatorial com controle de precisão.
//
// Fatorial: n! = 1 x 2 x 3 x ... x n
//
// Código comentado disponível em 
// https://github.com/gustavogx/cpp/Fatorial
//
// Assista a programação ao vivo em
// https://youtu.be/7Xry8R91F5E
// 
// =============================================================

#include <iostream>
#include <limits>

// Primeiro, vamos perguntar à biblioteca <limits> qual é o maior valor
// que <long double> pode armazenar. Isso será útil mais adiante.
const long double valor_max = std::numeric_limits<long double>::max();

// Em inglês, Fatorial é Factorial. É assim que vamos chamar nossa função.
long double factorial(unsigned int n){
    
    long double f = 1;
    for(unsigned int i=1; i<=n; i++ ){

        if( f < valor_max/i ){ // Testamos se a multiplicação será um overflow, antes de executá-la.
            // Se a multiplicação não for ultrapassar o limite, vamos fazê-la:
            f *= i;
        } else {
            // Senão, temos que avisar o usuário que o cálculo foi limitado pela variável.
            // Nós já sabemos que o maior valor que essa função é capaz de obter é 1754!
            // Mas não é interessante colocar a condição de erro fixa neste valor.
            // Se ou invés de usar <long double> usarmos <float> ou <double>, o limite será menor.
            // Detecção automática de limites é boa quando não sabemos quem é a próxima pessoa que
            // vai usar o seu programa.
            std::cout << "Erro! Limite de Ponto-flutuante atingido em n = " << i  << std::endl;
            return 0;
        }
    }
    return f;
}

int main(){

    unsigned int n;
    std::cout << "Entre com n para calculo de n! : ";
    std::cin >> n;

    std::cout << n <<"!= " << factorial(n) << std::endl;

    return 0;
}
