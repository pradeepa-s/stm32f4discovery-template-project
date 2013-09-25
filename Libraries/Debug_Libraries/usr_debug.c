#include "usr_debug.h"

/***********************************************************************
Re-targets the standard printf call and use USART to execute it
***********************************************************************/

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  USART_SendData(USART, (uint8_t) ch);

  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(USART, USART_FLAG_TC) == RESET)
  {}

  return ch;
}