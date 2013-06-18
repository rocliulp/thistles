/*
 * @author Paul
 */

#include <stdio.h>
#include <string.h>

#include <ErrorCodes.h>

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
    
    if (strcmp (cmd, CMD_EXIT) == 0) {
      break;
    } else if (strcmp (cmd, CMD_HTTP) == 0) {
      printf ("%s%s", CMD_PROMPT_NOT_IMPLEMENTED, STR_NEW_LINE);
    } else {
      printf ("%s%s", CMD_PROMPT_INVALID_CMD, STR_NEW_LINE);
    }

    i = -1;
    while (++ i < CMD_CAPACITY) {
      cmd [i] = STR_END;
    }
  }

  return EC_OK;
}
