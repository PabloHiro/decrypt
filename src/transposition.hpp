#ifndef TRANSPOSITION_2329NF9O2N30J
#define TRANSPOSITION_2329NF9O2N30J

#include <list>

#include "base_decrypter.hpp"

class transposition : public base_decrypter
{
    private:

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
        size_t pwd_size;
        size_t index;
        //std::vector<int> col_order(key_word.size(), -1); // -1 means not determined
        
        for( pwd_size = 3; pwd_size < key_word.size(); ++pwd_size )
        {
            if(found) break;
            
            // We scan the text for the keyword 
            const size_t row_num = (1 + this->my_txt.size()/pwd_size);
            std::list<char> prev_check;
            std::list<char> curr_check;
            for( size_t i = 0; i < pwd_size; ++i ) //Rows
            {
                if(found) break;
                for( size_t j = 0; j < row_num; ++j ) //Columns
                {
                    index = i + j*pwd_size;
                    if ( index >= this->my_txt.size() ) continue;

                    check.push_back( this->my_txt[index] );
                    
                    if( check.size() > key_word.size() )
                    {
                        check.pop_front();
                    }

                    for ( auto &ch : check ) // Check if there is a letter not contained in the keyword
                    {
                        if ( std::find(check.begin(), check.end(), key_word[k]) != check.end() )
                        {
                            std::cerr << "Found " << key_word[k] << std::endl;
                            found = true;
                        }
                        else
                        {
                            found = false;
                            break;
                        }
                    }
                }
            }
        }
        // Fix
        --pwd_size;
        
        if(found)
        {
            std::cerr <<"Pwd size " << pwd_size << std::endl;
            std::cerr <<"Index " << index << std::endl;
            this->my_ans.clear();
            this->my_ans.resize(this->my_txt.size());
        }

    }
};

#endif // TRANSPOSITION_2329NF9O2N30J