#include <SPI.h>
#include <SD.h>

File root;

//CS    PIN 10
//MOSI  PIN 11
//MISO  PIN 12
//SCK   PIN 13

const int chipSelect = 10;

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    ; //Pause until serial monitor is opened
  }

  if (!SD.begin(10))
  {
    Serial.println("initialization failed!");
    while (1);
  }

  root = SD.open("/");
  dumpFilesInSerial(root);

}

void dumpFilesInSerial(File dir)
{
  while (true) 
  {
    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }

    if (!entry.isDirectory()) 
    {
      Serial.println("FILENAME:" + String(entry.name()));
      printFileToSerial(entry.name());
    }
    entry.close();
  }
}

void printFileToSerial(String filename)
{
  File dataFile = SD.open(filename);

  if (dataFile) 
  {
    while (dataFile.available()) 
    {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  }
  else 
  {
    Serial.println("error opening datalog.txt");
  }
  Serial.println("END_OF_FILE(EOF)");
}


void loop()
{
  //Do Nothing
}
