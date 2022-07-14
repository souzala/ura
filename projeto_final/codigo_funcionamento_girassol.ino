#include <Servo.h>

Servo s;
int pos_s = 0; //posicao da helice
int ldrD = 3; //porta do LDR do lado direito
int valor_formatadoD, valorD; //variaveis referentes ao LDR do lado direito
int ldrE = 2; //porta do LDR do lado esquerdo
int valor_formatadoE, valorE; //variaveis referentes ao LDR do lado esquerdo

void setup() {
  Serial.begin(9600);
  s.attach(4); //porta do servo motor
  s.write(pos_s); //leitura da posicao inicial da helice = 0
}

void loop() {
  //leitura da luz que o LDR esta recebendo
  valorD = analogRead(ldrD);
  valorE = analogRead(ldrE);

  //formatacao do valor recebido referente a luz do LDR
  valor_formatadoD = map(valorD, 0, 1023, 0, 100);
  valor_formatadoE = map(valorE, 0, 1023, 0, 100);

  delay(500);

  // para o servo mexer para a direita
  if (valor_formatadoD > valor_formatadoE){ // se a luz recebida pelo direito for maior que o esquerdo, move para a direita
    
    for (pos_s = 180; pos_s > 0; pos_s--){
      s.write(1);
      
      //print dos valores do lado direito no serial
      Serial.print("O valor de D quando o servo vai para a direita é: ");
      Serial.println(valor_formatadoD);
      Serial.print("O valor é E quando o servo vai para a direita é: ");
      Serial.println(valor_formatadoE);
    } 
   
 }
 
  // para servo mover para esquerda
  else if (valor_formatadoD < valor_formatadoE){ // se a luz recebida pelo esquerdo for maior que o direito, move para a esquerda
    
    for (pos_s = 0; pos_s < 180;pos_s++){
    s.write(175);
    
    //print dos valores do lado direito no serial
    Serial.print("O valor de D quando o servo vai para a esquerda é: ");
    Serial.println(valor_formatadoD);
    Serial.print("O valor é E quando o servo vai para a esquerda é: ");
    Serial.println(valor_formatadoE);
    }

  }
  
}
