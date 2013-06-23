/*
 * @author Paul
 */

#ifndef _CMD_H_
#define _CMD_H_

struct Cmd;
int Cmd_New (struct Cmd ** ppCmd);
int Cmd_Delete (struct Cmd ** ppCmd);
int Cmd_Run (struct Cmd * pCmd);

#endif
