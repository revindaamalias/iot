#include "CTBot.h"
CTBot machine;
int relay=4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  pinMode(relay,OUTPUT);
  digitalWrite(relay,HIGH);
  machine.wifiConnect("Rayan", "arrayyan");
  machine.setTelegramToken("1605810040:AAELmWG82oYAjGRnLjqM4Lj0qQqFucZpCZc");
  if(machine.testConnection())
  Serial.println("Connected");
  else
  Serial.println("Error");
}

void loop() {
  // put your main code here, to run repeatedly:
  TBMessage msg;

  if(machine.getNewMessage(msg)){
    Serial.print("Get new message: ");
    Serial.println(msg.text);
    if(msg.text.equalsIgnoreCase("LAMP ON")){
      digitalWrite(relay,LOW);
      machine.sendMessage(msg.sender.id,"Lamp is on");
    }
    else if(msg.text.equalsIgnoreCase("LAMP OFF")){
      digitalWrite(relay,HIGH);
      machine.sendMessage(msg.sender.id,"Lamp is off");
    }
    else{
      String reply;
      reply = "Sorry, the command is wrong. Try to send LAMP ON / LAMP OFF.";
      machine.sendMessage(msg.sender.id,reply);
    }
  }
}
