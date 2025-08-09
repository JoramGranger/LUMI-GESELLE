#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
#include "../config/config.h"

class Logger {
public:
    static void initialize();
    static void info(const String& message);
    static void error(const String& message);
    static void debug(const String& message);
};

#endif