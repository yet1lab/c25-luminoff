//======================================================
//                   ASYNC TIMERS
//======================================================
void turnOff(void* arg) {
  btnState = Long_Press;
  digitalWrite(RELAY, LOW);
}

void unlockButton(void* arg) { btnLocked = false; }
//------------------------------------------------------
const esp_timer_create_args_t offTimer_args = {
  .callback = &turnOff,
  .arg = nullptr,
  .dispatch_method = ESP_TIMER_TASK,
  .name = "offTimer"
};
const esp_timer_create_args_t unlockTimer_args = {
  .callback = &unlockButton,
  .arg = nullptr,
  .dispatch_method = ESP_TIMER_TASK,
  .name = "unlockTimer"
};