#include <iostream>
#include <string>

#include <decrypt.hpp>
#include <affine.hpp>


int main ( int argc, char **argv )
{
    std::string the_text = "NWREPZPNCHMIRAIRNAUHZDPQJMHJQHAQKPJQCPPQJHWBNMBXQQNQKHXJNAIJHWFRMHTPQPCJWCHTKHTPKPJXCEREPJTNAZBKNMMPADPJUPWHCPUPRADNIHOQPIUZNBHXOMPRANXJQCNMRN";
    std::string the_key_word = "KILOMETERS";
    std::cout << decrypt<affine>( the_text, the_key_word ) << std::endl;
    return 0;
}