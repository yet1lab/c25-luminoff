//======================================================
//               BUTTON STATE MACHINE
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
      esp_timer_start_once(offTimer, 1000000); // 1 sec
      esp_timer_start_once(unlockTimer, 500); // 500 us
      break;

    case Short_Release:
      esp_timer_stop(offTimer);
      digitalWrite(RELAY, HIGH);
      esp_timer_start_once(unlockTimer, 50000); // 50 ms
      break;

    case Long_Release:
      esp_timer_stop(offTimer);
      esp_timer_start_once(unlockTimer, 50000); // 50 ms
      break;
  }
}