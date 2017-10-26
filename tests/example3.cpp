#include <iostream>
#include <string>

#include <decrypt.hpp>
#include <portabellaso.hpp>


int main ( int argc, char **argv )
{
    std::string the_text = "SYLIPANPIJUWWIJZWPVCHCHJRKPWXZGXYWZUIUMCHE";
    std::string the_key_word = "CONFLICTO";
    std::cout << decrypt<portabellaso>( the_text, the_key_word ) << std::endl;
    return 0;
}