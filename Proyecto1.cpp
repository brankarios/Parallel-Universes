#include <iostream>
using namespace std;

int main(){
	
	//Posiciones, Movimientos y Sentidos de Mario y sus copias
    int MarioX, MarioY, MarioC1X, MarioC1Y, MarioC2X, MarioC2Y; //Posición inicial de Mario y sus copias
    int VMarioX, VMarioY, VMarioC1X, VMarioC1Y, VMarioC2X, VMarioC2Y; //Velocidad (movimiento) de Mario y sus copias
    int SMarioX, SMarioY, SMarioC1X, SMarioC1Y, SMarioC2X, SMarioC2Y; //Sentido de Mario y sus copias
    int cuadrante;
	bool ErrorEnLaEntrada = false;
	
	//Scuttlebugs Cantidad, Posiciones y Puntos de Salud
	int CScuttlebugs;
	int PScuttlebug1X = 0, PScuttlebug1Y = 0, PScuttlebug2X = 0, PScuttlebug2Y = 0, PScuttlebug3X = 0, PScuttlebug3Y = 0;
	int VidaScuttlebug1, VidaScuttlebug2, VidaScuttlebug3;

	//Posición de la estrella y su duración
	int StarX, StarY;
	int DStar = 0;

	//Número de iteraciones de la simulación
	int NIteraciones;
	int MarioXF, MarioYF, MarioC1XF, MarioC1YF, MarioC2XF, MarioC2YF;

    //Pedirle al usuario la posición inicial, la velocidad y el sentido de Mario y sus copias
    cin >> MarioX >> MarioY;
    cin >> SMarioX >> SMarioY >> SMarioC1X >> SMarioC1Y >> SMarioC2X >> SMarioC2Y;
	
	//Pedimos al usuario todo lo relacionado a Scuttlebugs
	cin >> CScuttlebugs;
	if ( CScuttlebugs == 1) { cin >> PScuttlebug1X >> PScuttlebug1Y >> VidaScuttlebug1; }
	else if ( CScuttlebugs == 2) { cin >> PScuttlebug1X >> PScuttlebug1Y >> VidaScuttlebug1 >> PScuttlebug2X >> PScuttlebug2Y >> VidaScuttlebug2; }
	else if ( CScuttlebugs == 3) { cin >> PScuttlebug1X >> PScuttlebug1Y >> VidaScuttlebug1 >> PScuttlebug2X >> PScuttlebug2Y >> VidaScuttlebug2 >> PScuttlebug3X >> PScuttlebug3Y >> VidaScuttlebug3;}
	
	cin >> StarX >> StarY; //Pedimos las coordenadas de la estrella
	cin >> NIteraciones; //Pedimos el numero de iteraciones
	
	//Validación de entradas
	if ( CScuttlebugs < 0 || CScuttlebugs > 3) { ErrorEnLaEntrada = true;}
	else if (VidaScuttlebug1 <= 0 || VidaScuttlebug2 <= 0 || VidaScuttlebug3 <= 0) { ErrorEnLaEntrada = true; }
	if (NIteraciones <= 0) {ErrorEnLaEntrada = true;}
	
    //Igualamos la posición inicial de las copias y las velocidades con el Mario original
    MarioC1X = MarioX;
    MarioC1Y = MarioY;
    MarioC2X = MarioX;
    MarioC2Y = MarioY;
	
	//Inician las iteraciones
	for(int i = 0; i < NIteraciones ; i++){
		cin >> VMarioX >> VMarioY;
		VMarioC1X = VMarioX;
		VMarioC1Y = VMarioY;
		VMarioC2X = VMarioX;
		VMarioC2Y = VMarioY;
		
		if( i > 0 ){
			MarioX = MarioXF;
			MarioY = MarioYF;
			MarioC1X = MarioC1XF;
			MarioC1Y = MarioC1YF;
			MarioC2X = MarioC2XF;
			MarioC2Y = MarioC2YF;
		}
			
		if(DStar > 0) { DStar-= 1;}
		
	if(SMarioX == 1){MarioX += VMarioX;}              //Mario se mueve a la derecha
	else if(SMarioX == -1){MarioX -= VMarioX;}        //Mario se mueve a la izquierda
	else { ErrorEnLaEntrada = true;}
	if(SMarioY == 1){MarioY += VMarioY;}			  //Mario se mueve hacia arriba
	else if(SMarioY == -1){MarioY -= VMarioY;}        //Mario se mueve hacia abajo
	else { ErrorEnLaEntrada = true;}

    //Definimos los cuadrantes
    if(MarioX >= 0 && MarioY >= 0){cuadrante = 1;}
    else if(MarioX < 0 && MarioY >= 0){cuadrante = 2;}
    else if(MarioX < 0 && MarioY < 0){cuadrante = 3;}
    else if(MarioX >= 0 && MarioY < 0){cuadrante = 4;}

    //Validamos lo que sucede en cuada cuadrante
    switch(cuadrante)
    {
        case 2: //Cuadrante 2
        SMarioC1X *= -1;
        SMarioC2X *= -1;
        break;

        case 3: //Cuadrante 3
        SMarioC1Y *= -1;
        SMarioC2Y *= -1;
        break;

        case 4: //Cuadrante 4
        SMarioC1X *= -1;
        SMarioC2X *= -1;
        SMarioC1Y *= -1;
        SMarioC2Y *= -1;
        break;
    }
	
    //Desplazamiento de las copias de Mario
    if(SMarioC1X == 1){MarioC1X += VMarioC1X;}        //Copia 1 se mueve hacia la derecha
    else if(SMarioC1X == -1){MarioC1X -= VMarioC1X;}  //Copia 1 se mueve hacia la izquierda
	else { ErrorEnLaEntrada = true;}
    if(SMarioC1Y == 1){MarioC1Y += VMarioC1Y;} 		  //Copia 1 se mueve hacia arriba
    else if(SMarioC1Y == -1){MarioC1Y -= VMarioC1Y;}  //Copia 1 se mueve hacia abajo
	else { ErrorEnLaEntrada = true;}

    if(SMarioC2X == 1){MarioC2X += VMarioC2X;}        //Copia 2 se mueve a la derecha
    else if(SMarioC2X == -1){MarioC2X -= VMarioC2X;}  //Copia 2 se mueve a la izquierda
	else { ErrorEnLaEntrada = true;}
    if(SMarioC2Y == 1){MarioC2Y += VMarioC2Y;}        //Copia 2 se mueve hacia arriba
    else if(SMarioC2Y == -1){MarioC2Y -= VMarioC2Y;}  // Copia 2 se mueve hacia abajo
	else { ErrorEnLaEntrada = true;}
	
	//Evaluamos la cantidad de Scuttlebugs que el usuario introdujo	
	switch(CScuttlebugs){		
		case 1:
		// Si Mario y el Scuttlebug estan en la misma posicion 
		if (PScuttlebug1X == MarioX && PScuttlebug1Y == MarioY && DStar > 0){ 
			VidaScuttlebug1 = 0;
			MarioC1X = MarioX;
			MarioC1Y = MarioY;
			MarioC2X = MarioX;
			MarioC2Y = MarioY;
		}
		else if (PScuttlebug1X == MarioX && PScuttlebug1Y == MarioY){
			VidaScuttlebug1 -= 2; 
			//Si el Scuttlebug se muere, las copias se alinean con Mario
			if (VidaScuttlebug1 <= 0){
				VidaScuttlebug1 = 0;
				MarioC1X = MarioX;
				MarioC1Y = MarioY;
				MarioC2X = MarioX;
				MarioC2Y = MarioY;
			}
		} // Si el Scuttlebug y la copia 1 de Mario estan alineadas

		if (PScuttlebug1X == MarioC1X && PScuttlebug1Y == MarioC1Y && DStar > 0){ 
			VidaScuttlebug1 = 0;
			MarioX = MarioC1X;
			MarioY = MarioC1Y;
			MarioC2X = MarioC1X;
			MarioC2Y = MarioC1Y;
		}
		else if (PScuttlebug1X == MarioC1X && PScuttlebug1Y == MarioC1Y){ 
			VidaScuttlebug1 -= 1;
			//Si el Scuttlebug se muere, Mario y la copia 2 se alinean con la copia 1  			
			if (VidaScuttlebug1 <= 0){
				MarioX = MarioC1X;
				MarioY = MarioC1Y;
				MarioC2X = MarioC1X;
				MarioC2Y = MarioC1Y;
			}
		} // Si el scuttlebug y la copia 2 de Mario estan alineada		
		if (PScuttlebug1X == MarioC2X && PScuttlebug1Y == MarioC2Y && DStar > 0){ 
			VidaScuttlebug1 = 0;
			MarioX = MarioC2X;
			MarioY = MarioC2Y;
			MarioC1X = MarioC2X;
			MarioC1Y = MarioC2Y;
		}
		else if (PScuttlebug1X == MarioC2X && PScuttlebug1Y == MarioC2Y){ 
			VidaScuttlebug1 -= 1;
			// Si el Scuttlebug se muere, Mario y la copia 1 se alinean con la copia 2			
			if (VidaScuttlebug1 <= 0){
				VidaScuttlebug1 = 0;
				MarioX = MarioC2X;
				MarioY = MarioC2Y;
				MarioC1X = MarioC2X;
				MarioC1Y = MarioC2Y;
			}
		}
		break;
		
		case 2:
		// Trabajar la posicion y vida del scuttlebug 1
		// Si Mario y el Scuttlebug estan en la misma posicion
		if (PScuttlebug1X == MarioX && PScuttlebug1Y == MarioY && DStar > 0){ 
			VidaScuttlebug1 = 0;
			MarioC1X = MarioX;
			MarioC1Y = MarioY;
			MarioC2X = MarioX;
			MarioC2Y = MarioY;
		}
		else if (PScuttlebug1X == MarioX && PScuttlebug1Y == MarioY){
			VidaScuttlebug1 -= 2; 
			//Si el Scuttlebug se muere, las copias se alinean con Mario
			if (VidaScuttlebug1 <= 0){
				MarioC1X = MarioX;
				MarioC1Y = MarioY;
				MarioC2X = MarioX;
				MarioC2Y = MarioY;
			}
		} // Si el Scuttlebug y la copia 1 de Mario estan alineadas
		if (PScuttlebug1X == MarioC1X && PScuttlebug1Y == MarioC1Y && DStar > 0){ 
			VidaScuttlebug1 = 0;
			MarioX = MarioC1X;
			MarioY = MarioC1Y;
			MarioC2X = MarioC1X;
			MarioC2Y = MarioC1Y;
		}
		else if (PScuttlebug1X == MarioC1X && PScuttlebug1Y == MarioC1Y){ 
			VidaScuttlebug1 -= 1;
			//Si el Scuttlebug se muere, Mario y la copia 2 se alinean con la copia 1  			
			if (VidaScuttlebug1 <= 0){
				MarioX = MarioC1X;
				MarioY = MarioC1Y;
				MarioC2X = MarioC1X;
				MarioC2Y = MarioC1Y;
			}
		} // Si el scuttlebug y la copia 2 de Mario estan alineadas
		
		if (PScuttlebug1X == MarioC2X && PScuttlebug1Y == MarioC2Y && DStar > 0){ 
			VidaScuttlebug1 = 0;
			MarioX = MarioC2X;
			MarioY = MarioC2Y;
			MarioC1X = MarioC2X;
			MarioC1Y = MarioC2Y;
		}
		else if (PScuttlebug1X == MarioC2X && PScuttlebug1Y == MarioC2Y){ 
			VidaScuttlebug1 -= 1;
			// Si el Scuttlebug se muere, Mario y la copia 1 se alinean con la copia 2			
			if (VidaScuttlebug1 <= 0){
				MarioX = MarioC2X;
				MarioY = MarioC2Y;
				MarioC1X = MarioC2X;
				MarioC1Y = MarioC2Y;
			}
		}
		// Trabajar la posicion y vida del scuttlebug 2
		// Si Mario y el Scuttlebug estan en la misma posicion 
		if (PScuttlebug2X == MarioX && PScuttlebug2Y == MarioY && DStar > 0){ 
			VidaScuttlebug2 = 0; 
			MarioC1X = MarioX;
			MarioC1Y = MarioY;
			MarioC2X = MarioX;
			MarioC2Y = MarioY;
		}
		else if (PScuttlebug2X == MarioX && PScuttlebug2Y == MarioY){
			VidaScuttlebug2 -= 2; 
			//Si el Scuttlebug se muere, las copias se alinean con Mario
			if (VidaScuttlebug2 <= 0){
				MarioC1X = MarioX;
				MarioC1Y = MarioY;
				MarioC2X = MarioX;
				MarioC2Y = MarioY;
			}
		} // Si el Scuttlebug y la copia 1 de Mario estan alineadas
		
		if (PScuttlebug2X == MarioC1X && PScuttlebug2Y == MarioC1Y && DStar > 0){ 
			VidaScuttlebug2 = 0;
			MarioX = MarioC1X;
			MarioY = MarioC1Y;
			MarioC2X = MarioC1X;
			MarioC2Y = MarioC1Y;
		} 
		else if (PScuttlebug2X == MarioC1X && PScuttlebug2Y == MarioC1Y){ 
			VidaScuttlebug2 -= 1;
			//Si el Scuttlebug se muere, Mario y la copia 2 se alinean con la copia 1  			
			if (VidaScuttlebug2 <= 0){
				MarioX = MarioC1X;
				MarioY = MarioC1Y;
				MarioC2X = MarioC1X;
				MarioC2Y = MarioC1Y;
			}
		} // Si el scuttlebug y la copia 2 de Mario estan alineadas
		if (PScuttlebug2X == MarioC2X && PScuttlebug2Y == MarioC2Y && DStar > 0){ 
			VidaScuttlebug2 = 0;
			MarioX = MarioC2X;
			MarioY = MarioC2Y;
			MarioC1X = MarioC2X;
			MarioC1Y = MarioC2Y;
			}
		else if (PScuttlebug2X == MarioC2X && PScuttlebug2Y == MarioC2Y){ 
			VidaScuttlebug2 -= 1;
			// Si el Scuttlebug se muere, Mario y la copia 1 se alinean con la copia 2			
			if (VidaScuttlebug2 <= 0){
				MarioX = MarioC2X;
				MarioY = MarioC2Y;
				MarioC1X = MarioC2X;
				MarioC1Y = MarioC2Y;
			}
		}
		break;
		
		case 3:
		// Trabajar la posicion y vida del scuttlebug 1
		// Si Mario y el Scuttlebug estan en la misma posicion 
	 	if (PScuttlebug1X == MarioX && PScuttlebug1Y == MarioY && DStar > 0){ 
			VidaScuttlebug1 = 0;
			MarioC1X = MarioX;
			MarioC1Y = MarioY;
			MarioC2X = MarioX;
			MarioC2Y = MarioY;
		}
		else if (PScuttlebug1X == MarioX && PScuttlebug1Y == MarioY){
			VidaScuttlebug1 -= 2; 
			//Si el Scuttlebug se muere, las copias se alinean con Mario
			if (VidaScuttlebug1 <= 0){
				MarioC1X = MarioX;
				MarioC1Y = MarioY;
				MarioC2X = MarioX;
				MarioC2Y = MarioY;
			}
		} // Si el Scuttlebug y la copia 1 de Mario estan alineadas
		
		if (PScuttlebug1X == MarioC1X && PScuttlebug1Y == MarioC1Y && DStar > 0){ 
			VidaScuttlebug1 = 0;
			MarioX = MarioC1X;
			MarioY = MarioC1Y;
			MarioC2X = MarioC1X;
			MarioC2Y = MarioC1Y;
		}
		else if (PScuttlebug1X == MarioC1X && PScuttlebug1Y == MarioC1Y){ 
			VidaScuttlebug1 -= 1;
			//Si el Scuttlebug se muere, Mario y la copia 2 se alinean con la copia 1  			
			if (VidaScuttlebug1 <= 0){
				MarioX = MarioC1X;
				MarioY = MarioC1Y;
				MarioC2X = MarioC1X;
				MarioC2Y = MarioC1Y;
			}
		} // Si el scuttlebug y la copia 2 de Mario estan alineadas
		if (PScuttlebug1X == MarioC2X && PScuttlebug1Y == MarioC2Y && DStar > 0){ 
			VidaScuttlebug1 = 0;
			MarioX = MarioC2X;
			MarioY = MarioC2Y;
			MarioC1X = MarioC2X;
			MarioC1Y = MarioC2Y;
		}
		else if (PScuttlebug1X == MarioC2X && PScuttlebug1Y == MarioC2Y){ 
			VidaScuttlebug1 -= 1;
			// Si el Scuttlebug se muere, Mario y la copia 1 se alinean con la copia 2			
			if (VidaScuttlebug1 <= 0){
				MarioX = MarioC2X;
				MarioY = MarioC2Y;
				MarioC1X = MarioC2X;
				MarioC1Y = MarioC2Y;
			}
		}
		// Trabajar la posicion y vida del scuttlebug 2
		// Si Mario y el Scuttlebug estan en la misma posicion 
		if (PScuttlebug2X == MarioX && PScuttlebug2Y == MarioY && DStar > 0){ 
			VidaScuttlebug2 = 0;
			MarioC1X = MarioX;
			MarioC1Y = MarioY;
			MarioC2X = MarioX;
			MarioC2Y = MarioY;
		}
		else if (PScuttlebug2X == MarioX && PScuttlebug2Y == MarioY){
			VidaScuttlebug2 -= 2; 
			//Si el Scuttlebug se muere, las copias se alinean con Mario
			if (VidaScuttlebug2 <= 0){
				MarioC1X = MarioX;
				MarioC1Y = MarioY;
				MarioC2X = MarioX;
				MarioC2Y = MarioY;
			}
		} // Si el Scuttlebug y la copia 1 de Mario estan alineadas
		if (PScuttlebug2X == MarioC1X && PScuttlebug2Y == MarioC1Y && DStar > 0){ 
			VidaScuttlebug2 = 0;
			MarioX = MarioC1X;
			MarioY = MarioC1Y;
			MarioC2X = MarioC1X;
			MarioC2Y = MarioC1Y;
		}
		else if (PScuttlebug2X == MarioC1X && PScuttlebug2Y == MarioC1Y){ 
			VidaScuttlebug2 -= 1;
			//Si el Scuttlebug se muere, Mario y la copia 2 se alinean con la copia 1  			
			if (VidaScuttlebug2 <= 0){
				MarioX = MarioC1X;
				MarioY = MarioC1Y;
				MarioC2X = MarioC1X;
				MarioC2Y = MarioC1Y;
			}
		} // Si el scuttlebug y la copia 2 de Mario estan alineadas
		if (PScuttlebug2X == MarioC2X && PScuttlebug2Y == MarioC2Y && DStar > 0){ 
			VidaScuttlebug2 = 0;
			MarioX = MarioC2X;
			MarioY = MarioC2Y;
			MarioC1X = MarioC2X;
			MarioC1Y = MarioC2Y;
		}
		else if (PScuttlebug2X == MarioC2X && PScuttlebug2Y == MarioC2Y){ 
			VidaScuttlebug2 -= 1;
			// Si el Scuttlebug se muere, Mario y la copia 1 se alinean con la copia 2			
			if (VidaScuttlebug2 <= 0){
				MarioX = MarioC2X;
				MarioY = MarioC2Y;
				MarioC1X = MarioC2X;
				MarioC1Y = MarioC2Y;
			}
		}
		// Trabajar la posicion y vida del scuttlebug 1
		// Si Mario y el Scuttlebug estan en la misma posicion 
		if (PScuttlebug3X == MarioX && PScuttlebug3Y == MarioY && DStar > 0){ 
			VidaScuttlebug3 = 0;
			MarioC1X = MarioX;
			MarioC1Y = MarioY;
			MarioC2X = MarioX;
			MarioC2Y = MarioY;
		}
		else if (PScuttlebug3X == MarioX && PScuttlebug3Y == MarioY){
			VidaScuttlebug3 -= 2; 
			//Si el Scuttlebug se muere, las copias se alinean con Mario
			if (VidaScuttlebug3 <= 0){
				MarioC1X = MarioX;
				MarioC1Y = MarioY;
				MarioC2X = MarioX;
				MarioC2Y = MarioY;
			}
		} // Si el Scuttlebug y la copia 1 de Mario estan alineadas
		if (PScuttlebug3X == MarioC1X && PScuttlebug3Y == MarioC1Y && DStar > 0){ 
			VidaScuttlebug3 = 0;
			MarioX = MarioC1X;
			MarioY = MarioC1Y;
			MarioC2X = MarioC1X;
			MarioC2Y = MarioC1Y;
		}
		else if (PScuttlebug3X == MarioC1X && PScuttlebug3Y == MarioC1Y){ 
			VidaScuttlebug3 -= 1;
			//Si el Scuttlebug se muere, Mario y la copia 2 se alinean con la copia 1  			
			if (VidaScuttlebug3 <= 0){
				MarioX = MarioC1X;
				MarioY = MarioC1Y;
				MarioC2X = MarioC1X;
				MarioC2Y = MarioC1Y;
			}
		} // Si el scuttlebug y la copia 2 de Mario estan alineadas
		if (PScuttlebug3X == MarioC2X && PScuttlebug3Y == MarioC2Y && DStar > 0){ 
			VidaScuttlebug3 = 0;
			MarioX = MarioC2X;
			MarioY = MarioC2Y;
			MarioC1X = MarioC2X;
			MarioC1Y = MarioC2Y;
		}
		else if (PScuttlebug3X == MarioC2X && PScuttlebug3Y == MarioC2Y){ 
			VidaScuttlebug3 -= 1;
			// Si el Scuttlebug se muere, Mario y la copia 1 se alinean con la copia 2			
			if (VidaScuttlebug3 <= 0){
				MarioX = MarioC2X;
				MarioY = MarioC2Y;
				MarioC1X = MarioC2X;
				MarioC1Y = MarioC2Y;
			}
		}
		break;
	}
	
		if((MarioX == StarX && MarioY == StarY) || (MarioC1X == StarX && MarioC1Y == StarY) || (MarioC2X == StarX && MarioC2Y == StarY)){ DStar = 3;}
		
		MarioXF = MarioX;
		MarioYF = MarioY;
		MarioC1XF = MarioC1X;
   		MarioC1YF = MarioC1Y;
    	MarioC2XF = MarioC2X;
    	MarioC2YF = MarioC2Y;

		if(ErrorEnLaEntrada) {
		cout << "Error en la entrada." << endl;
		return 0;
		}
	}
    //Validamos las posiciones de Mario y sus copias
    if ((MarioX == MarioC1X && MarioX == MarioC2X) && (MarioY == MarioC1Y && MarioY == MarioC2Y) && !ErrorEnLaEntrada){ 
		cout << "Perfectamente alineado" << endl;
		cout << "Posicion de Mario: (" << MarioX << "," << MarioY << ")" << endl;
		if ((CScuttlebugs == 1 || CScuttlebugs == 2 || CScuttlebugs == 3) && VidaScuttlebug1 > 0){ cout << "Posicion del Scuttlebug 1: " << "(" << PScuttlebug1X << "," << PScuttlebug1Y << ");" << "Vida=" << VidaScuttlebug1 << endl; }
		if ((CScuttlebugs == 2 || CScuttlebugs == 3) && VidaScuttlebug2 > 0){ cout << "Posicion del Scuttlebug 2: " << "(" << PScuttlebug2X << "," << PScuttlebug2Y << ");" << "Vida=" << VidaScuttlebug2 << endl; }
		if (CScuttlebugs == 3 && VidaScuttlebug3 > 0){ cout << "Posicion del Scuttlebug 3: " << "(" << PScuttlebug3X << "," << PScuttlebug3Y << ");" << "Vida=" << VidaScuttlebug3 << endl; }
	}
	else if(!ErrorEnLaEntrada){
		cout <<"Desincronizacion Total" << endl;
		cout << "Posicion de Mario: (" << MarioX << "," << MarioY << ")" << endl;
		cout << "Posicion de la copia 1: (" << MarioC1X << "," << MarioC1Y << ")" << endl;
		cout << "Posicion de la copia 2: (" << MarioC2X << "," << MarioC2Y << ")" << endl;

		if ((CScuttlebugs == 1 || CScuttlebugs == 2 || CScuttlebugs == 3) && VidaScuttlebug1 > 0){ cout << "Posicion del Scuttlebug 1: " << "(" << PScuttlebug1X << "," << PScuttlebug1Y << ");" << "Vida=" << VidaScuttlebug1 << endl; }
		if ((CScuttlebugs == 2 || CScuttlebugs == 3) && VidaScuttlebug2 > 0){ cout << "Posicion del Scuttlebug 2: " << "(" << PScuttlebug2X << "," << PScuttlebug2Y << ");" << "Vida=" << VidaScuttlebug2 << endl; }
		if (CScuttlebugs == 3 && VidaScuttlebug3 > 0){ cout << "Posicion del Scuttlebug 3: " << "(" << PScuttlebug3X << "," << PScuttlebug3Y << ");" << "Vida=" << VidaScuttlebug3 << endl; }
	}	
	return 0;
}