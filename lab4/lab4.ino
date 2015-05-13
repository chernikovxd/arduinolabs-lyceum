/*
*     Лабораторная работа 4
*     "Телега"
*     Автор:Черников И Туманов
*     Дата создания:13.05
*/
#define OUT1 6
#define OUT2 5
#define OUT3 10
#define OUT4 9
void setup(){
	pinMode(OUT1, OUTPUT);
	pinMode(OUT2, OUTPUT);
	pinMode(OUT3, OUTPUT);
	pinMode(OUT4, OUTPUT); 
}

void testDrive(int out1,int out2,int out3,int out4){
	digitalWrite(OUT1, out1);
	digitalWrite(OUT2, out2);
	digitalWrite(OUT3, out3);
	digitalWrite(OUT4, out4);

}

void LeftMotorForward(){
	digitalWrite(OUT1, LOW);
	digitalWrite(OUT2, HIGH);
}

void LeftMotorBackward(){
	digitalWrite(OUT2, LOW);
	digitalWrite(OUT1, HIGH);
}

void RightMotorForward(){
	digitalWrite(OUT3, LOW);
	digitalWrite(OUT4, HIGH);
}

void RightMotorBackward(){
	digitalWrite(OUT4, LOW);
	digitalWrite(OUT3, HIGH);
}

void LeftMotorStop(){
	digitalWrite(OUT1, LOW);
	digitalWrite(OUT2, LOW);
}

void RightMotorStop(){
	digitalWrite(OUT3, LOW);
	digitalWrite(OUT4, LOW);
}

void LeftMotorForwardPWM(byte pwmDuty){
	digitalWrite(OUT1, LOW);
	analogWrite(OUT2, pwmDuty);
}

void RightMotorForwardPWM(byte pwmDuty){
	digitalWrite(OUT3, LOW);
	analogWrite(OUT4, pwmDuty);
}

void LeftMotorBackwardPWM(byte pwmDuty){
	digitalWrite(OUT2, LOW);
	analogWrite(OUT1, pwmDuty);
}

void RightMotorBackwardPWM(byte pwmDuty){
	digitalWrite(OUT4, LOW);
	analogWrite(OUT3, pwmDuty);
}

void loop(){
	RightMotorForward(250);
	LeftMotorForward(250);
	delay(2000);
	RightMotorBackward(120);
	LeftMotorBackward(120);
	delay(2000);

}
