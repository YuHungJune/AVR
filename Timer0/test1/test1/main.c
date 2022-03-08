
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect){
	//자동으로 0으로 변하지 않는다.
	TCNT1 = 0;
}

int main(void)
{
	//분주비를 1024로 설정
   TCCR1B |= (1 << CS12) | (1 << CS10);
   
   //비교일치 기준값
   OCR1A = 0x2000;
   
   //비교일치 인터럽트 발생 시 OC1A핀의 출력을 반전
   TCCR1A |= (1 << COM1A0);
   
   //PB1(OC1A)핀을 출력으로 설정
   DDRB = 0x01;	//PB1(OC1A)핀을 출력으로 설정
   
   //비교일치 인터럽트 허용
   TIMSK1 |= (1 << OCIE1A);
   
   //전역적으로 인터럽트 허용
   sei();	
   
   while(1){}

}

