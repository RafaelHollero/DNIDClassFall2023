import processing.serial.*;
import processing.sound.*;

Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port
String val_check;

boolean play_sound;

SoundFile hot_sound;
SoundFile cold_sound;
SoundFile right_sound;


void setup()
{
  size(1300, 750);
  background(255);
  hot_sound = new SoundFile(this, "HOT HOT HOT Sound Effect.mp3");
  cold_sound = new SoundFile(this, "Freezing cold (Sound Effect).mp3");
  right_sound = new SoundFile(this, "Correct Answer sound effect.mp3");
  
  // I know that the first port in the serial list on my mac
  // is Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  for(int i=0; i<Serial.list().length; i++){
   println(i + "; " + Serial.list()[i]); 
  }
  String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
  
}


void draw()
{
  if ( myPort.available() > 0) 
    {  // If data is available,
      val_check = myPort.readStringUntil('\n');
      if (val != null && val.equals(val_check))
      {
        play_sound = false;
      }
      else
      {
        val = val_check;
        play_sound = true;
      }
      
    
      if(val != null && play_sound){
        // println("[" + val.trim() + "]");
        if(val.trim().equals("hot")){
          if(hot_sound.isPlaying() == false && cold_sound.isPlaying() == false && right_sound.isPlaying() == false){
            hot_sound.play();
          }
          
        }
        
        else if(val.trim().equals("cold")){
          if(hot_sound.isPlaying() == false && cold_sound.isPlaying() == false && right_sound.isPlaying() == false){
            cold_sound.play();
          }
          
        }
      
        else if(val.trim().equals("right")){
          if(hot_sound.isPlaying() == false && cold_sound.isPlaying() == false && right_sound.isPlaying() == false){
            right_sound.play();
          }
        
        }
      
      
      }// end of if
    }// end of if data is available
    
}
