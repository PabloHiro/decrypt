#include<iostream>
#include<string>

#include<decrypt.hpp>
#include<transposition.hpp>


int main(int argc,char**argv)
{
    std::string the_clear_7 = "ENIGMAZTIENEZALGUNAZDEBILIDADZCRIPTOGRAFICAZPEROZFUERONZCOMBINACIONESZDEZOTROSZFACTORESZLOSZQUEZPERMITIERONZAZLOSZALIADOSZDESCIFRARZTANTOSZMENSAJESZEND";
    std::string the_text_7 =  "CZSQPAOYSYLGIZDBGMMQXULWIDFQQNTQOSLICZMRCWFNJJXSPVIHDADSKEBJONPYETCIVUXLBCTWREAIPHCUQIYNELPTUFWNJMSHITDLRMYULCGCNUPDLQFFIUAYEMWOCCEIFFZDZKBOYHMLLKGGZLW";
    std::string the_clear_8;
    std::string the_text_8 = "USYPNIOZSKFGVZWIMKIYAFEJFTJIGKKNYDRXXQNRQLDEKAPGXYXXAXZRZPZYXKVWNEPNNRYLICNNGCMOJFIEQMNYYAEOLMGAUZVBRMALIHXCDNZRETXOQCJPNUZRXXCOFIEIUSJ";
    for( size_t i = 0; i < the_text_8.size(); ++i )
    {
        const int a = static_cast<int>( the_text_7[i] - the_text_8[i] );
        const int b = static_cast<int>( the_clear_7[i] - 'A' );
        const char c = static_cast<char>( ((a+b)>=0)?((a+b)%26):(a+b+26) ) + 'A';
        the_clear_8.push_back( c );
    }
    std::cout << the_clear_8 << std::endl;
    return 0;
}