// Puertos    
                           // en esta parte se introducen las constantes
                            
const int SemaforoVerde = 6;
const int SemaforoAmarillo = 5;
const int SemaforoRojo = 4;
const int PasoVerde = 3;
const int PasoRojo = 2;
const int boton = 7;


//Variables                                        // se introducen las variables                     
int botonState;


void setup(){                                      // se especifica cuales puertos son de salida
  pinMode(SemaforoVerde, OUTPUT);
  pinMode(SemaforoAmarillo, OUTPUT);
  pinMode(SemaforoRojo, OUTPUT);
  pinMode(PasoRojo, OUTPUT);
  pinMode(PasoVerde, OUTPUT);
}


void loop(){
  botonState = digitalRead(boton);        // se identifica el botón
  if (botonState == LOW){                          // si no se presiona el semaforo esta en verde  y el de paso permanece en rojo
    digitalWrite(SemaforoVerde, HIGH);                  
    digitalWrite(PasoRojo, HIGH);
  }else{                                                      // si se presiona el boton se apaga el sem. verde
    for (int i = 0; i < 3; i++){
      digitalWrite(SemaforoVerde, LOW); 
      delay(500);
      digitalWrite(SemaforoVerde, HIGH);            // el semaforo verde parpadea con frecuencia 5ms
      delay(500);
    }
    digitalWrite(SemaforoVerde, LOW);
    digitalWrite(SemaforoAmarillo, HIGH);
    delay(1000);
    digitalWrite(SemaforoAmarillo, LOW);
       // se apaga el semaforo verde, prende amarillo y  parpadea por 1000 ms
    digitalWrite(SemaforoRojo, HIGH);                  
    digitalWrite(PasoVerde, HIGH);          // prende sem. rojo y el de paso en verde
    
    
    
    digitalWrite(PasoRojo, LOW);
   
    delay(7000);
    digitalWrite(PasoVerde, LOW); 
    delay(500);
    digitalWrite(PasoVerde, HIGH); 
    delay(500);
    digitalWrite(PasoVerde, LOW); 
    delay(500);
     digitalWrite(PasoVerde, HIGH); 
    delay(500);
    digitalWrite(SemaforoRojo, LOW);
    digitalWrite(PasoVerde, LOW);           // se apaga el semaforo rojo y el verde de paso
  }
}
