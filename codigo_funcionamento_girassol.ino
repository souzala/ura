#include <Servo.h>

Servo s;

int pos_s = 90; //posição da helice do servo motor
int ldrD = A2; // porta do ldr da direita;
int ldrE = A3; // porta do ldr da esquerda
int valorD; //variavel referente ao LDR do lado direito
int valorE; //variavel referente ao LDR do lado esquerdo
int diferenca = 0;


void setup(){
  
  Serial.begin(9600);
  s.attach(4); //porta do servo motor
  pinMode(ldrD, INPUT);
  pinMode(ldrE, INPUT);
 
}

void loop(){
   
  s.write(pos_s);
  delay(1000);
  
  //leitura da luz que o LDR esta recebendo
  valorD = analogRead(ldrD);
  valorE = analogRead (ldrE);
  
  //diferença dos valores que os dois LDRS estao recebendo
  diferenca = valorD - valorE;
  
  //print dos valores
  Serial.print("Valor LDR Direito: ");
  Serial.println(valorD);
 
  Serial.print("Valor LDR Esquerdo: ");
  Serial.println(valorE);  

  Serial.print("Diferença         : ");
  Serial.println(diferenca);  
 
  //limite da movimentacao do servo motor
  if(pos_s >= 180){
    pos_s = 180;
 
  }
  
  if(pos_s <= 0){
    pos_s = 0;
  }
  
  //condicao para o LDR ir para a direita
  if(diferenca > 0){
    pos_s = pos_s - 10;
    Serial.println("O girassol irá se movimentar para a direita");  
  }
 
  //condicao para o LDR ir para a esquerda
  if(diferenca < 0){
    pos_s = pos_s + 10;
    Serial.println("O girassol irá se movimentar para a esquerda");
  }
  
  //condicao para o LDR permanecer na posição atual
  if(diferenca == 0){
    pos_s = pos_s;
    Serial.println("Permanece na posição atual");
  }
}
