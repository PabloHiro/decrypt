#ifndef BASE_DECRYPTER_O2RJ9F2F920JION
#define BASE_DECRYPTER_O2RJ9F2F920JION

#include <iostream>
#include <string>

class base_decrypter
{
    public:
    base_decrypter() {}
    
    virtual ~base_decrypter() {}
    
    virtual void load( std::string &text )
    {
        if ( valid ( text ) )
        {
            my_txt = text;
        }
        else
        {
            std::cerr << std::endl << "Please load a valid text for this decrypter" << std::endl;
        }
    }
    
    void solve( std::string key_word )
    {
        if ( my_txt.empty() )
        {
            std::cerr << std::endl << "Please load text before decrypting" << std::endl;
            return;
        }
        
        if ( valid (key_word) )
        {
            if( this->my_txt.size() < key_word.size() )
            {
                std::cerr << std::endl << "The key word is too long for the text" << std::endl;
                return;
            }
            decryption_method( key_word );
        }
        else 
        {
            std::cerr << std::endl << "Please enter a valid keyword" << std::endl;
        }
    }
    
    std::string answer()
    {
        return my_ans;
    }
    
    
    void info()
    {
        std::cerr << my_info << std::endl;
    }
    
    protected:
    std::string my_txt;
    std::string my_ans;
    std::string my_info;
    
    private:
    
    virtual bool valid ( std::string &text )
    {
        for( size_t i = 0; i < text.size(); ++i )
        {
            if ( ( text[i] < 'A' ) || ( text [i] > 'Z' ) )
            {
                return false;
            }
        }
        return true;
    }
    
    virtual void decryption_method( std::string key_word ) = 0;
    
};


#endif //BASE_DECRYPTER_O2RJ9F2F920JION