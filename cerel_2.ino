int ldr=A5, ldr_v, cc=0, rsr_v;
int relay1=2, relay2=3;
int rsr=A4;

void setup(){
  Serial.begin(9600);
  pinMode(ldr,INPUT);
  pinMode(rsr,INPUT);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
}

void loop(){
  
  ldr_v=analogRead(ldr);
  Serial.print("LDR value is: ");
  Serial.println(ldr_v);

  rsr_v=analogRead(rsr);
  Serial.print("Rain sensor value is: ");
  Serial.println(rsr_v);

  while(ldr_v>700||rsr_v<750){
    digitalWrite(relay2,HIGH);
    ldr_v=analogRead(ldr);
    Serial.print("LDR 1 value is: ");
  Serial.println(ldr_v);
  rsr_v=analogRead(rsr);
    Serial.print("RSR 1 value is: ");
  Serial.println(rsr_v);
    if(cc<500){
    cc=cc+1;
    Serial.println(cc);
    digitalWrite(relay1,LOW);
    }
    else{
      Serial.println(cc);
      digitalWrite(relay1,HIGH);
    }
  }
  while(ldr_v<=700||rsr_v>=750){
     digitalWrite(relay1,HIGH);
    ldr_v=analogRead(ldr);
    Serial.print("LDR 2 value is: ");
    Serial.println(ldr_v);
    rsr_v=analogRead(rsr);
    Serial.print("RSR 2 value is: ");
  Serial.println(rsr_v);
    if(cc>0){
     cc=cc-1;
      Serial.println(cc);
      digitalWrite(relay2,LOW);
    }
    else{
      Serial.println(cc);
      digitalWrite(relay2,HIGH);
    }
    break;
  }
}
