#include <iostream>

using namespace std;
//
// # - empty
//
// White:
// K1 - King - Pawel
// Q1 - Queen - Maja
// R1 - Rook - Zosia
// B1 - Bishop - Marta
// N1 - Knight - Filip
// P1 - Pawn - Karol
//
// Black:
// K2 - King
// Q2 - Queen
// R2 - Rook
// B2 - Bishop
// N2 - Knight
// P2 - Pawn


int main(){
	int x,y;
	string tab[8][8];
	for (y=0;y<8;y++){
		for(x=0;x<8;x++){
			tab[y][x] = "##";
			}
		}

//chessboard setup
	y = 0;
	tab [y][0] = "R2";
	tab [y][1] = "N2";
	tab [y][2] = "B2";
	tab [y][3] = "Q2";
	tab [y][4] = "K2";
	tab [y][5] = "B2";
	tab [y][6] = "N2";
	tab [y][7] = "R2";
	y = 1;	
	for (x=0; x<8; x++){
		tab[y][x]="P2";
	}
	for (y=2; y<6; y++){
		for (x=0; x<8; x++){
		tab[y][x] = "##";
		}
	}
	
	y = 6;
	for (x=0; x<8; x++){
        	tab[y][x]="P1";
        }

	y=7;
		tab [y][0] = "R1";
        tab [y][1] = "N1";
        tab [y][2] = "B1";
        tab [y][3] = "Q1";
        tab [y][4] = "K1";
        tab [y][5] = "B1";
        tab [y][6] = "N1";
        tab [y][7] = "R1";


//faktyczna gra
for(int i=0; i<10000; i++){

	//pokazywanie szachownicy

	for (y=0;y<8;y++){
		for(x=0;x<8;x++){
			cout << tab[y][x] << "  ";
			}
			cout << "\n";
		}
	cout << endl;
	
	//PONIZEJ BEDZIE WASZ KOD W ODPOWIEDNIM IFIE
	if(i%2==0){

	//ruch
	cout << "Ruch " << i << endl;
	cout << "GRACZ 1:" << endl;
	cout << "podaj pole z ktorego chcesz sie ruszyc: " << endl;
	cout << "x:  ";
	cin >> x;
	cout << "y:  ";
	cin >> y;

	// pytanie do waszych funkcji !!!
	int a,b;
	cout << "podaj gdzie chcesz sie ruszyc: " << endl;
	cout << "x:  ";
	cin >> a;
	cout << "y:  ";
	cin >> b;

	// figura porusza sie z pola tab[y][x] do tab[b][a]

		if (tab[y][x]=="P1"){ //gracz1 (biale)

			//ruch do przodu
			if(x == a){
				if(b == (y-1)){ //ruch o1 pole
					if(tab[b][a] == "##"){
						tab[y][x] = "##";
						tab[b][a] = "P1";
					}else{
						cout << "wrong input" << endl;
						i--;
					}
				} else if(b == (y-2)){ // ruch o 2 pola
					if((y == 6)&&(tab[5][x] == "##")){
						tab[y][x] = "##";
						tab[b][a] = "P1";
					} else {
						cout << "wrong input" << endl;
						i--;
					}
				} else {
					cout << "wrong input" << endl;
					i--;
				}
			}

			// zbijanie
			if((x==a+1)or(x==a-1)){
				if(b==y-1){
					if(tab[b][a] != "##"){
						if((tab[b][a] != "P1") && (tab[b][a] != "N1") && (tab[b][a] != "R1") && (tab[b][a] != "B1") && (tab[b][a] != "Q1") && (tab[b][a] != "K1") ){
							tab[y][x] = "##";
							tab[b][a] = "P1";
						}
					} else{
						cout << "wrong input" << endl;
						i--;
					}
				} else {
					cout << "wrong input" << endl;
					i--;
				}
			}

			if ((x != a)&&(x != a+1)&&(x != a-1)){
				cout << "wrong input" << endl;
				i--;
			}

			//promocja piona
			if(b==0){
				char promocja;
				cout << "wpisz na jaka figure chcesz wypromowac piona:" << endl;
				cout << "Hetman(Krolowa) - [Q]; \t Wieza - [R]; \t Goniec - [B]; \t Skoczek(Kon) - [N] \n";
				cin >> promocja;
				if(promocja == 'Q'){
					tab[b][a] = "Q2";
				} else if(promocja == 'R'){
					tab[b][a] = "R2";
				} else if(promocja == 'B'){
					tab[b][a] = "B2";
				} else if(promocja == 'N'){
					tab[b][a] = "N2";
				} else {
					cout << "wrong input" << endl;
					i--;
				}

			}


		} else if (tab[y][x] == "R1"){
			if(x == a){ 
				//ruch w dół białej wieży
				if (y<b){
					for (int i = 1; i<8; i++){ 
						 if (tab[y+i][a] == "N1" || tab[y+i][a] == "P1" || tab[y+i][a] == "B1" || tab[y+i][a] == "Q1" || tab[y+i][a] == "K1"){
							
							tab[y][x] = "##";
							tab[y+i-1][a] = "R1";
							break;
						}else if (y+i == b && tab[b][a] == "##"){
							tab[b][a] = "R1";
							tab[y][x] = "##";
							break;
						}else if (tab[y+i][a] != "##" && (tab[y+i][a] != "N1" || tab[y+i][a] != "P1" || tab[y+i][a] != "B1" || tab[y+i][a] != "Q1" || tab[y+i][a] != "K1")){
							tab[y+i][a] = "R1";
							tab[y][x] = "##";
							break;
						}
					}
				}
		
				// ruch w górę białej wieży
				if (y>b){
					for (int i = 1; i<8; i++){
						if (tab[y-i][a] == "N1" || tab[y-i][a] == "P1" || tab[y-i][a] == "B1" || tab[y-i][a] == "Q1" || tab[y-i][a] == "K1"){
							tab[y][x] = "##";
							tab[y-i+1][a] = "R1";
							break; 
						}else if(y-i == b && tab[b][a] == "##"){
							tab[b][a] = "R1";
							tab[y][x] = "##";
							break;
						}else if (tab[y-i][a] != "##"  && (tab[y-i][a] != "N1" || tab[y-i][a] != "P1" || tab[y-i][a] != "B1" || tab[y-i][a] != "Q1" || tab[y-i][a] != "K1")){
							tab[y-i][a] = tab[y][x];
							tab[y][x] = "##";
							break;
						}
					}
				}
			}else if (y == b){
				// ruch w prawo białej wieży
				if (x<a){
					for (int i = 1; i<8; i++){
						 if (tab[b][x+i] == "N1" || tab[b][x+i] == "P1" || tab[b][x+i] == "B1" || tab[b][x+i] == "Q1" || tab[b][x+i] == "K1"){
							
							tab[y][x] = "##";
							tab[b][x+i-1] = "R1";
							break;
						}else if(x+i == a && tab[b][a] == "##"){
							tab[b][a] = "R1";
							tab[y][x] = "##";
							break;
						}else if (tab[b][x+i] != "##" && (tab[b][x+i] != "N1" || tab[b][x+i] != "P1" || tab[b][x+i] != "B1" || tab[b][x+i] != "Q1" || tab[b][x+i] != "K1")){
							tab[b][x+i] = "R1";
							tab[y][x] = "##";
							break;
						}	
					}
				}
				// ruch w lewo białej wieży
				if (x>a){
					for (int i = 1; i<8; i++){
						if (tab[b][x-i] == "N1" || tab[b][x-i] == "P1" || tab[b][x-i] == "B1" || tab[b][x-i] == "Q1" || tab[b][x-i] == "K1"){
							
							tab[y][x] = "##";
							tab[b][x-i+1] = "R1";
							break;
						}else if(x-i == a && tab[b][a] == "##"){
							tab[b][a] = "R1";
							tab[y][x] = "##";
							break;
						}else if (tab[b][x-i] != "##" && (tab[b][x-i] == "N1" || tab[b][x-i] == "P1" || tab[b][x-i] == "B1" || tab[b][x-i] == "Q1" || tab[b][x-i] == "K1")){
							tab[b][x-i] = "R1";
							tab[y][x] = "##";
							break;
						}	
					}
				}
			}else {
				cout << "wrong input" << endl;
				i--;
			}
		 }else if (tab[y][x] == "N1"){
		
			bool isValidMove = false; 
			bool isWhite = false;

			//ustalanie czy kon bialy czy czarny

			if(tab[y][x]=="N1") 
			{
				isWhite=true;
			}
			else if(tab[y][x]=="N2") 
			{
				isWhite =false;
			}
			else{
				cout<<"Brak pionka";
			}
			
			
			//1 sposob ruszania sie koniem: 2 up/down 1 left/right //2 sposob ruszania sie koniem : 1 up/down 2 left/right
			if(((a==x-1 || a==x+1) && (a>=0 & a<8))&&((b==y+2 || b==y-2) && (b<8 && b>=0))
			||((a==x-2 || a==x+2) && (a>=0 & a<8))&&((b==y+1 || b==y-1) && (b<8 && b>=0))) 
			{
				
				if(isWhite== true)
				{
					if(tab[b][a]=="N1"|| tab[b][a]=="K1"|| tab[b][a]=="Q1"|| tab[b][a]=="R1"|| tab[b][a]=="B1"|| tab[b][a]=="P1") 
					{
						cout<<"Nie mozesz zbic swoich pionkow "<<endl;
						isValidMove = false;
						
					}
					else{
						tab[b][a]=tab[y][x];
						tab[y][x]="##";
						isValidMove = true;
					}
				}
				else{
					if(tab[b][a]=="N2"|| tab[b][a]=="K2"|| tab[b][a]=="Q2"|| tab[b][a]=="R2"|| tab[b][a]=="B2"|| tab[b][a]=="P2") 
					{
						cout<<"Nie mozesz zbic swoich pionkow"<<endl;
						isValidMove = false;
					}
					else{	
						tab[b][a]=tab[y][x];
						tab[y][x]="##";
						isValidMove = true;
					}
				}
			}
			else{
				isValidMove = false;
				cout<<"Nie mozna sie ruszyc na ta pozycje"<<endl;
			}
			if(isValidMove == false){
				i--;
			}

		} else if (tab[y][x] == "B1"){
            if (x < a && y < b)
				{
					for (int i = 1; i < 8; i++)
					{
						if (y + i == b && x + i == a && tab[b][a] == "##")
						{
							tab[b][a] = "B1";
							tab[y][x] = "##";
							break;
						}
						else if (tab[y + 1][x + 1] != "##")
						{
							if ((tab[b][a] != "P1") && (tab[b][a] != "N1") && (tab[b][a] != "R1") && (tab[b][a] != "B1") && (tab[b][a] != "Q1") && (tab[b][a] != "K1"))
							{
								tab[y][x] = "##";
								tab[b][a] = "B1";
							}
						}
					}
				}
				if (x > a && y < b)
				{
					for (int i = 1; i < 8; i++)
					{
						if (y + i == b && x - i == a && tab[b][a] == "##")
						{
							tab[b][a] = "B1";
							tab[y][x] = "##";
							break;
						}
						else if (tab[y + 1][x - 1] != "##")
						{
							if ((tab[b][a] != "P1") && (tab[b][a] != "N1") && (tab[b][a] != "R1") && (tab[b][a] != "B1") && (tab[b][a] != "Q1") && (tab[b][a] != "K1"))
							{
								tab[y][x] = "##";
								tab[b][a] = "B1";
							}
						}
					}
				}

				// ruch w lewo białego gońca

				if (x < a && y > b)
				{
					for (int i = 1; i < 8; i++)
					{
						if ((y - i == b) && (x + i == a) && (tab[b][a] == "##"))
						{
							tab[b][a] = "B1";
							tab[y][x] = "##";
							break;
						}
						else if (tab[y - 1][x + 1] != "##")
						{
							if ((tab[b][a] != "P1") && (tab[b][a] != "N1") && (tab[b][a] != "R1") && (tab[b][a] != "B1") && (tab[b][a] != "Q1") && (tab[b][a] != "K1"))
							{
								tab[y][x] = "##";
								tab[b][a] = "B1";
							}
						}
					}
				}
				if (x > a && y > b)
				{
					for (int i = 1; i < 8; i++)
					{
						if ((y - i == b) && (x - i == a) && (tab[b][a] == "##"))
						{
							tab[b][a] = "B1";
							tab[y][x] = "##";
							break;
						}
						else if (tab[y - 1][x - 1] != "##")
						{
							if ((tab[b][a] != "P1") && (tab[b][a] != "N1") && (tab[b][a] != "R1") && (tab[b][a] != "B1") && (tab[b][a] != "Q1") && (tab[b][a] != "K1"))
							{
								tab[y][x] = "##";
								tab[b][a] = "B1";
							}
						}
					}
				}
				else
				{
					cout << "wrong input" << endl;
					i--;
                }

		} else if (tab[y][x] == "K1"){
				 if((a == x && b ==(y-1) || a == x && b == (y+1)) && a>=0 && a<8 && b>=0 && b<8){                 //ruch na y: pierwszy warunek na ruch do gory a drugi na ruch do dulu
                                if(tab[b][a] == "##"){
                                    tab[y][x] = "##";
                                    tab[b][a] = "K1";
                                }else if(tab[b][a] == "Q1" || tab[b][a] == "R1" || tab[b][a] == "B1"            //warunek na neibicie wlasnych figur
                                         || tab[b][a] == "N1" || tab[b][a] == "P1" ){
                                             cout<<"Nie mozesz bic wlasnych figur!!";
                                         }
                                 else{
                                    tab[y][x] = "##";                                                           //bicie figut przeciwnika
                                    tab[b][a] = "K1";
                                 }
                }
                else if((a == (x+1) && b == y || a == (x-1) && b == y) && a>=0 && a<8 && b>=0 && b<8){          //ruch na x: pierwszy warunek na ruch w prawo a drugi w lewo
                            if(tab[b][a] == "##"){
                                tab[y][x] = "##";
                                tab[b][a] = "K1";
                            }else if(tab[b][a] == "Q1" || tab[b][a] == "R1" || tab[b][a] == "B1"
                                         || tab[b][a] == "N1" || tab[b][a] == "P1" ){
                                             cout<<"Nie mozesz bic wlasnych figur!!";
                                         }
                                 else{
                                    tab[y][x] = "##";
                                    tab[b][a] = "K1";
                                 }
                }
                else if((a == (x+1) && b == (y-1) || a == (x+1) && b == (y+1))&& a>=0 && a<8 && b>=0 && b<8){          //ruch na przekatnych: pierwszy warunek na ruch w prawo-gora a drugi w prawo-dol
                            if(tab[b][a] == "##"){
                                tab[y][x] = "##";
                                tab[b][a] = "K1";
                            }else if(tab[b][a] == "Q1" || tab[b][a] == "R1" || tab[b][a] == "B1"
                                         || tab[b][a] == "N1" || tab[b][a] == "P1" ){
                                             cout<<"Nie mozesz bic wlasnych figur!!";
                                         }
                                 else{
                                    tab[y][x] = "##";
                                    tab[b][a] = "K1";
                                 }
                }
                else if((a == (x-1) && b == (y-1) || a == (x-1) && b == (y+1))&& a>=0 && a<8 && b>=0 && b<8){          //ruch na przekatnych: pierwszy warunek na ruch w lewo-gora a drugi w lewo-dol
                            if(tab[b][a] == "##"){
                                tab[y][x] = "##";
                                tab[b][a] = "K1";
                            }else if(tab[b][a] == "Q1" || tab[b][a] == "R1" || tab[b][a] == "B1"
                                         || tab[b][a] == "N1" || tab[b][a] == "P1" ){
                                             cout<<"Nie mozesz bic wlasnych figur!!";
                                         }
                                 else{
                                    tab[y][x] = "##";
                                    tab[b][a] = "K1";
                                 }
                }
                else {
                    cout<<"wrong input"<<endl;
                    i--;
                }
		} else if (tab[y][x] == "Q1"){
			if(a > 8 || b > 8){
                cout << "wrong input" << endl;
                i--;
        }

        else{
            //moving in a straight line

            if ((x == a) && (y < b)){

                for (int count = 0; (y + count) <= b; count++){
                    
                    if (tab[y + count][a] != "##"){
                            
                            if (((y + count) != b) && (count != 0)){
                            cout << "wrong input" << endl;
                            count = b + 1;
                            break;
                        }

                        else if (count == 0){
                                continue;
                        }

                        else{ //hit&run

                            //checking if the chess piece belongs to the opposite player

                            if(tab[b][a] == "P2" || tab[b][a] == "B2" || tab[b][a] == "R2" || tab[b][a] == "N2" || tab[b][a] == "Q2" || tab[b][a] == "K2"){
                                tab[b][a] = "Q1";
                                tab[y][x] = "##";
                            }

                            else{
                                cout << "wrong input" << endl;
                                count = b + 1;
                                break;
                            }
                        }
                    }
                    else{

                        if ((y + count) == b){
                            tab[y][x] = "##";
                            tab[b][a] = "Q1";
                        }
                        else{
                            continue;
                        }
                    }

                }
            }

            if ((x == a) && (y > b)){

                for (int count = 0; (y - count) >= b; count++){

                    if (tab[y - count][a] != "##"){

                        if (((y - count) != b) && (count != 0)){
                            cout << "wrong input" << endl;
                            break;
                        }
                        else if(count == 0){
                                continue;
                        }
                        else{ //hit&run

                            //checking if the chess piece belongs to the opposite player

                            if(tab[b][a] == "P2" || tab[b][a] == "B2" || tab[b][a] == "R2" || tab[b][a] == "N2" || tab[b][a] == "Q2" || tab[b][a] == "K2"){
                                tab[b][a] = "Q1";
                                tab[y][x] = "##";
                            }

                            else{
                                cout << "wrong input" << endl;
                                break;
                            }
                        }
                    }

                    else{

                        if ((y - count) == b){
                            tab[y][x] = "##";
                            tab[b][a] = "Q1";
                        }

                        else{
                            continue;
                        }
                    }

                }
            }

            if ((y == b) && (x < a)){

                for (int count = 0; (x + count) <= a; count++){

                    if (tab[b][x + count] != "##"){

                        if(((x + count) != a) && (count != 0)){
                            cout << "wrong input" << endl;
                            break;
                        }

                        else if (count == 0){
                                continue;
                        }

                        else{ //hit&run

                        //checking if the chess piece belongs to the opposite player

                            if(tab[b][a] == "P2" || tab[b][a] == "B2" || tab[b][a] == "R2" || tab[b][a] == "N2" || tab[b][a] == "Q2" || tab[b][a] == "K2"){
                                tab[b][a] = "Q1";
                                tab[y][x] = "##";

                            }

                            else{
                                cout << "wrong input" << endl;
                                break;
                            }
                        }

                    }

                    else{

                        if ((x + count) == a){
                            tab[y][x] = "##";
                            tab[b][a] = "Q1";
                        }

                        else{
                            continue;

                }

            }
      }
    }

            if ((y == b) && (x > a)){

                for (int count = 0; (x - count) >= a; count++){

                    if (tab[b][x - count] != "##"){

                        if (((x - count) != a) && (count != 0)){
                            cout << "wrong input" << endl;
                            break;
                        }
                        else if (count == 0){
                                continue;
                        }
                        else{ //hit&run

                            //checking if the chess piece belongs to the opposite player

                            if(tab[b][a] == "P2" || tab[b][a] == "B2" || tab[b][a] == "R2" || tab[b][a] == "N2" || tab[b][a] == "Q2" || tab[b][a] == "K2"){
                                tab[b][a] = "Q1";
                                tab[y][x] = "##";

                            }

                            else{
                                cout << "wrong input" << endl;
                                break;
                            }

                        }
                    }

                    else{

                        if ((x - count) == a){
                            tab[y][x] = "##";
                            tab[b][a] = "Q1";
                        }

                        else{
                            continue;
                        }
                    }

                }
            }

            //moving diagonally

            if ((y < b) && (x < a)){

                    for (int count = 1; y + count <= b; count++){

                        if((y == b - count) && (x == a - count)){

                            for (int number = 1; y + number <= b; number++ ){

                                if ((y + number != b) && (x + number != a) && (tab[y + number][x + number] != "##")){
                                    cout << "wrong input" << endl;
                                    break;
                                }

                                else if ((y + number == b) && (x + number == a)){

                                    if (tab[b][a] == "P2" || tab[b][a] == "R2" || tab[b][a] == "N2" || tab[b][a] == "B2" || tab[b][a] == "Q2" || tab[b][a] == "K2" || tab[b][a] == "##"){
                                        tab[y][x] = "##";
                                        tab[b][a] = "Q1";
                                    }
                                    else{
                                        cout << "wrong input" << endl;
                                        break;
                                    }
                                }

                                else{
                                    continue;
                                }
                            }
                        }
                        else if ((y + count == b) && (x + count != a)){
                           cout << "wrong input" << endl;
                           break;
                        }
                        else{
                           continue;
                        }
                     }
            }
            if ((y < b) && (x > a)){

                    for (int count = 1; y + count <= b; count++){

                        if ((y == b - count) && (x == a + count)){

                            for (int number = 1; y + number <= b; number++){

                                if ((y + number != b) && (x - number != a) && (tab[y + number][x - number] != "##")){
                                    cout << "wrong input" << endl;
                                    break;
                                }

                                else if ((y + number == b) && (x - number == a)){

                                    if (tab[b][a] == "P2" || tab[b][a] == "R2" || tab[b][a] == "N2" || tab[b][a] == "B2" || tab[b][a] == "Q2" || tab[b][a] == "K2" || tab[b][a] == "##"){
                                        tab[y][x] = "##";
                                        tab[b][a] = "Q1";
                                    }
                                    else{
                                        cout << "wrong input" << endl;
                                        break;
                                    }
                                }
                                else{
                                    continue;
                                }
                            }
                        }
                        else if ((y + count == b) && (x - count != a)){
                                cout << "wrong input" << endl;
                                break;
                        }
                        else{
                                continue;
                        }
                    }
            }
            if ((y > b) && ( x < a)){

                    for (int count = 1; y - count >= b; count++){

                        if ((y == b + count) && (x == a - count)){

                            for (int number = 1; y - number >= b; number++){

                                if ((y - number != b) && (x + number != a) && (tab[y - number][x + number] != "##")){
                                    cout << "wrong input" << endl;
                                    break;
                                }
                                else if ((y - number == b) && (x + number == a)){

                                    if (tab[b][a] == "P2" || tab[b][a] == "R2" || tab[b][a] == "N2" || tab[b][a] == "B2" || tab[b][a] == "Q2" || tab[b][a] == "K2" || tab[b][a] == "##"){
                                        tab[y][x] = "##";
                                        tab[b][a] = "Q1";
                                    }
                                    else{
                                        cout << "wrong input" << endl;
                                        break;
                                    }
                                }
                                else{
                                    continue;
                                }
                            }
                        }
                        else if ((y - count == b) && (x + count != a)){
                                cout << "wrong input" << endl;
                                break;
                        }
                        else{
                                continue;
                        }
                    }
            }
            if ((y > b) && ( x > a)){

                    for (int count = 1; y - count >= b; count++){

                        if ((y == b + count) && (x == a + count)){

                            for (int number = 1; y - number >= b; number++){

                                if ((y - number != b) && (x - number != a) && (tab[y - number][x - number] != "##")){
                                    cout << "wrong input" << endl;
                                    break;
                                }
                                else if ((y - number == b) && (x - number == a)){

                                    if (tab[b][a] == "P2" || tab[b][a] == "R2" || tab[b][a] == "N2" || tab[b][a] == "B2" || tab[b][a] == "Q2" || tab[b][a] == "K2" || tab[b][a] == "##"){
                                        tab[y][x] = "##";
                                        tab[b][a] = "Q1";
                                    }
                                    else{
                                        cout << "wrong input" << endl;
                                        break;
                                    }
                                }
                                else{
                                    continue;
                                }
                            }
                        }
                        else if ((y - count == b) && (x - count != a)){
                                cout << "wrong input" << endl;
                                break;
                        }
                        else{
                                continue;
                        }
                    }
                }
            }

		} else {
		cout << "nie mozesz sie ruszyc z tego pola" << endl;
		i--;
		}

	} else {//gracz2 (czarne)

	//ruch
	cout << "Ruch " << i << endl;
	cout << "GRACZ 2:" << endl; 
	cout << "podaj pole z ktorego chcesz sie ruszyc: " << endl;
	cout << "x:  ";
	cin >> x;
	cout << "y:  ";
	cin >> y;

	// pytanie do waszych funkcji !!!
	int a,b;
	cout << "podaj gdzie chcesz sie ruszyc: " << endl;
	cout << "x:  ";
	cin >> a;
	cout << "y:  ";
	cin >> b;

		if (tab[y][x]=="P2"){
			

			//ruch do przodu
			if(x == a){
				if(b == (y+1)){ //ruch o1 pole
					if(tab[b][a] == "##"){
						tab[y][x] = "##";
						tab[b][a] = "P2";
					}else{
						cout << "wrong input" << endl;
						i--;
					}
				} else if(b == (y+2)){ // ruch o 2 pola
					if((y == 1)&&(tab[2][x] == "##")){
						tab[y][x] = "##";
						tab[b][a] = "P2";
					} else {
						cout << "wrong input" << endl;
						i--;
					}
				} else {
					cout << "wrong input" << endl;
					i--;
				}
			}

			// zbijanie
			if((x==a+1)or(x==a-1)){
				if(b==y+1){
					if(tab[b][a] != "##"){
						if((tab[b][a] != "P2") && (tab[b][a] != "N2") && (tab[b][a] != "R2") && (tab[b][a] != "B2") && (tab[b][a] != "Q2") && (tab[b][a] != "K2") ){
							tab[y][x] = "##";
							tab[b][a] = "P2";
						}
					} else{
						cout << "wrong input" << endl;
						i--;
					}
				} else {
					cout << "wrong input" << endl;
					i--;
				}
			}

			if ((x != a)&&(x != a+1)&&(x != a-1)){
				cout << "wrong input" << endl;
				i--;
			}
			//promocja piona
			if(b==7){
				char promocja;
				cout << "wpisz na jaka figure chcesz wypromowac piona:" << endl;
				cout << "Hetman(Krolowa) - [Q]; \t Wieza - [R]; \t Goniec - [B]; \t Skoczek(Kon) - [N] \n";
				cin >> promocja;
				if(promocja == 'Q'){
					tab[b][a] = "Q2";
				} else if(promocja == 'R'){
					tab[b][a] = "R2";
				} else if(promocja == 'B'){
					tab[b][a] = "B2";
				} else if(promocja == 'N'){
					tab[b][a] = "N2";
				} else {
					cout << "wrong input" << endl;
					i--;
				}

			}


		} else if (tab[y][x] == "R2"){
			if (x == a){	
				if (y<b){
					for (int i = 1; i<8; i++){ 
						 if (tab[y+i][a] == "N2" || tab[y+i][a] == "P2" || tab[y+i][a] == "B2" || tab[y+i][a] == "Q2" || tab[y+i][a] == "K2"){
							
							tab[y][x] = "##";
							tab[y+i-1][a] = "R2";
							break;
						}else if (y+i == b && tab[b][a] == "##"){
							tab[b][a] = "R2";
							tab[y][x] = "##";
							break;
						}else if (tab[y+i][a] != "##" && (tab[y+i][a] != "N2" || tab[y+i][a] != "P2" || tab[y+i][a] != "B2" || tab[y+i][a] != "Q2" || tab[y+i][a] != "K2")){
							tab[y+i][a] = "R2";
							tab[y][x] = "##";
							break;
						}
					}
				}
		
				// ruch w górę czarnej wieży
				if (y>b){
					for (int i = 1; i<8; i++){
						if (tab[y-i][a] == "N2" || tab[y-i][a] == "P2" || tab[y-i][a] == "B2" || tab[y-i][a] == "Q2" || tab[y-i][a] == "K2"){
							
							tab[y][x] = "##";
							tab[y+1-i][a] = "R2";
							break; 
						}else if(y-i == b && tab[b][a] == "##"){
							tab[b][a] = "R2";
							tab[y][x] = "##";
							break;
						}else if (tab[y-i][a] != "##"  && (tab[y-i][a] != "N2" || tab[y-i][a] != "P2" || tab[y-i][a] != "B2" || tab[y-i][a] != "Q2" || tab[y-i][a] != "K2")){
							tab[y-i][a] = "R2";
							tab[y][x] = "##";
							break;
						}
					}
				}
			}else if (y == b){
				// ruch w prawo czarnej wieży
				if (x<a){
					for (int i = 1; i<8; i++){
						 if (tab[b][x+i] == "N2" || tab[b][x+i] == "P2" || tab[b][x+i] == "B2" || tab[b][x+i] == "Q2" || tab[b][x+i] == "K2"){
							
							tab[y][x] = "##";
							tab[b][x+i-1] = "R2";
							break;
						}else if(x+i == a && tab[b][a] == "##"){
							tab[b][a] = "R2";
							tab[y][x] = "##";
							break;
						}else if (tab[b][x+i] != "##" && (tab[b][x+i] != "N2" || tab[b][x+i] != "P2" || tab[b][x+i] != "B2" || tab[b][x+i] != "Q2" || tab[b][x+i] != "K2")){
							tab[b][x+i] = "R2";
							tab[y][x] = "##";
							break;
						}	
					}
				}
				// ruch w lewo czarnej wieży
				if (x>a){
					for (int i = 1; i<8; i++){
						if (tab[b][x-i] == "N2" || tab[b][x-i] == "P2" || tab[b][x-i] == "B2" || tab[b][x-i] == "Q2" || tab[b][x-i] == "K2"){
							
							tab[y][x] = "##";
							tab[b][x-i+1] = "R2";
							break;
						}else if(x-i == a && tab[b][a] == "##"){
							tab[b][a] = "R2";
							tab[y][x] = "##";
							break;
						}else if (tab[b][x-i] != "##" && (tab[b][x-i] == "N2" || tab[b][x-i] == "P2" || tab[b][x-i] == "B2" || tab[b][x-i] == "Q2" || tab[b][x-i] == "K2")){
							tab[b][x-i] = "R2";
							tab[y][x] = "##";
							break;
						}
					}
				}
			}else {
				cout << "wrong input" << endl;
				i--;
			}		
		} else if (tab[y][x] == "N2"){
							
			bool isValidMove = false; 
			bool isWhite = false;

			//ustalanie czy kon bialy czy czarny

			if(tab[y][x]=="N1") 
			{
				isWhite=true;
			}
			else if(tab[y][x]=="N2") 
			{
				isWhite =false;
			}
			else{
				cout<<"Brak pionka";
			}
			
			
			//1 sposob ruszania sie koniem: 2 up/down 1 left/right //2 sposob ruszania sie koniem : 1 up/down 2 left/right
			if(((a==x-1 || a==x+1) && (a>=0 & a<8))&&((b==y+2 || b==y-2) && (b<8 && b>=0))
			||((a==x-2 || a==x+2) && (a>=0 & a<8))&&((b==y+1 || b==y-1) && (b<8 && b>=0))) 
			{
				
				if(isWhite== true)
				{
					if(tab[b][a]=="N1"|| tab[b][a]=="K1"|| tab[b][a]=="Q1"|| tab[b][a]=="R1"|| tab[b][a]=="B1"|| tab[b][a]=="P1") 
					{
						cout<<"Nie mozesz zbic swoich pionkow "<<endl;
						isValidMove = false;
						
					}
					else{
						tab[b][a]=tab[y][x];
						tab[y][x]="##";
						isValidMove = true;
					}
				}
				else{
					if(tab[b][a]=="N2"|| tab[b][a]=="K2"|| tab[b][a]=="Q2"|| tab[b][a]=="R2"|| tab[b][a]=="B2"|| tab[b][a]=="P2") 
					{
						cout<<"Nie mozesz zbic swoich pionkow"<<endl;
						isValidMove = false;
					}
					else{	
						tab[b][a]=tab[y][x];
						tab[y][x]="##";
						isValidMove = true;
					}
				}
			}
			else{
				isValidMove = false;
				cout<<"Nie mozna sie ruszyc na ta pozycje"<<endl;
			}
			if(isValidMove == false){
				i--;
			}
			
		} else if (tab[y][x] == "B2"){
				if (x < a && y < b)
				{
					for (int i = 1; i < 8; i++)
					{
						if (y + i == b && x + i == a && tab[b][a] == "##")
						{
							tab[b][a] = "B2";
							tab[y][x] = "##";
							break;
						}
						else if (tab[y + 1][x + 1] != "##")
						{
							if ((tab[b][a] != "P2") && (tab[b][a] != "N2") && (tab[b][a] != "R2") && (tab[b][a] != "B2") && (tab[b][a] != "Q2") && (tab[b][a] != "K2"))
							{
								tab[y][x] = "##";
								tab[b][a] = "B2";
							}
						}
					}
				}
				if (x > a && y < b)
				{
					for (int i = 1; i < 8; i++)
					{
						if (y + i == b && x - i == a && tab[b][a] == "##")
						{
							tab[b][a] = "B2";
							tab[y][x] = "##";
							break;
						}
						else if (tab[y + 1][x - 1] != "##")
						{
							if ((tab[b][a] != "P2") && (tab[b][a] != "N2") && (tab[b][a] != "R2") && (tab[b][a] != "B2") && (tab[b][a] != "Q2") && (tab[b][a] != "K2"))
							{
								tab[y][x] = "##";
								tab[b][a] = "B2";
							}
						}
					}
				}
            // ruch w lewo czarnego gońca

				if (x < a && y > b)
				{
					for (int i = 1; i < 8; i++)
					{
						if ((y - i == b) && (x + i == a) && (tab[b][a] == "##"))
						{
							tab[b][a] = "B2";
							tab[y][x] = "##";
							break;
						}
						else if (tab[y - 1][x + 1] != "##")
						{
							if((tab[b][a] != "P2") && (tab[b][a] != "N2") && (tab[b][a] != "R2") && (tab[b][a] != "B2") && (tab[b][a] != "Q2") && (tab[b][a] != "K2") ){
							tab[y][x] = "##";
							tab[b][a] = "B2";
						}
						}
					}
				}
				if (x > a && y > b)
				{
					for (int i = 1; i < 8; i++)
					{
						if ((y - i == b) && (x - i == a) && (tab[b][a] == "##"))
						{
							tab[b][a] = "B2";
							tab[y][x] = "##";
							break;
						}
						else if (tab[y - 1][x - 1] != "##")
						{
							if((tab[b][a] != "P2") && (tab[b][a] != "N2") && (tab[b][a] != "R2") && (tab[b][a] != "B2") && (tab[b][a] != "Q2") && (tab[b][a] != "K2") ){
							tab[y][x] = "##";
							tab[b][a] = "B2";
						}
						}
					}
				}
				else
				{
					cout << "wrong input" << endl;
					i--;
				}

		} else if (tab[y][x] == "K2"){
						    if(a == x && b ==(y-1) || a == x && b == (y+1)){                 //ruch na y: pierwszy warunek na ruch do gory a drugi na ruch do dulu
                                            //ruch do przodu
                                if(tab[b][a] == "##"){
                                    tab[y][x] = "##";
                                    tab[b][a] = "K2";
                                }else if(tab[b][a] == "Q2" || tab[b][a] == "R2" || tab[b][a] == "B2"
                                         || tab[b][a] == "N2" || tab[b][a] == "P2" ){
                                             cout<<"Nie mozesz bic wlasnych figur!!";
                                         }
                                 else{
                                    tab[y][x] = "##";
                                    tab[b][a] = "K2";
                                 }
                }
                else if(a == (x+1) && b == y || a == (x-1) && b == y){          //ruch na x: pierwszy warunek na ruch w prawo a drugi w lewo
                            if(tab[b][a] == "##"){
                                tab[y][x] = "##";
                                tab[b][a] = "K2";
                            }else if(tab[b][a] == "Q2" || tab[b][a] == "R2" || tab[b][a] == "B2"
                                         || tab[b][a] == "N2" || tab[b][a] == "P2" ){
                                             cout<<"Nie mozesz bic wlasnych figur!!";
                                         }
                                 else{
                                    tab[y][x] = "##";
                                    tab[b][a] = "K2";
                                 }
                }
                else if(a == (x+1) && b == (y-1) || a == (x+1) && b == (y+1)){          //ruch na przekatnych: pierwszy warunek na ruch w prawo-gora a drugi w prawo-dol
                            if(tab[b][a] == "##"){
                                tab[y][x] = "##";
                                tab[b][a] = "K2";
                            }else if(tab[b][a] == "Q2" || tab[b][a] == "R2" || tab[b][a] == "B2"
                                         || tab[b][a] == "N2" || tab[b][a] == "P2" ){
                                             cout<<"Nie mozesz bic wlasnych figur!!";
                                         }
                                 else{
                                    tab[y][x] = "##";
                                    tab[b][a] = "K2";
                                 }
                }
                else if(a == (x-1) && b == (y-1) || a == (x-1) && b == (y+1)){          //ruch na przekatnych: pierwszy warunek na ruch w lewo-gora a drugi w lewo-dol
                            if(tab[b][a] == "##"){
                                tab[y][x] = "##";
                                tab[b][a] = "K2";
                            }else if(tab[b][a] == "Q2" || tab[b][a] == "R2" || tab[b][a] == "B2"
                                         || tab[b][a] == "N2" || tab[b][a] == "P2" ){
                                             cout<<"Nie mozesz bic wlasnych figur!!";
                                         }
                                 else{
                                    tab[y][x] = "##";
                                    tab[b][a] = "K2";
                                 }
                }
                else {
                    cout<<"wrong input"<<endl;
                    i--;
                }
		} else if (tab[y][x] == "Q2"){
			if(a > 8 || b > 8){
                cout << "wrong input" << endl;
            }

            else{
            //moving in a straight line

            if ((x == a) && (y < b)){

                for (int count = 0; (y + count) <= b; count++){
                    if (tab[y + count][a] != "##"){

                        if (((y + count) != b) && (count != 0)){
                            cout << "wrong input" << endl;
                            count = b + 1;
                            break;
                        }
                        else if (count == 0){
                                continue;
                        }
                        else{ //hit&run

                            //checking if the chess piece belongs to the opposite player

                            if(tab[b][a] == "P1" || tab[b][a] == "B1" || tab[b][a] == "R1" || tab[b][a] == "N1" || tab[b][a] == "Q1" || tab[b][a] == "K1"){
                                tab[b][a] = "Q2";
                                tab[y][x] = "##";
                            }
                            else{
                                cout << "wrong input" << endl;
                                count = b + 1;
                                break;
                            }
                        }
                    }
                    else{

                        if ((y + count == b)){
                            tab[y][x] = "##";
                            tab[b][a] = "Q2";
                        }

                        else{
                            continue;
                        }
                    }

                }
            }
            if ((x == a) && (y > b)){

                for (int count = 0; (y - count) >= b; count++){

                    if (tab[y - count][a] != "##"){

                        if (((y - count) != b) && (count != 0)){
                            cout << "wrong input" << endl;
                            break;
                        }
                        else if (count == 0){
                                continue;
                        }
                        else{ //hit&run

                            //checking if the chess piece belongs to the opposite player

                            if(tab[b][a] == "P1" || tab[b][a] == "B1" || tab[b][a] == "R1" || tab[b][a] == "N1" || tab[b][a] == "Q1" || tab[b][a] == "K1"){
                                tab[b][a] = "Q2";
                                tab[y][x] = "##";

                            }
                            else{
                                cout << "wrong input" << endl;
                                break;
                            }
                        }
                    }

                    else{

                        if ((y - count) == b){
                            tab[y][x] = "##";
                            tab[b][a] = "Q2";
                        }

                        else{
                            continue;
                        }
                    }
                }
            }
            if ((y == b) && (x < a)){

                for (int count = 0; (x + count) <= a; count++){

                    if (tab[b][x + count] != "##"){

                        if(((x + count) != a) && (count != 0)){
                            cout << "wrong input" << endl;
                            count = a + 1;
                            break;
                        }
                        else if (count == 0){
                                continue;
                        }
                        else{ //hit&run

                        //checking if the chess piece belongs to the opposite player

                            if(tab[b][a] == "P1" || tab[b][a] == "B1" || tab[b][a] == "R1" || tab[b][a] == "N1" || tab[b][a] == "Q1" || tab[b][a] == "K1"){
                                tab[b][a] = "Q2";
                                tab[y][x] = "##";

                            }
                            else{
                                cout << "wrong input" << endl;
                                count = a + 1;
                                break;
                            }
                        }
                    }
                    else{

                        if ((x + count) == a){
                            tab[y][x] = "##";
                            tab[b][a] = "Q2";
                        }

                        else{
                            continue;
                        }
                    }
                }
            }
            if ((y == b) && (x > a)){

                for (int count = 0; (x - count) >= a; count++){

                    if ( tab[b][x - count] != "##"){

                        if (((x - count) != a) && (count != 0)){
                            cout << "wrong input" << endl;
                            break;
                        }
                        else if (count == 0){
                                continue;
                        }
                        else{ //hit&run

                            //checking if the chess piece belongs to the opposite player

                            if(tab[b][a] == "P1" || tab[b][a] == "B1" || tab[b][a] == "R1" || tab[b][a] == "N1" || tab[b][a] == "Q1" || tab[b][a] == "K1"){
                                tab[b][a] = "Q2";
                                tab[y][x] = "##";

                            }
                            else{
                                cout << "wrong input" << endl;
                                break;
                            }
                        }
                    }
                    else{

                        if ((x - count) == a){
                            tab[y][x] = "##";
                            tab[b][a] = "Q2";
                        }

                        else{
                            continue;
                        }
                    }
            }
            }


            //moving diagonally

            if ((y < b) && (x < a)){

                    for (int count = 1; y + count <= b; count++){

                        if((y == b - count) && (x == a - count)){

                            for (int number = 1; y + number <= b; number++ ){

                                if ((y + number != b) && (x + number != a) && (tab[y + number][x + number] != "##")){
                                    cout << "wrong input" << endl;
                                    break;
                                }

                                else if ((y + number == b) && (x + number == a)){

                                    if (tab[b][a] == "P1" || tab[b][a] == "R1" || tab[b][a] == "N1" || tab[b][a] == "B1" || tab[b][a] == "Q1" || tab[b][a] == "K1" || tab[b][a] == "##"){
                                        tab[y][x] = "##";
                                        tab[b][a] = "Q2";
                                    }
                                    else{
                                        cout << "wrong input" << endl;
                                        break;
                                    }
                                }

                                else{
                                    continue;
                                }

                            }
                        }
                        else if ((y + count == b) && (x + count != a)){
                                cout << "wrong input" << endl;
                                break;
                        }
                        else{
                                continue;
                        }
                    }
                }
                if ((y < b) && (x > a)){

                    for (int count = 1; y + count <= b; count++){

                        if ((y == b - count) && (x == a + count)){

                            for (int number = 1; y + number <= b; number++){

                                if ((y + number != b) && (x - number != a) && (tab[y + number][x - number] != "##")){
                                    cout << "wrong input" << endl;
                                    break;
                                }

                                else if ((y + number == b) && (x - number == a)){

                                    if (tab[b][a] == "P1" || tab[b][a] == "R1" || tab[b][a] == "N1" || tab[b][a] == "B1" || tab[b][a] == "Q1" || tab[b][a] == "K1" || tab[b][a] == "##"){
                                        tab[y][x] = "##";
                                        tab[b][a] = "Q2";
                                    }
                                    else{
                                        cout << "wrong input" << endl;
                                        break;
                                    }
                                }
                                else{
                                    continue;
                                }
                            }
                        }
                        else if ((y + count == b) && (x - count != a)){
                                cout << "wrong input" << endl;
                                break;
                        }
                        else{
                                continue;
                        }
                    }
                }
                if ((y > b) && ( x < a)){

                    for (int count = 1; y - count >= b; count++){

                        if ((y == b + count) && (x == a - count)){

                            for (int number = 1; y - number >= b; number++){

                                if ((y - number != b) && (x + number != a) && (tab[y - number][x + number] != "##")){
                                    cout << "wrong input" << endl;
                                    break;
                                }
                                else if ((y - number == b) && (x + number == a)){

                                    if (tab[b][a] == "P1" || tab[b][a] == "R1" || tab[b][a] == "N1" || tab[b][a] == "B1" || tab[b][a] == "Q1" || tab[b][a] == "K1" || tab[b][a] == "##"){
                                        tab[y][x] = "##";
                                        tab[b][a] = "Q2";
                                    }
                                    else{
                                        cout << "wrong input" << endl;
                                        break;
                                    }
                                }
                                else{
                                    continue;
                                }
                            }
                        }
                        else if ((y - count == b) && (x + count != a)){
                                cout << "wrong input" << endl;
                                break;
                        }
                        else{
                                continue;
                        }
                    }
                }
                if ((y > b) && ( x > a)){

                    for (int count = 1; y - count >= b; count++){

                        if ((y == b + count) && (x == a + count)){

                            for (int number = 1; y - number >= b; number++){

                                if ((y - number != b) && (x - number != a) && (tab[y - number][x - number] != "##")){
                                    cout << "wrong input" << endl;
                                    break;
                                }
                                else if ((y - number == b) && (x - number == a)){

                                    if (tab[b][a] == "P1" || tab[b][a] == "R1" || tab[b][a] == "N1" || tab[b][a] == "B1" || tab[b][a] == "Q1" || tab[b][a] == "K1" || tab[b][a] == "##"){
                                        tab[y][x] = "##";
                                        tab[b][a] = "Q2";
                                    }
                                    else{
                                        cout << "wrong input" << endl;
                                        break;
                                    }
                                }
                                else{
                                    continue;
                                }
                            }
                        }
                        else if ((y - count == b) && (x - count != a)){
                                cout << "wrong input" << endl;
                                break;
                        }
                        else{
                                continue;
                        }
                    }
                }
        }

		} else  {
		cout << "nie mozesz sie ruszyc z tego pola" << endl;
		i--;
		}
	}	

	//sprawdzenie czy krol zostal zbity (w naszej grze nie ma mata, wygrywa sie poprzez zbicie krola przeciwnika)
	int mat1 = 0;
	int mat2 = 0;
	for (y=0;y<8;y++){
		for(x=0;x<8;x++){
			if (tab[y][x] == "K1"){
				mat1 = 1;
				};
			if (tab[y][x] == "K2"){
				mat2 = 1;
				}
			}
			cout << "\n";
		}
	if (mat1 == 0){
		cout << "player2 won" << endl;
		break;
	} else if (mat2 == 0){
		cout << "player1 won" << endl;
		break;
		}
	}	

	return 0;

}
