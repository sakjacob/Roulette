long randNumber;

void setup(){
  Serial.begin(9600);

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(4));
  //randomSeed(5);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  // print a random number from 10 to 19

}

int iter = 100;
//randomSeed(analogRead(13));
long randomNumber = random(0, 4);
//println(randomNumber);

void end_check(int iter){
  if (iter >=400){
    exit(0);
  }
}

void loop() {

  Serial.println(randomNumber);
  // Roulette Effect
  if(randomNumber==0){
   digitalWrite(10,LOW);
   digitalWrite(13,HIGH);
   randomNumber = 1;
   iter *= 1.035;
   delay(iter);
   end_check(iter);
  }
  if(randomNumber==1){
   digitalWrite(13,LOW);
   digitalWrite(12,HIGH);
   randomNumber =2;
   iter *= 1.035;
   delay(iter);
   end_check(iter);
  }
  if(randomNumber==2){
   digitalWrite(12,LOW);
   digitalWrite(11,HIGH);
   randomNumber = 3;
   iter *= 1.035;
   delay(iter);
   end_check(iter);
  }
  if(randomNumber==3){
   digitalWrite(11,LOW);
   digitalWrite(10,HIGH);
   randomNumber = 0;
   iter *= 1.035;
   delay(iter);
   end_check(iter);
  }
}
