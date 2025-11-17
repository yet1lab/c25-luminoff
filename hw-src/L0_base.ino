//=======================================================
//                  CONTROL VARIABLES
//=======================================================
#define CLASS 4
#define RELAY 10 //
#define BUTTON 20 // RX

esp_timer_handle_t pressTimer, unlockTimer;

//=======================================================
char* DAYS[] = {
  "sun","mon", "tue", "wed", "thu", "fri", "sat"
};
