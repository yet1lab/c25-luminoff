//======================================================
//             BUTTON STATES AND TASKS
//======================================================
enum LED_STATE {
  RED, BLUE, OFF, LOCK
};

volatile LED_STATE ledState = OFF;
//======================================================
//                   ASYNC TASKS
//======================================================
Task lockLedTask([](void* arg){
  ledState = LOCK;
});
//======================================================
//               BUTTON STATE MACHINE
//======================================================
Task ledMachineTask([](void* arg){
// MACHINE STATE TRANSITION
  switch (ledState) {
    case OFF:  ledState = RED  ; break;
    case RED:  ledState = BLUE ; break;
    case BLUE: ledState = RED  ; break;
    case LOCK: ledState = OFF  ; break;
  }

// MACHINE STATE EXECUTION
  switch (ledState) {
    case OFF:
      digitalWrite(R_LED, LOW);
      digitalWrite(B_LED, LOW);
      break;

    case RED:
      digitalWrite(R_LED, HIGH);
      digitalWrite(B_LED, LOW);
      break;

    case BLUE:
      digitalWrite(B_LED, HIGH);
      digitalWrite(R_LED, LOW);
      break;
  }
});
