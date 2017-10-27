#ifndef PORTABELLASO_0I32HF9O2NIONO1NJO
#define PORTABELLASO_0I32HF9O2NIONO1NJO

#include <vector>

#include "base_decrypter.hpp"

class portabellaso : public base_decrypter
{
    private:
    
    //ABCDEFGHIJKLM
    //NOPQRSTUVWXYZ
    const int M = static_cast<int>('M' - 'A'); //12
        // AB 0 - 13
        // CD 12 - 25
        // EF 11 - 24
        // GH 10 - 23
        // IJ 9 - 22
        // KL 8 - 21
        // MN 7 - 20
        // OP 6 - 19
        // QR 5 - 18
        // ST 4 - 17
        // UV 3 - 16
        // WX 2- 15
        // YZ 1 - 14
    char substitution (const int c, const int dist)
    {
        if ( c > M )
        {
            return static_cast<char>( (c + 13 - dist)%13+ 'A');
        }
        else // c <= M
        {
            return static_cast<char>( 13 + (c + 13 + dist)%13 + 'A');
        }
    }
    
    void decryption_method( std::string &key_word )
    {
        //Given a keyword, we must find where in the text its placed. This can be achieved by classifying
        //the letters in the text in to the first half or the last half of the alphabet. Once this is done,
        //the place where the opposite of this classification matches with the keyword will allow us to find
        //the password used to encrypt the text.
        std::vector<bool> txt_classifier;
        txt_classifier.reserve( this->my_txt.size() );
        for( size_t i = 0; i < this->my_txt.size(); ++i )
        {
            const int c = static_cast<int>(this->my_txt[i] - 'A');
            txt_classifier.push_back( ((c > M) ? true : false) );
        }
        std::vector<bool> key_classifier;
        key_classifier.reserve( key_word.size() );
        for( size_t i = 0; i < key_word.size(); ++i )
        {
            const int c = static_cast<int>(key_word[i] - 'A');
            key_classifier.push_back( ((c > M) ? false : true) );
        }
        bool found = false;
        size_t index;
        for( index = 0; index < (this->my_txt.size()-key_word.size()); ++index )
        {
            if (found)
            {
                break;
            }
            for ( size_t j = 0; j < key_word.size(); ++j )
            {
                if( txt_classifier[index+j]==key_classifier[j] )
                {
                    found = true;
                }
                else
                {
                    found = false;
                    break;
                }
            }
        }
        
        --index; //Fix index
        
        if( found )
        {
            this->my_ans.clear();
            this->my_ans.resize(this->my_txt.size());
            // First we find the password used to encrypt the text
            std::vector<int> password;
            for( size_t i = 0; i < key_word.size(); ++i )
            {
                const int txt = static_cast<int>(this->my_txt[index+i] - 'A');
                const int key = static_cast<int>(key_word[i] - 'A');
                const int distance = ( (txt-key) > 0 ? (txt-key) : (key-txt) );
                password.push_back(distance%13);
                //std::cerr << static_cast<char>(password[i]+'A') << ' ' << password[i] << ' ' << this->my_txt[index+i] << '-' << key_word[i] << std::endl;
            }
            
            // The keyword may be longer than the password, so we adjust the password because currently is bigger than it really is
            // We assume that the password is at least 2 characters long and these 2 characters are not repeated twice in the password
            for( size_t i = 2; i < (password.size() - 2); ++i )
            {
                if ( (password[0] == password[i]) && (password[1] ==password[i+1]) )
                {
                    password.resize(i);
                    break;
                }
            }

            // We decrypt from the keyword
            // Forwards
            for ( size_t i = index; i < this->my_txt.size(); ++i )
            {
                const int txt = static_cast<int>(this->my_txt[i] - 'A');
                this->my_ans[i] = substitution(txt, password[(i-index)%password.size()]);
            }
            // Backwards
            for ( size_t i = index; i > 0; --i )
            {
                const int txt = static_cast<int>(this->my_txt[i] - 'A');
                this->my_ans[i] = substitution(txt, password[password.size()-(index-i)%password.size()]);
            }
            const int txt = static_cast<int>(this->my_txt[0] - 'A');
            this->my_ans[0] = substitution(txt, password[password.size()-(index)%password.size()]);
        }
    }
};

#endif // PORTABELLASO_0I32HF9O2NIONO1NJO