/*
 * @author Paul
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include <ErrorCode.h>
#include <String.h>
#include <Logger.h>
#include <ErrMsg.h>

int main (int argc, char ** argv) {
  int ret = 0;
  struct Logger * pLogger = NULL;
  ret = Logger_New (& pLogger);
  if (ret != EC_OK) {
    printf (FAILED_CREATING_LOGGER);
    return ret;
  }
  struct String pString = NULL;
  ret = String_New (& pString);
  if (ret != EC_OK) {
    printf (FAILED_CREATING_STRING);
    return ret;    
  }

  pid_t pid;
  pid = fork ();
  if (pid < 0) {
    printf (FAILED_FORKING);
    return EC_FAILED_INVOKING_FUN; 
  } else if (pid == 0) {
    printf ("Child process.");
    return EC_OK;
  } else if (pid > 0) {
    printf ("Parent process.");
    return EC_OK;
  } else {
    printf ("Impossible case.");
    return EC_IMPOSSIBLE_CASE;
  }
  
  ret = Logger_Delete (pLogger);
  if (ret != EC_OK) {
    printf (FAILED_CLEARING_LOGGER);
    return ret;
  }
  ret = String_Delete (pString);
  if (ret != EC_OK) {
    printf (FAILED_CLEARING_STRING);
    return ret;
  }

  return EC_OK;
}
