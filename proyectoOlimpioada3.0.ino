int rojo11 = 51;//27;
int rojo12 = 39;//29;
int rojo13 = 27;//31;
int rojo21 = 53;//39;
int rojo22 = 41;
int rojo23 = 29;//43;
int rojo31 = 52;//51;
int rojo32 = 43;//53;
int rojo33 = 31;//52;

int verde11 = 45;//22;
int verde12 = 33;//23;
int verde13 = 22;//25;
int verde21 = 47;//33;
int verde22 = 35;
int verde23 = 23;//37;
int verde31 = 49;//45;
int verde32 = 37;//47;
int verde33 = 25;//49;

int puls1 = 15;//21;
int puls2 = 14;//20;
int puls3 = 2;//19;
int puls4 = 18;
int puls5 = 17;
int puls6 = 16;
int puls7 = 21;//15;
int puls8 = 20;//14;
int puls9 = 19;//2;

int led1 = 0;
int led2 = 0;
int led3 = 0;
int led4 = 0;
int led5 = 0;
int led6 = 0 ;
int led7 = 0;
int led8 = 0;
int led9 = 0;

int ver11 = 46;
int ver12 = 48;
int ver13 = 50;
int ver21 = 38;
int ver22 = 36;
int ver23 = 34;
int ver31 = 7;
int ver32 = 6;
int ver33 = 5;

int roj11 = 44;
int roj12 = 42;
int roj13 = 40;
int roj21 = 32;
int roj22 = 30;
int roj23 = 8;
int roj31 = 4;
int roj32 = 3;
int roj33 = 9;

int error = 0;
int zumbador = 10;

int dosPersonasFila1 = 0;
int dosPersonasFila2 = 0;
int dosPersonasFila3 = 0;

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};
byte rowPins[ROWS] = {A3, A2, A1, A0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A7, A6, A5, A4}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup() {

  Serial.begin(9600);

  pinMode(rojo11, OUTPUT);
  pinMode(rojo12, OUTPUT);
  pinMode(rojo13, OUTPUT);
  pinMode(rojo21, OUTPUT);
  pinMode(rojo22, OUTPUT);
  pinMode(rojo23, OUTPUT);
  pinMode(rojo31, OUTPUT);
  pinMode(rojo32, OUTPUT);
  pinMode(rojo33, OUTPUT);

  pinMode(verde11, OUTPUT);
  pinMode(verde12, OUTPUT);
  pinMode(verde13, OUTPUT);
  pinMode(verde21, OUTPUT);
  pinMode(verde22, OUTPUT);
  pinMode(verde23, OUTPUT);
  pinMode(verde31, OUTPUT);
  pinMode(verde32, OUTPUT);
  pinMode(verde33, OUTPUT);

  pinMode(puls1, INPUT);
  pinMode(puls2, INPUT);
  pinMode(puls3, INPUT);
  pinMode(puls4, INPUT);
  pinMode(puls5, INPUT);
  pinMode(puls6, INPUT);
  pinMode(puls7, INPUT);
  pinMode(puls8, INPUT);
  pinMode(puls9, INPUT);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(50, OUTPUT);

  digitalWrite(roj11, HIGH);
  digitalWrite(roj12, HIGH);
  digitalWrite(roj13, HIGH);
  digitalWrite(roj21, HIGH);
  digitalWrite(roj22, HIGH);
  digitalWrite(roj23, HIGH);
  digitalWrite(roj31, HIGH);
  digitalWrite(roj32, HIGH);
  digitalWrite(roj33, HIGH);

  pinMode(zumbador, OUTPUT);
}

void loop() {

  char key = keypad.getKey();

  if (error == 1){
    playtone(1700, 500);
    delay(1000);
    error=0;
  }

  if (key != NO_KEY) {

    if (key == 'A')  dosPersonasFila1 = 1;
    if (key == 'B')  dosPersonasFila2 = 1;
    if (key == 'C')  dosPersonasFila3 = 1;

    if (dosPersonasFila1 == 0 & dosPersonasFila2 == 0 & dosPersonasFila3 == 0 ) {

      delay(100);

      ///////////////PRIMERA FILA//////////////////////////////

      if (key == '1' & led2 == 0) {

        digitalWrite(rojo11, LOW);
        digitalWrite(verde11, HIGH);

        digitalWrite(verde12, LOW);
        digitalWrite(rojo12, HIGH);

        led1 = 1;

        digitalWrite(ver11, HIGH);
        digitalWrite(roj11, LOW);


      } else if (key == '1' & led2 == 1) {
        error = 1;
        Serial.println("NO SE PUEDE VENDER EL ASIENTO N°1");
      }

      if (key == '2' & led1 == 0 & led3 == 0) {

        digitalWrite(rojo11, HIGH);
        digitalWrite(verde11, LOW);
        digitalWrite(verde12, HIGH);
        digitalWrite(rojo12, LOW);
        digitalWrite(verde13, LOW);
        digitalWrite(rojo13, HIGH);
        led2 = 1;
        digitalWrite(ver12, HIGH);
        digitalWrite(roj12, LOW);

      } else if (key == '2' & (led1 == 1 | led3 == 1)) {
        error = 1;
        Serial.println("NO SE PUEDE VENDER EL ASIENTO N°2");
      }

      if (key == '3' & led2 == 0) {

        digitalWrite(rojo13, LOW);
        digitalWrite(verde13, HIGH);
        digitalWrite(verde12, LOW);
        digitalWrite(rojo12, HIGH);

        led3 = 1;

        digitalWrite(ver13, HIGH);
        digitalWrite(roj13, LOW);
      } else if (key == '3' & led2 == 1) {
        error = 1;
        Serial.println("NO SE PUEDE VENDER EL ASIENTO N°3");
      }

      /////////////////////////SEGUNDA FILA/////////////////////////

      if (key == '4' & led5 == 0) {

        digitalWrite(rojo21, LOW);
        digitalWrite(verde21, HIGH);

        digitalWrite(verde22, LOW);
        digitalWrite(rojo22, HIGH);

        led4 = 1;

        digitalWrite(ver21, HIGH);
        digitalWrite(roj21, LOW);
      } else if (key == '4' & led5 == 1) {
        error = 1;
        Serial.println("NO SE PUEDE VENDER EL ASIENTO N°4");
      }

      if (key == '5' & led4 == 0 & led6 == 0) {

        digitalWrite(rojo21, HIGH);
        digitalWrite(verde21, LOW);
        digitalWrite(verde22, HIGH);
        digitalWrite(rojo22, LOW);
        digitalWrite(verde23, LOW);
        digitalWrite(rojo23, HIGH);
        led5 = 1;

        digitalWrite(ver22, HIGH);
        digitalWrite(roj22, LOW);

      } else if (key == '5' & (led4 == 1 | led6 == 1)) {
        error = 1;
        Serial.println("NO SE PUEDE VENDER EL ASIENTO N°5");
      }

      if (key == '6' & led5 == 0) {

        digitalWrite(rojo23, LOW);
        digitalWrite(verde23, HIGH);
        digitalWrite(verde22, LOW);
        digitalWrite(rojo22, HIGH);
        led6 = 1;

        digitalWrite(ver23, HIGH);
        digitalWrite(roj23, LOW);

      } else if (key == '6' & led5 == 1) {
        error = 1;
        Serial.println("NO SE PUEDE VENDER EL ASIENTO N°6");
      }
      //////////////////////////////TERCERA FILA/////////////////////////////7

      if (key == '7' & led8 == 0) {

        digitalWrite(rojo31, LOW);
        digitalWrite(verde31, HIGH);

        digitalWrite(verde32, LOW);
        digitalWrite(rojo32, HIGH);

        led7 = 1;

        digitalWrite(ver31, HIGH);
        digitalWrite(roj31, LOW);

      } else if (key == '7' & led8 == 1) {
        error = 1;
        Serial.println("NO SE PUEDE VENDER EL ASIENTO N°7");
      }

      if (key == '8' & led7 == 0 & led9 == 0) {

        digitalWrite(rojo31, HIGH);
        digitalWrite(verde31, LOW);
        digitalWrite(verde32, HIGH);
        digitalWrite(rojo32, LOW);
        digitalWrite(verde33, LOW);
        digitalWrite(rojo33, HIGH);
        led8 = 1;

        digitalWrite(ver32, HIGH);
        digitalWrite(roj32, LOW);

      } else if (key == '8' & (led7 == 1 | led9 == 1)) {
        error = 1;
        Serial.println("NO SE PUEDE VENDER EL ASIENTO N°8");
      }

      if (key == '9' & led8 == 0) {

        digitalWrite(rojo33, LOW);
        digitalWrite(verde33, HIGH);
        digitalWrite(verde32, LOW);
        digitalWrite(rojo32, HIGH);
        led9 = 1;

        digitalWrite(ver33, HIGH);
        digitalWrite(roj33, LOW);

      } else if (key == '9' & led8 == 1) {
        error = 1;
        Serial.println("NO SE PUEDE VENDER EL ASIENTO N°9");
      }
    }

    //////////////////////////////////////////7DOS PERSONAS AL LADO/////////////////////////////////

    //////////////////////////primer fila dos personas al lado/////////////////////////////////
    if (dosPersonasFila1 == 1) {
      if (key == '1' & led3 == 0) {
        digitalWrite(rojo11, LOW);
        digitalWrite(verde11, HIGH);
        digitalWrite(verde12, HIGH);
        digitalWrite(rojo12, LOW);
        digitalWrite(verde13, LOW);
        digitalWrite(rojo13, HIGH);

        digitalWrite(roj11, LOW);
        digitalWrite(ver11, HIGH);
        digitalWrite(ver12, HIGH);
        digitalWrite(roj12, LOW);
        led1 = 1;
        led2 = 1;
        dosPersonasFila1 = 0;
      } else if (key == '1' & led3 == 1) {
        error = 1;
        Serial.print("NO SE PUEDE VENDER EL ASIENTO N°1 y 2");
        dosPersonasFila1 = 0;
      }

      if (key == '2' & led1 == 0) {
        digitalWrite(rojo11, HIGH);
        digitalWrite(verde11, LOW);
        digitalWrite(verde12, HIGH);
        digitalWrite(rojo12, LOW);
        digitalWrite(verde13, HIGH);
        digitalWrite(rojo13, LOW);

        digitalWrite(ver12, HIGH);
        digitalWrite(roj12, LOW);
        digitalWrite(ver13, HIGH);
        digitalWrite(roj13, LOW);
        led2 = 1;
        led3 = 1;
        dosPersonasFila1 = 0;
      } else if (key == '2' & led1 == 1) {
        error = 1;
        Serial.print("NO SE PUEDE VENDER EL ASIENTO N°2 y 3");
        dosPersonasFila1 = 0;
      }
    }


    ///////////////////////////////segunda fila dos personas al lado/////////////////////////////////7
  }
  if (dosPersonasFila2 == 1) {


    if (key == '4' & led6 == 0) {
      digitalWrite(rojo21, LOW);
      digitalWrite(verde21, HIGH);
      digitalWrite(verde22, HIGH);
      digitalWrite(rojo22, LOW);
      digitalWrite(verde23, LOW);
      digitalWrite(rojo23, HIGH);

      digitalWrite(roj21, LOW);
      digitalWrite(ver21, HIGH);
      digitalWrite(ver22, HIGH);
      digitalWrite(roj22, LOW);
      led4 = 1;
      led5 = 1;
      dosPersonasFila2 = 0;
    } else if (key == '1' & led6 == 1) {
      error = 1;
      Serial.print("NO SE PUEDE VENDER EL ASIENTO N°4 y 5");
      dosPersonasFila2 = 0;
    }
    if (key == '5' & led4 == 0) {
      digitalWrite(rojo21, HIGH);
      digitalWrite(verde21, LOW);
      digitalWrite(verde22, HIGH);
      digitalWrite(rojo22, LOW);
      digitalWrite(verde23, HIGH);
      digitalWrite(rojo23, LOW);

      digitalWrite(ver22, HIGH);
      digitalWrite(roj22, LOW);
      digitalWrite(ver23, HIGH);
      digitalWrite(roj23, LOW);
      led5 = 1;
      led6 = 1;
      dosPersonasFila2 = 0;
    } else if (key == '5' & led4 == 1) {
      error = 1;
      Serial.print("NO SE PUEDE VENDER EL ASIENTO N°5 y 6");
      dosPersonasFila2 = 0;
    }
  }

  ///////////////////////////////tercer fila dos personas al lado//////////////////////////////

  if (dosPersonasFila3 == 1) {

    if (key == '7' & led9 == 0) {
      digitalWrite(rojo31, LOW);
      digitalWrite(verde31, HIGH);
      digitalWrite(verde32, HIGH);
      digitalWrite(rojo32, LOW);
      digitalWrite(verde33, LOW);
      digitalWrite(rojo33, HIGH);

      digitalWrite(roj31, LOW);
      digitalWrite(ver31, HIGH);
      digitalWrite(ver32, HIGH);
      digitalWrite(roj32, LOW);
      led7 = 1;
      led8 = 1;
      dosPersonasFila3 = 0;
    } else if (key == '7' & led9 == 1) {
      error = 1;
      Serial.print("NO SE PUEDE VENDER EL ASIENTO N°6 y 7");
      dosPersonasFila3 = 0;
    }
    if (key == '8' & led7 == 0) {
      digitalWrite(rojo31, HIGH);
      digitalWrite(verde31, LOW);
      digitalWrite(verde32, HIGH);
      digitalWrite(rojo32, LOW);
      digitalWrite(verde33, HIGH);
      digitalWrite(rojo33, LOW);

      digitalWrite(ver32, HIGH);
      digitalWrite(roj32, LOW);
      digitalWrite(ver33, HIGH);
      digitalWrite(roj33, LOW);
      led8 = 1;
      led9 = 1;
      dosPersonasFila3 = 0;
    } else if (key == '8' & led7 == 1) {
      error = 1;
      Serial.print("NO SE PUEDE VENDER EL ASIENTO N°8 y 9");
      dosPersonasFila3 = 0;
    }
  }



  ////////////////////////7PROGRAMO PLACA DE CINE ////////////////////////////////////

  if (digitalRead(puls1) == 0  & led1 == 0) {
    delay(300);
    error = 1;
    Serial.println("ALGUIEN SE SENTÓ EN EL ASIENTO N°1");
  } else if (digitalRead(puls1) == 0  & led1 == 1) {
    digitalWrite(ver11, HIGH);
    digitalWrite(roj11, HIGH);

  }

  if (digitalRead(puls2) == 0  & led2 == 0) {
    delay(300);
    Serial.println("ALGUIEN SE SENTÓ EN EL ASIENTO N°2");
    error = 1;
  } else if (digitalRead(puls2) == 0  & led2 == 1) {
    digitalWrite(ver12, HIGH);
    digitalWrite(roj12, HIGH);
  }

  if (digitalRead(puls3) == 0  & led3 == 0) {
    delay(300);
    Serial.println("ALGUIEN SE SENTÓ EN EL ASIENTO N°3");
    error = 1;
  } else if (digitalRead(puls3) == 0  & led3 == 1) {
    digitalWrite(ver13, HIGH);
    digitalWrite(roj13, HIGH);
  }

  if (digitalRead(puls4) == 0  & led4 == 0) {
    delay(300);
    Serial.println("ALGUIEN SE SENTÓ EN EL ASIENTO N°4");
    error = 1;
  } else if (digitalRead(puls4) == 0  & led4 == 1) {
    digitalWrite(ver21, HIGH);
    digitalWrite(roj21, HIGH);
  }

  if (digitalRead(puls5) == 0  & led5 == 0) {
    delay(300);
    Serial.println("ALGUIEN SE SENTÓ EN EL ASIENTO N°5");
    error = 1;
  } else if (digitalRead(puls5) == 0  & led5 == 1) {
    digitalWrite(ver22, HIGH);
    digitalWrite(roj22, HIGH);
  }

  if (digitalRead(puls6) == 0  & led6 == 0) {
    delay(300);
    Serial.println("ALGUIEN SE SENTÓ EN EL ASIENTO N°6");
    error = 1;
  } else if (digitalRead(puls6) == 0  & led6 == 1) {
    digitalWrite(ver23, HIGH);
    digitalWrite(roj23, HIGH);
  }

  if (digitalRead(puls7) == 0  & led7 == 0) {
    delay(300);
    Serial.println("ALGUIEN SE SENTÓ EN EL ASIENTO N°7");
    error = 1;
  } else if (digitalRead(puls7) == 0  & led7 == 1) {
    digitalWrite(ver31, HIGH);
    digitalWrite(roj31, HIGH);
  }
  if (digitalRead(puls8) == 0  & led8 == 0) {
    delay(300);
    Serial.println("ALGUIEN SE SENTÓ EN EL ASIENTO N°8");
    error = 1;
  } else if (digitalRead(puls8) == 0  & led8 == 1) {
    digitalWrite(ver32, HIGH);
    digitalWrite(roj32, HIGH);
  }
  if (digitalRead(puls9) == 0  & led9 == 0) {
    delay(300);
    Serial.println("ALGUIEN SE SENTÓ EN EL ASIENTO N°9");
    error = 1;
  } else if (digitalRead(puls9) == 0  & led9 == 1) {
    digitalWrite(ver33, HIGH);
    digitalWrite(roj33, HIGH);
  }

}


//////////////////////////////////////////////////////zumbador////////////////////////////////////////////////////////////////

// Funcion para definir las notas segun la duración y el tono
void playtone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(zumbador, HIGH);
    delayMicroseconds(tone);
    digitalWrite(zumbador, LOW);
    delayMicroseconds(tone);
  }
}
