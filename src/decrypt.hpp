#ifndef DECRYPT_029JFO92JNF23
#define DECRYPT_029JFO92JNF23

#include "base_decrypter.hpp"

template <typename D>
std::string decrypt( std::string &the_text, std::string &key_word )
{
    D my_decrypter;
    my_decrypter.load(the_text);
    my_decrypter.solve(key_word);
    my_decrypter.info();
    return my_decrypter.answer();
}

#endif // DECRYPT_029JFO92JNF23