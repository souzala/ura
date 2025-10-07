# 🌻 Projeto Girassol – Rastreador Solar Educacional</h1>
 

O **Projeto Girassol** foi desenvolvido com o objetivo de demonstrar, de forma lúdica e acessível, o **princípio de rastreamento solar**, utilizando **materiais recicláveis e componentes de baixo custo**.

A proposta busca integrar **educação, sustentabilidade e tecnologia**, incentivando a curiosidade científica em crianças do ensino básico e promovendo a conscientização sobre o uso de energias renováveis.

<p align="center">
  <img src="https://user-images.githubusercontent.com/55934217/181629662-826bcc37-f253-43e9-aa1a-d01cc8f29579.png" alt="Motivação" width="600">
</p>


## 🧩 Materiais Utilizados

| Quantidade | Componente | Descrição |
|-------------|-------------|-----------|
| 1 | Arduino Uno | Microcontrolador principal |
| 1 | Servo motor | Responsável pelo movimento do girassol |
| 2 | LDR (sensor de luz) | Detecta a intensidade luminosa |
| 1 | Bateria 3.7V (18650) | Alimentação do circuito |
| 1 | Base de cortiça | Sustentação do protótipo |
| Diversos | Materiais recicláveis (papel, PET, EVA) | Estrutura e acabamento do “girassol” |
| — | Jumpers e resistores | Conexões elétricas |


## ⚙️ Circuito

O circuito utiliza dois sensores LDR posicionados em lados opostos do "Girassol", conectados às portas analógicas do Arduino. O servo motor ajusta a direção do “Girassol” conforme a diferença de luminosidade detectada.

<p align="center">
  <img src="https://user-images.githubusercontent.com/55934217/181630757-24aea32b-e7fe-4ffe-a348-e7c0927b62ce.png" alt="Circuito" width="600">
</p>


## 💾 Código Utilizado

A seguir está o código em C++ utilizado no projeto Girassol:

```
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
```


## ▶️ Demonstração de Funcionamento

🎥 [**Clique aqui para assistir ao vídeo de demonstração**](https://user-images.githubusercontent.com/55934217/191489618-b551d162-59d2-4686-9f54-3f074435f5df.mp4)


## 🌻 Resultado Final

O resultado é um protótipo funcional capaz de **acompanhar uma fonte de luz** em tempo real, simulando o comportamento natural de um girassol.

<p align="center">
  <img src="https://user-images.githubusercontent.com/55934217/191489345-aa4cdc60-b280-4d80-a883-5bc38b70c159.jpeg" alt="Resultado Final" width="400">
</p>


## 🧠 Licença

Este projeto é de **código aberto (open-source)** e pode ser livremente reproduzido para fins **educacionais e não comerciais**.

Contribuições e melhorias são bem-vindas! 🌞  


## 📢 Contribuição  
Sinta-se à vontade para contribuir com o projeto!  
Se encontrar algum problema ou tiver sugestões, entre em contato através do 📧 email: larissa.souza.119@ufrn.edu.br


## 👩‍💻 Desenvolvido por:

**Larissa Souza** - Graduanda em Engenharia da Computação e Mestranda na área de Robótica Educacional pela UFRN 

**Ruth Inês** - Graduanda em Engenharia da Computação pela UFRN
