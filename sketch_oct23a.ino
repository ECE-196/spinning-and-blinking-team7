const unsigned int LED = 17;    // Define the pin for the LED (optional)
const unsigned int MTR_HI = 15;  // Pin to control the high side of the motor
const unsigned int MTR_LO = 16; // Pin to control the low side of the motor

// speed and direction control
int base_value = 0;     // PWM value starts at 0 
int step_value_for_base_value = 5; // (adjust for smoothness)
int time_for_delay = 19;   //  (adjust for faster or slower oscillation)

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(MTR_HI, OUTPUT);
    pinMode(MTR_LO, OUTPUT);

    analogWrite(MTR_HI, base_value); 
    analogWrite(MTR_LO, 0);        
}

void loop() {
        digitalWrite(LED, HIGH); // turn the LED on
      delay(150); // wait 1 second
      digitalWrite(LED, LOW); // turn the LED off
      delay(150); // wait 1 second    
    
    
    while (base_value <= 255) {
        analogWrite(MTR_HI, base_value); // Increase torque in forward direction
        analogWrite(MTR_LO, 0);        
        base_value += step_value_for_base_value;      // Increase the value 
        delay(time_for_delay); 
            // Increase the PWM value to smoothly accelerate the motor forward
        
    }

    // Decrease the PWM value to smoothly decelerate the motor and stop
    while (base_value >= 0) {
        analogWrite(MTR_HI, base_value); // Decrease torque in forward direction
        analogWrite(MTR_LO, 0);        // MTR_LO stays LOW for forward
        base_value -= step_value_for_base_value;      // Decrease PWM value
        delay(time_for_delay);              // Delay for smooth transition
    }
        digitalWrite(LED, HIGH); // turn the LED on
      delay(150); // wait 1 second
      digitalWrite(LED, LOW); // turn the LED off
      delay(150); // wait 1 second    
    
    while (base_value <= 255) {
        analogWrite(MTR_HI, 0);        // MTR_HI is LOW for reverse direction
        analogWrite(MTR_LO, base_value); // Increase torque in reverse direction
        base_value += step_value_for_base_value;      // Increase PWM value
        delay(time_for_delay);              // Delay for smooth transition

    }

    // Decrease the PWM value to smoothly decelerate the motor and stop in reverse
    while (base_value >= 0) {
        analogWrite(MTR_HI, 0);        // MTR_HI is LOW for reverse direction
        analogWrite(MTR_LO, base_value); // Decrease torque in reverse direction
        base_value -= step_value_for_base_value;      // Decrease PWM value
        delay(time_for_delay);              // Delay for smooth transition

    }

}
