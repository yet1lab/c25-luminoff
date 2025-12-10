//======================================================
//                   ASYNC TIMERS
//======================================================
class Task {
private:
  esp_timer_handle_t timer;
  esp_timer_create_args_t args;

public:
  static inline std::set<Task*> TASKS{};

  Task(esp_timer_cb_t fn) {
    args = esp_timer_create_args_t {
      .callback = fn,
      .arg = nullptr,
      .dispatch_method = ESP_TIMER_TASK,
      .name = nullptr
    };
    Task::TASKS.insert(this);
  }

  void run()                      { args.callback(args.arg); }
  void runIn(uint64_t delay_us)   { esp_timer_start_once(timer, delay_us); }
  void loopIn(uint64_t period_us) { esp_timer_start_periodic(timer, period_us); }
  void stop()                     { esp_timer_stop(timer); }
  
  static void setup(){
    for (auto &task : TASKS){
      esp_timer_create(&task->args, &task->timer);
    }
  }
};
