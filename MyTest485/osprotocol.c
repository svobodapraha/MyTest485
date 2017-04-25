#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "osprotocol.h"

FILE  *ProtocolLogFile = NULL;
const char  *ProtocolLogFileName = "OSprotocolLog.log";


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

int fnMessageAssembled(char *ReceivedMessage)
{
   fprintf( stderr, "Message: %s", ReceivedMessage+1);
   return 0;
}
