#include<string>
#include<sstream>

void triTab(std::string *T, std::string *T2, int tailleT){

      int k = 0;
      std::string k2;
      int x,y;

      for(int i=0; i<=tailleT-1; i++){
          for(int j=i+1; j<=tailleT-1; j++){

              std::stringstream x2(T[i]);
              std::stringstream y2(T[j]);

              x2 >> x;
              y2 >> y;

              if(x<=y){
                  k = x;
                  T[i] = T[j];

                  std::stringstream ss;
                  ss << k;
                  std::string str = ss.str();

                  T[j] = str;

                  k2 = T2[i];
                  T2[i] = T2[j];
                  T2[j] = k2;

              }
             }
          }
        }