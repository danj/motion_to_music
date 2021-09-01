
/*
 * NodeMCU Control Code
 * 
 * 
 * Interface to Sparkfun Little Soundy
 * D0 - 00
 * D1 - 01
 * D2 - 02  
 * D8 - PB
 * 
 * D3 - Right hand sensor
 * D4 - Left hand sensor
 * D5 - GND
 * D6 - GND
 */

 
int o_sound_select_0 = D0;
int o_sound_select_1 = D1;
int o_sound_select_2 = D2;

int i_sensor_0 = D3;
int i_sensor_1 = D4;
int i_sensor_2 = D5;
int i_sensor_3 = D6;

int o_reset = D8;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(o_sound_select_0, OUTPUT);
  pinMode(o_sound_select_1, OUTPUT);
  pinMode(o_sound_select_2, OUTPUT);
  pinMode(o_reset, OUTPUT);

  pinMode(i_sensor_0, INPUT);
  pinMode(i_sensor_1, INPUT);
  pinMode(i_sensor_2, INPUT);
  pinMode(i_sensor_3, INPUT);

  Serial.begin(115200);
  Serial.println("Setting up outputs");
  
  digitalWrite(o_sound_select_0, LOW);
  digitalWrite(o_sound_select_1, LOW);
  digitalWrite(o_sound_select_2, LOW);

  Serial.println("Enabling");
  digitalWrite(o_reset, HIGH);
  delay(100);
  digitalWrite(o_reset, LOW); 
}

void loop() {  
  int s0 = digitalRead(i_sensor_0);
  int s1 = digitalRead(i_sensor_1);

  int ss0 = LOW;
  int ss1 = LOW;
  int d = 100;

  // print out the state of the button:
  Serial.print("left: ");
  Serial.print(s0);
  Serial.print(", Right: ");
  Serial.print(s1);
  Serial.print(" ");

  if ((s0 == 1) && (s1 == 1)) {
    
  }

  if ((s0 == 0) && (s1 == 1)) {
    ss0 = HIGH;
    d = 600;
  }

  if ((s0 == 1) && (s1 == 0)) {
    ss1 = HIGH;
    d = 838;
  }

  if ((s0 == 0) && (s1 == 0)) {
    ss0 = ss1 = HIGH;
    d = 3290;
  }

  digitalWrite(o_sound_select_0, ss0);
  digitalWrite(o_sound_select_1, ss1);
  Serial.print(ss0);
  Serial.print(",");
  Serial.print(ss1);
  Serial.print(",");
  Serial.print(d);
  Serial.println();
  delay(d);
}
