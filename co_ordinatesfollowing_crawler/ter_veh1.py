#please comment all lines starting with GPIO and time(just use replace all :D; GPIO with #GPIO and time with #time) and comment the "import RPi" and "import time" lines too to just run the code
#the code contains lot of print statements which will give us a picture of the direction and angle by which the robot has to turn by
import math
import time
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)

#define pins
enableA=5
inA1=6
inA2=13
enableB=17
inB1=22
inB2=27

#SET-UP
GPIO.setup(input1,GPIO.OUT)
GPIO.setup(input2,GPIO.OUT)
GPIO.setup(enable,GPIO.OUT)

#variables
refer_angle=90
speed1=23.35
rottime=0.01023

#functions
def get_dist(co_or):
	d1=((co_or[0][0]-co_or[1][0])*(co_or[0][0]-co_or[1][0]))+((co_or[0][1]-co_or[1][1])*(co_or[0][1]-co_or[1][1]))
	d2=math.sqrt(d1)
	return d2
def get_angle(co_or):
	x1=co_or[0][0]
	y1=co_or[0][1]
	x2=co_or[1][0]
	y2=co_or[1][1]
	if(x1==x2 and y1>y2):
		return 270
	elif(x1==x2 and y1<y2):
		return 90
	elif(x1>x2 and y1==y2):
		return 180
	elif(x1<x2 and y1==y2):
		return 0
	else:
		x=x1-x2
		y=y1-y2
		d=y/x
		#print("d value is",d)
		aa=math.atan(d)
		bb=(aa*180)/3.1415
		if(x1<x2 and y1<y2):#first quad
			return bb
		elif(x1>x2 and y1>y2):#third quad
			return 180+bb
		elif(x1>x2 and y1<y2):#second quad
			return 180+bb
		elif(x1<x2 and y1>y2):#fourth quad
			return 360+bb
def botTurn(ga,refer_angle):
	print("In bot turn")
	turnby=refer_angle-ga
	print("Should Turn by:",turnby)
	timing=turnby*rottime
	print("before Reference angle:",refer_angle)
	if(timing<0):
		timing=(-1)*timing
	if(turnby<0):
		turnby=(-1)*turnby
	if((ga>=refer_angle and ga<=(refer_angle+180))):
		if(turnby>180):
			turnby1=180-ga
			timing1=turnby*rottime
			print("Actual turn by",turnby1)
			print("Turned left1")
			GPIO.output (enableA, GPIO.HIGH)
			GPIO.output (enableB, GPIO.LOW)
			time.sleep (0.15)
			GPIO.output (inputA1, GPIO.LOW)
			GPIO.output (inputA2, GPIO.HIGH)#The right motor should turn and not the left so as to turn left
			time.sleep(timing1)
		else:
			print("Turned left")
			GPIO.output (enableA, GPIO.HIGH)
			GPIO.output (enableB, GPIO.LOW) 
			time.sleep (0.15)
			GPIO.output (inputA1, GPIO.LOW)
			GPIO.output (inputA2, GPIO.HIGH)#The left motor should turn and not the right so as to turn right
			time.sleep(timing)
	else:
		if(turnby>180 and refer_angle<=180):	
			turnby1=360-turnby
			timing1=turnby1*rottime
			print("Actual turn by",turnb1)
			print("Turned right1")
			GPIO.output (enableA, GPIO.HIGH)
			GPIO.output (enableB, GPIO.LOW) 
			time.sleep (0.15)
			GPIO.output (inputB1, GPIO.HIGH)
			GPIO.output (inputB2, GPIO.LOW)#The right motor should turn and not the left so as to turn left
			time.sleep(timing1)
		else:
			print("Turned right")
			GPIO.output (enableA, GPIO.LOW)
			GPIO.output (enableB, GPIO.HIGH)
			time.sleep (0.15)
			GPIO.output (inputB1, GPIO.LOW)
			GPIO.output (inputB2, GPIO.HIGH)#The right motor should turn and not the left so as to turn left
			time.sleep(timing)
	refer_angle=ga
	print("current Reference angle:",refer_angle)
	return refer_angle
def botMove(gd): 
	print("In bot move")
	timing=gd/speed1
	GPIO.output(enableA,GPIO.HIGH)
	GPIO.output(inA1,GPIO.HIGH)
	GPIO.output(inA2,GPIO.LOW)
	GPIO.output(enableB,GPIO.HIGH)
	GPIO.output(inB1,GPIO.HIGH)
	GPIO.output(inB2,GPIO.LOW)
	time.sleep(timing)
	print("Done with botmove")

#main
co_or=[[0,0],[1,1],[2,1],[2,2],[1,2],[0,0]]
refer_angle=90
for i in range(0,len(co_or)-1):
	a=[]
	a1=list(co_or[i])
	a.append(a1)
	a.append(co_or[i+1])
	print(a)
	gd=get_dist(a)
	print(gd)
	ga=get_angle(a)
	print(ga)
	refer_angle=botTurn(ga,refer_angle)
	botMove(gd)
	print("\n")