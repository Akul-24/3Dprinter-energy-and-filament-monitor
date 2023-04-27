//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Read Voltage & Current

void readVoltage() {
  int A0Value = analogRead(34);
  voltage_sensed = A0Value * (arduinoVCC / (float)inputResolution) + 0.134;
  voltage = voltage_sensed * ( 1 + ( (float) ValueR2 /  (float) ValueR1) );
}

float getVoltageAverage() {
  float voltage_temp_average = 0;
  for (int i = 0; i < average_of; i++)
  {
    readVoltage();
    voltage_temp_average += voltage;
  }

  return voltage_temp_average / average_of;
}

void readCurrent() {
  float QOV =   0.5 * VCC;
  float voltage_raw =   ((VCC / 4095.0) * analogRead(32)) + 0.134;
  cvoltage =  voltage_raw - QOV + 0.000 ;  // 0.000 is a value to make voltage zero when there is no current

  Current = (cvoltage - 0.00) * (23.60 - 0.00) / (1.65 - 0.00) + 0.00;
  if (Current < 1.00){
    Current = Current / (2.5 - Current);
  }

}

float getCurrentaverage() {
  float current_temp_average = 0;
  for (int k = 0; k < 500; k++) {
    readCurrent();
    current_temp_average += Current;
  }
  return current_temp_average / 500;
}
