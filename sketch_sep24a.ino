
int ThermPin = 0;
int Vo;
float R1 = 10000;
float b = 3435;
float t0 = 273.15;
float adc = 0;
float logR,T,R,Tc,Tf,Rth;
void setup(){
  Serial.begin(9600);
}
float Calcul(float adc)
{
  Vo = analogRead(ThermPin);
  R = (1024/adc - 1);
  logR = log(R);
  T= 1.0/ (1/(Vo+t0) + 1/b * logR);
  Tc = T - 273.15;
  //Tf = (Tc * 9.0)/ 5.0 + 32.0; 
  Rth = exp(b * (1/T - 1/(Vo+t0)));
  
  return Rth;
 }
void loop()
{
  while(adc<1025)
  {
  Serial.print("Temperature: ");   
  Serial.print(Tc);
  Serial.println(" C"); 
  Serial.print(Calcul(adc));
  Serial.print("K Rt; "); 
  delay(1000);
  adc++;
  }
}

