//======================================================
//               BUTTON STATE MACHINE
//======================================================
enum BTN_STATE {
  Long_Press, Short_Press,
  Long_Release, Short_Release
};

volatile bool btnLocked = false;
volatile BTN_STATE btnState = Short_Release;
//======================================================
void IRAM_ATTR btnMachine() {
  if (btnLocked) return;
  btnLocked = true;

// MACHINE STATE TRANSITION
  switch (btnState) {
    case Long_Press:    btnState = Long_Release  ; break;
    case Short_Press:   btnState = Short_Release ; break;
    case Long_Release:  btnState = Short_Press   ; break;
    case Short_Release: btnState = Short_Press   ; break;
  }

// MACHINE STATE EXECUTION
  switch (btnState) {
    case Short_Press:
      esp_timer_start_once(unlockTimer, 500); // 500 us
      esp_timer_start_once(pressTimer, 1000000); // 1 sec
      break;

    case Short_Release:
      esp_timer_stop(pressTimer);
      digitalWrite(RELAY, HIGH);
      esp_timer_start_once(unlockTimer, 50000); // 50 ms
      break;

    case Long_Release:
      esp_timer_stop(pressTimer);
      esp_timer_start_once(unlockTimer, 50000); // 50 ms
      break;
  }
}