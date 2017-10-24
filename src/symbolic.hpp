#ifndef SYMBOLIC_029F2NFI2NFM2
#define SYMBOLIC_029F2NFI2NFM2

#include "base_decrypter.hpp"

class symbolic : public base_decrypter
{
    private:
    
    // C:= Encrypted message
    // K:= Original  message
    // C = a*K + b mod|ALPHABET_SIZE|
    // The first two characters of the keyword are compared to every pair of characters in
    // the text. Once a and b are generated for these characters, the rest of characters of
    // the keyword are checked for this values of a and b. If they match we have decrypted
    // the message.
    void decryption_method( std::string &key_word )
    {
        if( this->my_txt.size() < key_word.size() )
        {
            std::cerr << std::endl << "The key word is too long for the text" << std::endl;
            return;
        }
        else if ( key_word.size() <= 2 )
        {
            std::cerr << std::endl << "The key word must be at least 3 characters long" << std::endl;
            return;
        }
        
        bool found = false;
        int a = 0;
        int b = 0;
        for( size_t i = 0; i < (this->my_txt.size() - key_word.size()); ++ i)
        {
            if( found ) 
            {
                break;
            }
            // C1 = a*K1 + b
            // C2 = a*K2 + b
            // a = (C1 - C2) / (K1 - K2)
            // b = C1 - a*K1
            const int C1 = static_cast<int>(this->my_txt[i]);
            const int C2 = static_cast<int>(this->my_txt[i+1]);
            const int K1 = static_cast<int>(key_word[0]);
            const int K2 = static_cast<int>(key_word[1]);
            const int dC = (C1-C2) >= 0 ? (C1-C2) : (25+(C1-C2));
            const int dK = (K1-K2) >= 0 ? (K1-K2) : (25+(K1-K2));
            std::cerr << "dC is " << dC <<", dK is " << dK <<std::endl;
            // if a is an integer, there may be a solution
            if ( ( dC > dK ) && !(dC%dK) )
            {
                a = dC / dK;
                b = C1 - a*K1;
                b = (b >= 0) ? b : (25+b);
                //std::cerr << "a is " << a <<", b is " << b <<std::endl;
                for ( size_t j = 2; j < key_word.size(); ++j)
                {
                    const int CJ = static_cast<int>(this->my_txt[i+j]);
                    const int KJ = static_cast<int>(key_word[j]);
                    if ( CJ != ((a*KJ + b)%26) ) // Parameters dont match
                    {
                        //std::cerr << "CJ is " << CJ <<", KJ is " << KJ <<std::endl;
                        found = false;
                        break;
                    }
                    else
                    {
                        found = true;
                    }
                }
            }
        }
        
        if( found )
        {
            this->my_ans.resize(this->my_txt.size());
            
            for( size_t i = 0; i < this->my_txt.size(); ++i )
            {
                int KI = static_cast<int>(this->my_txt[i]);
                KI -= b;
                KI = (KI >= 0) ? KI : (25+KI);
                while ( !(KI%a) ) // If not integer
                {
                    KI+=25;
                }
                KI /= a;
                this->my_ans[i] = static_cast<char>(KI);
            }
        }
    }
    
};
#endif //SYMBOLIC_029F2NFI2NFM2