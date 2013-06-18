/*
 * @author Paul
 */

#ifndef _ERROR_CODE_H_
#define _ERROR_CODE_H_

#define CONST

#define B_TRUE 1
#define B_FALSE 0

#define STR_END '\0'
#define STR_NEW_LINE "\n"

#define CMD_CAPACITY 1024
#define CMD_PROMPT "CMD"
#define CMD_PROMPT_INVALID_CMD "Invalid command."
#define CMD_PROMPT_NOT_IMPLEMENTED "Command is not implemented."
#define CMD_EXIT "EXIT"
#define CMD_HTTP "HTTP"
#define CMD_HTTP_OPTIONS "OPTIONS"
#define CMD_HTTP_GET "GET"
#define CMD_HTTP_HEAD "HEAD"
#define CMD_HTTP_POST "POST"
#define CMD_HTTP_PUT "PUT"
#define CMD_HTTP_DELETE "DELETE"
#define CMD_HTTP_TRACE "TRACE"
#define CMD_HTTP_CONNECT "CONNECT"

#define EC_OK 0x0000
#define EC_IMPOSSIBLE_CASE 0x0001
#define EC_FAILED_INVOKING_FUN 0x0002;
#define EC_NOT_IMPLEMENTED 0x0003;

#endif
