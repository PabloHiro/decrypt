#include <iostream>
#include <string>

#include <decrypt.hpp>
#include <caesar.hpp>


int main ( int argc, char **argv )
{
    std::string the_text = "CQNBCXAHXOJCNJVXOJOARLJWJVNARLJWFXVNWVJCQNVJCRLRJWBFQXBNAENMJERCJUAXUNRWWJBJMDARWPCQNNJAUHHNJABXOCQNBYJLNYAXPAJV";
    std::string the_key_word = "STORY";
    std::cout << decrypt<caesar>( the_text, the_key_word) << std::endl;
    return 0;
}