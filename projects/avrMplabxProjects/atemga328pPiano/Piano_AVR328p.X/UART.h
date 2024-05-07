

void UART_init();							//start USART AVR asynchronous, 8 bits, 9600 baudios,
unsigned char UART_read();					//UART reception
void UART_write(unsigned char);				//UART transmision

void UART_init()
{
	DDRD |= (1<<1);							//PD1	PIN OUTPUT TXa
	DDRD &= ~(1<<0);						//PD0	PIN INPUT  RX
	UCSR0A = (0<<TXC0)|(0<<U2X0)|(0<<MPCM0);
	UCSR0B = (1<<RXCIE0)|(0<<TXCIE0)|(0<<UDRIE0)|(1<<RXEN0)|(1<<TXEN0)|(0<<UCSZ02)|(0<<TXB80);
	UCSR0C = (0<<UMSEL01)|(0<<UMSEL00)|(0<<UPM01)|(0<<UPM00)|(0<<USBS0)|(1<<UCSZ01)|(1<<UCSZ00)|(0<<UCPOL0);
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;							
}

unsigned char UART_read(){
	if(UCSR0A&(1<<7)){			
		return UDR0;			
	}
	else
	return 0;
}

void UART_write(unsigned char caracter){
	while(!(UCSR0A&(1<<5)));    
	UDR0 = caracter;            
}

void UART_write_txt(char* cadena){			
	while(*cadena !=0x00){				
		UART_write(*cadena);			
		cadena++;						
										
	}
}


