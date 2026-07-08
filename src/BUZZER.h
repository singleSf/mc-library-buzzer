#ifndef BUZZER_INIT_H
#define BUZZER_INIT_H

#include <Arduino.h>

class BUZZER {
  private:
    uint8_t  __pin;
    bool     __isEnable;

    void __end(uint16_t);
    void __toneStart(uint16_t);
    void __toneEnd();
    void __delay(uint16_t, uint16_t = 0);

  public:
    explicit BUZZER(uint8_t);
    ~BUZZER();

    void setEnable(bool);

    // --- Системные уведомления ---
    void startup(uint16_t = 0);  // Приветственный мажорный аккорд (включение)
    void ok(uint16_t = 0);       // Подтверждение, короткий подъем частоты
    void done(uint16_t = 0);     // Завершение задачи, двухтональный сигнал
    void ping(uint16_t = 0);     // Одиночный средний импульс
    void pong(uint16_t = 0);     // Одиночный низкий импульс
    void scan(uint16_t = 0);     // Двойной быстрый "пик" (успешное чтение)
    void key(uint16_t = 0);      // Глухой щелчок (имитация нажатия клавиши)
    void notify(uint16_t = 0);   // Трель вверх (внимание, сообщение)
    void click(uint16_t = 0);    // Механический двойной щелчок

    // --- Ошибки и предупреждения ---
    void no(uint16_t = 0);       // Отрицание, два низких гудка
    void cancel(uint16_t = 0);   // Отмена, каскад частот вниз
    void refuse(uint16_t = 0);   // Жесткий отказ, 5 резких гудков
    void error(uint16_t = 0);    // Ошибка, длинный низкий тон
    void lowBat(uint16_t = 0);   // Разряд батареи, высокий и низкий тон
    void critical(uint16_t = 0); // Критическая тревога, быстрые резкие гудки
    void alarm(uint16_t = 0);    // Сирена, плавное нарастание и спад

    // --- Интерактивные эффекты ---
    void question(uint16_t = 0); // Вопрос, три ступени вверх
    void sleep(uint16_t = 0);    // Уход в сон, три длинных затухающих тона
    void in(uint16_t = 0);       // Плавный логарифмический подъем (вход в меню)
    void out(uint16_t = 0);      // Плавный логарифмический спуск (выход из меню)
};

#endif
