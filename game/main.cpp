#include<iostream>
#include"window.h"
#include"terrain.h"
#include"raquette.h"
#include"balle.h"
#include<stdlib.h>
#include<time.h>
#include"brique.h"
#include"menu.h"
#include"option.h"
#include"score.h" // modif
#include<sstream> // modif 2
#include<fstream> 
#include"pseudo.h"
using namespace std;
void myProgram();
void GlobalRemove(Ball &b,terrain &ter,racket &r,bool &leftM, bool &rightM){
  ter.remove_Ball(b);
  remove_Racket(r,ter,leftM,rightM);
  // remove_Brick(br,ter,WCYAN);

}

void GlobalPrint(Ball &b,terrain &ter,racket &r,Brick *br,unsigned int nbrBrick, Score &s){
  printRacket(r,ter);
  if ((b.getDeplacement()==1)||(b.getDeplacement()==2)){
    ter.printInField(b.getposX(),b.getposY(),b.getChar(),WBLACK);
  }
  unsigned int nbr= 0;
  while(nbr < nbrBrick){
    printBrick(br[nbr],ter,BWHITE);
    nbr++;
  }

  //Partie Score
  string p1 = "Votre score est de : ";
  std::ostringstream n;
  n << s.getValueScore();
  string p2 = n.str();
  s.printStringInScore(0,0,p1+p2,BGREEN);
  //Partie Score

  //Partie Vie
  string p3;
  switch(ter.getLife()){
    case 0:
    p3 = "Vous avez 0 vie";
    break;
    case 1:
    p3 = "Vous avez 1 vie ";
    break;
    case 2:
    p3 = "Vous avez 2 vies ";
    break;
    case 3:
    p3 = "Vous avez 3 vies ";
    break;
  }
  s.printStringInScore(0,2,p3,WBLUE);
  //Partie Vie

  //Partie Pseudo
  string p4 = "Votre pseudo est : " + s.getPseudo();
  s.printStringInScore(0,4,p4,BGREEN);
  //Partie Pseudo

  //Partie Classement

  //Partie Classement
}

void GlobalMove(Ball &b, terrain &ter, racket &r, bool &leftM, bool &rightM){
  
  if (b.getDeplacement()==2){
    b.move_Ball();
  }
  
  if (leftM) {

    if (((r.getXRacket()-(ter.getXField()-2))<=4)){
	
	r.setPosXRacket(ter.getXField()-2);
	
      } else if((r.getXRacket()-(ter.getXField()-2))>4){
	r.setPosXRacket(r.getXRacket()-2);
      }
  } else if (rightM) {

    if ((( ((ter.getXField()-2) + ter.getWidthField()) ) - (r.getXRacket()+r.getWidthRacket())) > 4 ){
	
	r.setPosXRacket(r.getXRacket()+2);
	
      } else if((((ter.getXField()-2)+ter.getWidthField())-(r.getXRacket()+r.getWidthRacket()))<=4){
	
	r.setPosXRacket((ter.getXField() + ter.getWidthField())-(r.getWidthRacket()+3));
      }
  }
  if (b.getDeplacement()==1){
    b.setposX((r.getXRacket())+(0.5*r.getWidthRacket()));
  }
}

void GlobalCollision(Ball &b, terrain &ter, racket &r,Brick* br,unsigned int nbrBrick, Score &s){

  if (b.getDeplacement()==2){
    r.collision_Ball_racket(b);
    ter.collision_Ball_field(b,s);
    
  }

  unsigned int nbr =0 ;
  while( nbr < nbrBrick ){
    collision_Ball_Brique(b,br[nbr],s);
    nbr++;
  }
}

void initTabBrick(Brick * br,unsigned int taille ,int posXDebut,int posYDebut ,terrain &ter){
  br[0].setPosX(posXDebut);
  br[0].setPosY(posYDebut);
  srand (time(NULL));
  unsigned int i=1 ;
  unsigned int resistance_generator= rand()%10+1;
  while(i < taille){
      resistance_generator= rand()%10+1;
    if( ter.getWidthField() - (br[i-1].getWidth() +  br[i-1].getPosX()) > br[i-1].getWidth() + 1 ){
      br[i].setPosX( br[i-1].getPosX() + br[i-1].getWidth() + 3 );
      br[i].setPosY(br[i-1].getPosY());
      br[i].setResistance(resistance_generator);

      i++;
    }else{
      br[i].setPosY( br[i-1].getPosY() + br[i-1].getHeight() + 3);
      br[i].setPosX(posXDebut);
      br[i].setResistance(resistance_generator);
      i++;
    }
  }
}

void Game_Launch(string p){
  
  Window w(40,70,2,2,'_');
  Score s(40,35,74,2,' ',0,p);
  unsigned int nbrBrick = 40;
  Ball b('@',35,27,0,0,1);
  terrain  ter(w,b,3);
  Brick tab[nbrBrick];
  initTabBrick(tab,nbrBrick, 4 ,4 ,ter);
  racket r1(12,30,36,b);
  int ch ;
  bool leftMouvRacket = false;
  bool rightMouvRacket = false;

  //GlobalPrint(b,ter,r1,tab,5); 
  while((ch = getch()) != 'q'){
    
    GlobalRemove(b,ter,r1,leftMouvRacket,rightMouvRacket);
    GlobalMove(b,ter,r1,leftMouvRacket, rightMouvRacket);
    GlobalCollision(b,ter,r1,tab,nbrBrick,s);
    GlobalPrint(b,ter,r1,tab,nbrBrick,s);

    cout << "" << endl; // TEST
    
    switch (ch) {
    case '1':
      ter.setBkgdColorField(WMAGENTA);
      break;
    case '2':
      ter.setBkgdColorField(WYELLOW);
      break;
    case '3':
      ter.setBordureField('X');
      break;
    case '4' :
      ter.setBkgdColorField(WBLACK);
      break;
    case KEY_LEFT:
      if (leftMouvRacket==false){
	leftMouvRacket=true;
      } else if (leftMouvRacket==true){
	leftMouvRacket=false;
      }
      rightMouvRacket=false;
      break;
    case KEY_RIGHT:
      if (rightMouvRacket==false){
	rightMouvRacket=true;
      } else if (rightMouvRacket==true){
	rightMouvRacket=false;
      }
      leftMouvRacket=false;
      break;
    case ' ':
      if (b.getDeplacement()==1){

	b.setDeplacement(2);
	b.setVitesseX(0);
	b.setVitesseY(-1);
      }
      break;

   
    }
  }    
  
}

void Before_Launch(){
  Window PseudoEntry(20,30,50,20,' ');
  //  w.print(0,0,"Veuillez saisir un pseudonyme : ",BBLUE);
  string psdo;
  Pseudo psd(PseudoEntry,psdo);
  psd.setBkgdColorPseudo(WBLUE);
  psd.setBordColorPseudo(WBLUE);
  psd.printStringInPseudo(0,0,"Veuillez saisir un pseudonyme : ",WBLUE);
  char chokolat;
  bool saisi=false;
  while( (chokolat =getch() )!=10 && !saisi){
    while(!saisi){
      cin>>psdo;
      if(!psdo.empty()){
	saisi=true;
      }
    }
    //    sd.printStringInPseudo(4,4,psdo,WBLUE);
  }
  chokolat='0';
  while( (chokolat =getch() )!=10){
  psd.printStringInPseudo(4,4,psdo,WBLUE);
  }
  Game_Launch(psdo);
}

void Tuto_Launch(){
  
  Window tuto(30,50,COLS/2-30,LINES/2-10,' ');
  Menu Tuto(tuto);
  Tuto.setBordColorMenu(WRED);
  int ch;
  string Return[]={
    "Retour"
  };
  
  while( (ch=getch()) != 10){
    // Tuto.setBkgdColorMenu(WRED);
    Tuto.printStringInMenu(2,2,"Ceci est un Tutoriel",WBLACK);
    Tuto.printStringInMenu(5,5,Return[0],WRED);
    
  }
  tuto.setCouleurBordure(WBLACK);
  Tuto.ClearMenu();
  myProgram();
}
void Credits_Launch(){
  Window credits(30,50,COLS/2-30,LINES/2-10,' ');
  Menu Credits(credits);
  Credits.setBordColorMenu(WRED);
  int ch;
  string Return[]={
    "Retour"
  };
  
  while( (ch=getch()) != 10){
    // Tuto.setBkgdColorMenu(WRED);
    Credits.printStringInMenu(2,2,"Les magnifiques auteurs de ce jeu ne sont \n  pas diponibles pour faire d'autres jeux. \n Merci pour votre compréhension.",WBLACK);
    Credits.printStringInMenu(5,8,Return[0],WRED);
  }
  credits.setCouleurBordure(WBLACK);
  Credits.ClearMenu();
  myProgram();
}

void myProgram(){
  
  Window w(20,30,COLS/2-30,LINES/2-10,' ');
  Window Classement(25,35,w.getX()+w.getLargeur()+3,w.getY(),' ');
  Menu menu(w);
  Menu ScoreList(Classement);
  ScoreList.setBordColorMenu(WBLUE);
  menu.setBordColorMenu(WRED);
  unsigned int posY=2;
  ScoreList.printStringInMenu(1,1,"Classement des anciens joueurs :",WBLUE);
  ifstream r("leaderboard.txt");
  if(r.is_open()){
    string MyList ;
    while( getline(r,MyList) ){
      ScoreList.printStringInMenu(1,posY,MyList,WBLACK);
      posY++;
    }
  }else{
    terminate();
  }
  r.close();
  
  int ch;
  string Choix[]={
    "Lancer un nouveau Jeu",
    "Lancer une sauvegarde",
    "Turoriel",
    "CREDITS",
    "Quitter",
  };
  
  int choix =1;
  int posX2Choix = 2;
  int posY2Choix= 2;
  int indice2Choix=-1;
  Color Highlight=WRED;
  menu.printStringInMenu(posX2Choix,posY2Choix,Choix[0],WBLACK);
  menu.printStringInMenu(posX2Choix,posY2Choix+2,Choix[1],WBLACK);
  menu.printStringInMenu(posX2Choix,posY2Choix+4,Choix[2],WBLACK);
  menu.printStringInMenu(posX2Choix,posY2Choix+6,Choix[3],WBLACK);
  menu.printStringInMenu(posX2Choix,posY2Choix+8,Choix[4],WBLACK);
  
  while(choix!=0 ){
    ch = getch();
    switch (ch) {
      
    case KEY_DOWN:
      if(indice2Choix==-1){
	menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix+1],Highlight);
       	indice2Choix++;
	//	posY2Choix+=2;
      }else{
	if(indice2Choix==4){
	  menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix],WBLACK);
	  indice2Choix=0;
	  // posX2Choix=2;
	  posY2Choix=2;
	  menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix],Highlight);
	}else{
	  menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix],WBLACK);
	  indice2Choix++;
	  posY2Choix+=2;
	  choix++;
	  menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix],Highlight);
	}
      }
      //menu.printStringInMenu(2,4,Choix[1],WRED);
      break;
    case KEY_UP:
      if(indice2Choix==-1){
	menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix+1],Highlight);
       	indice2Choix++;
	//	posY2Choix+=2;
      }else{
	if(indice2Choix==0){
	  menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix],WBLACK);
	  indice2Choix=4;
	  // posX2Choix=2;
	  posY2Choix=10;
	  menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix],Highlight);
	}else{
	  menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix],WBLACK);
	  posY2Choix-=2;
	  indice2Choix--;
	  menu.printStringInMenu(posX2Choix,posY2Choix,Choix[indice2Choix],Highlight);
	  // menu.printStringInMenu(2,2,Choix[0],WRED);
	  //menu.printStringInMenu(2,4,Choix[1],WBLACK);
	}
      }
      break;
    case 10 :
      choix=0;
      break;  
    }
  }

  w.setCouleurBordure(WBLACK);
  Classement.setCouleurBordure(WBLACK);

  string p ;
 switch(indice2Choix){

 case 0 :
   menu.ClearMenu();
   ScoreList.ClearMenu();
   Before_Launch();
   // Game_Launch(p);   
   break;
 case 1:
    break;
 case 2:
   // menu.setBkgdColorMenu(WBLACK);
   //menu.setBordColorMenu(WBLACK);
   menu.ClearMenu();
   Tuto_Launch();
   break;
 case 3:
   // menu.setBkgdColorMenu(WBLACK);
   // menu.setBordColorMenu(WBLACK);
   menu.ClearMenu();
   Credits_Launch();
   break;   
 
  }
}



int main(int argc,char**argv){
  
  Option tabOp[5]={ Option(Option::HELP,Option::AUCUN,"-h","Ceci est une aide pour jouer"),
		    Option(Option::VERSION,Option::AUCUN,"-v","\033[01;31;5mVERSION 1.0\033[0m "),
		    Option(Option::AUTHORS,Option::AUCUN,"-a","NOUS SOMMES LES AUTEURS"),
		    Option(Option::NBR_BRICK,Option::ENTIER,"-nb","le nombre de brick de debut de jeu"),
		    Option(Option::CONFIG,Option::CHARACTER,"-cfg","Passer un fichier de config pour pouvoir configurer votre jeu")
  };
  /*  TabOp tabOp(4);
  tabOp.addOption(Option(Option::HELP,Option::AUCUN,"-h","Ceci est une aide pour jouer"));
  cout<<tabOp[0].getdescription()<<endl;
  tabOp.addOption(Option(Option::VERSION,Option::AUCUN,"-v","VERSION 1.0"));
  cout<<tabOp[0].getdescription()<<endl;
  cout<<tabOp[1].getdescription()<<endl;
  tabOp.addOption(Option(Option::AUTHORS,Option::AUCUN,"-a","NOUS SOMMES LES AUTEURS"));
  
  tabOp.addOption(Option(Option::NBR_BRICK,Option::ENTIER,"-nb","le nombre de brick de debut de jeu"));
  cout<<tabOp[0].getdescription()<<endl;
  cout<<tabOp[1].getdescription()<<endl;
  cout<<tabOp[0].getdescription()<<endl;

  tabOp.printTabOp();*/
  
  if(argc<2){
  startProgramX();
  myProgram();
  stopProgramX();
  }else{
    for( int i=1;i<argc;++i){
      
      for(int j=0;j<4;j++){
	
	if(argv[i][0]=='-'){
	  if(argv[i] == tabOp[j].getraccourci()){
	    switch(j){
	    case 0 :
	      cout<<"NOUS POUVONS VOUS AIDER COMME SUIT :"<<endl;
	      cout<<endl;
	      for(int k=0;k<3;k++){
		tabOp[k].print();
		cout<<endl;;
	      }
	      break;
	    case 1:
	      cout<<tabOp[j].getdescription()<<endl;
	      break;
	    case 2 :
	      cout<<"==============\033[01;31;5mAUTHORS\033[0m========="<<endl;
	      cout<<"-> \033[1;33mMohamed Masbah Abou Laich\033[0m"<<endl;
	      cout<<"-> \033[1;33mAntoine Afflatet\033[0m "<<endl;
	      cout<<"-> \033[1;33mAntoine Brahimi\033[0m"<<endl;
	      cout<<"-> \033[1;33mAyoub Benhamdi\033[0m"<<endl;
	      break;
	    case 3:
	      if(i+1<argc){
		int nb=atoi(argv[++i]);
		cout<<nb<<endl;
	      }else{
		cout<<"Erreur il faut passer un parametre"<<endl;
		tabOp[j].print();
	      }
	      break;
     	    }
	  }
	}else{
	  
	  string s = ID2String(tabOp[j].getId());
	  
	  if(argv[i] == s ){
	    //tabOp[j].print();
	      switch(j){
	      case 0 :
		cout<<"NOUS POUVONS VOUS AIDER COMME SUIT"<<endl;
		cout<<endl;
		for(int k=0;k<3;k++){
		  tabOp[k].print();
		  cout<<endl;
		}
		break;
	      case 1:
		cout<<tabOp[j].getdescription()<<endl;
		break;
	      case 2 :
		cout<<"==============AUTHORS========="<<endl;
		cout<<"-> Mohamed Masbah Abou Laich"<<endl;
		cout<<"-> Antoine Afflatet "<<endl;
		cout<<"-> Antoine Brahimi"<<endl;
		cout<<"-> Ayoub Benhamdi"<<endl;
		break;
	      case 3 :
		if(i+1<argc){
		  int nb=atoi(argv[++i]);
		  cout<<nb<<endl;
		}else{
		  cout<<"Erreur il faut passer un parametre"<<endl;
		  tabOp[j].print();
		}
		break;
	      }
	      
	  }
	  
	}
	
      } 
    }
  }

  return 0;
}
