#pragma once

#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

bool validPort(const char *port);
bool hasNumber(const std::string &string);
bool hasSpecial(const std::string &string);
bool validPassword(const std::string &password);

#endif