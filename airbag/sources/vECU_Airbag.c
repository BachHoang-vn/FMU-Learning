// define class name and unique id
#define MODEL_IDENTIFIER vECU_Airbag
#define MODEL_GUID "{8c4e810f-3df3-4a00-8276-176fa3c9f009}"

// define model size
#define FMI_COSIMULATION
#define NUMBER_OF_REALS 0
#define NUMBER_OF_INTEGERS 3
#define NUMBER_OF_BOOLEANS 0
#define NUMBER_OF_STRINGS 0
#define NUMBER_OF_STATES 0
#define NUMBER_OF_EVENT_INDICATORS 0

// include fmu header files, typedefs and macros
#include "fmu2Template.h"

// define all model variables and their value references
// conventions used here:
// - if x is a variable, then macro x_ is its variable reference
// - the vr of a variable is its index in array  r, i, b or s
// - if k is the vr of a real state, then k+1 is the vr of its derivative
#define PADS_ 0
#define PADL_ 1
#define PAEL_ 2

#define STATES { }

typedef enum
{
    Not_Turn_Off_PA = (fmi2Integer)0,
    Turn_Off_PA = (fmi2Integer)1
} PADS_state_type;

typedef enum
{
    Turn_Off_PADL = (fmi2Integer)0,
    Turn_On_PADL = (fmi2Integer)1
} PADL_state_type;

typedef enum
{
    Turn_Off_PAEL = (fmi2Integer)0,
    Turn_On_PAEL = (fmi2Integer)1
} PAEL_state_type;

// called by fmi2Instantiate
// Set values for all variables that define a start value
// Settings used unless changed by fmi2SetX before fmi2EnterInitializationMode
static void
setStartValues(ModelInstance *comp) {
    i(PADS_) = Not_Turn_Off_PA; //0: Not_Turn_Off_PA, 1: Turn_Off_PA
    i(PADL_) = Turn_Off_PADL; //0: Turn_Off_PADL, 1: Turn_On_PADL
    i(PAEL_) = Turn_On_PAEL; //0: Turn_Off_PAEL, 1: Turn_On_PAEL
}

// called by fmi2GetReal, fmi2GetInteger, fmi2GetBoolean, fmi2GetString, fmi2ExitInitialization
// if setStartValues or environment set new values through fmi2SetXXX.
// Lazy set values for all variable that are computed from other variables.
static void
calculateValues(ModelInstance *comp) {
    if (comp->state == modelInitializationMode) {
        // set first time event
        comp->eventInfo.nextEventTimeDefined   = fmi2True;
        comp->eventInfo.nextEventTime          = -1; //1 + comp->time;
    }
}

// used to set the next time event, if any.
static void
eventUpdate(ModelInstance *comp, fmi2EventInfo *eventInfo, int timeEvent, int isNewEventIteration) {
    switch((PADS_state_type)i(PADS_))
    {
        case Not_Turn_Off_PA:
            i(PADL_) = Turn_Off_PADL;
            i(PAEL_) = Turn_On_PAEL;
            break;
        case Turn_Off_PA:
            i(PADL_) = Turn_On_PADL;
            i(PAEL_) = Turn_Off_PAEL;
            break;
        default:
            // Do nothing
            break;
    }

}

// include code that implements the FMI based on the above definitions
#include "fmu2Template.c"
