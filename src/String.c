struct String {
};

int String_New (struct String ** ppString) {
  /*
   * @ TODO:
   */
  return EC_NOT_IMPLEMENTED;
};

int String_NewByChars (struct String ** ppString, char * const pChars) {
  return EC_NOT_IMPLEMENTED;
};

int String_NewByWChars (struct String ** ppString, wchar_t * const pWChars) {
  return EC_NOT_IMPLEMENTED;
};


int String_Delete (struct String * pString) {
  return EC_NOT_IMPLEMENTED;
};

int String_SetChars (struct String * pString, char * const pChars) {
  return EC_NOT_IMPLEMENTED;
};

int String_SetWChars (struct String * pString, wchar_t * const pWChars) {
  return EC_NOT_IMPLEMENTED;
};

int String_GetWChars (struct String * const pString, char ** ppChars) {
  return EC_NOT_IMPLEMENTED;
};
