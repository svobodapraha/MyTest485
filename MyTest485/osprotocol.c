#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "osprotocol.h"

FILE  *ProtocolLogFile = NULL;
const char  *ProtocolLogFileName = "OSprotocolLog.log";
TOs2DhLSet Os2DhLSet;

int fnInit(void)
{
    //u8NodeId = NODE_ID;
    //eCommStatus = comclst_ClientInit;
    ProtocolLogFile = NULL;
    ProtocolLogFile =  fopen(ProtocolLogFileName, "a+");


    if(ProtocolLogFile != NULL)
    {
        fprintf(ProtocolLogFile, "ProgramStart");
        return 0;
    }
    else
    {
        return -1;
    }
    return 0;
}

int fnDeInt(void)
{
    if(ProtocolLogFile != NULL)
    {

        fprintf(ProtocolLogFile, "ProgramStop");
        fclose(ProtocolLogFile);
    }

    return 0;
}

int fnMessageAssembled(char *ReceivedMessage, int iMessageSize)
{
   fprintf( stderr, "Message: %s", ReceivedMessage+1);
   //message type
   if(iMessageSize > 2)
   {
       switch (ReceivedMessage[1])
       {
          case OS_CHAR_OS2DH_LNSET:
           if (iMessageSize == (sizeof(TOs2DhLSet) + (MESSAGE_OVERHEAD_SIZE - 1)))
           {
              memset(&Os2DhLSet, 0,               sizeof(TOs2DhLSet));
              memcpy(&Os2DhLSet, ReceivedMessage+2, sizeof(TOs2DhLSet)-1);
              fprintf( stderr, ";  I: %s", (char *)&Os2DhLSet);
           }
          break;
//          case value:

//          break;
//          case value:

//          break;
          default:
           break;
       }

   }



   return 0;
}
