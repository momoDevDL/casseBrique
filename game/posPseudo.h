#include"score.h"
#include<string>

int posPseudo(std::string *T, int tailleT, Score &s){

    int x=0;
    for(int i=0; i<=tailleT-1; i++){
        if(s.getPseudo()==T[i])
            x=i;
    }

    return x;
}