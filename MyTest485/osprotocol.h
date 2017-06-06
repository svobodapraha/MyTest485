#ifndef OSPROTOCOL_H
#define OSPROTOCOL_H


#define MESSAGE_OVERHEAD_SIZE           4
#define OS_CHAR_OS2DH_LNSET             ('I')


typedef struct _Os2DhLSet
{
  char wh;
  char wl;
  char xh;
  char xl;
  char yh;
  char yl;
  char sep;
} TOs2DhLSet;






#ifdef __cplusplus
 extern "C" {
 #endif

 int fnInit(void);
 int fnDeInt(void);
 int fnMessageAssembled(char *ReceivedMessage, int iMessageSize);


#ifdef __cplusplus
 }
#endif





#endif // OSPROTOCOL_H
