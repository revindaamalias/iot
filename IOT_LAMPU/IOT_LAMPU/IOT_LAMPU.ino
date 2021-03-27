#include "CTBot.h"
CTBot robot;
int relay=4;

void setup() {
  Serial.begin(115200);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,HIGH);
  robot.wifiConnect("Rayan", "arrayyan");
  robot.setTelegramToken("1605810040:AAELmWG82oYAjGRnLjqM4Lj0qQqFucZpCZc");
  if(robot.testConnection())
  Serial.println("Terhubung!");
  else
  Serial.println("Error!");

}

void loop() {
  TBMessage pesan;

  if(robot.getNewMessage(pesan)){
    Serial.print("Get new message : ");
    Serial.println(pesan.text);
    if(pesan.text.equalsIgnoreCase("LAMP ON")){
      digitalWrite(relay,LOW);
      robot.sendMessage(pesan.sender.id,"LAMP IS ON");
    }
    else if(pesan.text.equalsIgnoreCase("LAMP OFF")){
      digitalWrite(relay,HIGH);
      robot.sendMessage(pesan.sender.id,"LAMP IS OFF");
    }
    else{
      String balas;
      balas="Sorry, the command is wrong. Try to send LAMP ON / LAMP OFF.";
      robot.sendMessage(pesan.sender.id,balas);
    }
  }

}
