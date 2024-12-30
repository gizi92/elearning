#include <open62541/client_config_default.h>
#include <open62541/client_highlevel.h>
#include <open62541/plugin/log_stdout.h>

int main(void) {
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                    "PROGRAM START");

    UA_Client *client = UA_Client_new();
    UA_ClientConfig_setDefault(UA_Client_getConfig(client));
    UA_ClientConfig_setAuthenticationUsername(UA_Client_getConfig(client), "user1", "password");
    UA_EndpointDescription *endpoints = NULL;
    unsigned long int endpointCount = 0;
    UA_StatusCode retval = UA_Client_getEndpoints(client, "opc.tcp://192.168.56.10:4840", &endpointCount, &endpoints);
    UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                    "Getting Endpoints successful. Status code %s, %ld",
                    UA_StatusCode_name(retval), endpointCount);

    UA_Client_delete(client); /* Disconnects the client internally */

    // if(retval != UA_STATUSCODE_GOOD) {
    //     UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
    //                 "The connection failed with status code %s",
    //                 UA_StatusCode_name(retval));
    //     UA_Client_delete(client);
    //     return 0;
    // }
    // UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
    //                 "Getting Endpoints successful. Status code %s",
    //                 UA_StatusCode_name(retval));

    // retval = UA_Client_connect(client, "opc.tcp://192.168.56.10:4840");
    // if(retval != UA_STATUSCODE_GOOD) {
    //     UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
    //                 "The connection failed with status code %s",
    //                 UA_StatusCode_name(retval));
    //     UA_Client_delete(client);
    //     return 0;
    // }
    // else {
    //   UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
    //                 "Client Connection successfull!");
    // }

    // /* Clean up */
    // UA_Client_delete(client); /* Disconnects the client internally */
    return 0;
}