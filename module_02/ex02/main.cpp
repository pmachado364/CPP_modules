#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl; // printa 0
    std::cout << ++a << std::endl;
    /* o objecto a passa a ser 1
    o operador << chama o toFloat() e faz 1 / 256 */

    std::cout << a << std::endl; // printa 0.00390625 (1/256)
    std::cout << a++ << std::endl;
    // printa 0.00390625 (1/256)
    // o operador ++ faz uma copia de a (raw = 1) e depois incrementa a (raw = 2)

    std::cout << a << std::endl; // printa 0.0078125 (2/256)
    std::cout << b << std::endl;
    /* 10.1016 (5.05 * 2 ao serem iniciados tornam se 1292 e 512 respetivamente.
    O operador * converte os dois para float e multiplica
    retornando um Fixed com o valor de roundf(10.10156 * 256) ≈ 2586)
    ao imprimir b chama se o toFloat() que faz 2586 / 256 = 10.1016 */
    
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}