

volatile uint8_t  flag0 = 0;
volatile uint8_t  flag1 = 0;
volatile uint8_t  flag2 = 0;
volatile uint8_t  flag3 = 0;
volatile uint8_t  flag4 = 0;
volatile uint8_t  flag5 = 0;
int b1 =31;
int b2 = 17;
unsigned long prosloVreme=0;
void setup() {

  DDRD = 0x00;
  PORTD = 0x04;

DDRC = 0x1F;
PORTC =0x0C;

EICRA |= (1<<ISC01);
EICRA |= ~(1<<ISC00);

// INT 0 intterupt

EIMSK |= (1<<INT0);

sei();
Serial.begin(9600);
}

void loop() {

  if(flag0){

  if(millis()-prosloVreme >=1000 && b1!=0)
  {

    b1++;
    prosloVreme=millis();
    Serial.println(b1);
  }
  if(b1==31){
    b1=31;
    flag0=0;
    flag1=1;
    prosloVreme=0;
  }
  
  }
   
  if(flag1){
    treperenjes1();
    treperenjes1();
    treperenjes1();
    treperenjes1();
    treperenjes2();
    treperenjes2();;
    promenaSvetla();

    flag1=0;
    flag2=1;
  }
   
  if(flag2){
    if(millis()- prosloVreme >= 1000 && b2!=0){

      b2++;
      prosloVreme=millis();
      Serial.println(b2);
    }
    if(b2==17){
      flag2=0;
      flag3=1;
      b2=17;
    }
  }

  if(flag3){
    treperenjep1();
    treperenjep1();
    treperenjep1();
    treperenjep1();
    promenaP();
    promenaSvetla2();
    flag3=0;
  }

}

    
    
void treperenjes1(){

    delay(1000);
   PORTC &= ~(1<<2);
   delay(1000);
   PORTC |= (1<<2);
}
void treperenjes2(){
 PORTC &= ~(1<<2);
 PORTC |= (1<<1);
 delay(1000);
 PORTC &= ~(1<<1);
 delay(1000);
 PORTC |= (1<<1);

}

void treperenjep1(){
 delay(1000);
   PORTC &= ~(1<<4);
   delay(1000);
   PORTC |= (1<<4);
  
}
void promenaP(){

PORTC &= ~(1<<4);
PORTC |= (1<<3); 
}

void promenaSvetla(){
PORTC &= ~(1<<1);
PORTC |= (1<<0);
PORTC &= ~(1<<3);
PORTC |= (1<<4);
  
}
void promenaSvetla2(){

 PORTC &=~(1<<0);
 PORTC |=(1<<1);
 delay(1000);
 PORTC &=~(1<<1);
 delay(1000);
 PORTC |=(1<<2);

  
}


ISR(INT0_vect){

  flag0 = 1;
}
