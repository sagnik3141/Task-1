from gpiozero import MotionSensor
from picamera import PiCamera

pir = MotionSensor(4)
camera = PiCamera()
filename = "intruder.h264"

while True:
	pir.wait_for_motion()

	import smtplib
 
        server = smtplib.SMTP('smtp.gmail.com', 587)
        server.starttls()
        server.login("from_email_address", "from_email_password")
 
        msg = "INTRUDER!"
        server.sendmail("from_email_address", "to_email_address", msg)
        server.quit()
	print("Motion detected!")
    	camera.start_recording(filename)

    	pir.wait_for_no_motion()

    	camera.stop_preview()