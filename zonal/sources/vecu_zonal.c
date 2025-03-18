#define MODEL_IDENTIFIER vecu_zonal
#define MODEL_GUID "{8c4e810f-3df3-4a00-8276-176fa3c9f003}"

// define model size
#define FMI_COSIMULATION
#define NUMBER_OF_REALS 0
#define NUMBER_OF_INTEGERS 4
#define NUMBER_OF_BOOLEANS 2
#define NUMBER_OF_STRINGS 0
#define NUMBER_OF_STATES 0
#define NUMBER_OF_EVENT_INDICATORS 0

#include "fmu2Template.h"
typedef enum {
    NoConfirm   = (fmi2Integer)0,
    Enable      = (fmi2Integer)1,
    Disable     = (fmi2Integer)2
} UserConfirmAbState;

typedef enum {
    NoWarning     = (fmi2Integer)0,
    WarningLevel1 = (fmi2Integer)1,
    WarningLevel2 = (fmi2Integer)2
} PassensgerAbWarningState;

typedef enum {
    IsEnable  = (fmi2Integer)0,
    IsDisable = (fmi2Integer)1
} PassensgerAbIsEnable;

#define In_PassengerAirbagWarningState_se   0
#define Out_PassengerAirbagWarningState_se  1

#define In_PassengerAirbagIsDisabled_bo      0
#define Out_PassengerAirbagDeactivationSwitch_bo 1

#define In_UserConfirmAirbagState_se        2      
#define Out_UserConfirmAirbagState_se       3

#define STATES { }

void setStartValues(ModelInstance *comp)
{
    b(In_PassengerAirbagIsDisabled_bo)      = fmi2False;
    b(Out_PassengerAirbagDeactivationSwitch_bo) = fmi2False;
    i(In_PassengerAirbagWarningState_se)   = NoWarning;
    i(Out_PassengerAirbagWarningState_se)  = NoWarning;
    i(In_UserConfirmAirbagState_se)        = NoConfirm;
    i(Out_UserConfirmAirbagState_se)       = NoConfirm;
}

void calculateValues(ModelInstance *comp) {
     if (comp->state == modelInitializationMode) {
        // set first time event
        comp->eventInfo.nextEventTimeDefined   = fmi2True;
        comp->eventInfo.nextEventTime          = -1; //1 + comp->time;
    }
}

void eventUpdate(ModelInstance *comp, fmi2EventInfo *eventInfo, int isTimeEvent, int isNewEventIteration)
{
    i(Out_PassengerAirbagWarningState_se)   = i(In_PassengerAirbagWarningState_se);
    i(Out_UserConfirmAirbagState_se)        = i(In_UserConfirmAirbagState_se);
    b(Out_PassengerAirbagDeactivationSwitch_bo) = b(In_PassengerAirbagIsDisabled_bo);

}

#include "fmu2Template.c"
