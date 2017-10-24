#include <iostream>
#include <string>

#include <decrypt.hpp>
#include <symbolic.hpp>


int main ( int argc, char **argv )
{
    std::string the_text = "NWREPZPNCHMIRAIRNAUHZDPQJMHJQHAQKPJQCPPQJHWBNMBXQQNQKHXJNAIJHWFRMHTPQPCJWCHTKHTPKPJXCEREPJTNAZBKNMMPADPJUPWHCPUPRADNIHOQPIUZNBHXOMPRANXJQCNMRN";
    std::string the_key_word = "INDIANBOY";
    std::cout << decrypt<symbolic>( the_text, the_key_word) << std::endl;
    return 0;
}