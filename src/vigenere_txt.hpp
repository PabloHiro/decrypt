#ifndef VIGENERE_TXT_2O03FO9349
#define VIGENERE_TXT_2O03FO9349

#include "base_decrypter.hpp"

class vigenere_txt : public base_decrypter
{
    private:
    
    void decryption_method( std::string &key_word )
    {
        if( this->my_txt.size() < key_word.size() )
        {
            std::cerr << std::endl << "The key word is too long for the text" << std::endl;
            return;
        }
        
        
        this->my_ans.clear();
    }
};

#endif // VIGENERE_TXT_2O03FO9349