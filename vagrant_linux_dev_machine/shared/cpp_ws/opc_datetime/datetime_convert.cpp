#include <iostream>
#include <stdexcept>
#include <open62541/server.h>
#include <open62541/types.h>

// Function to convert ISO datetime string to UA_DateTime
UA_DateTime isoToUADateTime(const char* isoDateTime) {
     int year, month, day, hour, minute, second;
     UA_DateTimeStruct ts;
     ts.milliSec = 0;
     ts.microSec = 0;
     ts.nanoSec = 0;
     if (sscanf(isoDateTime, "%hu-%hu-%huT%hu:%hu:%hu", &ts.year, &ts.month, &ts.day, &ts.hour, &ts.min, &ts.sec) != 6) {
       throw std::runtime_error("Invalid ISO datetime format");
     }
    
    // Create a UA_DateTime value
    UA_DateTime uaDateTime = UA_DateTime_fromStruct(ts);
    return uaDateTime;
}

int main() {
  const char* isoDateTime = "2019-11-14T03:52:34";
  const char* hasToFail   = "2024.06.11-15:26:03";
  try {
    UA_DateTime uaDateTime = isoToUADateTime(isoDateTime);
    UA_String out = UA_STRING_NULL;
    UA_print(&uaDateTime, &UA_TYPES[UA_TYPES_DATETIME], &out);
    std::cout << "UA_DateTime: " << out.data << std::endl;
    
    UA_DateTime uaDateTimeFailing = isoToUADateTime(hasToFail);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return 0;
}
