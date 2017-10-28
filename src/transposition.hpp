#ifndef TRANSPOSITION_2329NF9O2N30J
#define TRANSPOSITION_2329NF9O2N30J

#include "base_decrypter.hpp"

class transposition : public base_decrypter
{
    private:
    
    unsigned factorial( unsigned n )
    {
        if(!n) return 1;
        return n*factorial(n-1);
    }
    
    void decryption_method( std::string key_word )
    {
        if ( key_word.size() <= 2 )
        {
            std::cerr << std::endl << "The key word must be at least 3 characters long" << std::endl;
            return;
        }
        // Since the size of the password is unknown, we have to try for 
        // different sizes and build columns. Once this is done, we have to
        // permutate the columns until the keyword appears.
        // We assume that the size of the password is at least three, and in
        // order to be able to find the keyword, it has to be smaller than it.
        bool found = false;
        for(size_t pwd_size = 3; pwd_size < key_word.size(); ++pwd_size );
        {
            for( unsigned permutations = 0; permutations < factorial(pwd_size); ++permutations )
            {
                for( unsigned row = 0; row < (1 + this->my_txt.size()/pwd_size); ++row )
                {
                }
            }
        }

    }
};

#endif // TRANSPOSITION_2329NF9O2N30J