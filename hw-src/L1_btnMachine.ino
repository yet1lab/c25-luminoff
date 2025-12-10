//======================================================
//             BUTTON STATES AND TASKS
//======================================================
enum BTN_STATE {
  Long_Press, Short_Press,
  Long_Release, Short_Release
};

volatile bool btnLocked = false;
volatile BTN_STATE btnState = Short_Release;
//======================================================
//                   ASYNC TASKS
//======================================================
Task pressTask([](void* arg) {
  btnState = Long_Press;
  digitalWrite(RELAY, LOW);
});

Task unlockTask([](void* arg){
  btnLocked = false;
});
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
      unlockTask.runIn(500); // 500 us
      pressTask.runIn(1000000); // 1 sec
      break;

    case Short_Release:
      pressTask.stop();
      digitalWrite(RELAY, HIGH);
      unlockTask.runIn(50000); // 50 ms
      break;

    case Long_Release:
      pressTask.stop();
      unlockTask.runIn(50000); // 50 ms
      break;
  }
}
