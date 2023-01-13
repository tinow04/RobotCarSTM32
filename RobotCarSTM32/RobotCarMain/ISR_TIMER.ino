// LED is blinking while driving back
// This method is called when driving back the timer is up (every 0.5s)

void ISR_Timer(void)
{
    toggle = !toggle;           // toggle Bit High / Low
    digitalWrite(LED, toggle);  // LED is blinking
}
