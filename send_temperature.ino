#include <SoftwareSerial.h>
SoftwareSerial myGsm(A0,A1);

void setup()
{
 myGsm.begin(9600);  
 Serial.begin(9600);  
 delay(500);
 
 myGsm.println("AT+CGATT=1");
 delay(200);
 printSerialData();
 
 myGsm.println("AT+SAPBR=3,1,\"APN\",\"mtnirancell\"");//setting the SAPBR,connection type is GPRS
 delay(1000);
 printSerialData();
 
 myGsm.println();
 myGsm.println("AT+SAPBR=1,1");
 delay(10000);
 printSerialData();
 
 myGsm.println("AT+HTTPINIT"); //init the HTTP request
 delay(2000); 
 printSerialData();
 
 myGsm.println("AT+HTTPPARA=\"CID\",1");
 delay(5000);
 printSerialData();

 
// myGsm.println("AT+HTTPTERM");// terminate HTTP service
// printSerialData();

}
void send_data(int value){
 String cmd="AT+HTTPPARA=\"URL\",\"http://robankala.ir/daryaft.php?value=";
 myGsm.print(cmd);
 myGsm.print(value); 
 myGsm.println("\"");
 //the second parameter is the website from where you want to access data 
 delay(1000);
 printSerialData();
 
 myGsm.println();
 myGsm.println("AT+HTTPACTION=0");//submit the GET request 
 delay(8000);
 printSerialData();  
 myGsm.println("");
 delay(1000);
}
void loop()
{
  send_data(get_temp());
 }
  

float get_temp(){
  float sensorValue = analogRead(A5);
  float temp=sensorValue/11.8777;
  delay(2500);
  return temp;
}

void printSerialData()
{
 while(myGsm.available()!=0)
 Serial.write(myGsm.read());
}
