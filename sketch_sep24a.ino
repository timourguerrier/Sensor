
int ThermPin = 0;
int Vo;
float R1 = 10000;
float refT = 32.00;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
float logR2,R2,T,Tc,Tf;

void setup(){
  Serial.begin(9600);
}
void printOut(float Tf, float Tc) {
  Serial.print("Temperature: ");
  Serial.print(Tf);
  Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");
}

void loop() {
  
  Vo = analogRead(ThermPin);
  
  R2=R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  Tf = ( Tc * 9.0)/ 5.0 + 32.0;
  
  printOut(Tf, Tc);
  delay(1000);
  
}

