#ifndef VIGENERE_TXT_20NEOFI2NOFIN
#define VIGENERE_TXT_20NEOFI2NOFIN

#include "base_decrypter.hpp"

class vigenere_txt : public base_decrypter
{
    private:
    
    void decryption_method( std::string key_word )
    {
        // We don't know the size of the initial password, so we have to try for
        // every size. We assume that this size is at least 2 and smaller than the
        // keyword.
        // We have to find a text, that given a password size, would have the keyword
        // in it. This can be verified because the keyword will be encrypting itslef
        // as long as it is bigger than the password used, this is a property of the
        // text-autokey vigenere version.
        if ( key_word.size() <= 2 )
        {
            std::cerr << std::endl << "The key word must be at least 3 characters long" << std::endl;
            return;
        }
        bool found = false;
        size_t index = 0;
        size_t pwd_size = 0;
        for( pwd_size = 2; pwd_size < key_word.size(); ++pwd_size )
        {
            if(found) break;
            
            for( size_t i = pwd_size; i < (this->my_txt.size() - key_word.size() + 1); ++i )
            {
                if(found) break;
                for( size_t j = 0; j < (key_word.size() - pwd_size); ++j )
                {
                    const int txt = static_cast<int>(this->my_txt[i+j] - 'A');
                    const int pwd = static_cast<int>(key_word[j] - 'A'); // The keyword works as the password
                    const int key = static_cast<int>(key_word[pwd_size+j] - 'A');
                    if( key == ( (txt-pwd >= 0)? (txt-pwd) : (26+txt-pwd) ) )
                    {
                        found = true;
                        index = i;
                    }
                    else
                    {
                        found = false;
                        break;
                    }
                }
            }
        }
        --pwd_size; //Fix size
        
        if(found)
        {
            this->my_ans.clear();
            this->my_ans.resize(this->my_txt.size());
            // We decrypt from the keyword
            // First we place the first part of the keyword in the text to enable our algorithm
            for ( size_t i = 0; i < pwd_size; ++i )
            {
                this->my_ans[index - pwd_size + i] = key_word[i];
            }
            // Forwards
            for ( size_t i = index; i < this->my_txt.size(); ++i )
            {
                const int txt = static_cast<int>(this->my_txt[i] - 'A');
                const int pwd = static_cast<int>(this->my_ans[i-pwd_size] - 'A');
                this->my_ans[i] = static_cast<char>( ((txt-pwd >= 0)? (txt-pwd) : (26+txt-pwd)) + 'A');
            }
            // Backwards
            for ( size_t i = index-1; i >= pwd_size; --i )
            {
                const int txt = static_cast<int>(this->my_txt[i] - 'A');
                const int pwd = static_cast<int>(this->my_ans[i] - 'A');
                this->my_ans[i-pwd_size] = static_cast<char>( ((txt-pwd >= 0)? (txt-pwd) : (26+txt-pwd)) + 'A');
            }

            this->my_info.clear();
            this->my_info = "Password is: ";
            for ( size_t i = 0; i < pwd_size; ++i )
            {
                const int txt = static_cast<int>(this->my_txt[i] - 'A');
                const int ans = static_cast<int>(this->my_ans[i] - 'A');
                this->my_info+=static_cast<char>( ((txt-ans >= 0)? (txt-ans) : (26+txt-ans)) + 'A');
            }
        }
    }
};

#endif // VIGENERE_TXT_20NEOFI2NOFIN
