#include <iostream>
#include <string>

#include <decrypt.hpp>
#include <transposition.hpp>


int main ( int argc, char **argv )
{
    std::string the_text = "ILQRLAAOLIMSOLTOUIALCVSEIDNAIBENCOEOUNLEAOSESNSPPNIDNRNSCARGCSOCFTLPSLGSTEOIREMEESDPALEEEOSAROOEE";
    std::string the_key_word = "CDGUERA";
    std::cout << decrypt<transposition>( the_text, the_key_word ) << std::endl;
    the_key_word = "CEGUDRA";
    std::cout << decrypt<transposition>( the_text, the_key_word ) << std::endl;
    return 0;
}