#ifndef AFFINE_029F2NFI2NFM2
#define AFFINE_029F2NFI2NFM2

#include "base_decrypter.hpp"

class affine : public base_decrypter
{
    private:
    
    // C:= Encrypted message
    // K:= Original  message
    // C = a*K + b mod|ALPHABET_SIZE|
    // The first two characters of the keyword are compared to every pair of characters in
    // the text. Once a and b are generated for these characters, the rest of characters of
    // the keyword are checked for this values of a and b. If they match we have decrypted
    // the message.
    void decryption_method( std::string key_word )
    {
        if ( key_word.size() <= 2 )
        {
            std::cerr << std::endl << "The key word must be at least 3 characters long" << std::endl;
            return;
        }
        
        bool found = false;
        int a = 0;
        int b = 0;
        for( size_t i = 0; i < (this->my_txt.size() - key_word.size() + 1); ++i)
        {
            if( found ) break;
            
            // C1 = a*K1 + b
            // C2 = a*K2 + b
            // a * (K1 - K2) = (C1 - C2)
            // b = C1 - a*K1
            const int C1 = static_cast<int>(this->my_txt[i]);
            const int C2 = static_cast<int>(this->my_txt[i+1]);
            const int K1 = static_cast<int>(key_word[0]);
            const int K2 = static_cast<int>(key_word[1]);
            const int dC = (C1-C2) >= 0 ? (C1-C2) : (26+(C1-C2));
            const int dK = (K1-K2) >= 0 ? (K1-K2) : (26+(K1-K2));
            a = 0;
            // a * (K1 - K2) = (C1 - C2)
            while( ((dK*a)%26 != dC) && (a<26) )
            {
                ++a;
            }
            b = (C1 - a*K1);
            while ( b < 0 )
            {
                b += 26;
            }
            b %= 26;
            for ( size_t j = 2; j < key_word.size(); ++j)
            {
                const int CJ = static_cast<int>(this->my_txt[i+j] - 'A');
                const int KJ = static_cast<int>(key_word[j] - 'A');
                if ( CJ != ((a*KJ + b)%26) ) // Parameters dont match
                {
                    found = false;
                    break;
                }
                else
                {
                    found = true;
                }
            }
        }
        
        if( found )
        {
            this->my_ans.clear();
            this->my_ans.reserve(this->my_txt.size());
            
            for( size_t i = 0; i < this->my_txt.size(); ++i )
            {
                const int C = static_cast<int>(this->my_txt[i] - 'A');
                int K = 0;
                // a*K + b = C
                while ( ((a*K + b)%26) != C )
                {
                    ++K;
                }
                this->my_ans.push_back( static_cast<char>(K) + 'A');
            }
        }
    }
    
};
#endif //AFFINE_029F2NFI2NFM2