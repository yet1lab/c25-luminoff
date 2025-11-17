//======================================================
//                   ASYNC TIMERS
//======================================================
void longPress(void* arg) {
  btnState = Long_Press;
  digitalWrite(RELAY, LOW);
}

void unlockButton(void* arg) { btnLocked = false; }
//------------------------------------------------------
const esp_timer_create_args_t unlockTimer_args = {
  .callback = &unlockButton,
  .arg = nullptr,
  .dispatch_method = ESP_TIMER_TASK,
  .name = nullptr
};
const esp_timer_create_args_t pressTimer_args = {
  .callback = &longPress,
  .arg = nullptr,
  .dispatch_method = ESP_TIMER_TASK,
  .name = nullptr
};
