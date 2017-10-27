#include <iostream>
#include <string>

#include <decrypt.hpp>
#include <vigenere_txt.hpp>


int main ( int argc, char **argv )
{
    std::string the_text = "ICXCSMPXBPIHDVHETGMEEYHXPRDRGGZJRQWZOEDPRRZONMVASKEXGT";
    std::string the_key_word = "INTERVENCION";
    std::cout << decrypt<vigenere_txt>( the_text, the_key_word ) << std::endl;
    return 0;
}