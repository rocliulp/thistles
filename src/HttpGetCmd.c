/*
 * @author Paul
 */

#ifndef _HTTP_GET_CMD_C_
#define _HTTP_GET_CMD_C_

#include <HttpGetCmd.h>

struct HttpGetCmd {
  struct Cmd _base;
};

int HttpGetCmd_virtualRun (struct Cmd * pHttpGetCmd) {
}

int HttpGetCmd_New (struct Cmd ** ppHttpGetCmd) {
  if (ppHttpGetCmd == NULL) return EC_NULL_POINTER;
  int ret = Cmd_New (ppHttpGetCmd);
  if (ret != EC_OK) return ret;
  (* ppHttpGetCmd) -> pfCmd_Run = HttpGetCmd_virtualRun;
  return EC_OK;
}

#endif
