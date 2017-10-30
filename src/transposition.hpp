#ifndef TRANSPOSITION_2329NF9O2N30J
#define TRANSPOSITION_2329NF9O2N30J

#include <vector>

#include "base_decrypter.hpp"

class transposition : public base_decrypter
{
    private:
    
    size_t get_pos( const std::vector<unsigned> &col_order , unsigned col )
    {
        for ( size_t i = 0; i < col_order.size(); ++i )
        {
            if( col_order[i] == col )
            {
                return i;
            }
        }
        return col_order.size(); // Not found
    }

    void decryption_method( std::string password )
    {
        // In this case the input is the password of the text, not a keyword contained in the text
        // We assume that the password doesnt have repeated letters
        // First, we find the order of the columns
        std::vector<unsigned> col_order;
        for( size_t i = 0; i < password.size(); ++i )
        {
            unsigned place = 0;
            for ( size_t j = 0; j < password.size(); ++j )
            {
                if ( password[i] > password[j] )
                {
                    place++;
                }
            }
            col_order.push_back ( place );
        }
        
        // Now we divide the text in n substrings, where n is the size of the text divided by the size of the password
        std::vector<std::string> columns;
        size_t column_size = 1 + (this->my_txt.size()/password.size());
        //Number of columns larger than the rest. These will be the first columns once the text is ordered
        unsigned larg_col = this->my_txt.size()%password.size();
        size_t total_size = 0;
        for( size_t i = 0; i < password.size(); ++i )
        {
            size_t curr_size;
            if( get_pos( col_order, i ) >= larg_col ) //This column will be shorter
            {
                curr_size = column_size - 1;
            }
            else
            {
                curr_size = column_size;
            }
            
            std::string sub_text( (this->my_txt.begin() + total_size) , (this->my_txt.begin() + total_size + curr_size) );
            columns.push_back(sub_text);
            total_size += curr_size;
        }
        
        // Once we have all the columns stored, we have to print them in the correct order
        this->my_ans.clear();
        this->my_ans.resize(this->my_txt.size());
        for( size_t i = 0; i < password.size(); ++i )
        {
            for( size_t j = 0; j < password.size(); ++j )
            {
                if( col_order[i] == j )
                {
                    for( size_t k = 0; k < columns[j].size(); ++k )
                    {
                        this->my_ans[k*password.size()+i] = columns[j][k];
                    }
                    break;
                }
            }
        }
    }
};

#endif // TRANSPOSITION_2329NF9O2N30J