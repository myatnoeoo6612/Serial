bool previous_state=HIGH;
bool swith_state;
bool serial_state=false;
bool state;
void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
  state = LOW;
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(8,LOW);
  
  readSerialPort();
  state = digitalRead(3);
 // Serial.println(state);
  if (state != previous_state){
    previous_state = state;
    if(state == HIGH){
      //Serial.println(state);
      if(serial_state == false){
      Serial.println("open !");
      digitalWrite(8,HIGH);
      }
      else{
        Serial.println("shutdown !");
        Serial.write('S');
      }
      Serial.println("pushed !");
    }
  }

}

void readSerialPort(){
  if(Serial.available()){
    serial_state = true;
  } 
  else{
    serial_state = false;
  } 
}

