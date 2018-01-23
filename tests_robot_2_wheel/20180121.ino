#define MD_ENA_1 5
#define MD_IN_1 6
#define MD_IN_2 7
#define MI_ENA_1 9
#define MI_IN_1 8
#define MI_IN_2 10
#define MD_VEL 150
#define MI_VEL 150
int pulsosMD=0;
int pulsosMI=0;
void pulsoD(){
  pulsosMD++;
  }
  void pulsoI(){
  pulsosMI++;
  }
void setup() {
  Serial.begin(9600);  
  // put your setup code here, to run once:
  pinMode(MD_ENA_1,OUTPUT);
  pinMode(MD_IN_1,OUTPUT);
  pinMode(MD_IN_2,OUTPUT);
  pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
  analogWrite(MD_ENA_1,MD_VEL);
  analogWrite(MI_ENA_1,MI_VEL);
  attachInterrupt(digitalPinToInterrupt(2),pulsoD,RISING);
  attachInterrupt(digitalPinToInterrupt(3),pulsoI,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  palante();
  delay(3000);
  libre();
  Serial.print(pulsosMI);
  Serial.print("---");
  Serial.print(pulsosMD);
  Serial.print("\n");
  pulsosMD=0;
  pulsosMI=0;
  delay(3000);
 // patras();
  //delay(3000);
  //freno();
  //delay(3000);


}
void palante(){
  int md_vel=65;
  int mi_vel=65;
  analogWrite(MD_ENA_1,md_vel);
  analogWrite(MI_ENA_1,mi_vel);
  digitalWrite(MD_IN_1,HIGH);
  digitalWrite(MD_IN_2,LOW);
  digitalWrite(MI_IN_1,HIGH);
  digitalWrite(MI_IN_2,LOW);
 
  while(md_vel<MD_VEL || mi_vel<MI_VEL){
    if(md_vel<MD_VEL){
        md_vel+=1;
        analogWrite(MD_ENA_1,md_vel);
      }
      if(mi_vel<MI_VEL){
        mi_vel+=1;
        analogWrite(MI_ENA_1,mi_vel);
      }
      delay(40);
   }
}
void patras(){
  digitalWrite(MD_IN_2,HIGH);
  digitalWrite(MD_IN_1,LOW);
  digitalWrite(MI_IN_2,HIGH);
  digitalWrite(MI_IN_1,LOW);
}
void freno(){
  digitalWrite(MD_IN_2,HIGH);
  digitalWrite(MD_IN_1,HIGH);
  digitalWrite(MI_IN_2,HIGH);
  digitalWrite(MI_IN_1,HIGH);
}
void libre(){
  digitalWrite(MD_IN_2,LOW);
  digitalWrite(MD_IN_1,LOW);
  digitalWrite(MI_IN_2,LOW);
  digitalWrite(MI_IN_1,LOW);
}


