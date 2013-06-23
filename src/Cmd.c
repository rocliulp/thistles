/*
 * @author Paul
 */

#ifndef _CMD_C_
#define _CMD_C_

#include <stddef.h>
#include <stdlib.h>

#include <ErrorCodes.h>

struct Cmd {
  int (*pfCmd_Delete) (struct Cmd ** pCmd);
  int (*pfCmd_Run) (struct Cmd * pCmd);
};

int Cmd_virtualDelete (struct Cmd ** ppCmd) {
  if (ppCmd == NULL) return EC_NULL_POINTER;
  struct Cmd * pCmd = * ppCmd;
  if (pCmd == NULL) return EC_NULL_POINTER;
  free (pCmd);
  return EC_OK;
}

int Cmd_New (struct Cmd ** ppCmd) {
  if (ppCmd == NULL) return EC_NULL_POINTER;
  struct Cmd * pCmd  = (struct Cmd *) malloc (sizeof (struct Cmd));
  if (pCmd == NULL) {
    return EC_OUT_OF_MEMORY;
  }
  pCmd -> pfCmd_Delete = Cmd_virtualDelete;
  pCmd -> pfCmd_Run = NULL;
  * ppCmd = pCmd;
  return EC_OK;
}

int Cmd_Delete (struct Cmd ** ppCmd) {
  if (ppCmd == NULL) return EC_NULL_POINTER;
  struct Cmd * pCmd = * ppCmd;
  if (pCmd == NULL) return EC_NULL_POINTER;
  if (pCmd -> pfCmd_Delete == NULL) return EC_NULL_POINTER;
  return (* (pCmd -> pfCmd_Delete)) (ppCmd);
}

int Cmd_Run (struct Cmd * pCmd) {
  if (pCmd == NULL) return EC_NULL_POINTER;
  if (pCmd -> pfCmd_Run == NULL) return EC_NULL_POINTER;
  return (* (pCmd -> pfCmd_Run)) (pCmd);
}

#endif
