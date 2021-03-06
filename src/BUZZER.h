using namespace std;

#ifndef BUZZER_INIT_H
#define BUZZER_INIT_H true

#include <Arduino.h>

class BUZZER {
  private:
    byte __pin;
    bool __isEnable;
    void __end(uint32_t);
    void __toneStart(uint32_t);
    void __toneEnd();
    void __delay(uint32_t, uint32_t = 0);

  public:
    BUZZER(byte);
    ~BUZZER();

    void setEnable(bool);
    
    void question(uint32_t = 0);
    void no(uint32_t = 0);
    void ok(uint32_t = 0);
    void cancel(uint32_t = 0);
    void alarm(uint32_t = 0);
    void done(uint32_t = 0);
    void refuse(uint32_t = 0);
    void ping(uint32_t = 0);
    void pong(uint32_t = 0);
    void in(uint32_t = 0);
    void out(uint32_t = 0);
};

#endif