#ifndef UTIL_H
#define UTIL_H

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c);

enum State strtoState(string str);

bool isHaveSpecialChar(const char *Str);

bool existsFile (const std::string& name);

#endif
