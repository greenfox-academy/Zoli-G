extern UART_HandleTypeDef UartHandle;

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

void UART_Config(void);

PUTCHAR_PROTOTYPE {
    HAL_UART_Transmit(&UartHandle, (uint8_t *) &ch, 1, 0xFFFF);
    return ch;
}
