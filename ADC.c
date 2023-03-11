#include <16f887.h>
#device *=16 adc =10
#FUSES HS, NOWDT, NOPUT, NOLVP
#use delay(clock =8M)
#include <lcd.h>
unsigned int16 GIA_TRI =0;

void main()
{
    set_tris_a(0x00);
	set_tris_b(0x00);
	set_tris_c(0x00);
    set_tris_d(0x00);
    set_tris_e(0xFF);

    SETUP_ADC(ADC_CLOCK_INTERNAL);
    SETUP_ADC_PORTS(ALL_ANALOG);
    lcd_init();
    delay_ms(20);
    lcd_gotoxy(1,1);
    printf(lcd_putc,"AD10Bit");
   
    //output_b(0x00);
    while(TRUE)
        { 
		
        SET_ADC_CHANNEL(5);
        GIA_TRI=READ_ADC();
        lcd_gotoxy(9,1);
        printf(lcd_putc, "REO: %lu",GIA_TRI);
        
        if(GIA_TRI < 100)
		{
		output_b(0x01);
		}

		if( 200 > GIA_TRI && GIA_TRI >= 100)
		{
		output_b(0x02);
		}

		if( 300  >= GIA_TRI && GIA_TRI >= 200)
		{
		output_b(0x04);
		}

        if(400 >= GIA_TRI && GIA_TRI > 300)
		{
		output_b(0x08);
		}

		if(500 >= GIA_TRI && GIA_TRI > 400)
		{
		output_b(0x10);
		}

		if(600 >= GIA_TRI && GIA_TRI > 500)
		{
		output_b(0x20);
		}
		if(700 >= GIA_TRI && GIA_TRI > 600)
		{
		output_b(0x40);
		}

		if(800 >= GIA_TRI && GIA_TRI > 700)
		{
		output_b(0x80);
		}
		if(900 >= GIA_TRI && GIA_TRI > 800)
		{
		output_b(0xff);
		delay_ms(100);
		output_b(0x00);
		delay_ms(100);
		}
		if(GIA_TRI > 900)
		{
		output_b(0xff);
		}


        GIA_TRI=GIA_TRI-GIA_TRI;
        SET_ADC_CHANNEL(6);
        GIA_TRI=READ_ADC(); 
        lcd_gotoxy(9,2);
        printf(lcd_putc, "RE1: %lu",GIA_TRI);
		
		if(GIA_TRI < 100)
		{
		output_c(0x01);
		}

		if( 200 > GIA_TRI && GIA_TRI >= 100)
		{
		output_c(0x02);
		}

		if( 300  >= GIA_TRI && GIA_TRI >= 200)
		{
		output_c(0x04);
		}

        if(400 >= GIA_TRI && GIA_TRI > 300)
		{
		output_c(0x08);
		}

		if(500 >= GIA_TRI && GIA_TRI > 400)
		{
		output_c(0x10);
		}

		if(600 >= GIA_TRI && GIA_TRI > 500)
		{
		output_c(0x20);
		}
		if(700 >= GIA_TRI && GIA_TRI > 600)
		{
		output_c(0x40);
		}

		if(800 >= GIA_TRI && GIA_TRI > 700)
		{
		output_c(0x80);
		}
		if(900 >= GIA_TRI && GIA_TRI > 800)
		{
		output_c(0xff);
		delay_ms(100);
		output_c(0x00);
		delay_ms(100);
		}
		if(GIA_TRI > 900)
		{
		output_c(0xff);
		}
    }
}