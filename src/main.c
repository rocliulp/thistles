/*
 * @author Paul
 */

#include <stdio.h>
#include <string.h>

#include <ErrorCodes.h>
#include <Cmd.h>

int main (int argc, char ** argv) {
  int ret = 0;
  char cmd [CMD_CAPACITY] = {STR_END};
  int cmdLen = 0;

  while (B_TRUE) {
    int i = -1;

    printf ("%s: ", CMD_PROMPT);

    scanf ("%s", cmd);
    cmdLen = strlen (cmd);
    if (cmdLen >= CMD_CAPACITY) {
      cmd [CMD_CAPACITY - 1] = STR_END;
      cmdLen = CMD_CAPACITY - 1;
    }
    while (cmd [++ i] != STR_END) {
      cmd [i] = toupper (cmd [i]);
    }

    struct Cmd * pCmd = NULL;    
    if (strcmp (cmd, CMD_EXIT) == 0) {
      break;
    } else if (strcmp (cmd, CMD_HTTP_GET) == 0) {
      ret = Cmd_New (& pCmd);
      if (ret != EC_OK) {
        printf ("Failed creating Cmd.");
      }
    } else {
      printf ("%s%s", CMD_PROMPT_INVALID_CMD, STR_NEW_LINE);
    }
    if (pCmd != NULL) {
      ret = Cmd_Run (pCmd);
      if (ret != EC_OK) {
        printf ("%s%s.%s", CMD_PROMPT_FAILED_RUNNING_CMD, cmd, STR_NEW_LINE);
      }
      ret = Cmd_Delete (& pCmd);
      if (ret != EC_OK) {
        printf ("%s%s", CMD_PROMPT_FAILED_DESTROYING_CMD, STR_NEW_LINE);
      }
    }

    i = -1;
    while (++ i < CMD_CAPACITY) {
      cmd [i] = STR_END;
    }
  }

  return EC_OK;
}
