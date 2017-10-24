#ifndef CAESAR_29R0FNO2FN02JFN
#define CAESAR_29R0FNO2FN02JFN

#include "base_decrypter.hpp"

class caesar : public base_decrypter
{
    private:
    
    void decryption_method( std::string &key_word )
    {
        if( this->my_txt.size() < key_word.size() )
        {
            std::cerr << std::endl << "The key word is too long for the text" << std::endl;
            return;
        }
        
        for ( int c = 0; c < static_cast<int>('Z' - 'A'); ++c )
        {
            this->my_ans = this->my_txt;
            
            for( size_t i = 0; i < this->my_txt.size(); ++i )
            {
                int curr = static_cast<int> (this->my_ans[i]);
                curr += c;
                curr %= 26;
                this->my_ans[i] = 'A' + static_cast<char>(curr);
            }
            
            if ( this->my_ans.find ( key_word ) != std::string::npos )
            {
                return;
            }
        }
        
        this->my_ans.clear();
    }
};

#endif // CAESAR_29R0FNO2FN02JFN