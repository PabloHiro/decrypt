#include <iostream>
#include <string>
#include <algorithm>

#include <decrypt.hpp>
#include <transposition.hpp>


int main ( int argc, char **argv )
{
    std::string the_text = "GEEIOLLSATAESDDLLAMAILANIOELNSACENARREUSPTUAAEOAPVONICSDEELUNSCSIDUSISNDOEDAMERAODJARNMDIDCDTAEELSMREN";
    std::string the_key_word = "MEDICAMENTOS";
    std::string password;
    bool found = false;
    for( size_t pwd_size = 3; pwd_size < the_key_word.size(); ++pwd_size )
    {
        if(found) break;
        password.clear();
        std::cout << "Trying with password size " << pwd_size << std::endl;
        for( size_t i = 0; i < pwd_size; ++i )
        {
            password.push_back('A' + i);
        }
        do {
            std::string answer = decrypt<transposition>( the_text, password );
            if ( answer.find( the_key_word ) != std::string::npos )
            {
                std::cout << answer << std::endl;
                std::cout << password << std::endl;
                found = true;
                break;
            }
        } while( std::next_permutation(password.begin(), password.end()) );
    }
    return 0;
}